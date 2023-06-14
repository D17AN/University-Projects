package domain.value;

import domain.type.StringType;
import domain.type.TypeInterface;

public class StringValue implements ValueInterface{
    private final String val;

    public StringValue(String val){
        this.val = val;
    }

    @Override
    public TypeInterface getType() {
        return new StringType();
    }

    @Override
    public ValueInterface clone() {
        return new StringValue(this.val);
    }

    @Override
    public boolean equals(Object anotherObject){
        if(!(anotherObject instanceof StringValue))
            return false;
        StringValue castValue = (StringValue)anotherObject;
        return this.val.equals(castValue);
    }

    public String getValue(){
        return this.val;
    }

    @Override
    public String toString(){
        return "\"" + this.val + "\"";
    }

}
