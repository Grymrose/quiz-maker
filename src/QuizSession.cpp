#include "../header/QuizSession.hpp"

// Constructor implementation
QuizSession::QuizSession(std::shared_ptr<Quiz> quiz) : quiz(quiz), score(0), timeElapsed(0) {}

// Submit student answers to the quiz
void QuizSession::SubmitAnswers(const std::vector<std::string>& inputAnswers) {
    for (size_t i = 0; i < inputAnswers.size(); ++i) {
        const std::vector<std::shared_ptr<Question>>& questions = quiz->GetQuestions();

        if (i < questions.size()) {
            score += questions[i]->ScoreQuestion(inputAnswers[i]);
        }
    }
}

// Get the score achieved in the quiz
int QuizSession::GetScore() const {
    return score;
}

// Get the time elapsed during the quiz
int QuizSession::GetTimeElapsed() const {
    return timeElapsed;
}

// Set the time elapsed during the quiz
void QuizSession::SetTimeElapsed(int time) {
    timeElapsed = time;
}