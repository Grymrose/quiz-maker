#include "../header/Student.hpp"

//give instructorName
void Student::JoinClass(std::string instructor) {
    instructorName = instructor;
}

//get QuizzesToDo
vector<Quiz> Student::ViewAvailableQuizzes() {
    return quizzesToDo;
}

//get takenQuizzes
vector<QuizSession> Student::ViewCompletedQuizzes() {
    return takenQuizzes;
}