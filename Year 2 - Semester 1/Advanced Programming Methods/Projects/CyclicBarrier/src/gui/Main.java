package gui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


import java.util.Objects;

public class Main extends Application {
    @Override
    public void start(Stage mainStage) throws Exception{
        FXMLLoader programListLoader = new FXMLLoader();
        programListLoader.setLocation(Main.class.getResource("resources/ProgramOptionsController.fxml"));
        Parent programListRoot = programListLoader.load();
        Scene programListScene = new Scene(programListRoot, 500, 500);
        programListScene.getStylesheets().add(Objects.requireNonNull(
                Main.class.getResource("resources/button_style.css")).toExternalForm());
        ProgramOptionsController programOptionsController = programListLoader.getController();
        mainStage.setTitle("Program selector");
        mainStage.setScene(programListScene);
        mainStage.show();

        FXMLLoader runProgramLoader = new FXMLLoader();
        runProgramLoader.setLocation(Main.class.getResource("resources/RunProgramController.fxml"));
        Parent runProgramRoot = runProgramLoader.load();
        Scene runProgramScene = new Scene(runProgramRoot, 700, 500);
        runProgramScene.getStylesheets().add(Objects.requireNonNull(
                Main.class.getResource("resources/button_style.css")).toExternalForm());
        RunProgramController runProgramController = runProgramLoader.getController();
        programOptionsController.setRunProgramController(runProgramController);
        Stage otherStage = new Stage();
        otherStage.setTitle("Interpreter");
        otherStage.setScene(runProgramScene);
        otherStage.show();
    }

    public static void main(String []args){
        launch();
    }
}
