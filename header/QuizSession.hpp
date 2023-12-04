#include <iostream>
#include <string>
#include <vector>

class QuizSession{
    private:
        Quiz& quiz;
        std::vector<std::string> answers;
        int score;
        int timeElapsed;
    public:
        void SubmitAnswers(std::vector<std::string> inputAnswers);
        int GetScore();
        int GetTimeElapsed();
};