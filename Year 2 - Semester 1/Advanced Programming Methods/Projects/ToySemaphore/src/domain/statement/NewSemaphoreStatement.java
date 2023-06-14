package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.utils.ADTToySemaphoreTable.ADTToySemaphoreTableInterface;
import domain.utils.ADTToySemaphoreTable.Tuple;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewSemaphoreStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expression1;
    private final ExpressionInterface expression2;
    private static final Lock lock = new ReentrantLock();

    public NewSemaphoreStatement(String var, ExpressionInterface expression1, ExpressionInterface expression2) {
        this.var = var;
        this.expression1 = expression1;
        this.expression2 = expression2;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        ADTToySemaphoreTableInterface semaphoreTable = state.getToySemaphoreTable();
        IntValue nr1 = (IntValue) (expression1.eval(symTable, heap));
        IntValue nr2 = (IntValue) (expression2.eval(symTable, heap));
        int number1 = nr1.getValue();
        int number2 = nr2.getValue();
        int freeAddress = semaphoreTable.getFreeAddress();
        semaphoreTable.put(freeAddress, new Tuple<>(number1, new ArrayList<>(), number2));
        if (symTable.isExistent(var) && symTable.get(var).getType().equals(new IntType()))
            symTable.put(var, new IntValue(freeAddress));
        else
            throw new ToyLanguageException(String.format("%s in not defined in the symbol table!", var));
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new NewSemaphoreStatement(var, expression1.clone(), expression2.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        return typeD;
    }

    @Override
    public String toString() {
        return String.format("newSemaphore(%s, %s, %s)", var, expression1, expression2);
    }
}
