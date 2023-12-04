#include "../header/QuizSession.hpp"

void QuizSession::SubmitAnswers(std::vector<std::string> inputAnswers) {
    answers.insert(answers.end(), inputAnswers.begin(), inputAnswers.end());
}

int QuizSession::GetScore() {
    return 1;
}

int QuizSession::GetTimeElapsed() {
    return 1;
}