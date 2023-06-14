package domain.statement;

import domain.expression.ExpressionInterface;
import domain.expression.NotExpression;
import domain.programState.ProgramState;
import domain.type.BooleanType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;

public class RepeatUntilStatement implements StatementInterface{
    private final StatementInterface stm;
    private ExpressionInterface expr;

    public RepeatUntilStatement(StatementInterface stm, ExpressionInterface expr){
        this.stm = stm;
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTStackInterface<StatementInterface>  exeStack = state.getExeStack();
        StatementInterface new_stat = new CompStatement(this.stm,
                new WhileStatement(new NotExpression(this.expr), this.stm));
        exeStack.push(new_stat);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new RepeatUntilStatement(this.stm.clone(), this.expr.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface type = this.expr.checkType(typeD);
        if(type.equals(new BooleanType())){
            this.stm.checkType(typeD.clone());
            return typeD;
        }
        else{
            throw new ToyLanguageException("Error, the condition must be of type bool!");
        }
    }

    @Override
    public String toString(){
        return String.format("repeat(%s) until (%s)", this.stm, this.expr);
    }
}
