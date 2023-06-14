package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.BooleanType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import domain.value.BooleanValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

public class WhileStatement implements StatementInterface{
    private final ExpressionInterface expression;
    private final StatementInterface statement;

    public WhileStatement(ExpressionInterface expression, StatementInterface statement){
        this.expression = expression;
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ValueInterface value = this.expression.eval(state.getSymTable(), state.getHeap());
        ADTStackInterface<StatementInterface> stack = state.getExeStack();
        if(!value.getType().equals(new BooleanType()))
            throw new ToyLanguageException(String.format("%s is not a BooleanType", value));
        if(!(value instanceof BooleanValue))
            throw new ToyLanguageException(String.format("%s is not a BooleanValue", value));
        BooleanValue booleanValue = (BooleanValue) value;
        if(booleanValue.getValue()){
            stack.push(this);
            stack.push(this.statement);
        }
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new WhileStatement(this.expression.clone(), this.statement.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        TypeInterface tExpr = expression.checkType(typeD);
        if(tExpr.equals(new BooleanType())){
            statement.checkType(typeD.clone());
            return typeD;
        }else
            throw new ToyLanguageException("While condition must be boolean!");
    }

    @Override
    public String toString(){
        return String.format("while(%s){%s}", this.expression, this.statement);
    }
}
