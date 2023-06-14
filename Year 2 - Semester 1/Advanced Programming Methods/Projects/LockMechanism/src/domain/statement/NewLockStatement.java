package domain.statement;

import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTLockTable.ADTLockTableInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLockStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public NewLockStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTLockTableInterface lockTable = state.getLockTable();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        int freeAddress = lockTable.getFreeValue();
        lockTable.put(freeAddress, -1);
        if (symTable.isExistent(var) && symTable.get(var).getType().equals(new IntType()))
            symTable.put(var, new IntValue(freeAddress));
        else
            throw new ToyLanguageException("Variable not declared!");
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new NewLockStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType()))
            return typeD;
        else
            throw new ToyLanguageException("Var is not of int type!");
    }

    @Override
    public String toString() {
        return String.format("newLock(%s)", var);
    }
}
