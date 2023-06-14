package domain.expression;

import domain.type.TypeInterface;
import domain.utils.ADTHeap.ADTHeap;
import domain.utils.ADTHeap.ADTHeapInterface;
import exceptions.ExpressionEvaluationException;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.value.ValueInterface;
import exceptions.NonExistentElementException;
import exceptions.ToyLanguageException;

import java.lang.reflect.Type;

public interface ExpressionInterface {
    ValueInterface eval(ADTDictionaryInterface<String, ValueInterface> symTable, ADTHeapInterface heap) throws ToyLanguageException;
    ExpressionInterface clone();
    TypeInterface checkType(ADTDictionaryInterface<String, TypeInterface> typeD)throws ToyLanguageException;
}
