#include "Tests.h"

void Tests::runTests(){
	Tests::testAddQuestion();
	Tests::testGetAllAnswersToQuestion();
}

void Tests::testAddQuestion(){
    QuestionsRepository questionsRepo;
    AnswersRepository answersRepo;
    Controller controller(questionsRepo, answersRepo);

    // Test adding a question
    controller.addQuestion("Is the sky blue?", "User1");
    std::vector<Question> questions = controller.getAllQuestions();
    assert(questions.size() == 1);
    assert(questions[0].getText() == "Is the sky blue?");
    assert(questions[0].getCreator() == "User1");
}

void Tests::testGetAllAnswersToQuestion(){
    QuestionsRepository questionsRepo;
    AnswersRepository answersRepo;
    Controller controller(questionsRepo, answersRepo);

    // Test adding a question
    controller.addQuestion("Is the sky blue?", "User1");

    // Test adding answers to the question
    controller.addAnswer(1, "User2", "Yes, the sky is blue.");
    controller.addAnswer(1, "User3", "No, the sky is not blue.");
    controller.addAnswer(1, "User4", "Sometimes the sky is blue.");

    std::vector<Answer> answers = controller.getAllAnswersToQuestion(1);
    assert(answers.size() == 3);
    assert(answers[0].getText() == "Yes, the sky is blue.");
    assert(answers[0].getCreator() == "User2");
    assert(answers[0].getNrVotes() == 0);
}
