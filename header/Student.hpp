#ifndef __STUDENT_HEADER__
#define __STUDENT_HEADER__

#include <iostream>
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
        void JoinClass(std::string instructor);
        bool HasInstructor() const;
        void AddQuizzes(const std::vector<Quiz>& quiz);
        void AddTakenQuiz(const QuizSession& completedQuizSession);
        std::vector<Quiz> ViewAvailableQuizzes();
        std::vector<QuizSession> ViewCompletedQuizzes();
}

#endif