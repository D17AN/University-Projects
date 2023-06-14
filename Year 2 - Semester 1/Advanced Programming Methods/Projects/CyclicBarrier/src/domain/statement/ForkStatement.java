package domain.statement;

import com.sun.jdi.Value;
import domain.programState.ProgramState;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionary;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTStack.ADTStack;
import domain.utils.ADTStack.ADTStackInterface;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.util.Map;

public class ForkStatement implements StatementInterface{
    private final StatementInterface statement;

    public ForkStatement(StatementInterface statement){
        this.statement = statement;
    }

    @Override
    public ProgramState execute(ProgramState prgState) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        ADTStackInterface<StatementInterface> newStack = new ADTStack<>();
        newStack.push(statement);
        ADTDictionaryInterface<String, ValueInterface> newSymTable = new ADTDictionary<>();
        for(Map.Entry<String, ValueInterface> e: prgState.getSymTable().getContent().entrySet()){
            newSymTable.put(e.getKey(), e.getValue().clone());
        }
        return new ProgramState(newStack, newSymTable, prgState.getOut(), prgState.getFileTable(), prgState.getHeap(), prgState.getBarrierTable());
    }

    @Override
    public StatementInterface clone() {
        return new ForkStatement(statement.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        statement.checkType(typeD.clone());
        return typeD;
    }

    @Override
    public String toString(){
        return String.format("Fork(%s)", statement.toString());
    }
}
