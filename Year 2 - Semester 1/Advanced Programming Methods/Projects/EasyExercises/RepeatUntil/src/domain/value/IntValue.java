package domain.value;

import domain.type.IntType;
import domain.type.TypeInterface;

public class IntValue implements ValueInterface{
    private final int value;
    public IntValue(int value){
        this.value = value;
    }

    @Override
    public TypeInterface getType(){
        return new IntType();
    }

    @Override
    public ValueInterface clone(){
        return new IntValue(this.value);
    }

    @Override
    public boolean equals(Object other){
        if(!(other instanceof IntValue))
            return false;
        IntValue castValue = (IntValue)other;
        return castValue.value == this.value;
    }

    @Override
    public String toString(){
        return String.format("%d", this.value);
    }

    public int getValue(){
        return this.value;
    }








}
