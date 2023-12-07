#ifndef __QUIZ_SESSION_HEADER__
#define __QUIZ_SESSION_HEADER__

#include <string>
#include <vector>
#include "../header/Quiz.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionFRQ.hpp"

class QuizSession {
    private:
        Quiz* quiz;
        std::vector<std::string> answers;
        int score;
        int timeElapsed;

    public:
        // Constructor takes a pointer to Quiz
        QuizSession(Quiz* quiz);

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