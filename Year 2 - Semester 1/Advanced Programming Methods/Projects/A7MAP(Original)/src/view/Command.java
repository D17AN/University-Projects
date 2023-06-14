package view;

import exceptions.EmptyStackException;
import exceptions.ExpressionEvaluationException;
import exceptions.NonExistentElementException;
import exceptions.StatementExecutionException;

import java.io.IOException;

public abstract class Command {
    private final String key;
    private final String info;

    public Command(String key, String info){
        this.key = key;
        this.info = info;
    }

    public abstract void execute() throws EmptyStackException, ExpressionEvaluationException, NonExistentElementException, IOException, InterruptedException, StatementExecutionException;

    public String getKey(){
        return this.key;
    }

    public String getInfo(){
        return this.info;
    }
}
