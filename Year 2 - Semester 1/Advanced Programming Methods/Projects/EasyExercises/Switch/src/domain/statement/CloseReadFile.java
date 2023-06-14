package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.StringType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.StringValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.io.BufferedReader;
import java.io.IOException;

public class CloseReadFile implements StatementInterface{
    private final ExpressionInterface expression;

    public CloseReadFile(ExpressionInterface expression){
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ValueInterface value = this.expression.eval(state.getSymTable(), state.getHeap());
        if(value.getType().equals(new StringType())) {
            StringValue fileName = (StringValue) value;
            ADTDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();
            if (!fileTable.isExistent(fileName.getValue())) {
                BufferedReader buffRead = fileTable.get(fileName.getValue());
                try {
                    buffRead.close();
                } catch (IOException e) {
                    throw new ToyLanguageException(String.format("Error when closing the file %s", value));
                }
                fileTable.remove(fileName.getValue());
                state.setFileTable(fileTable);
            }
            else
                throw new ToyLanguageException(String.format("%s not in FileTable.", value));
        }
        else
            throw new ToyLanguageException(String.format("%s evaluation error to StringType.", this.expression));
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new CloseReadFile(this.expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(expression.checkType(typeD).equals(new StringType()))
            return typeD;
        else
            throw new ToyLanguageException("Expression CloseReadFile needs provided a string expression.");
    }

    @Override
    public String toString(){
        return String.format("CloseReadFile(%s)", this.expression.toString());
    }
}
