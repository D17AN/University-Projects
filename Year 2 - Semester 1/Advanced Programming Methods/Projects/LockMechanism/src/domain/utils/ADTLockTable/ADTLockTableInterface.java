package domain.utils.ADTLockTable;

import exceptions.ToyLanguageException;

import java.util.HashMap;
import java.util.Set;

public interface ADTLockTableInterface{
    int getFreeValue();
    void put(int key, int value) throws ToyLanguageException;
    HashMap<Integer, Integer> getContent();
    boolean containsKey(int position);
    int get(int position) throws ToyLanguageException;
    void update(int position, int value) throws ToyLanguageException;
    void setContent(HashMap<Integer, Integer> newMap);
    Set<Integer> keySet();
}
