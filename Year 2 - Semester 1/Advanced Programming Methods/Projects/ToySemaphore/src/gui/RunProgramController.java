package gui;

import controller.Controller;
import domain.utils.ADTToySemaphoreTable.ADTToySemaphoreTableInterface;
import domain.utils.ADTToySemaphoreTable.Tuple;
import exceptions.ToyLanguageException;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import domain.programState.ProgramState;
import domain.statement.StatementInterface;
import domain.utils.ADTDictionary.ADTDictionaryInterface;
import domain.utils.ADTHeap.ADTHeapInterface;
import domain.value.ValueInterface;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.stream.Collectors;

class Pair<T1, T2>{
    T1 first;
    T2 second;
    public Pair(T1 first, T2 second) {
        this.first = first;
        this.second = second;
    }
}
public class RunProgramController {
    private Controller controller;

    @FXML
    private TextField nrOfProgramStatesTextField;
    @FXML
    private TableView<Pair<Integer, ValueInterface>> heaptableView;
    @FXML
    private TableColumn<Pair<Integer, ValueInterface>, Integer> addressColumn;
    @FXML
    private TableColumn<Pair<Integer, ValueInterface>, String> valueColumn;
    @FXML
    private ListView<String> outputListView;
    @FXML
    private ListView<String> fileTableListView;
    @FXML
    private ListView<Integer> programStateIDListView;
    @FXML
    private TableView<Pair<String, ValueInterface>> symbolTableView;
    @FXML
    private TableColumn<Pair<String, ValueInterface>, String> variableNameColumn;
    @FXML
    private TableColumn<Pair<String, ValueInterface>, String> variableValueColumn;
    @FXML
    private ListView<String> execStackListView;
    @FXML
    private TableView<Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>>> toySemaphoreTableView;
    @FXML
    private TableColumn<Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>>, Integer> indexToySemaphoreColumn;
    @FXML
    private TableColumn<Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>>, Integer> valueToySemaphoreColumn;
    @FXML
    private TableColumn<Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>>, List<Integer>> listToySemaphoreColumn;
    @FXML
    private Button runOneStepButton;

    public void setController(Controller controller){
        this.controller = controller;
        this.populate();
    }

