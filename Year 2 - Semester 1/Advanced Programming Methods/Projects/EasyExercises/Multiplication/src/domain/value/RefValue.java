package domain.value;

import domain.type.RefType;
import domain.type.TypeInterface;

public class RefValue implements ValueInterface{
    private final int address;
    private final TypeInterface locationType;

    public RefValue(int address, TypeInterface locationType){
        this.address = address;
        this.locationType = locationType;
    }

    @Override
    public TypeInterface getType() {
        return new RefType(this.locationType);
    }

    public int getAddress(){
        return this.address;
    }

    public TypeInterface getLocationType(){
        return this.locationType;
    }

    @Override
    public ValueInterface clone() {
        return new RefValue(this.address, this.locationType.clone());
    }

    @Override
    public String toString(){
        return String.format("(%d, %s)", this.address, this.locationType);
    }

}
