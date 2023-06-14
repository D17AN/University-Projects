package domain.type;

import domain.value.BooleanValue;
import domain.value.ValueInterface;

public class BooleanType implements TypeInterface {
    public BooleanType(){
    }

    @Override
    public boolean equals(TypeInterface anotherType) {
        return anotherType instanceof BooleanType;
    }

    @Override
    public String toString(){
        return "bool";
    }

    @Override
    public TypeInterface clone(){
        return new BooleanType();
    }

    @Override
    public ValueInterface defaultValue(){
        return new BooleanValue(false);
    }
}
