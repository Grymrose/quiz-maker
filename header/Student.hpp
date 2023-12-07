#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include <string>
#include <vector>
#include "../header/User.hpp"
#include "../header/Quiz.hpp"
#include "../header/QuizSession.hpp"


class Student : public User {
    private:
        std::string instructorName;
        std::vector<Quiz> quizzesToDo;
        std::vector<QuizSession> takenQuizzes;
    public:
        Student(std::string username, std::string password, bool isInstructor)
        : User(username, password, isInstructor) {}
        void JoinClass(std::string instructor);
        bool HasInstructor() const;
        void AddQuizzes(const std::vector<Quiz>& quiz);
        void AddTakenQuiz(const QuizSession& completedQuizSession);
        std::vector<Quiz> ViewAvailableQuizzes();
        std::vector<QuizSession> ViewCompletedQuizzes();
};

#endif