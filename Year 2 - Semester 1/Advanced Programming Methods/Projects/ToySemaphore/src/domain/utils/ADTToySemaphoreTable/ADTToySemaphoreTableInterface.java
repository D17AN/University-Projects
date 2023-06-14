package domain.utils.ADTToySemaphoreTable;

import exceptions.ToyLanguageException;

import java.util.HashMap;
import java.util.List;

public interface ADTToySemaphoreTableInterface {
    void put(int key, Tuple<Integer, List<Integer>, Integer> value) throws ToyLanguageException;
    Tuple<Integer, List<Integer>, Integer> get(int key) throws ToyLanguageException;
    boolean containsKey(int key);
    int getFreeAddress();
    void setFreeAddress(int freeAddress);
    void update(int key, Tuple<Integer, List<Integer>, Integer> value) throws ToyLanguageException;
    HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> getToySemaphoreTable();
    void setToySemaphoreTable(HashMap<Integer, Tuple<Integer, List<Integer>, Integer>> newToySemaphoreTable);
}
