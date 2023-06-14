package view;

import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import controller.Controller;

import java.io.IOException;
import java.util.Objects;
import java.util.Scanner;

public class RunExampleCommand extends Command{
    private final Controller controller;

    public RunExampleCommand(String key, String info, Controller controller){
        super(key, info);
        this.controller = controller;
    }

    @Override
    public void execute() {
        try{
            System.out.println("Display the steps?\n[Y/n]");
            Scanner readOption = new Scanner(System.in);
            String option = readOption.next();
            controller.setDisplayFlag(Objects.equals(option, "Y"));
            controller.allSteps();
        }catch (IOException | ToyLanguageException |
               InterruptedException exception){
            System.out.println("\u001B[31m" + exception.getMessage() + "\u001B[0m");
        }

    }
}
