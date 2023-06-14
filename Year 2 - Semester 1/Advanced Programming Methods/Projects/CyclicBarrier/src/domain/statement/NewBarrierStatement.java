package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTBarrierTable.ADTBarrierTableInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewBarrierStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expression;
    private static final Lock lock = new ReentrantLock();

    public NewBarrierStatement(String var, ExpressionInterface expression) {
        this.var = var;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        ADTBarrierTableInterface barrierTable = state.getBarrierTable();
        IntValue personTargetedForRansom = (IntValue) (expression.eval(symTable, heap));
        int personCapturedForRansom = personTargetedForRansom.getValue();
        int availableAddress = barrierTable.getAvailableAddressFromBasement();
        barrierTable.putHostageInBasement(availableAddress, new Pair<>(personCapturedForRansom, new ArrayList<>()));
        if (symTable.isExistent(var))
            symTable.put(var, new IntValue(availableAddress));
        else
            throw new ToyLanguageException(String.format("%s not found in symbol table!", var));
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new NewBarrierStatement(var, expression.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType()))
            if (expression.checkType(typeD).equals(new IntType()))
                return typeD;
            else
                throw new ToyLanguageException("Expression must be int!");
        else
            throw new ToyLanguageException("Variable must be int!");
    }

    @Override
    public String toString() {
        return String.format("newBarrier(%s, %s)", var, expression);
    }
}
