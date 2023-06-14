package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.BooleanType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import exceptions.ToyLanguageException;

import javax.swing.plaf.nimbus.State;

public class DoWhileStatement implements StatementInterface{
    private final StatementInterface stm;//statement
    private final ExpressionInterface expr;//expression

    public DoWhileStatement(ExpressionInterface expr, StatementInterface stm){
        this.stm = stm;
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        StatementInterface new_stat = new CompStatement(this.stm, new WhileStatement(this.expr, this.stm));// converting while statement to a do while
        state.getExeStack().push(new_stat);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new DoWhileStatement(this.expr.clone(), this.stm.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface typeExpr = this.expr.checkType(typeD);
        if(typeExpr.equals(new BooleanType())){
            this.stm.checkType(typeD.clone());
            return typeD;
        }
        else{
            throw new ToyLanguageException("Error, Boolean condition is requiered!");
        }
    }

    public String toString(){
        return String.format("do {%s} while (%s)", this.stm, this.expr);
    }
}
