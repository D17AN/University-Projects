package domain.statement;

import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.ValueInterface;

public class VarDeclarationStatement implements StatementInterface{
    String name;
    TypeInterface type;

    public VarDeclarationStatement(String name, TypeInterface type){
        this.name = name;
        this.type = type;
    }

    @Override
    public ProgramState execute(ProgramState state)throws ToyLanguageException {
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        if(symTable.isExistent(name)){
            throw new ToyLanguageException("Variable " + name + " has a previous declaration in symTable.");
        }
        symTable.put(name, type.defaultValue());
        state.setSymTable(symTable);
        return null;
    }

    @Override
    public StatementInterface clone(){
        return new VarDeclarationStatement(name, type);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        typeD.put(name, type);
        return typeD;
    }

    @Override
    public String toString(){
        return String.format("%s %s", type.toString(), name);
    }
}
