package domain.type;

import domain.value.IntValue;
import domain.value.ValueInterface;

public class IntType implements TypeInterface{
    public IntType(){
    }

    @Override
    public boolean equals(TypeInterface anotherType){
        return anotherType instanceof IntType;
    }

    @Override
    public String toString(){
        return "int";
    }

    @Override
    public TypeInterface clone(){
        return new IntType();
    }

    @Override
    public ValueInterface defaultValue(){
        return new IntValue(0);
    }



}
