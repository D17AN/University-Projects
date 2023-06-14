package repository;

import domain.programState.ProgramState;
import exceptions.ToyLanguageException;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements RepositoryInterface{
    private List<ProgramState> programStates;
    private final String logFileLocation;

    public Repository(ProgramState programState, String logFileLocation) throws IOException {
        this.programStates = new ArrayList<>();
        this.logFileLocation = logFileLocation;
        this.addProgram(programState);
        this.emptyLogFile();
    }

    @Override
    public List<ProgramState> getProgramStatesList(){
        return this.programStates;
    }

    @Override
    public void setProgramStates(List<ProgramState> programStates){
        this.programStates = programStates;
    }

    @Override
    public void addProgram(ProgramState prg){
        this.programStates.add(prg);
    }

    @Override
    public void logPrgStateExec(ProgramState prg) throws ToyLanguageException, IOException {
        PrintWriter logFile;
        logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFileLocation, true)));
        logFile.println(prg.programeStateToString());
        logFile.close();

    }
    @Override
    public void emptyLogFile() throws IOException {
        PrintWriter logFile;
        logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFileLocation, false)));
        logFile.close();
    }
}
