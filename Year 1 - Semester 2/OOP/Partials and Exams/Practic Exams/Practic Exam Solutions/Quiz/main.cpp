#include "ParticipantWindow.h"
#include "PresenterWindow.h"
#include "ParticipantsRepository.h"
#include <QtWidgets/QApplication>
#include "Tests.h"

int main(int argc, char *argv[])
{
    Tests::runTests();
    QApplication a(argc, argv);
    ParticipantsRepository participantsRepo{"Participants.txt"};
    QuestionsRepository questionsRepo{"Questions.txt"};
    Controller c{questionsRepo};

    PresenterWindow* window = new PresenterWindow(c);
    window->show();
    for (Participant& p : participantsRepo.getAll()){
        ParticipantWindow* window = new ParticipantWindow(c, p);
        window->show();
    }
    return a.exec();
}
