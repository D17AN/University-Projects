package domain.statement;

import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

public class CompStatement implements StatementInterface{
    StatementInterface first;
    StatementInterface second;

    public CompStatement(StatementInterface first, StatementInterface second) {
        this.first = first;
        this.second = second;
    }

    public ProgramState execute(ProgramState state){
        ADTStackInterface<StatementInterface> stk = state.getExeStack();
        stk.push(second);
        stk.push(first);
        state.setExeStack(stk);
        return null;
    }

    @Override
    public StatementInterface clone(){
        return new CompStatement(first.clone(), second.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return second.checkType(first.checkType(typeD));
    }

    @Override
    public String toString(){
        return String.format("%s|%s", first.toString(), second.toString());
    }
}
