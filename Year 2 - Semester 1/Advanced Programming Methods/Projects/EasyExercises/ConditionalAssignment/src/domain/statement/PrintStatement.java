package domain.statement;

import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import exceptions.ToyLanguageException;
import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.utils.ADTList.ADTListInterface;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

public class PrintStatement implements StatementInterface {
    ExpressionInterface expression;

    public PrintStatement(ExpressionInterface expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException {
        ADTListInterface<ValueInterface> out = state.getOut();
        out.add(expression.eval(state.getSymTable(), state.getHeap()));
        state.setOut(out);
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new PrintStatement(expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        expression.checkType(typeD);
        return typeD;
    }

    @Override
    public String toString() {
        return String.format("Print(%s)", expression.toString());
    }
}
