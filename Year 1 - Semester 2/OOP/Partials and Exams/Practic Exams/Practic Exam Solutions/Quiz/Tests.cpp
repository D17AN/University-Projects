#include "Tests.h"

void Tests::runTests(){
	Tests::testAddQuestion();
	Tests::testUpdateParticipantScore();
}

void Tests::testAddQuestion(){
    QuestionsRepository questionsRepo; 
    Controller controller(questionsRepo);

    controller.addQuestion(1, "What is the capital of France?", "Paris", 10);
    assert(questionsRepo.getAll().size() == 1);

    try {
        controller.addQuestion(1, "What is the capital of Germany?", "Berlin", 10);
        assert(false);
    }
    catch (const std::exception& e) {
        assert(true);
    }

}

void Tests::testUpdateParticipantScore(){
}
