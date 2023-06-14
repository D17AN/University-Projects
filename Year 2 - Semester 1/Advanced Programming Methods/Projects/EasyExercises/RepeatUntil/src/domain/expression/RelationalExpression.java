package domain.expression;

import domain.type.BooleanType;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.BooleanValue;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.util.Objects;

public class RelationalExpression implements ExpressionInterface{
    ExpressionInterface expression1;
    ExpressionInterface expression2;
    String operator;

    public RelationalExpression(String operator, ExpressionInterface expression1, ExpressionInterface expression2){
        this.expression1 = expression1;
        this.expression2 = expression2;
        this.operator = operator;
    }

    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException{
        ValueInterface val1, val2;
        val1 = this.expression1.eval(symTable, heap);
        if(val1.getType().equals(new IntType())){
            val2 = this.expression2.eval(symTable, heap);
            if(val2.getType().equals(new IntType())) {
                IntValue v1 = (IntValue) val1;
                IntValue v2 = (IntValue) val2;
                int a1 = v1.getValue();
                int a2 = v2.getValue();
                if (Objects.equals(this.operator, "<"))
                    return new BooleanValue(a1 < a2);
                else if (Objects.equals(this.operator, ">"))
                    return new BooleanValue(a1 > a2);
                else if (Objects.equals(this.operator, "<="))
                    return new BooleanValue(a1 <= a2);
                else if (Objects.equals(this.operator, ">="))
                    return new BooleanValue(a1 >= a2);
                else if (Objects.equals(this.operator, "=="))
                    return new BooleanValue(a1 == a2);
                else if (Objects.equals(this.operator, "!="))
                    return new BooleanValue(a1 != a2);
            }
            else
                throw new ToyLanguageException("Second operand must be an integer!");
        }
        else
            throw new ToyLanguageException("First operand must be an integer!");
        return null;
    }

    @Override
    public ExpressionInterface clone() {
        return new RelationalExpression(operator, expression1.clone(), expression2.clone());
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException{
        TypeInterface t1, t2;
        t1 = expression1.checkType(typeD);
        t2 = expression2.checkType(typeD);
        if(t1.equals(new IntType())) {
            if (t2.equals(new IntType())) {
                return new BooleanType();
            } else
                throw new ToyLanguageException("2nd operand not an integer!");
        }
        else
            throw new ToyLanguageException("1st operand not an integer!");
    }

    @Override
    public String toString(){
        return this.expression1.toString() + " " + this.operator + " " + this.expression2.toString();
    }
}
