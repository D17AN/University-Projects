package domain.utils.ADTBarrierTable;

import exceptions.ToyLanguageException;
import javafx.util.Pair;

import java.util.HashMap;
import java.util.List;

public class ADTBarrierTable implements ADTBarrierTableInterface{
    private HashMap<Integer, Pair<Integer, List<Integer>>> barrierTable;
    private int availableLocation = 0;

    public ADTBarrierTable() {
        this.barrierTable = new HashMap<>();
    }

    @Override
    public void putHostageInBasement(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException {
        //set value to a key
        synchronized (this) {
            if(barrierTable.containsKey(key))
                throw new ToyLanguageException(String.format("Key %d already existent in BarrierTable!", key));
            else{
                barrierTable.put(key, value);
            }
        }
    }

    @Override
    public Pair<Integer, List<Integer>> getHostageFromBasement(int key) throws ToyLanguageException {
        //get value associated to a key
        synchronized (this) {
            if (barrierTable.containsKey(key)) {
                return barrierTable.get(key);
            } else {
                throw new ToyLanguageException(String.format("Key %d not present in BarrierTable!", key));
            }
        }
    }

    @Override
    public boolean isKeyInBasement(int key) {
        //check if the key is existent in the table
        synchronized (this) {
            return barrierTable.containsKey(key);
        }
    }

    @Override
    public int getAvailableAddressFromBasement() {
        //get an available location
        synchronized (this) {
            availableLocation++;
            return availableLocation;
        }
    }

    @Override
    public void setAvailableAddressInBasement(int freeAddress) {
        synchronized (this) {
            this.availableLocation = freeAddress;
        }
    }

    @Override
    public void updateHostageFromBasement(int key, Pair<Integer, List<Integer>> value) throws ToyLanguageException {
        synchronized (this) {
            if (barrierTable.containsKey(key)) {
                barrierTable.replace(key, value);
            } else {
                throw new ToyLanguageException(String.format("Barrier table doesn't contain key %d!", key));
            }
        }
    }

    @Override
    public HashMap<Integer, Pair<Integer, List<Integer>>> getBarrierTableHostagesFromBasement() {
        synchronized (this) {
            return barrierTable;
        }
    }

    @Override
    public void setBarrierTableHostagesFromBasement(HashMap<Integer, Pair<Integer, List<Integer>>> newBarrierTable) {
        synchronized (this) {
            this.barrierTable = newBarrierTable;
        }
    }

    @Override
    public String toString() {
        return this.barrierTable.toString();
    }
}
