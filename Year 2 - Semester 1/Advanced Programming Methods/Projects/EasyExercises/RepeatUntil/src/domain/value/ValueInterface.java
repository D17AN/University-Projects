package domain.value;

import domain.type.TypeInterface;

public interface ValueInterface{
    TypeInterface getType();
    ValueInterface clone();
}
