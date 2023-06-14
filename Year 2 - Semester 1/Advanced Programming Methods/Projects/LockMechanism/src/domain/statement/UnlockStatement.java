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

public class UnlockStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public UnlockStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTLockTableInterface lockTable = state.getLockTable();
        if (symTable.isExistent(var)) {
            if (symTable.get(var).getType().equals(new IntType())) {
                IntValue fi = (IntValue) symTable.get(var);
                int foundIndex = fi.getValue();
                if (lockTable.containsKey(foundIndex)) {
                    if (lockTable.get(foundIndex) == state.getID())
                        lockTable.update(foundIndex, -1);
                } else {
                    throw new ToyLanguageException("Index not in the lock table!");
                }
            } else {
                throw new ToyLanguageException("Var is not of int type!");
            }
        } else {
            throw new ToyLanguageException("Variable is not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new UnlockStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType()))
            return typeD;
        else
            throw new ToyLanguageException("Var is not of type int!");
    }

    @Override
    public String toString() {
        return String.format("unlock(%s)", var);
    }
}