    @FXML
    public void initialize(){
        programStateIDListView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        addressColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().first).asObject());
        valueColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().second.toString()));
        variableNameColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().first));
        variableValueColumn.setCellValueFactory(p -> new SimpleStringProperty(p.getValue().second.toString()));
        indexToySemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getKey()).asObject());
        valueToySemaphoreColumn.setCellValueFactory(p -> new SimpleIntegerProperty(p.getValue().getValue().getFirst() - p.getValue().getValue().getThird()).asObject());
        listToySemaphoreColumn.setCellValueFactory(p -> new SimpleObjectProperty<>(p.getValue().getValue().getSecond()));
    }

    private ProgramState getCurrentPrgState(){
        if(controller.getProgramStates().size() == 0)
            return null;
        else{
            int currID = programStateIDListView.getSelectionModel().getSelectedIndex();
            if(currID == -1)
                return controller.getProgramStates().get(0);
            else
                return controller.getProgramStates().get(currID);
        }
    }

    private void populate(){
        this.populateHeapTableView();
        this.populateOutputListView();
        this.populateFileTableView();
        this.populateProgramStateIDListView();
        this.populateSymbolTableView();
        this.populateExecutionStackListView();
        this.populateToySemaphoreTableView();
    }

    @FXML
    private void changeProgramState(javafx.scene.input.MouseEvent event){
        this.populateExecutionStackListView();
        this.populateSymbolTableView();
    }

    @FXML
    private void populateNrOfProgramStatesTextField(){
        List<ProgramState> programStates = controller.getProgramStates();
        this.nrOfProgramStatesTextField.setText(String.valueOf(programStates.size()));
    }

    @FXML
    private void populateToySemaphoreTableView() {
        ProgramState programState = getCurrentPrgState();
        ADTToySemaphoreTableInterface semaphoreTable = Objects.requireNonNull(programState).getToySemaphoreTable();
        List<Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>>> toySemaphoreList = new ArrayList<>();
        for (Map.Entry<Integer, Tuple<Integer, List<Integer>, Integer>> entry: semaphoreTable.getToySemaphoreTable().entrySet()) {
            toySemaphoreList.add(entry);
        }
        toySemaphoreTableView.setItems(FXCollections.observableArrayList(toySemaphoreList));
        toySemaphoreTableView.refresh();
    }

    @FXML
    private void populateHeapTableView(){
        ProgramState programState = getCurrentPrgState();
        ADTHeapInterface heap = Objects.requireNonNull(programState).getHeap();
        ArrayList<Pair<Integer, ValueInterface>> heapEntries = new ArrayList<>();
        for(Map.Entry<Integer, ValueInterface> entry: heap.getContent().entrySet()){
            heapEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        this.heaptableView.setItems(FXCollections.observableArrayList(heapEntries));
    }

    @FXML
    private void populateOutputListView(){
        ProgramState programState = getCurrentPrgState();
        List<String> output = new ArrayList<>();
        List<ValueInterface> outputList = Objects.requireNonNull(programState).getOut().getList();
        for(int i = 0; i < outputList.size(); i++){
            output.add(outputList.get(i).toString());
        }
        this.outputListView.setItems(FXCollections.observableArrayList(output));
    }

    private void populateFileTableView(){
        ProgramState programState = this.getCurrentPrgState();
        List<String> files = new ArrayList<>(Objects.requireNonNull(programState).getFileTable().getContent().keySet());
        this.fileTableListView.setItems(FXCollections.observableList(files));
    }

    private void populateProgramStateIDListView(){
        List<ProgramState> programStates = controller.getProgramStates();
        List<Integer> IDList = programStates.stream().map(ProgramState::getID).collect(Collectors.toList());
        this.programStateIDListView.setItems(FXCollections.observableList(IDList));
        this.populateNrOfProgramStatesTextField();
    }

    private void populateSymbolTableView(){
        ProgramState programState = getCurrentPrgState();
        ADTDictionaryInterface<String, ValueInterface> symbolTable = Objects.requireNonNull(programState).getSymTable();
        ArrayList<Pair<String, ValueInterface>> symbolTableEntries = new ArrayList<>();
        for(Map.Entry<String, ValueInterface> entry: symbolTable.getContent().entrySet()){
            symbolTableEntries.add(new Pair<>(entry.getKey(), entry.getValue()));
        }
        this.symbolTableView.setItems(FXCollections.observableArrayList(symbolTableEntries));
    }

    private void populateExecutionStackListView(){
        ProgramState programState = getCurrentPrgState();
        List<String> executionStackToString = new ArrayList<>();
        if(programState != null)
            for(StatementInterface statement: programState.getExeStack().getReversed()){
                executionStackToString.add(statement.toString());
            }
        this.execStackListView.setItems(FXCollections.observableList(executionStackToString));
    }

    @FXML
    private void runOneStep(javafx.scene.input.MouseEvent mouseEvent){
        if(this.controller != null){
            try{
                List<ProgramState> programStates = Objects.requireNonNull(controller.getProgramStates());
                if(programStates.size() > 0){
                   this.controller.oneStep();
                   populate();
                   programStates = controller.removeTerminatedProgram(controller.getProgramStates());
                   this.controller.setProgramStates(programStates);
                   this.populateProgramStateIDListView();
                }
                else{
                    Alert alert = new Alert(Alert.AlertType.ERROR);
                    alert.setTitle("Error!");
                    alert.setHeaderText("Error occured!");
                    alert.setContentText("Nothing to execute!");
                    alert.showAndWait();
                }
            }
            catch (ToyLanguageException
                   | InterruptedException e) {
                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("Error!");
                alert.setHeaderText("Error occured!");
                alert.setContentText(e.getMessage());
                alert.showAndWait();
            }
        }
        else{
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("Error occured!");
            alert.setContentText("A program must be selected!");
            alert.showAndWait();
        }
    }
}
