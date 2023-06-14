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
import java.io.FileNotFoundException;
import java.io.FileReader;

public class OpenReadFile implements StatementInterface{
    private final ExpressionInterface expression;

    public OpenReadFile(ExpressionInterface expression){
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ValueInterface value = this.expression.eval(state.getSymTable(), state.getHeap());
        if(value.getType().equals(new StringType())) {
            StringValue fileName = (StringValue) value;
            ADTDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();
            if (!fileTable.isExistent(fileName.getValue())) {
                BufferedReader buffRead;
                try {
                    buffRead = new BufferedReader(new FileReader(fileName.getValue()));

                } catch (FileNotFoundException e) {
                    throw new ToyLanguageException(e.getMessage());
                }
                fileTable.put(fileName.getValue(), buffRead);
                state.setFileTable(fileTable);
            } else {
                throw new ToyLanguageException(String.format("%s has currently an open status.",
                        fileName.getValue()));
            }
        }
        else{
            throw new ToyLanguageException(String.format("%s evaluation error to StringType",
                    this.expression.toString()));
        }
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new OpenReadFile(this.expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
         if(expression.checkType(typeD).equals(new StringType()))
             return typeD;
         else
             throw new ToyLanguageException("String expression requiered for OpenReadFile statement!");
    }

    @Override
    public String toString(){
        return String.format("OpenReadFile(%s)", this.expression.toString());
    }
}
