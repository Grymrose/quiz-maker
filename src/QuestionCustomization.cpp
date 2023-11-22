#include "../header/QuizCustomization.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void QuizCustomization::RecordFRQAmounts(){
    std::cout << "Enter the total numbers of FRQ:" << std::endl;
    std::cin >> FRQAmounts;
}

void QuizCustomization::RecordMCQAmounts(){
    std::cout << "Enter the total numbers of MCQ:" << std::endl;
    std::cin >> MCQAmounts;
}

void QuizCustomization::RecordTFAmounts(){
    std::cout << "Enter the total numbers of TF:" << std::endl;
    std::cin >> TFAmounts;
}

void QuizCustomization::SetCriteria(){
    std::cout << "Enter question ID:" << std::endl;
    std::cin >> QuestionID;
    std::cout << "Enter criteria of this question:" << std::endl;
    std::getline(std::cin, QuestionCriteria);
}

void QuizCustomization::RecordCriteria(){
    ID.insert(ID.end(), QuestionID);
    Criteria.insert(Criteria.end(), QuestionCriteria);
}

void QuizCustomization::SetTime(){
    std::cout << "Set hours of the quiz:" << std::endl;
    std::cin >> TimerHours;
    if (TimerHours < 0)
    {
        std::cout << "Invalid time" << std::endl;
        TimerHours = 0;
    }
    std::cout << "Set minutes of the quiz:" << std::endl;
    std::cin >> TimerMinutes;
    if (TimerMinutes < 0)
    {
        std::cout << "Invalid time" << std::endl;
        TimerMinutes = 0;
    }
}

std::string QuizCustomization::Timer(){
    std::this_thread::sleep_for(std::chrono::hours(TimerHours));
    std::this_thread::sleep_for(std::chrono::hours(TimerMinutes));
    return TIMESUP;
}