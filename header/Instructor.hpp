#ifndef __INSTRUCTOR_HEADER__
#define __INSTRUCTOR_HEADER__
#include <string>
#include <vector>
#include "../header/User.hpp"
#include "../header/Quiz.hpp"

class Instructor : public User {
    private:
        vector<Quiz> quizzes;
    public:
        vector<Quiz> ViewQuizzes();
}

#endif