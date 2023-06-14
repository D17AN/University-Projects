package domain.utils.ADTLatchTable;

import exceptions.ToyLanguageException;

import java.util.HashMap;

public interface ADTLatchTableInterface{
    void put(int key, int val) throws ToyLanguageException;
    int get(int key) throws ToyLanguageException;
    boolean containsKey(int key);
    int getAvailableAddress();
    void update(int key, int value) throws ToyLanguageException;
    void setAvailableAddress(int availableAddress);
    HashMap<Integer, Integer> getLatchTable();
    void setLatchTable(HashMap<Integer, Integer> newLatchTable);
}
