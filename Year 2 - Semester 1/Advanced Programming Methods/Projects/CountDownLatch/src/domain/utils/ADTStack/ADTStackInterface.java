package domain.utils.ADTStack;

import exceptions.EmptyStackException;
import exceptions.ToyLanguageException;

import java.util.List;

public interface ADTStackInterface<T>{
    void push(T item);
    T pop()throws ToyLanguageException;
    T peek()throws ToyLanguageException;
    boolean isEmpty();
    int size();
    List<T> getReversed();
}

