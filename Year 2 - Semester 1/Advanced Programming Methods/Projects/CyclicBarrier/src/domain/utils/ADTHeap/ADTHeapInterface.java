package domain.utils.ADTHeap;

import domain.value.ValueInterface;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

import java.util.HashMap;
import java.util.Set;

public interface ADTHeapInterface {
    int getFreeValue();

    HashMap<Integer, ValueInterface> getHeap();

    void setHeap(HashMap<Integer, ValueInterface> anotherHeap);

    int add(ValueInterface val);

    void update(Integer pos, ValueInterface val) throws ToyLanguageException;

    ValueInterface get(Integer pos) throws ToyLanguageException;

    boolean isExistent(Integer pos);

    void remove(Integer key)throws ToyLanguageException;

    Set<Integer> keySet();

    HashMap<Integer, ValueInterface> getContent();

}
