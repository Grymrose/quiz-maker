#include "../header/Student.hpp"

//give instructorName
void Student::JoinClass(std::string instructor) {
    instructorName = instructor;
}

//get QuizzesToDo
std::vector<Quiz> Student::ViewAvailableQuizzes() {
    return quizzesToDo;
}

//get takenQuizzes
std::vector<QuizSession> Student::ViewCompletedQuizzes() {
    return takenQuizzes;
}