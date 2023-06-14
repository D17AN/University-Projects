package domain.statement;

import domain.type.BooleanType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.utils.ADTStack.ADTStackInterface;
import domain.value.ValueInterface;
import domain.value.BooleanValue;

public class IfStatement implements StatementInterface{
    ExpressionInterface expression;
    StatementInterface thenStatement;
    StatementInterface elseStatement;

    public IfStatement(ExpressionInterface expression, StatementInterface thenStatement, StatementInterface elseStatement){
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ValueInterface res = this.expression.eval(state.getSymTable(), state.getHeap());
        if(res instanceof BooleanValue boolRes){
            StatementInterface statement;
            if(boolRes.getValue()){
                statement = thenStatement;
            }
            else{
                statement = elseStatement;
            }
            ADTStackInterface<StatementInterface> stack = state.getExeStack();
            stack.push(statement);
            state.setExeStack(stack);
            return null;
        }
        else{
            throw new ToyLanguageException("A boolean expression is required to be provided in the if statement!");
        }
    }

    @Override
    public StatementInterface clone(){
        return new IfStatement(expression.clone(), thenStatement.clone(), elseStatement.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface tExpr = expression.checkType(typeD);
        if(tExpr.equals(new BooleanType())){
            thenStatement.checkType(typeD.clone());
            elseStatement.checkType(typeD.clone());
            return typeD;
        }
        else
            throw new ToyLanguageException("Condition expression must be a Boolean!");
    }

    @Override
    public String toString(){
        return String.format("if(%s){%s}else{%s}", expression.toString(), thenStatement.toString(), elseStatement.toString());
    }
}
