package gui;

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
import domain.utils.ADTToySemaphoreTable.ADTToySemaphoreTable;
import domain.value.BooleanValue;
import domain.value.IntValue;
import domain.value.StringValue;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import exceptions.ToyLanguageException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import repository.Repository;
import repository.RepositoryInterface;

import java.awt.event.ActionEvent;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ProgramOptionsController {
    private RunProgramController runProgramController;

    public void setRunProgramController(RunProgramController runProgramController){
        this.runProgramController = runProgramController;
    }

    @FXML
    private ListView<StatementInterface> programsListView;
    @FXML
    private Button displayButton;

    @FXML
    public void initialize(){
        this.programsListView.setItems(this.getAllStatements());
        this.programsListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    @FXML
    public void displayPrg(javafx.event.ActionEvent actionEvent){
        StatementInterface selectedStm = programsListView.getSelectionModel().getSelectedItem();
        if(selectedStm == null){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setContentText("A statement must be selected!");
            alert.showAndWait();
        }
        else{
            int id = this.programsListView.getSelectionModel().getSelectedIndex();
            try{
                selectedStm.checkType(new ADTDictionary<>());
                ProgramState programState = new ProgramState(new ADTStack<>(), new ADTDictionary<>(), new ADTList<>(),
                        new ADTDictionary<>(), new ADTHeap(), new ADTToySemaphoreTable(), selectedStm);
                RepositoryInterface repo = new Repository(programState, "log" + (id + 1) +".txt");
                Controller controller = new Controller(repo);
                this.runProgramController.setController(controller);
            }
            catch(ToyLanguageException| IOException e){
             Alert alert = new Alert(Alert.AlertType.ERROR);
             alert.setTitle("Error!");
             alert.setContentText(e.getMessage());
             alert.showAndWait();
            }
        }
    }

    @FXML
    private ObservableList<StatementInterface> getAllStatements(){
        List<StatementInterface> allStmts = new ArrayList<>();

        StatementInterface ex1 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(2))),
                        new PrintStatement(new VariableExpression("v"))));
        allStmts.add(ex1);

        StatementInterface ex2 = new CompStatement(new VarDeclarationStatement("a", new IntType()),
                new CompStatement(new VarDeclarationStatement("b", new IntType()),
                        new CompStatement(new AssigStatement("a", new ArithmExpression('+', new ValueExpression(new IntValue(2)), new
                                ArithmExpression('*', new ValueExpression(new IntValue(3)), new ValueExpression(new IntValue(5))))),
                                new CompStatement(new AssigStatement("b", new ArithmExpression('+', new VariableExpression("a"), new ValueExpression(new
                                        IntValue(1)))), new PrintStatement(new VariableExpression("b"))))));
        allStmts.add(ex2);

        StatementInterface ex3 = new CompStatement(new VarDeclarationStatement("a", new BooleanType()),
                new CompStatement(new VarDeclarationStatement("v", new IntType()),
                        new CompStatement(new AssigStatement("a", new ValueExpression(new BooleanValue(true))),
                                new CompStatement(new IfStatement(new VariableExpression("a"),
                                        new AssigStatement("v", new ValueExpression(new IntValue(2))),
                                        new AssigStatement("v", new ValueExpression(new IntValue(3)))),
                                        new PrintStatement(new VariableExpression("v"))))));

        allStmts.add(ex3);

        StatementInterface ex4 = new CompStatement(new VarDeclarationStatement("varf", new StringType()),
                new CompStatement(new AssigStatement("varf", new ValueExpression(new StringValue("test.txt"))),
                        new CompStatement(new OpenReadFile(new VariableExpression("varf")),
                                new CompStatement(new VarDeclarationStatement("varc", new IntType()),
                                        new CompStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                new CompStatement(new PrintStatement(new VariableExpression("varc")),
                                                        new CompStatement(new ReadFile(new VariableExpression("varf"), "varc"),
                                                                new CompStatement(new PrintStatement(new VariableExpression("varc")),
                                                                        new CloseReadFile(new VariableExpression("varf"))))))))));
        allStmts.add(ex4);

        StatementInterface ex5 = new CompStatement(new VarDeclarationStatement("a", new IntType()),
                new CompStatement(new VarDeclarationStatement("b", new IntType()),
                        new CompStatement(new AssigStatement("a", new ValueExpression(new IntValue(5))),
                                new CompStatement(new AssigStatement("b", new ValueExpression(new IntValue(7))),
                                        new IfStatement(new RelationalExpression(">", new VariableExpression("a"),
                                                new VariableExpression("b")), new PrintStatement(new VariableExpression("a")),
                                                new PrintStatement(new VariableExpression("b")))))));
        allStmts.add(ex5);

        StatementInterface ex6 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(4))),
                        new CompStatement(new WhileStatement(new RelationalExpression(">", new VariableExpression("v"), new ValueExpression(new IntValue(0))),
                                new CompStatement(new PrintStatement(new VariableExpression("v")), new AssigStatement("v", new ArithmExpression('-', new VariableExpression("v"), new ValueExpression(new IntValue(1)))))),
                                new PrintStatement(new VariableExpression("v")))));
        allStmts.add(ex6);

        StatementInterface ex7 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new VariableExpression("a")))))));
        allStmts.add(ex7);

        StatementInterface ex8 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new VarDeclarationStatement("a", new RefType(new RefType(new IntType()))),
                                new CompStatement(new NewStatement("a", new VariableExpression("v")),
                                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                                new PrintStatement(new ArithmExpression('+', new ReadHeapExpression(new ReadHeapExpression(new VariableExpression("a"))), new ValueExpression(new IntValue(5)))))))));
        allStmts.add(ex8);

        StatementInterface ex9 = new CompStatement(new VarDeclarationStatement("v", new RefType(new IntType())),
                new CompStatement(new NewStatement("v", new ValueExpression(new IntValue(20))),
                        new CompStatement(new PrintStatement(new ReadHeapExpression(new VariableExpression("v"))),
                                new CompStatement(new WriteHeapStatement("v", new ValueExpression(new IntValue(30))),
                                        new PrintStatement(new ArithmExpression('+', new ReadHeapExpression(new VariableExpression("v")), new ValueExpression(new IntValue(5))))))));
        allStmts.add(ex9);

        StatementInterface ex10 = new CompStatement(new VarDeclarationStatement("v", new IntType()),
                new CompStatement(new VarDeclarationStatement("a", new RefType(new IntType())),
                        new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(10))),
                                new CompStatement(new NewStatement("a", new ValueExpression(new IntValue(22))),
                                        new CompStatement(new ForkStatement(new CompStatement(new WriteHeapStatement("a", new ValueExpression(new IntValue(30))),
                                                new CompStatement(new AssigStatement("v", new ValueExpression(new IntValue(32))),
                                                        new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a"))))))),
                                                new CompStatement(new PrintStatement(new VariableExpression("v")), new PrintStatement(new ReadHeapExpression(new VariableExpression("a")))))))));
        allStmts.add(ex10);

        StatementInterface ex11 = new CompStatement(
                new VarDeclarationStatement("v1", new RefType(new IntType())),
                new CompStatement(
                        new VarDeclarationStatement("cnt", new IntType()),
                        new CompStatement(
                                new NewStatement("v1", new ValueExpression(new IntValue(2))),
                                new CompStatement(
                                        new NewSemaphoreStatement("cnt", new ReadHeapExpression(new VariableExpression("v1")), new ValueExpression(new IntValue(1))),
                                        new CompStatement(
                                                new ForkStatement(
                                                        new CompStatement(
                                                                new AcquireStatement("cnt"),
                                                                new CompStatement(
                                                                        new WriteHeapStatement("v1", new ArithmExpression('*', new ReadHeapExpression(new VariableExpression("v1")), new ValueExpression(new IntValue(10)))),
                                                                        new CompStatement(
                                                                                new PrintStatement(new ReadHeapExpression(new VariableExpression("v1"))),
                                                                                new ReleaseStatement("cnt")
                                                                        )
                                                                )
                                                        )
                                                ),
                                                new CompStatement(
                                                        new ForkStatement(
                                                                new CompStatement(
                                                                        new AcquireStatement("cnt"),
                                                                        new CompStatement(
                                                                                new WriteHeapStatement("v1", new ArithmExpression('*',  new ReadHeapExpression(new VariableExpression("v1")), new ValueExpression(new IntValue(10)))),
                                                                                new CompStatement(
                                                                                        new WriteHeapStatement("v1", new ArithmExpression('*',  new ReadHeapExpression(new VariableExpression("v1")), new ValueExpression(new IntValue(2)))),
                                                                                        new CompStatement(
                                                                                                new PrintStatement(new ReadHeapExpression(new VariableExpression("v1"))),
                                                                                                new ReleaseStatement("cnt")
                                                                                        )
                                                                                )
                                                                        )
                                                                )
                                                        ),
                                                        new CompStatement(
                                                                new AcquireStatement("cnt"),
                                                                new CompStatement(
                                                                        new PrintStatement(new ArithmExpression('-', new ValueExpression(new IntValue(1)), new ReadHeapExpression(new VariableExpression("v1")))),
                                                                        new ReleaseStatement("cnt")
                                                                )
                                                        )
                                                )
                                        )
                                )
                        )
                )
        );
        allStmts.add(ex11);

        return FXCollections.observableArrayList(allStmts);
    }
}
