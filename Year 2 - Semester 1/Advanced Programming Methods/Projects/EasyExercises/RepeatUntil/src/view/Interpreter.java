package view;

import controller.Controller;
import domain.expression.*;
import domain.programState.ProgramState;
import domain.statement.*;
import domain.type.BooleanType;
import domain.type.IntType;
import domain.type.RefType;
import domain.type.StringType;
import domain.utils.ADTDictionary.ADTDictionary;
import domain.utils.ADTHeap.ADTHeap;
import domain.utils.ADTList.ADTList;
import domain.utils.ADTStack.ADTStack;
import domain.value.BooleanValue;
import domain.value.IntValue;
import domain.value.StringValue;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import repository.Repository;
import repository.RepositoryInterface;

import java.io.IOException;

public class Interpreter {
    public static void main(String[] args){
        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0","exit"));
        //int v; v=2;Print(v)
        StatementInterface ex1 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));

        try {
            ex1.checkType(new ADTDictionary<>());
            ProgramState prg1 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex1);
            RepositoryInterface repo1 = null;
            repo1 = new Repository(prg1, "log1.txt");
            Controller controller1 = new Controller(repo1);
            menu.addCommand(new RunExampleCommand("1", ex1.toString(), controller1));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }


        //int a;int b; a=2+3*5;b=a+1;Print(b)
        StatementInterface ex2 = new CompStatement(new VarDeclarationStatement("a", new IntType()),
                new CompStatement(new VarDeclarationStatement("b", new IntType()),
                        new CompStatement(new AssigStatement("a", new ArithmExpression('+', new ValueExpression(new IntValue(2)), new
                                ArithmExpression('*', new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssigStatement("b", new ArithmExpression('+', new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));

        try {
            ex2.checkType(new ADTDictionary<>());
            ProgramState prg2 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex2);
            RepositoryInterface repo2 = null;
            repo2 = new Repository(prg2, "log2.txt");
            Controller controller2 = new Controller(repo2);
            menu.addCommand(new RunExampleCommand("2", ex2.toString(), controller2));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }


        //bool a; int v; a=true;(If a Then v=2 Else v=3);Print(v)
        StatementInterface ex3 = new CompStatement(new VarDeclarationStatement("a", new BooleanType()),
                new CompStatement(new VarDeclarationStatement("v", new IntType()),
                        new CompStatement(new AssigStatement("a", new ValueExpression(new BooleanValue(true))),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssigStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssigStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));

        try {
            ex3.checkType(new ADTDictionary<>());
            ProgramState prg3 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex3);
            Repository repo3 = null;
            repo3 = new Repository(prg3, "log3.txt");
            Controller controller3 = new Controller(repo3);
            menu.addCommand(new RunExampleCommand("3", ex3.toString(), controller3));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }


        StatementInterface ex4 = new CompStatement(new VarDeclarationStatement("varf", new StringType()),
                new CompStatement(new AssigStatement("varf", new ValueExpression(new StringValue("test.txt"))),
                        new CompStatement(new OpenReadFile(new VariableExpression("varf")),
                                new CompStatement(new VarDeclarationStatement("varc", new IntType()),
                                        new CompStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VariableExpression("varc")),
                                                        new CompStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                                new CompStatement(new PrintStatement(new VariableExpression("varc")),
                                                                        new CloseReadFile(new VariableExpression("varf"))))))))));


        try {
            ex4.checkType(new ADTDictionary<>());
            ProgramState prg4 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex4);
            RepositoryInterface repo4 = null;
            repo4 = new Repository(prg4, "log4.txt");
            Controller controller4 = new Controller(repo4);
            menu.addCommand(new RunExampleCommand("4", ex4.toString(), controller4));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        StatementInterface ex5 = new CompStatement(new VarDeclarationStatement("a", new IntType()),
                new CompStatement(new VarDeclarationStatement("b", new IntType()),
                        new CompStatement(new AssigStatement("a", new ValueExpression(new IntValue(5))),
                                new CompStatement(new AssigStatement("b", new ValueExpression(new IntValue(7))),
                                        new IfStatement(new RelationalExpression(">", new VariableExpression("a"),
                                                new VariableExpression("b")), new PrintStatement(new VariableExpression("a")),
                                                new PrintStatement(new VariableExpression("b")))))));


        try {
            ex5.checkType(new ADTDictionary<>());
            ProgramState prg5 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex5);
            RepositoryInterface repo5 = null;
            repo5 = new Repository(prg5, "log5.txt");
            Controller controller5 = new Controller(repo5);
            menu.addCommand(new RunExampleCommand("5", ex5.toString(), controller5));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        StatementInterface ex6 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new WhileStatement(new RelationalExpression(">", new VariableExpression("v"), new ValueExpression(new IntValue(0))),
                                new CompStatement(new PrintStatement(new VariableExpression("v")), new AssigStatement("v", new ArithmExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v")))));


        try {
            ex6.checkType(new ADTDictionary<>());
            ProgramState prg6 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex6);
            RepositoryInterface repo6 = null;
            repo6 = new Repository(prg6, "log6.txt");
            Controller controller6 = new Controller(repo6);
            menu.addCommand(new RunExampleCommand("6", ex6.toString(), controller6));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        StatementInterface ex7 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));

        try {
            ex7.checkType(new ADTDictionary<>());
            ProgramState prg7 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex7);
            RepositoryInterface repo7 = null;
            repo7 = new Repository(prg7, "log7.txt");
            Controller controller7 = new Controller(repo7);
            menu.addCommand(new RunExampleCommand("7", ex7.toString(), controller7));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }


        StatementInterface ex8 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmExpression('+', new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));

        try {
            ex8.checkType(new ADTDictionary<>());
            ProgramState prg8 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex8);
            RepositoryInterface repo8 = null;
            repo8 = new Repository(prg8, "log8.txt");
            Controller controller8 = new Controller(repo8);
            menu.addCommand(new RunExampleCommand("8", ex8.toString(), controller8));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        StatementInterface ex9 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                new CompStatement(new WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmExpression('+', new ReadHeapExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        try {
            ex9.checkType(new ADTDictionary<>());
            ProgramState prg9 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex9);
            RepositoryInterface repo9 = null;
            repo9 = new Repository(prg9, "log9.txt");
            Controller controller9 = new Controller(repo9);
            menu.addCommand(new RunExampleCommand("9", ex9.toString(), controller9));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        /*
        int v; Ref int a; v=10;new(a,22);
        fork(wH(a,30);v=32;print(v);print(rH(a)));
        print(v);print(rH(a))
         */
        StatementInterface ex10 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new VarDeclarationStatement("a", new RefType(new IntType())),
                        new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(10))),
                                new CompStatement(new NewStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompStatement(new ForkStatement(new CompStatement(new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a"))))))),
                                                new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))))))));

        try {
            ex10.checkType(new ADTDictionary<>());
            ProgramState prg10 = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(), new ADTDictionary<>(), new ADTHeap(), ex10);
            RepositoryInterface repo10 = null;
            repo10 = new Repository(prg10, "log10.txt");
            Controller controller10 = new Controller(repo10);
            menu.addCommand(new RunExampleCommand("10", ex10.toString(), controller10));
        } catch (IOException | ToyLanguageException e) {
            System.out.println("\u001B[31m" + e.getMessage() + "\u001B[0m");
        }

        menu.show();
    }
}
