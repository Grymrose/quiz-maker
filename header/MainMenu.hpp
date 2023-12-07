#ifndef __MAIN_MENU_HEADER__
#define __MAIN_MENU_HEADER__
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include "../header/User.hpp"
#include "../header/Instructor.hpp"
#include "../header/Student.hpp"
#include "../header/Quiz.hpp"
#include "../header/QuizSession.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionFRQ.hpp"

class MainMenu {
    private:
        std::vector<Instructor*> instructors;
        std::vector<Student*> students;
        bool isSignedIn;
        unsigned instructorID;
        unsigned studentID;

    public:
        MainMenu();
        ~MainMenu();
        void DisplayMenu();
        void CreateQuiz();
        void EditQuiz();
        void TakeQuiz();
        void AddUser();
        void UserLogin();
        void UserLogout();
    };

#endif