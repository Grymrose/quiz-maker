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
        vector<Quiz> quizzesToDo;
        vector<QuizSession> takenQuizzes;
    public:
        void JoinClass(std::string instructor);
        vector<Quiz> ViewAvailableQuizzes();
        vector<QuizSession> ViewCompletedQuizzes();
}

#endif