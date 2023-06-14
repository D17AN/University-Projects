package domain.statement;

import domain.expression.ExpressionInterface;
import domain.expression.VariableExpression;
import domain.programState.ProgramState;
import domain.type.BooleanType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;

public class ConditionalAssignmentStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expr1;
    private final ExpressionInterface expr2;
    private final ExpressionInterface expr3;

    public ConditionalAssignmentStatement(String var, ExpressionInterface expr1, ExpressionInterface expr2, ExpressionInterface expr3){
        this.var = var;
        this.expr1 = expr1;
        this.expr2 = expr2;
        this.expr3 = expr3;

    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTStackInterface<StatementInterface> exeStack = state.getExeStack();
        StatementInterface new_stat = new IfStatement(this.expr1,
                new AssigStatement(this.var, this.expr2), new AssigStatement(this.var, this.expr3));//converting IfStatement to a conditional statement
        exeStack.push(new_stat);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new ConditionalAssignmentStatement(this.var, this.expr1.clone(), this.expr2.clone(), this.expr3.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface varType = new VariableExpression(this.var).checkType(typeD);
        TypeInterface type1 = this.expr1.checkType(typeD);
        TypeInterface type3 = this.expr2.checkType(typeD);
        TypeInterface type2 = this.expr3.checkType(typeD);
        if(type1.equals(new BooleanType()) && type2.equals(varType) && type3.equals(varType))
            return typeD;
        else
            throw new ToyLanguageException("Error, types are not matching!");

    }

    @Override
    public String toString(){
        return String.format("%s = (%s)? %s : %s", this.var, this.expr1, this.expr2, this.expr3);
    }
}
