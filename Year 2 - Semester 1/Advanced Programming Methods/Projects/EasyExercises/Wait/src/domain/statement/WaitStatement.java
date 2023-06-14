package domain.statement;

import domain.expression.ValueExpression;
import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStackInterface;
import domain.value.IntValue;
import exceptions.ToyLanguageException;

public class WaitStatement implements StatementInterface{
    private final int val;

    public WaitStatement(int val){
        this.val = val;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(this.val != 0){
            ADTStackInterface<StatementInterface> exeStack = state.getExeStack();
            exeStack.push(new CompStatement(new PrintStatement(new ValueExpression(new IntValue(this.val))),
                    new WaitStatement(this.val - 1)));
            state.setExeStack(exeStack);
        }
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new WaitStatement(this.val);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return typeD;
    }

    @Override
    public String toString(){
        return String.format("wait(%s)", this.val);
    }
}
