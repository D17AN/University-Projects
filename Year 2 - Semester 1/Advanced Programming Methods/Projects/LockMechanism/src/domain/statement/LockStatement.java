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

public class LockStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public LockStatement(String var) {
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
                    if (lockTable.get(foundIndex) == -1) {
                        lockTable.update(foundIndex, state.getID());
                        state.setLockTable(lockTable);
                    } else {
                        state.getExeStack().push(this);
                    }
                } else {
                    throw new ToyLanguageException("Index is not in the lock table!");
                }
            } else {
                throw new ToyLanguageException("Var is not of type int!");
            }
        } else {
            throw new ToyLanguageException("Variable not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new LockStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType())) {
            return typeD;
        } else {
            throw new ToyLanguageException("Var is not of int type!");
        }
    }

    @Override
    public String toString() {
        return String.format("lock(%s)", var);
    }
}
