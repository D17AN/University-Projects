package domain.utils.ADTLatchTable;

import exceptions.ToyLanguageException;

import java.util.HashMap;

public class ADTLatchTable implements ADTLatchTableInterface{
    private HashMap<Integer, Integer> latchTable;
    private int availableLocation = 0;

    public ADTLatchTable(){
        this.latchTable = new HashMap<>();
    }

    @Override
    public void put(int key, int val) throws ToyLanguageException {
        synchronized (this){
            if(!this.latchTable.containsKey(key)){
                this.latchTable.put(key, val);
            }
            else{
                throw new ToyLanguageException(String.format("Already a value associated to the key %d!", key));
            }
        }
    }

    @Override
    public int get(int key) throws ToyLanguageException {
        synchronized (this){
            if(this.latchTable.containsKey(key)){
                return this.latchTable.get(key);
            }
            else{
                throw new ToyLanguageException(String.format("Key %d not found in the latch table!", key));
            }
        }
    }

    @Override
    public boolean containsKey(int key) {
        synchronized (this){
            return this.latchTable.containsKey(key);
        }
    }

    @Override
    public int getAvailableAddress() {
        synchronized (this){
            this.availableLocation++;
            return this.availableLocation;
        }
    }

    @Override
    public void update(int key, int value) throws ToyLanguageException {
        synchronized (this){
            if(this.latchTable.containsKey(key)){
                this.latchTable.replace(key, value);
            }
            else{
                throw new ToyLanguageException(String.format("Key %d not found in the latch table!", key));
            }
        }
    }

    @Override
    public void setAvailableAddress(int availableAddress) {
        synchronized (this){
            this.availableLocation = availableAddress;
        }
    }

    @Override
    public HashMap<Integer, Integer> getLatchTable() {
        synchronized (this){
            return this.latchTable;
        }
    }

    @Override
    public void setLatchTable(HashMap<Integer, Integer> newLatchTable) {
        synchronized (this){
            this.latchTable = newLatchTable;
        }
    }

    @Override
    public String toString(){
        return this.latchTable.toString();
    }
}
