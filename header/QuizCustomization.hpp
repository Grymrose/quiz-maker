#ifndef _QUIZ_CUSTOMIZATION_HEADER
#define _QUIZ_CUSTOMIZATION_HEADER

#include <string>
#include <chrono>
#include <thread>
#include <vector>

class QuizCustomization{
private:
    int MCQAmounts;
    int FRQAmounts;
    int TFAmounts;

    int TimerHours;
    int TimerMinutes;

    unsigned QuestionID;

    std::string QuestionCriteria;

    std::vector <std::string> Criteria;
    std::vector <unsigned> ID;
public:
    void RecordMCQAmounts();
    void RecordFRQAmounts();
    void RecordTFAmounts();
    void RecordCriteria();

    void SetTime();
    void SetCriteria();
    std::string Timer();

    const std::string TIMESUP = "TimesUp";
};

#endif