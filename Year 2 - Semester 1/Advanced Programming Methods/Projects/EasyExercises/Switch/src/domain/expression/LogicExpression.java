package domain.expression;

import domain.type.TypeInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import exceptions.ExpressionEvaluationException;
import domain.type.BooleanType;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.BooleanValue;
import domain.value.ValueInterface;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

import java.util.Objects;

public class LogicExpression implements ExpressionInterface{
    ExpressionInterface expression1;
    ExpressionInterface expression2;
    String operation;

    public LogicExpression(ExpressionInterface expression1, ExpressionInterface expression2, String operation){
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.operation = operation;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException {
        ValueInterface val1, val2;
        val1 = this.expression1.eval(symTable, heap);
        if(val1.getType().equals(new BooleanType())) {
            val2 = this.expression2.eval(symTable, heap);
            if (val2.getType().equals(new BooleanType())) {
                BooleanValue bool1 = (BooleanValue) val1;
                BooleanValue bool2 = (BooleanValue) val2;
                boolean b1, b2;
                b1 = bool1.getValue();
                b2 = bool2.getValue();
                if (Objects.equals(this.operation, "and")) {
                    return new BooleanValue(b1 && b2);
                } else if (Objects.equals(this.operation, "or")) {
                    return new BooleanValue(b1 || b2);
                }
            } else {
                throw new ToyLanguageException("Second operand is not of type boolean!");
            }
        }
        else{
            throw new ToyLanguageException("First operand is not of type boolean!");
        }
        return null;
    }

    @Override
    public ExpressionInterface clone(){
        return new LogicExpression(this.expression1.clone(), this.expression2.clone(), this.operation);
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException {
        TypeInterface t1, t2;
        t1 = expression1.checkType(typeD);
        t2 = expression2.checkType(typeD);
        if (t1.equals(new BooleanType())) {
            if (t2.equals(new BooleanType())) {
                return new BooleanType();
            } else
                throw new ToyLanguageException("2nd operand not boolean!");
        }
        throw new ToyLanguageException("1st operand not boolean");
    }

    @Override
    public String toString(){
        return this.expression1.toString() + " " + this.operation + " " + this.expression2.toString();
    }
}
