#include <iostream>
#include "../header/User.hpp"

class MainMenu {
    private:
        std::vector<User> users;
        bool isSignedIn;
        unsigned userID;
    public:
        void CreateQuiz();
        void EditQuiz();
        void TakeQuiz();
        void AddUser();
        void UserLogin();
        void UserLogout();
}