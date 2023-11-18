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
    static void PrintPossibleAnswers(const std::string& output);
    static void PrintTFSpecific(const std::string& specificOutput);
    static void PrintMCQSpecific(const std::string& specificOutput);
};

#endif