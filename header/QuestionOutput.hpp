#ifndef __QUESTION_OUTPUT_HEADER__
#define __QUESTION_OUTPUT_HEADER__

#include <iostream>
#include <string>

class QuestionOutput {
public:
    static void PrintQuestion(unsigned points, const std::string& question);
    static void PrintPossibleAnswer(char letter, const std::string& possibleAnswer);
    static char GetUserInputChar(const std::string& prompt);
    static std::string GetUserInputString(const std::string& prompt);
    static bool GetCorrectnessFromUser();
};

#endif