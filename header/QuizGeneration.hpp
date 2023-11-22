#include "../header/QuizCustomization.hpp"
#include "../header/Question.hpp"
#include <iostream>
#include <string>
#include <vector>

class QuizGeneration : public QuizCustomization, public Question{
private:
    std::vector <Question> GeneratedQuiz;
public:
    virtual ~QuizGeneration() noexcept = default;
    void GenerateQuiz();
    void GetMCQList(unsigned MCQID);
    void GetTFList(unsigned TFID);
    void GetFRQList(unsigned FRQID);
};