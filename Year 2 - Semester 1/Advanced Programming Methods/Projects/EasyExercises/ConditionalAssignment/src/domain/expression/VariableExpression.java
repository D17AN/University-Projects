package domain.expression;

import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

public class VariableExpression implements ExpressionInterface{
    String key;

    public VariableExpression(String key){
        this.key = key;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap){
        return symTable.get(this.key);
    }

    @Override
    public ExpressionInterface clone(){
        return new VariableExpression(key);
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException {
        return typeD.get(key);
    }

    @Override
    public String toString() {
        return key;
    }

}

