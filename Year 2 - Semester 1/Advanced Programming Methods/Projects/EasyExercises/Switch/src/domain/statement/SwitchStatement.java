package domain.statement;

import domain.expression.ExpressionInterface;
import domain.expression.RelationalExpression;
import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import exceptions.ToyLanguageException;

public class SwitchStatement implements StatementInterface{
    private final ExpressionInterface mainExpr;
    private final ExpressionInterface expr1;
    private final StatementInterface stm1;
    private final ExpressionInterface expr2;
    private final StatementInterface stm2;
    private final StatementInterface baseStm;

    public SwitchStatement(ExpressionInterface mainExpr, ExpressionInterface expr1, StatementInterface stm1, ExpressionInterface expr2, StatementInterface stm2, StatementInterface baseStm){
        this.mainExpr = mainExpr;
        this.expr1 = expr1;
        this.stm1 = stm1;
        this.expr2 = expr2;
        this.stm2 = stm2;
        this.baseStm = baseStm;
    }
    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTStackInterface<StatementInterface> exeStack = state.getExeStack();
        StatementInterface new_stat = new IfStatement(new RelationalExpression("==", this.mainExpr, this.expr1),
                this.stm1, new IfStatement(new RelationalExpression("==", this.mainExpr, this.expr2),
                this.stm2, this.baseStm));
        exeStack.push(new_stat);
        state.setExeStack(exeStack);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new SwitchStatement(this.mainExpr.clone(), this.expr1.clone(), this.stm1.clone(), this.expr2.clone(), this.stm2.clone(), this.baseStm.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface mainType = this.mainExpr.checkType(typeD);
        TypeInterface type1 = this.expr1.checkType(typeD);
        TypeInterface type2 = this.expr2.checkType(typeD);
        if(mainType.equals(type1) && mainType.equals(type2)){
            this.stm1.checkType(typeD.clone());
            this.stm2.checkType(typeD.clone());
            this.baseStm.checkType(typeD.clone());
            return typeD;
        }
        else{
            throw new ToyLanguageException("Error, expression types don't match");
        }
    }

    @Override
    public String toString(){
        return String.format("switch(%s){(case(%s): %s)(case(%s): %s)(default: %s)}", this.mainExpr, this.expr1, this.stm1, this.expr2, this.stm2, this.baseStm);

    }
}
