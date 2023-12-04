#include <iostream>
#include <string>
#include <vector>

class QuizSession{
    private:
        Quiz& quiz;
        std::vector<String> answers;
        int score;
        int timeElapsed;
    public:
        void SubmitAnswers(std::vector<String> answers);
        int GetScore();
        int GetTimeElapsed();
};