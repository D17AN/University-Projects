package domain.expression;

import domain.type.RefType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.RefValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.beans.Expression;

public class ReadHeapExpression implements ExpressionInterface{
    private final ExpressionInterface expression;

    public ReadHeapExpression(ExpressionInterface expression){
        this.expression = expression;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException{
        ValueInterface value = this.expression.eval(symTable, heap);
        if(value instanceof RefValue) {
            RefValue refValue = (RefValue) value;
            if(heap.isExistent(refValue.getAddress()))
                return heap.get(refValue.getAddress());
            else
                throw new ToyLanguageException("The address is not defined on the heap!");
        }
        else
            throw new ToyLanguageException(String.format("%s is not defined as a RefType", value));
    }

    @Override
    public ExpressionInterface clone() {
        return new ReadHeapExpression(this.expression.clone());
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException{
        TypeInterface t = expression.checkType(typeD);
        if(t instanceof RefType){
            RefType rt = (RefType) t;
            return rt.getInner();
        }else
            throw new ToyLanguageException("The ReadHeap argurment not a RefType.");
    }

    @Override
    public String toString(){
        return String.format("ReadHeap(%s)", expression);
    }
}
