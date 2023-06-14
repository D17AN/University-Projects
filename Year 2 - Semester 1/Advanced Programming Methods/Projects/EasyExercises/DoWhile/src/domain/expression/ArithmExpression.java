package domain.expression;

import domain.type.TypeInterface;
import domain.utils.ADTHeap.ADTHeap;
import domain.utils.ADTHeap.ADTHeapInterface;
import exceptions.ExpressionEvaluationException;
import domain.type.IntType;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

public class ArithmExpression implements ExpressionInterface{
    ExpressionInterface exp1;
    ExpressionInterface exp2;
    char operation;

    public ArithmExpression(char op, ExpressionInterface exp2, ExpressionInterface exp1){
        this.exp1 = exp1;
        this.exp2 = exp2;
        this.operation = op;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException {
        ValueInterface val1, val2;
        val1 = this.exp1.eval(symTable, heap);
        if (val1.getType().equals(new IntType())) {
            val2 = this.exp2.eval(symTable, heap);
            if (val2.getType().equals(new IntType())) {
                IntValue int1 = (IntValue) val1;
                IntValue int2 = (IntValue) val2;
                int n1, n2;
                n1 = int1.getValue();
                n2 = int2.getValue();
                if (this.operation == '+')
                    return new IntValue(n1 + n2);
                else if (this.operation == '-') {
                    return new IntValue(n1 - n2);
                } else if (this.operation == '*') {
                    return new IntValue(n1 * n2);
                } else if (this.operation == '/') {
                    if (n2 == 0)
                        throw new ToyLanguageException("Division by zero!");
                    else
                        return new IntValue(n1 / n2);
                }
            } else
                throw new ToyLanguageException("Second operand is not an interger!");
        } else
            throw new ToyLanguageException("First operand is not an interger!");
        return null;
    }

    @Override
    public ExpressionInterface clone(){
        return new ArithmExpression(this.operation, this.exp2.clone(), this.exp1.clone());
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException {
        TypeInterface t1, t2;
        t1 = exp1.checkType(typeD);
        t2 = exp2.checkType(typeD);
        if(t1.equals(new IntType())){
            if(t2.equals(new IntType())){
                return new IntType();
            }else
                throw new ToyLanguageException("2nd operand not integer!");
        }
        else
            throw new ToyLanguageException("1st operand not integer!");
    }

    @Override
    public String toString(){
        return this.exp1.toString() + " " + this.operation + " " + this.exp2.toString();
    }
}
