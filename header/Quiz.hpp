#ifndef __QUIZ_HEADER__
#define __QUIZ_HEADER__
#include <string>
#include <vector>
#include <iostream>
#include "../header/Question.hpp"

class Quiz {
    private:
        int quizID;
        std::string title;
        std::vector<Question*> questions;
        bool availability;
        int attempts;
        std::vector<int> Schedule;
    public:
        // Constructor with default values for title, availability, and attempts
        Quiz(int quizID, const std::string& title = "Untitled", bool availability = true, int attempts = -1, const std::vector<int>& Schedule = {});
      
        // Setter methods
        void setAvailability(bool availability);
        void setAttempts(int attempts);

        // Add a question to the quiz
        void AddQuestion(Question* question);

        // Getter method for questions
        const std::vector<Question*>& GetQuestions() const;

        // Getter methods for other properties
        int GetQuizID() const;
        const std::string& GetTitle() const;
        bool IsAvailable() const;
        int GetAttempts() const;

        void ScheduleQuiz();
        void printSchedule();
};

#endif