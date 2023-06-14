package repository;

import domain.programState.ProgramState;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

import java.io.IOException;
import java.util.List;

public interface RepositoryInterface {
    List<ProgramState> getProgramStatesList();
    void setProgramStates(List<ProgramState> programStates);
    void addProgram(ProgramState prg);
    void logPrgStateExec(ProgramState prg) throws ToyLanguageException, IOException;
    void emptyLogFile() throws IOException;


}
