package domain.statement;

import domain.expression.ExpressionInterface;
import domain.expression.RelationalExpression;
import domain.expression.VariableExpression;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;

import java.lang.reflect.Type;

public class ForStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expr1;
    private final ExpressionInterface expr2;
    private final ExpressionInterface expr3;
    private final StatementInterface stm;

    public ForStatement(String var, ExpressionInterface expr1,ExpressionInterface expr2, ExpressionInterface expr3, StatementInterface stm){
        this.var = var;
        this.expr1 = expr1;
        this.expr2 = expr2;
        this.expr3 = expr3;
        this.stm = stm;

    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTStackInterface<StatementInterface> exeStack = state.getExeStack();
        StatementInterface new_stat = new CompStatement(new AssigStatement("v", this.expr1),
                new WhileStatement(new RelationalExpression("<", new VariableExpression("v"), this.expr2),
                        new CompStatement(this.stm, new AssigStatement("v", this.expr3))));
        exeStack.push(new_stat);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new ForStatement(this.var, this.expr1.clone(), this.expr2.clone(), this.expr3.clone(), this.stm.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface type1 = this.expr1.checkType(typeD);
        TypeInterface type2 = this.expr2.checkType(typeD);
        TypeInterface type3 = this.expr3.checkType(typeD);

        if(type1.equals(new IntType()) && type2.equals(new IntType()) && type3.equals(new IntType()))
            return typeD;
        else
            throw new ToyLanguageException("Error, types aren't matching!");
    }

    @Override
    public String toString(){
        return String.format("for(%s = %s; %s < %s; %s = %s) { %s }", this.var, this.expr1, this.var, this.expr2, this.var, this.expr3, this.stm);
    }

}
