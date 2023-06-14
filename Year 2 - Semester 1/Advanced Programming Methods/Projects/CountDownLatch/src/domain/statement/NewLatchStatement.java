package domain.statement;

import domain.expression.ExpressionInterface;
import domain.programState.ProgramState;
import domain.type.IntType;
import domain.type.TypeInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.utils.ADTLatchTable.ADTLatchTableInterface;
import domain.value.IntValue;
import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class NewLatchStatement implements StatementInterface{
    private final String var;
    private final ExpressionInterface expr;
    private static final Lock lock = new ReentrantLock();

    public NewLatchStatement(String var, ExpressionInterface expr){
        this.var = var;
        this.expr = expr;
    }

    @Override
    public ProgramState execute(ProgramState state) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        lock.lock();
        ADTDictionaryInterface<String, ValueInterface> symTable =  state.getSymTable();
        ADTHeapInterface heap = state.getHeap();
        ADTLatchTableInterface latchTable = state.getLatchTable();
        IntValue nr1 = (IntValue) (this.expr.eval(symTable, heap));
        int nr2 = nr1.getValue();
        int availableAddress = latchTable.getAvailableAddress();
        latchTable.put(availableAddress, nr2);
        if(symTable.isExistent(this.var)){
            symTable.put(this.var, new IntValue(availableAddress));
        }
        else{
            throw new ToyLanguageException(String.format("%s must be defined in the symbol table!", this.var));
        }
        lock.unlock();
        return null;
    }

    @Override
    public StatementInterface clone() {
        return new NewLatchStatement(this.var, this.expr.clone());
    }

    @Override
    public ADTDictionaryInterface<String, TypeInterface> checkType(ADTDictionaryInterface<String, TypeInterface> typeD) throws ToyLanguageException, ToyLanguageException, ToyLanguageException {
        if(typeD.get(this.var).equals(new IntType())){
            if(this.expr.checkType(typeD).equals(new IntType())){
                return typeD;
            }
            else{
                throw new ToyLanguageException("The expression must be of type int!");
            }
        }
        else{
            throw new ToyLanguageException(String.format("%s must be of type int!", this.var));
        }
    }

    @Override
    public String toString(){
        return String.format("newLatch(%s, %s)", this.var, this.expr);
    }
}
