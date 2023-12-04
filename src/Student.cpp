#include "../header/Student.hpp"

//give instructorName
void Student::JoinClass(std::string instructor) {
    instructorName = instructor;
}

//check for instructor
bool Student::HasInstructor() const {
    return !instructorName.empty();
}

//add quizzes that instrutor permits
void Student::AddQuizzes(const std::vector<Quiz>& quiz) {
    if (HasInstructor()) {
        quizzesToDo.insert(quizzesToDo.end(), inputQuizzes.begin(), inputQuizzes.end());
    }
}

//add quiz that has been taken
void Student::AddTakenQuiz(const QuizSession& completedQuizSession) {
    takenQuizzes.push_back(completedQuizSession);
}

//get QuizzesToDo
std::vector<Quiz> Student::ViewAvailableQuizzes() {
    return quizzesToDo;
}

//get takenQuizzes
std::vector<QuizSession> Student::ViewCompletedQuizzes() {
    return takenQuizzes;
}