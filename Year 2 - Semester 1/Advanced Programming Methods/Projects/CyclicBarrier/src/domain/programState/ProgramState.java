package domain.programState;

import domain.statement.StatementInterface;
import domain.utils.ADTBarrierTable.ADTBarrierTableInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.utils.ADTList.ADTListInterface;
import domain.utils.ADTStack.ADTStackInterface;
import domain.value.ValueInterface;
import exceptions.*;

import java.io.BufferedReader;
import java.util.List;

public class ProgramState {
    ADTStackInterface<StatementInterface> exeStack;
    ADTDictionaryInterface<String, ValueInterface> symTable;
    ADTListInterface<ValueInterface> out;
    private ADTDictionaryInterface<String, BufferedReader> fileTable;
    private ADTHeapInterface heap;
    private ADTBarrierTableInterface barrierTable;
    private StatementInterface originalProgram;
    private int id;
    private static int lastID = 0;

    public ProgramState(ADTStackInterface<StatementInterface> stk, ADTDictionaryInterface<String,
            ValueInterface> symtbl, ADTListInterface<ValueInterface> ot,
                        ADTDictionaryInterface<String, BufferedReader> fileTable, ADTHeapInterface heap,
                        ADTBarrierTableInterface barrierTable,
                        StatementInterface prg){
        this.exeStack = stk;
        this.symTable = symtbl;
        this.out = ot;
        this.fileTable = fileTable;
        this.heap = heap;
        this.barrierTable = barrierTable;
        this.originalProgram = prg.clone();
        this.exeStack.push(this.originalProgram);
        this.id = setID();
    }

    public ProgramState(ADTStackInterface<StatementInterface> stk, ADTDictionaryInterface<String,
            ValueInterface> symtbl, ADTListInterface<ValueInterface> ot,
                        ADTDictionaryInterface<String, BufferedReader> fileTable, ADTHeapInterface heap,
                        ADTBarrierTableInterface barrierTable){
        this.exeStack = stk;
        this.symTable = symtbl;
        this.out = ot;
        this.fileTable = fileTable;
        this.heap = heap;
        this.barrierTable = barrierTable;
        this.id = setID();
    }

    public synchronized int setID(){
        lastID++;
        return lastID;
    }

    public int getID(){
        return this.id;
    }

    public void setExeStack(ADTStackInterface<StatementInterface> newStk){
        this.exeStack = newStk;
    }

    public void setSymTable(ADTDictionaryInterface<String, ValueInterface> newSymTbl){
        this.symTable = newSymTbl;
    }

    public void setOut(ADTListInterface<ValueInterface> new_o){
        this.out = new_o;
    }

    public void setFileTable(ADTDictionaryInterface<String, BufferedReader> newFileTable){
        this.fileTable = newFileTable;
    }

    public void setHeap(ADTHeapInterface newHeap){
        this.heap = newHeap;
    }

    public void setBarrierTable(ADTBarrierTableInterface newBarrierTable) {
        this.barrierTable = newBarrierTable;
    }

    public ADTStackInterface<StatementInterface> getExeStack(){
        return this.exeStack;
    }

    public ADTDictionaryInterface<String, ValueInterface> getSymTable(){
        return this.symTable;
    }

    public ADTListInterface<ValueInterface> getOut(){
        return this.out;
    }

    public ADTDictionaryInterface<String, BufferedReader> getFileTable(){
        return this.fileTable;
    }

    public ADTHeapInterface getHeap(){
        return this.heap;
    }

    public ADTBarrierTableInterface getBarrierTable() {
        return barrierTable;
    }

    public boolean isNotFinished(){
        return exeStack.isEmpty();
    }

    public ProgramState oneStep() throws ToyLanguageException {
        if(exeStack.isEmpty())
            throw new ToyLanguageException("The program state is empty!");
        StatementInterface currStat = exeStack.pop();
        return currStat.execute(this);
    }

    public String exeStackToString(){
        StringBuilder exeStackStringBuilder = new StringBuilder();
        List<StatementInterface> stack = this.exeStack.getReversed();
        for(StatementInterface statement: stack){
            exeStackStringBuilder.append(statement.toString()).append("\n");
        }
        return exeStackStringBuilder.toString();
    }

    public String symTableToString(){
        StringBuilder symTableStringBuilder = new StringBuilder();
        for(String key: this.symTable.getKeys()){
            symTableStringBuilder.append(String.format("%s -> %s\n", key, this.symTable.get(key).toString()));
        }
        return symTableStringBuilder.toString();
    }

    public String outToString(){
        StringBuilder outStringBuilder = new StringBuilder();
        for(ValueInterface elem: out.getList()){
            outStringBuilder.append(String.format("%s\n", elem.toString()));
        }
        return outStringBuilder.toString();
    }

    public String fileTableToString(){
        StringBuilder fileTableStringBuilder = new StringBuilder();
        for(String key: this.fileTable.getKeys()){
            fileTableStringBuilder.append(String.format("%s\n", key));
        }
        return fileTableStringBuilder.toString();
    }

    public String heapToString() throws ToyLanguageException {
        StringBuilder heapStringBuilder = new StringBuilder();
        for(int key: this.heap.keySet())
            heapStringBuilder.append(String.format("%d -> %s\n", key, this.heap.get(key)));
        return heapStringBuilder.toString();
    }

    public String barrierTableToString() throws ToyLanguageException {
        StringBuilder barrierTableStringBuilder = new StringBuilder();
        for (int key: barrierTable.getBarrierTableHostagesFromBasement().keySet()) {
            barrierTableStringBuilder.append(String.format("%d -> (%d, %s)\n", key, barrierTable.getHostageFromBasement(key).getKey(), barrierTable.getHostageFromBasement(key).getValue()));
        }
        return barrierTableStringBuilder.toString();
    }

    @Override
    public String toString(){
        return "ID: " + id + "\nExecution stack:\n" + this.exeStack.getReversed() + "\nSymbol table:\n" + this.symTable.toString()
                + "\nOutput list:\n" + out.toString() + "\nFile table:\n" + fileTable.toString() +
                "\nHeap memory:\n" + heap.toString() + "\nBarrier Table:\n" + barrierTable.toString() + "\n";
    }

    public String programeStateToString() throws ToyLanguageException {
        return "ID: " + id + "\nExecution Stack:\n" + exeStackToString() + "SymbolTable:\n" + symTableToString()
                + "Output list:\n" + outToString() + "File table:\n" + fileTableToString() + "Heap memory:\n" + heapToString() +
                "Barrier table:\n" + barrierTableToString();

    }


}
