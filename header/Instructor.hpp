#ifndef __INSTRUCTOR_HEADER__
#define __INSTRUCTOR_HEADER__
#include <string>
#include <vector>
#include "../header/User.hpp"
#include "../header/Quiz.hpp"

class Instructor : public User {
    private:
        std::vector<Quiz> quizzes;
    public:
        Instructor(std::string username, std::string password, bool isInstructor)
        : User(username, password, isInstructor) {}
        void AddQuiz(const Quiz& quiz);
        std::vector<Quiz> GetQuizzes();
};

#endif