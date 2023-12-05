#ifndef __QUIZ_SESSION_HEADER__
#define __QUIZ_SESSION_HEADER__

#include <string>
#include <vector>
#include <memory>  // Include for shared_ptr
#include "../header/Quiz.hpp"

class QuizSession {
private:
    std::shared_ptr<Quiz> quiz;  // Use shared_ptr for managing Quiz object
    std::vector<std::string> answers;
    int score;
    int timeElapsed;

public:
    // Constructor takes a shared_ptr to Quiz
    QuizSession(std::shared_ptr<Quiz> quiz);

    // Submit student answers to the quiz
    void SubmitAnswers(const std::vector<std::string>& inputAnswers);

    // Get the score achieved in the quiz
    int GetScore() const;

    // Get the time elapsed during the quiz
    int GetTimeElapsed() const;

    // Set the time elapsed during the quiz
    void SetTimeElapsed(int time);
};

#endif