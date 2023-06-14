package view;

import domain.utils.ADTDictionary.ADTDictionary;
import domain.utils.ADTDictionary.ADTDictionaryInterface;

import java.util.Scanner;

public class TextMenu {
    private ADTDictionaryInterface<String, Command> commands;

    public TextMenu() {
        this.commands = new ADTDictionary<>();
    }

    public void addCommand(Command command) {
        this.commands.put(command.getKey(), command);
    }

    private void printMenu() {
        for (Command cmd : this.commands.getValues()) {
            String line = String.format("%4s: %s", cmd.getKey(), cmd.getInfo());
            System.out.println(line);
        }
    }

    public void show() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            printMenu();
            System.out.println("Input the option: ");
            String key = scanner.nextLine();
            try {
                Command command = commands.get(key);
                command.execute();
            } catch (Exception e) {
                System.out.println("Invalid option.");
            }
        }
    }
}

