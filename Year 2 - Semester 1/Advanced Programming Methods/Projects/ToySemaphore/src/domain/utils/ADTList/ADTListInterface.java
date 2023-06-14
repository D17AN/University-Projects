package domain.utils.ADTList;

import exceptions.EmptyListException;
import exceptions.IndexOutOfBoundsException;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

import java.util.List;

public interface ADTListInterface<T>{
    T get(int index)throws ToyLanguageException;
    void insert(int index, T elem)throws ToyLanguageException;
    void add(T elem);
    void remove(T elem)throws ToyLanguageException;
    void removeAt(int index)throws ToyLanguageException;
    void replace(int index, T new_elem)throws ToyLanguageException;
    int size();
    boolean isEmpty();
    List<T> getList();
}


