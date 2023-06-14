package domain.utils.ADTList;

import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ADTList<T> implements ADTListInterface<T>{
    ArrayList<T> l;

    public ADTList(){
        l = new ArrayList<T>();
    }

    public T get(int index)throws ToyLanguageException {
        synchronized (this) {
            if (0 > index || index >= this.l.size()) {
                throw new ToyLanguageException("Index out of bounds! Cannot access the element at that index!");
            }
            return this.l.get(index);
        }
    }

    public void insert(int index, T elem)throws ToyLanguageException {
        synchronized (this) {
            if (0 > index || index > this.l.size()) {
                throw new ToyLanguageException("Index out of bounds! Cannot insert the element at that position!");
            }
            this.l.add(index, elem);
        }
    }

    public void add(T elem){
        synchronized (this) {
            this.l.add(elem);
        }
    }

    public void remove(T elem)throws ToyLanguageException {
        synchronized (this) {
            if (this.l.size() == 0) {
                throw new ToyLanguageException("The list is empty! No elements can be removed!");
            }
            if (!this.l.contains(elem)) {
                throw new ToyLanguageException("The element to be deleted doesn't exist in the list!");
            }
            this.l.remove(elem);
        }
    }

    public void removeAt(int index)throws ToyLanguageException {
        synchronized (this) {
            if (this.l.size() == 0) {
                throw new ToyLanguageException("The list is empty! No element can be deleted!");
            }
            if (0 > index || index > this.l.size()) {
                throw new ToyLanguageException("The element to be deleted is on a position which cannot be accessed!");
            }
            this.l.remove(index);
        }
    }

    public void replace(int index, T new_elem)throws ToyLanguageException {
        synchronized (this) {
            if (this.l.size() == 0) {
                throw new ToyLanguageException("The list is empty! No element can be replaced!");
            }
            if (0 > index || index > this.l.size()) {
                throw new ToyLanguageException("The element to be replaced is on a position which cannot be accessed!");
            }

            this.l.set(index, new_elem);
        }
    }

    public int size(){
        synchronized (this) {
            return this.l.size();
        }
    }

    public boolean isEmpty(){
        synchronized (this) {
            return this.l.isEmpty();
        }
    }

    public List<T> getList(){
        synchronized (this) {
            List<T> new_l = Arrays.asList((T[]) this.l.toArray());
            return new_l;
        }
    }

    @Override
    public String toString(){
        return this.l.toString();
    }
}
