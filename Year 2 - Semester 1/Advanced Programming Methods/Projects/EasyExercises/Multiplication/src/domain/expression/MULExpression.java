package domain.expression;

import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

public class MULExpression implements ExpressionInterface{
    private final ExpressionInterface expr1;
    private final ExpressionInterface expr2;

    public MULExpression(ExpressionInterface expr1, ExpressionInterface expr2){
        this.expr1 = expr1;
        this.expr2 = expr2;
    }
    @Override
    public ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException {
        ExpressionInterface new_expr = new ArithmExpression('-',
                new ArithmExpression('+', this.expr1, this.expr2),
                new ArithmExpression('*', this.expr1, this.expr2));

        return new_expr.eval(symTable, heap);
    }

    @Override
    public ExpressionInterface clone() {
        return new MULExpression(this.expr1.clone(), this.expr2.clone());
    }

    @Override
    public TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException {
        TypeInterface type1 = this.expr1.checkType(typeD);
        TypeInterface type2 = this.expr2.checkType(typeD);
        if(type1.equals(new IntType()) && type2.equals(new IntType()))
            return new IntType();
        else
            throw new ToyLanguageException("Error, the types inside the expression must be int!");
    }

    @Override
    public String toString(){
        return String.format("MUL(%s, %s)", this.expr1, this.expr2);
    }
}
