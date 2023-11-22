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

public:
    void GetMCQList(int MCQCount);
    void GetTFList(int TFCount);
    void GetFRQList(int FRQCount);
};