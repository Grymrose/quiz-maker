#include <iostream>
#include "User.h"

class MainMenu
{
    private:
    std::vector<User> Users;
    bool IsSignedIn;

    public:
    void CreateQuiz();
    void EditQuiz();
    void TakeQuiz();
    void AddUser();
}