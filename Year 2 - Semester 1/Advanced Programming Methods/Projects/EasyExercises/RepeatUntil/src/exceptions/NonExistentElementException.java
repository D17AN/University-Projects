package exceptions;

public class NonExistentElementException extends Exception{
    public NonExistentElementException(String msg){
        super(msg);
    }
}
