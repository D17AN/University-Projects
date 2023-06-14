package domain.utils.ADTStack;
import exceptions.ToyLanguageException;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ADTStack<T> implements ADTStackInterface<T>{
    ArrayList<T> stack;

    public ADTStack(){
        stack = new ArrayList<T>();
    }

    public void push(T item) {
        synchronized (this) {
            this.stack.add(item);
        }
    }

    public T pop()throws ToyLanguageException {
        synchronized (this) {
            if (this.stack.isEmpty()) {
                throw new ToyLanguageException("The stack is empty! Cannot pop elements.");
            }
            return this.stack.remove(this.stack.size() - 1);
        }
    }

    public T peek()throws ToyLanguageException {
        synchronized (this) {
            if (this.stack.isEmpty()) {
                throw new ToyLanguageException("The stack is empty! Cannot return the top item.");
            }
            return this.stack.get(this.stack.size() - 1);
        }
    }

    public boolean isEmpty() {
        synchronized (this) {
            return this.stack.isEmpty();
        }
    }

    public int size() {
        synchronized (this) {
            return this.stack.size();
        }
    }

    public List<T> getReversed(){
        synchronized (this) {
            List<T> l = Arrays.asList((T[]) this.stack.toArray());
            return l;
        }
    }

    @Override
    public String toString(){
        return this.stack.toString();
    }


}
