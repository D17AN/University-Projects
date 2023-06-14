package domain.type;

import domain.value.ValueInterface;

public interface TypeInterface {
    boolean equals(TypeInterface anothertype);
    String toString();
    TypeInterface clone();
    ValueInterface defaultValue();
}
