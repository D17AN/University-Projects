package domain.statement;

import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionary;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTLatchTable.ADTLatchTableInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AwaitStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AwaitStatement(String var){
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTLatchTableInterface latchTable = state.getLatchTable();
        if(symTable.isExistent(this.var)) {
            IntValue foundIndex1 = (IntValue) symTable.get(this.var);
            int foundIndex2 = foundIndex1.getValue();
            if (latchTable.containsKey(foundIndex2)) {
                if (latchTable.get(foundIndex2) != 0) {
                    state.getExeStack().push(this);
                }
            } else {
                throw new ToyLanguageException("Index must be in latch table!");
            }
        }
        else{
            throw new ToyLanguageException("Variable must be defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new AwaitStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(this.var).equals(new IntType())) {
            return typeD;
        } else
            throw new ToyLanguageException(String.format("%s must be of type int!", this.var));
    }

    @Override
    public String toString(){
        return String.format("await(%s)", this.var);
    }
}
