package domain.value;

import domain.type.BooleanType;
import domain.type.TypeInterface;

public class BooleanValue implements ValueInterface{
    private final boolean value;

    public BooleanValue(boolean value){
        this.value = value;
    }

    @Override
    public TypeInterface getType(){
        return new BooleanType();
    }

    @Override
    public boolean equals(Object anotherValue){
        if(!(anotherValue instanceof BooleanValue)){
            return false;
        }
        BooleanValue castValue = (BooleanValue) anotherValue;
        return this.value == castValue.value;
    }

    @Override
    public ValueInterface clone(){
        return new BooleanValue(this.value);
    }

    public boolean getValue(){
        return this.value;
    }

    @Override
    public String toString(){
        return this.value == true ? "true" : "false";
    }
}
