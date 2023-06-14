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

public class WriteHeapStatement implements StatementInterface{
    private final String variableName;
    private final ExpressionInterface expression;

    public WriteHeapStatement(String variableName, ExpressionInterface expression){
        this.variableName = variableName;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        if(symTable.isExistent(this.variableName)) {
            ValueInterface value = symTable.get(this.variableName);
            if (value.getType() instanceof RefType) {
                RefValue refValue = (RefValue) value;
                if(heap.isExistent(refValue.getAddress())) {
                    ValueInterface result = expression.eval(symTable, heap);
                    if (result.getType().equals(refValue.getLocationType())) {
                        heap.update(refValue.getAddress(), result);
                        state.setHeap(heap);
                    } else
                        throw new ToyLanguageException(String.format("%s not of %s", result, refValue));
                }
                else
                    throw new ToyLanguageException(String.format("The RefValue %s not defined in the heap", value));
            }
            else
                throw new ToyLanguageException(String.format("%s not of RefType", value));
        }
        else
            throw new ToyLanguageException(String.format("%s not found in symTable", this.variableName));
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new WriteHeapStatement(this.variableName, this.expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(typeD.get(variableName).equals(new RefType(expression.checkType(typeD))))
            return typeD;
        else
            throw new ToyLanguageException("Writting heap, right and left hand side have different types!");
    }

    @Override
    public String toString(){
        return String.format("WriteHeap(%s, %s)", this.variableName, this.expression);
    }
}
