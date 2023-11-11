#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
#include <vector>

struct Option {
    std::string content;
    bool isCorrect;
    Option(const std::string& opt, bool correct) : content(opt), isCorrect(correct) {}
};

class Question {
    public:
        enum QuestionType { //MC = Multiple Choice, TF = True/False, FR = Free Response
            MCQ, TFQ, FRQ
        };
        Question();
        ~Question();
        void AddOption(const std::string& option, bool isCorrect = false);
        void RemoveOption(const std::string& option);
        void EditOptions(const std::string& oldOption, const std::string& newOption, bool newCorrectStatus);
        void SetCorrectAnswer(const std::string& answer);
        void SetQuestionType(QuestionType type);
    private:
        unsigned questionID;
        QuestionType questionType;
        std::string questionPrompt;
        std::vector<Option> options;
};

/*
========ISSUES TO BE RESOLVED========
*   It seems that a string is being attempted for answer.
    It is recommended to use a void type pointer in private data field and cast such void type pointer into either char for MCQ or string for FRQ upon construction.

*   No scoring system has been planned.
    It is recommended that a scoring type function be implemented into the question class.
    A score can be manually given if FRQ through instructor or be automatically calculated if MCQ.
*/

#endif