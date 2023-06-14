package domain.type;

import domain.value.StringValue;
import domain.value.ValueInterface;

public class StringType implements TypeInterface{

    @Override
    public boolean equals(TypeInterface anothertype) {
        return anothertype instanceof StringType;
    }

    @Override
    public TypeInterface clone() {
        return null;
    }

    @Override
    public ValueInterface defaultValue() {
        return new StringValue("");
    }

    @Override
    public String toString(){
        return "string";
    }
}
