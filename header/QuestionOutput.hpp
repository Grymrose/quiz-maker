#ifndef __QUESTION_OUTPUT_HEADER__
#define __QUESTION_OUTPUT_HEADER__

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
    static char GetUserInputChar(const std::string& prompt);
    static std::string GetUserInputString(const std::string& prompt);
    static bool GetCorrectnessFromUser();
    static void PrintTFSpecific(const std::string& specificOutput);
    static void PrintMCQSpecific(const std::string& specificOutput);
};

#endif