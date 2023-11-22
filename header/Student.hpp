#include <iostream>
#include <string>
#include <vector>
#include "../header/Quiz.hpp"
#include "../header/QuizSession.hpp"


class Student{
    private:
    std::string InstructorName;
    vector <Quizzes> QuizzesToDo; //quizzes or quiz
    vector <QuizSession> TakenQuizzes;

    public:
    void JoinClass(std::string instructor);
    Student();
    ~Student();
    vector <Quiz> ViewAvailableQuizzes();
    vector <QuizSession> ViewCompletedQuizzes();

}