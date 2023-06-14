package domain.statement;

import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTBarrierTable.ADTBarrierTableInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class AwaitStatement implements StatementInterface{
    private final String var;
    private static final Lock lock = new ReentrantLock();

    public AwaitStatement(String var) {
        this.var = var;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable = state.getSymTable();
        ADTBarrierTableInterface barrierTableForHostages = state.getBarrierTable();
        if (symTable.isExistent(var)) {
            IntValue f = (IntValue) symTable.get(var);
            int foundTargetedPersonForCapture = f.getValue();//index
            if (barrierTableForHostages.isKeyInBasement(foundTargetedPersonForCapture)) {
                Pair<Integer, List<Integer>> barrierKeptHostage = barrierTableForHostages.getHostageFromBasement(foundTargetedPersonForCapture);
                int barrierKeptHostageSize = barrierKeptHostage.getValue().size();
                int barrierKeptHostageKey = barrierKeptHostage.getKey();
                ArrayList<Integer> list = (ArrayList<Integer>) barrierKeptHostage.getValue();
                if (barrierKeptHostageKey > barrierKeptHostageSize) {
                    if (list.contains(state.getID()))
                        state.getExeStack().push(this);
                    else {
                        list.add(state.getID());
                        barrierTableForHostages.updateHostageFromBasement(foundTargetedPersonForCapture, new Pair<>(barrierKeptHostageKey, list));
                        state.setBarrierTable(barrierTableForHostages);
                    }
                }
            } else {
                throw new ToyLanguageException("Index not in Barrier Table!");
            }
        } else {
            throw new ToyLanguageException("Var is not defined!");
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new AwaitStatement(var);
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if (typeD.get(var).equals(new IntType()))
            return typeD;
        else
            throw new ToyLanguageException("Var is not of type int!");
    }

    @Override
    public String toString() {
        return String.format("await(%s)", var);
    }

}
