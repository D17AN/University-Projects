package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.StringType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.IntValue;
import domain.value.StringValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements StatementInterface{
    private final ExpressionInterface expression;
    private final String variableName;

    public ReadFile(ExpressionInterface expression, String variableName){
        this.expression = expression;
        this.variableName = variableName;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTDictionaryInterface<String, BufferedReader> fileTable = state.getFileTable();
        if(symTable.isExistent(variableName)){
            ValueInterface value = symTable.get(variableName);
            if (value.getType().equals(new IntType())) {
                value = expression.eval(symTable, state.getHeap());
                if (value.getType().equals(new StringType())) {
                    StringValue castValue = (StringValue) value;
                    if (fileTable.isExistent(castValue.getValue())) {
                        BufferedReader buffRead = fileTable.get(castValue.getValue());
                        try {
                            String line = buffRead.readLine();
                            if (line == null)
                                line = "0";
                            symTable.put(variableName, new IntValue(Integer.parseInt(line)));
                        } catch (IOException e) {
                            throw new ToyLanguageException(
                                    String.format("Error reading the content of the file %s", castValue));
                        }
                    } else {
                        throw new ToyLanguageException(String.format("%s doesn't appear in the file table", castValue));
                    }
                } else {
                    throw new ToyLanguageException(String.format("%s error evaluation to StringType", value));
                }
            } else {
                throw new ToyLanguageException(String.format("%s is not of type IntType", value));
            }
        }else {
            throw new ToyLanguageException(String.format("%s is not in symTable", variableName));
        }
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new ReadFile(this.expression.clone(), this.variableName);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(expression.checkType(typeD).equals(new StringType()))
            if(typeD.get(variableName).equals(new IntType()))
                return typeD;
            else
                throw new ToyLanguageException("ReadFile parameter must be of type int!");
        else
            throw new ToyLanguageException("ReadFile expression must be a string!");
    }

    @Override
    public String toString(){
        return String.format("ReadFile(%s, %s)", this.expression.toString(), this.variableName);
    }
}
