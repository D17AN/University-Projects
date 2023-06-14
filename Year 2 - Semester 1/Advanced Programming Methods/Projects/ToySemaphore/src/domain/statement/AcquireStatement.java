package domain.statement;

import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTToySemaphoreTable.ADTToySemaphoreTableInterface;
import domain.utils.ADTToySemaphoreTable.Tuple;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

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
        ADTToySemaphoreTableInterface semaphoreTable = state.getToySemaphoreTable();
        if (symTable.isExistent(var)) {
            if (symTable.get(var).getType().equals(new IntType())) {
                IntValue fi = (IntValue) symTable.get(var);
                int foundIndex = fi.getValue();
                if (semaphoreTable.containsKey(foundIndex)) {
                    Tuple<Integer, List<Integer>, Integer> foundSemaphore = semaphoreTable.get(foundIndex);
                    int NL = foundSemaphore.getSecond().size();
                    int N1 = foundSemaphore.getFirst();
                    int N2 = foundSemaphore.getThird();
                    if ((N1 - N2) > NL) {
                        if (!foundSemaphore.getSecond().contains(state.getID())) {
                            foundSemaphore.getSecond().add(state.getID());
                            semaphoreTable.update(foundIndex, new Tuple<>(N1, foundSemaphore.getSecond(), N2));
                        }
                    } else {
                        state.getExeStack().push(this);
                    }
                } else {
                    throw new ToyLanguageException("Index is not in the semaphore table!");
                }
            } else {
                throw new ToyLanguageException("Index does not have the int type!");
            }
        } else
            throw new ToyLanguageException("Index not in the symbol table!");
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new AcquireStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return typeD;
    }

    @Override
    public String toString() {
        return String.format("acquire(%s)", var);
    }
}
