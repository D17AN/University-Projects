package domain.utils.ADTSemaphoreTable;

import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public interface ADTSemaphoreTableInterface {
    void put(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException;
    Pair<Integer, List<Integer>> get(int key) throws ToyLanguageException;
    boolean containsKey(int key);
    int getFreeAddress();
    void setFreeAddress(int freeAddress);
    void update(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException;
    HashMap<Integer, Pair<Integer, List<Integer>>> getSemaphoreTable();
    void setSemaphoreTable(HashMap<Integer, Pair<Integer, List<Integer>>> newSemaphoreTable);
}
