package domain.type;

import domain.value.RefValue;
import domain.value.ValueInterface;

import java.lang.reflect.Type;

public class RefType implements TypeInterface{
    private final TypeInterface inner;

    public RefType(TypeInterface inner){
        this.inner = inner;
    }

    @Override
    public boolean equals(TypeInterface anothertype) {
        return anothertype instanceof RefType;
    }

    @Override
    public TypeInterface clone() {
        return new RefType(this.inner.clone());
    }

    @Override
    public String toString(){
        return String.format("Reference(%s)", this.inner);
    }

    public TypeInterface getInner(){
        return this.inner;
    }

    @Override
    public ValueInterface defaultValue(){
        return new RefValue(0, this.inner);
    }
}
