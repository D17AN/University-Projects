package view;

public class ExitCommand extends Command{
    public ExitCommand(String key, String info){
        super(key, info);
    }

    @Override
    public void execute(){
        System.exit(0);
    }
}
