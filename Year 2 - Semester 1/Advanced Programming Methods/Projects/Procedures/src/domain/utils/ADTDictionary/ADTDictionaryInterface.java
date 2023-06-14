package domain.utils.ADTDictionary;

import exceptions.NonExistentElementException;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

public interface ADTDictionaryInterface<K, V>{
    void put(K key, V value);
    V get(K key);
    void remove(K key);
    int size();
    Collection<V> getValues();
    Set<K> getKeys();
    boolean isExistent(K key);
    Map<K,V> getContent();
    ADTDictionaryInterface<K,V> clone();
}
