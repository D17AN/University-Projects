package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.RefType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.RefValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.beans.Expression;

public class NewStatement implements StatementInterface{
    private final String variableName;
    private final ExpressionInterface expression;

    public NewStatement(String variableName, ExpressionInterface expression){
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        if(symTable.isExistent(this.variableName)) {
            ValueInterface variableValue = symTable.get(this.variableName);
            if ((variableValue.getType() instanceof RefType)) {
                ValueInterface result = this.expression.eval(symTable, heap);
                TypeInterface locationType = ((RefValue) variableValue).getLocationType();
                if (locationType.equals(result.getType())) {
                    int newPos = heap.add(result);
                    symTable.put(this.variableName, new RefValue(newPos, locationType));
                    state.setSymTable(symTable);
                    state.setHeap(heap);
                }
                else
                    throw new ToyLanguageException(String.format("%s not of %s", this.variableName, result.getType()));
            }
            else
                throw new ToyLanguageException(String.format("%s is not RefType", this.variableName));
        }
        else
            throw new ToyLanguageException(String.format("%s not found in symTable", this.variableName));
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new NewStatement(this.variableName, this.expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface tVar = typeD.get(variableName);
        TypeInterface tExpr = expression.checkType(typeD);
        if(tVar.equals(new RefType(tExpr)))
            return typeD;
        else
            throw new ToyLanguageException("Right and left hand side must have the same types!");
    }

    @Override
    public String toString(){
        return String.format("New(%s,%s)", this.variableName, this.expression);
    }
}
