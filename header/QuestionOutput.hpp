#ifndef __QUESTION_OUTPUT__
#define __QUESTION_OUTPUT__

#include <iostream>
#include <string>
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionFRQ.hpp"

class QuestionOutput {
public:
    static void PrintQuestion(unsigned points, const std::string& question);
    static void PrintPossibleAnswer(char letter, const std::string& possibleAnswer);
    char GetUserInputChar(const std::string& prompt);
    std::string GetUserInputString(const std::string& prompt);
    bool GetCorrectnessFromUser();
    static void PrintTFSpecific(const std::string& specificOutput);
    static void PrintMCQSpecific(const std::string& specificOutput);
};

#endif