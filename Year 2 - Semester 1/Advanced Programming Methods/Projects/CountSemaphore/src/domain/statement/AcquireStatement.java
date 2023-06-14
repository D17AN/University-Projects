package domain.statement;

import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTSemaphoreTable.ADTSemaphoreTableInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AcquireStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AcquireStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTSemaphoreTableInterface semaphoreTable = state.getSemaphoreTable();
        if (symTable.isExistent(var)) {
            if (symTable.get(var).getType().equals(new IntType())){
                IntValue fi = (IntValue) symTable.get(var);
                int foundIndex = fi.getValue();
                if (semaphoreTable.getSemaphoreTable().containsKey(foundIndex)) {
                    Pair<Integer, List<Integer>> foundSemaphore = semaphoreTable.get(foundIndex);
                    int NL = foundSemaphore.getValue().size();
                    int N1 = foundSemaphore.getKey();
                    if (N1 > NL) {
                        if (!foundSemaphore.getValue().contains(state.getID())) {
                            foundSemaphore.getValue().add(state.getID());
                            semaphoreTable.update(foundIndex, new Pair<>(N1, foundSemaphore.getValue()));
                        }
                    } else {
                        state.getExeStack().push(this);
                    }
                } else {
                    throw new ToyLanguageException("Index not a key in the semaphore table!");
                }
            } else {
                throw new ToyLanguageException("Index must be of int type!");
            }
        } else {
            throw new ToyLanguageException("Index not in symbol table!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new AcquireStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType())) {
            return typeD;
        } else {
            throw new ToyLanguageException(String.format("%s is not int!", var));
        }
    }

    @Override
    public String toString() {
        return String.format("acquire(%s)", var);
    }

}
