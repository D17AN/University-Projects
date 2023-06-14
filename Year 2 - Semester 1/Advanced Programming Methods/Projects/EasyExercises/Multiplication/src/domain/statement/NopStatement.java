package domain.statement;

import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

public class NopStatement implements StatementInterface{
    @Override
    public ProgramState execute(ProgramState state){
        return null;
    }

    @Override
    public StatementInterface clone(){
        return new NopStatement();
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return typeD;
    }

    @Override
    public String toString(){
        return "NopStatement";
    }
}
