#include "../header/Instructor.hpp"

void Instructor::AddQuiz(const Quiz& quiz) {
    quizzes.push_back(quiz);
}

std::vector<Quiz> Instructor::GetQuizzes() {
    return quizzes;
}