package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.utils.ADTSemaphoreTable.ADTSemaphoreTableInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CreateSemaphoreStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expression;
    private static final Lock lock = new ReentrantLock();

    public CreateSemaphoreStatement(String var, ExpressionInterface expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        ADTSemaphoreTableInterface semaphoreTable = state.getSemaphoreTable();
        IntValue nr = (IntValue) (expression.eval(symTable, heap));
        int number = nr.getValue();
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Pair<>(number, new ArrayList<>()));
        if (symTable.isExistent(var) && symTable.get(var).getType().equals(new IntType()))
            symTable.put(var, new IntValue(freeAddress));
        else
            throw new ToyLanguageException(String.format("Error for variable %s: not defined/does not have int type!", var));
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new CreateSemaphoreStatement(var, expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType())) {
            if (expression.checkType(typeD).equals(new IntType()))
                return typeD;
            else
                throw new ToyLanguageException("Expression is not of int type!");
        } else {
            throw new ToyLanguageException(String.format("%s is not of type int!", var));
        }
    }

    @Override
    public String toString() {
        return String.format("createSemaphore(%s, %s)", var, expression);
    }

}
