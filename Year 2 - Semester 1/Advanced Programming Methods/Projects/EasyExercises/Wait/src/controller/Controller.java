package controller;

import domain.value.RefValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import domain.programState.ProgramState;
import domain.statement.StatementInterface;
import domain.utils.ADTStack.ADTStackInterface;
import repository.RepositoryInterface;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Controller {
    RepositoryInterface repo;
    boolean displayFlag = false;
    ExecutorService executorService;

    public void setDisplayFlag(boolean value){
        this.displayFlag = value;
    }

    public Controller(RepositoryInterface repository){
        this.repo = repository;
    }


    public List<Integer> getAddressesFromSymTable(Collection<ValueInterface> symTable){
        return symTable.stream().filter(s->s instanceof RefValue).
                map(s->{RefValue s1 = (RefValue) s; return s1.getAddress();}).
                collect(Collectors.toList());
    }

    public List<Integer> getAddressesFromHeap(Collection<ValueInterface> heap){
        return heap.stream().filter(s->s instanceof RefValue).
                map(s->{RefValue s1 = (RefValue) s; return s1.getAddress();}).
                collect(Collectors.toList());
    }

    public Map<Integer, ValueInterface> safeGarbageCollector(List<Integer> symTableAddresses, List<Integer> heapAddresses, Map<Integer, ValueInterface> heap){
        return heap.entrySet().stream().
                filter(s->(symTableAddresses.contains(s.getKey()) || heapAddresses.contains(s.getKey()))).
                collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public void conservativeGarbageCollector(List<ProgramState> programStates){
        List<Integer> symTableAddrs = Objects.requireNonNull(programStates.stream()
                .map(p->getAddressesFromSymTable(p.getSymTable().getValues()))
                .map(Collection::stream)
                .reduce(Stream::concat).orElse(null))
                .collect(Collectors.toList());
        programStates.forEach(p->{
            p.getHeap().setHeap((HashMap<Integer, ValueInterface>) safeGarbageCollector(symTableAddrs, getAddressesFromHeap(p.getHeap().getContent().values()), p.getHeap().getContent()));
        });
    }

    public void oneStepForAllPrograms(List<ProgramState> prgStates) throws InterruptedException, ToyLanguageException{
        prgStates.forEach(prg -> {
            try{
                this.repo.logPrgStateExec(prg);
                this.display(prg);
            }
            catch (IOException | ToyLanguageException e){
                System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
            }
        });
        List<Callable<ProgramState>> callList = prgStates.stream()
                .map((ProgramState p) -> (Callable<ProgramState>) (p::oneStep))
                .collect(Collectors.toList());

        List<ProgramState> newPrgList = executorService.invokeAll(callList).stream()
                .map(f->{
                    try{
                        return f.get();
                    }
                    catch (ExecutionException | InterruptedException e){
                        System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
                    }
                    return null;
                })
                .filter(Objects::nonNull)
                .collect(Collectors.toList());

        prgStates.addAll(newPrgList);

        prgStates.forEach(programState -> {
            try{
                this.repo.logPrgStateExec(programState);
            }
            catch(IOException | ToyLanguageException e){
                System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
            }
        });

        this.repo.setProgramStates(prgStates);
    }

    public void allSteps() throws ToyLanguageException, IOException, InterruptedException {
        this.executorService = Executors.newFixedThreadPool(2);
        List<ProgramState>  prgStates = removeTerminatedProgram(this.repo.getProgramStatesList());
        while(prgStates.size() > 0){
            oneStepForAllPrograms(prgStates);
            conservativeGarbageCollector(prgStates);
            //prgStates = removeTerminatedProgram(this.repo.getProgramStatesList());//comment?
        }
        this.executorService.shutdownNow();
        //this.repo.setProgramStates(prgStates);//comment?
    }

    public void oneStep()throws ToyLanguageException, InterruptedException{
        this.executorService = Executors.newFixedThreadPool(2);
        List<ProgramState>  prgStates = removeTerminatedProgram(this.repo.getProgramStatesList());
        oneStepForAllPrograms(prgStates);
        conservativeGarbageCollector(prgStates);
        //prgStates = removeTerminatedProgram(this.repo.getProgramStatesList());//comment?
        this.executorService.shutdownNow();
        //this.repo.setProgramStates(prgStates);//comment?
    }

    public List<ProgramState> removeTerminatedProgram(List<ProgramState> inPrgList){
        return inPrgList.stream().filter(p->!p.isNotFinished()).collect(Collectors.toList());
    }

    private void display(ProgramState prg){
        if(displayFlag){
            System.out.println(prg.toString());
        }
    }

    public void setProgramStates(List<ProgramState> programStates){
        this.repo.setProgramStates(programStates);
    }

    public List<ProgramState> getProgramStates(){
        return this.repo.getProgramStatesList();
    }



}
