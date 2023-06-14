package domain.expression;

import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.BooleanValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

public class NotExpression implements ExpressionInterface{
    private final ExpressionInterface expr;

    public NotExpression(ExpressionInterface expr){
        this.expr = expr;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException {
        BooleanValue val = (BooleanValue) this.expr.eval(symTable, heap);
        if(!val.getValue())
            return new BooleanValue(true);
        return new BooleanValue(false);
    }

    @Override
    public ExpressionInterface clone() {
        return new NotExpression(this.expr.clone());
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException {
        return this.expr.checkType(typeD);
    }

    @Override
    public String toString(){
        return String.format("!(%s)", this.expr);
    }
}
