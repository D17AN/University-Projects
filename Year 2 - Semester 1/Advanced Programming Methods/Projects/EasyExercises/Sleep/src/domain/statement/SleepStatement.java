package domain.statement;

import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;

public class SleepStatement implements StatementInterface{
    private final int val;

    public SleepStatement(int val){
        this.val = val;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(this.val != 0){
            ADTStackInterface<StatementInterface> exeStack = state.getExeStack();
            exeStack.push(new SleepStatement(this.val - 1));
            state.setExeStack(exeStack);
        }
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new SleepStatement(this.val);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return typeD;
    }

    @Override
    public String toString(){
        return String.format("sleep(%s)", this.val);
    }
}
