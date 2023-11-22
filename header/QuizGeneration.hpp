#include "../header/QuizCustomization.hpp"
#include "../header/Question.hpp"
#include <iostream>
#include <string>
#include <vector>

class QuizGeneration : public QuizCustomization, public Question{
private:
    std::vector <unsigned> MCQIDList;
    std::vector <unsigned> TFIDList;
    std::vector <unsigned> FRQIDList;

    std::vector <unsigned> GeneratedQuiz;
public:
    virtual ~QuizGeneration() noexcept = default;
    void GenerateQuiz();
    void GetMCQList();
    void GetTFList();
    void GetFRQList();
};