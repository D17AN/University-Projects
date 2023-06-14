package domain.utils.ADTBarrierTable;

import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public interface ADTBarrierTableInterface {
    void putHostageInBasement(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException;
    Pair<Integer, List<Integer>> getHostageFromBasement(int key) throws ToyLanguageException;
    boolean isKeyInBasement(int key);
    int getAvailableAddressFromBasement();
    void setAvailableAddressInBasement(int freeAddress);
    void updateHostageFromBasement(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException;
    HashMap<Integer, Pair<Integer, List<Integer>>> getBarrierTableHostagesFromBasement();
    void setBarrierTableHostagesFromBasement(HashMap<Integer, Pair<Integer, List<Integer>>> newBarrierTable);
}
