#include "../header/QuizGeneration.hpp"
#include "../header/Question.hpp"
#include <string>
#include <vector>

void QuizGeneration::GetMCQList(int MCQCount){
    MCQCount = MCQAmounts;
    for (int i = 0; i < MCQCount; i++)
    {
        MCQIDList.insert(MCQIDList.end(), Question::QuestionID); 
    }
}

void QuizGeneration::GetTFList(int TFCount){
    TFCount = TFAmounts;
    for (int i = 0; i < TFCount; i++)
    {
        TFIDList.insert(TFIDList.end(), Question::QuestionID); 
    }
}

void QuizGeneration::GetFRQList(int FRQCount){
    FRQCount = FRQAmounts;
    for (int i = 0; i < FRQCount; i++)
    {
        FRQIDList.insert(FRQIDList.end(), Question::QuestionID); 
    }
}