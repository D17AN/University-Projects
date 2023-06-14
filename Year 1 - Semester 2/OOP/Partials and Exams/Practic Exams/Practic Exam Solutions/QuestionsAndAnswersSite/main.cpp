#include "UserWindow.h"
#include "SearchWindow.h"
#include "UsersRepository.h"
#include "Tests.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    Tests::runTests();
    QApplication a(argc, argv);
    UsersRepository usersRepo{"Users.txt"};
    QuestionsRepository questionsRepo{"Questions.txt"};
    AnswersRepository answersRepo{"Answers.txt"};
    Controller c{questionsRepo, answersRepo};
    
    for (User& u : usersRepo.getAll()){
        UserWindow* window = new UserWindow(c, u);
        window->show();
    }
    
    SearchWindow* window = new SearchWindow(c);
    window->show();
    return a.exec();
}
