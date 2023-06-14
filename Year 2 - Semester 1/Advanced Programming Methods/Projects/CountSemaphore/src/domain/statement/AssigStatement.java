package domain.statement;

import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.ValueInterface;

public class AssigStatement implements StatementInterface{
    private final String key;
    private final ExpressionInterface expression;

    public AssigStatement(String key, ExpressionInterface expression){
        this.key = key;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTDictionaryInterface<String, ValueInterface> symbolTable = state.getSymTable();
        if(symbolTable.isExistent(key)) {
            ValueInterface val = expression.eval(symbolTable, state.getHeap());
            TypeInterface typeID = (symbolTable.get(key)).getType();
            if (val.getType().equals(typeID)) {
                symbolTable.put(key, val);
            } else {
                throw new ToyLanguageException("Declaration type of the variable " + key
                        + " and type of the assigned expression doesn't correspond!");
            }
        } else {
            throw new ToyLanguageException("The used variable " + key + " has no previous declaration!");
        }
        state.setSymTable(symbolTable);
        return null;
    }

    @Override
    public StatementInterface clone(){
        return new AssigStatement(key, expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface tVar = typeD.get(key);
        TypeInterface tExpr = expression.checkType(typeD);
        if(tVar.equals(tExpr))
            return typeD;
        else
            throw new ToyLanguageException("Assignment error, right and Left hand side have different type!");
    }

    @Override
    public String toString(){
        return String.format("%s = %s", key, expression.toString());
    }

}
