#include "../header/QuizSession.hpp"

// Constructor implementation
QuizSession::QuizSession(Quiz* quiz) : quiz(quiz), score(0), timeElapsed(0) {}

// Submit student answers to the quiz
void QuizSession::SubmitAnswers(const std::vector<std::string>& inputAnswers) {
    const std::vector<Question*>& questions = quiz->GetQuestions();

    for (size_t i = 0; i < questions.size(); ++i) {
        Question* currentQuestion = questions[i];
        score += currentQuestion->ScoreQuestion(inputAnswers[i]);
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