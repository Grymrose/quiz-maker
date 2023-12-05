#include "../header/QuizSession.hpp"

// Constructor implementation
QuizSession::QuizSession(std::shared_ptr<Quiz> quiz) : quiz(quiz), score(0), timeElapsed(0) {}

// Submit student answers to the quiz
void QuizSession::SubmitAnswers(const std::vector<std::string>& inputAnswers) {
    const std::vector<std::shared_ptr<Question>>& questions = quiz->GetQuestions();

    for (size_t i = 0; i < questions.size(); ++i) {
        // Use dynamic casting to determine the type of the question
        std::shared_ptr<QuestionMCQ> mcqQuestion = std::dynamic_pointer_cast<QuestionMCQ>(questions[i]);
        std::shared_ptr<QuestionTF> tfQuestion = std::dynamic_pointer_cast<QuestionTF>(questions[i]);
        std::shared_ptr<QuestionFRQ> frqQuestion = std::dynamic_pointer_cast<QuestionFRQ>(questions[i]);

        // Check the type and score accordingly
        if (mcqQuestion) {
            score += mcqQuestion->ScoreQuestion(inputAnswers[i]);
        } else if (tfQuestion) {
            score += tfQuestion->ScoreQuestion(inputAnswers[i]);
        } else if (frqQuestion) {
            score += frqQuestion->ScoreQuestion(inputAnswers[i]);
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