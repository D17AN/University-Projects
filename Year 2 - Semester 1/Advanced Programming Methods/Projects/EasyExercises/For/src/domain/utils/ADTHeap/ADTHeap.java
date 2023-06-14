package domain.utils.ADTHeap;

import domain.value.ValueInterface;
import exceptions.ToyLanguageException;

import java.util.HashMap;
import java.util.Set;

public class ADTHeap implements ADTHeapInterface{
    HashMap<Integer, ValueInterface> heap;
    Integer freeLocationValue;

    public ADTHeap(){
        this.heap = new HashMap<>();
        this.freeLocationValue = 1;
    }

    public int newValue(){
        this.freeLocationValue += 1;
        while(this.freeLocationValue == 0 || heap.containsKey(this.freeLocationValue))
            this.freeLocationValue += 1;
        return this.freeLocationValue;
    }

    @Override
    public int getFreeValue(){
        return this.freeLocationValue;
    }

    @Override
    public HashMap<Integer, ValueInterface> getHeap(){
        return this.heap;
    }

    @Override
    public void setHeap(HashMap<Integer, ValueInterface> anotherHeap){
        this.heap = anotherHeap;
    }

    @Override
    public int add(ValueInterface val){
        this.heap.put(this.freeLocationValue, val);
        Integer returnedLocation = this.freeLocationValue;
        this.freeLocationValue = this.newValue();
        return returnedLocation;
    }

    @Override
    public void update(Integer pos, ValueInterface val) throws ToyLanguageException {
        if(!this.heap.containsKey(pos))
            throw new ToyLanguageException(String.format("%d is not existent in the heap.", pos));
        this.heap.put(pos, val);
    }

    @Override
    public ValueInterface get(Integer pos) throws ToyLanguageException {
        if(!this.heap.containsKey(pos))
            throw new ToyLanguageException(String.format("%d is not existent in the heap.", pos));
       return this.heap.get(pos);
    }

    @Override
    public boolean isExistent(Integer pos){
        return this.heap.containsKey(pos);
    }

    @Override
    public void remove(Integer key)throws ToyLanguageException{
        if(!this.heap.containsKey(key))
            throw new ToyLanguageException(key + " is not an existent key in the heap.");
        this.freeLocationValue = key;
        this.heap.remove(key);
    }

    @Override
    public Set<Integer> keySet(){
        return this.heap.keySet();
    }

    @Override
    public String toString(){
        return this.heap.toString();
    }

    @Override
    public HashMap<Integer, ValueInterface> getContent(){
        return this.heap;
    }

}
