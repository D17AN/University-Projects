package domain.utils.ADTDictionary;

import exceptions.NonExistentElementException;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class ADTDictionary<K,V> implements ADTDictionaryInterface<K,V>{
    HashMap<K,V> dict;

    public ADTDictionary(){
        this.dict = new HashMap<K,V>();
    }

    public void put(K key, V value){
        synchronized (this) {
            this.dict.put(key, value);
        }
    }

    public V get(K key) {
        synchronized (this) {
            V val = this.dict.get(key);
            return val;
        }
    }

    public boolean isExistent(K key){
        synchronized (this) {
            return this.dict.containsKey(key);
        }
    }

    public void remove(K key){
        synchronized (this) {
            this.dict.remove(key);
        }
    }

    public int size(){
        synchronized (this) {
            return this.dict.size();
        }
    }

    public Collection<V> getValues(){
        synchronized (this) {
            return this.dict.values();
        }
    }

    public Set<K> getKeys(){
        synchronized (this) {
            return this.dict.keySet();
        }
    }

    public Map<K,V> getContent(){
        synchronized (this) {
            return this.dict;
        }
    }

    @Override
    public ADTDictionaryInterface<K, V> clone(){
        ADTDictionaryInterface<K, V> newDic = new ADTDictionary<>();
        for (K key : getKeys())
            newDic.put(key, get(key));
        return newDic;
    }

    @Override
    public String toString(){
        return this.dict.toString();
    }
}
