package domain.statement;

import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import domain.programState.ProgramState;
import exceptions.ToyLanguageException;

public interface StatementInterface{
    ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException;//execution method for a statement
    StatementInterface clone();
    ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String,TypeInterface> typeD)throws ToyLanguageException, ToyLanguageException, ToyLanguageException;
}
