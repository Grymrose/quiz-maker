#include "../header/Quiz.hpp"
#include <iostream>
Quiz::Quiz() {
    QuizID = 0;
    Title = "";
    Availability = false;
    Attempts = 1; 
}

Quiz::~Quiz() {
    
}

void Quiz::setAvailability(bool availability) {
    Availability = availability;
}

void Quiz::setAttempts(int attempts) {
    Attempts = attempts;

void scheduleQuiz(Quiz& quiz);{
    struct Time {
        int Month;
        int Day;
        int Year;
        int Hour;
        int Minute;
        int Second;

        Time():Time(0,0,0,0,0,0){ 

        } 

        Time(int month, int day, int year, int hour, int minute, int second){
            Month = month;
            Day = day;
            Year = year;
            Hour = hour;
            Minute = minute;
            Second = second;
        };

        void ReadTime(){

        }

        void DisplayTime{
            cout << Month << "," << Day << ","<< Year << " " << Hour << ":" << Minute << ":"<< Second;
        }
    };
}
}