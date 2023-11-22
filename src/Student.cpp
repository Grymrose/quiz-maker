#include <iostream>
#include <string>
#include <vector>
#include "../header/Student.hpp"

//give instructorName
void Student::JoinClass(std::string instructor)
{
    InstructorName = instructor;
}

//get QuizzesToDo
vector <Quiz> Student::ViewAvailableQuizzes()
{
    return QuizzesToDo;
}

//get takenQuizzes
vector <QuizSession> Student::ViewCompletedQuizzes()
{
    return TakenQuizzes;
}