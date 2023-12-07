#include "../header/Quiz.hpp"

// Constructor implementation
Quiz::Quiz(int quizID, const std::string& title, bool availability, int attempts, const std::vector<int>& Schedule)
    : quizID(quizID), title(title), availability(availability), attempts(attempts), Schedule(Schedule) {}

// Setter methods implementation
void Quiz::setAvailability(bool availability) {
    this->availability = availability;
}

void Quiz::setAttempts(int attempts) {
    this->attempts = attempts;
}

// Add a question to the quiz
void Quiz::AddQuestion(Question* question) {
    questions.push_back(question);
}

// Getter method for questions
const std::vector<Question*>& Quiz::GetQuestions() const {
    return questions;
}

// Getter methods for other properties
int Quiz::GetQuizID() const {
    return quizID;
}

const std::string& Quiz::GetTitle() const {
    return title;
}

bool Quiz::IsAvailable() const {
    return availability;
}

int Quiz::GetAttempts() const {
    return attempts;
}

void Quiz::ScheduleQuiz()
{
    int month = -1;
    int day = -1;
    int startHour = -1;
    int startMinute = -1;
    int endHour = -1;
    int endMinute = -1; 

    std::cout << "Please enter a number from 1 to 12 for the corresponding month." << std::endl;

    while (true)
    {
        std::cin >> month;
        if (month >= 1 && month <= 12)
        {
            break;
        }
        std::cout << "Invalid Input!" << std::endl << "Please enter a number from 1 to 12." << std::endl;
    }
    this->Schedule.push_back(month);

    std::cout << "Please enter a number from 1 to 31 for the corresponding date." << std::endl;
    while (true)
    {
        std::cin >> day;
        if (day >= 1 && day <= 31)
        {
            break;
        }
        std::cout << "Invalid Input!" << std::endl << "Please enter a number from 1 to 31." << std::endl;
    }
    this->Schedule.push_back(day);

    std::cout << "Please enter the starting hour and minute." << std::endl;
    while (true)
    {
        std::cin >> startHour;
        std::cin >> startMinute;
        if (startHour >= 0 && startHour <= 23 && startMinute >= 0 && startMinute <= 59)
        {
            break;
        }
        std::cout << "Invalid Input!" << std::endl << "Please enter a valid time." << std::endl;
    }
    this->Schedule.push_back(startHour);
    this->Schedule.push_back(startMinute);   

    std::cout << "Please enter the ending hour and minute." << std::endl;
    while (true)
    {
        std::cin >> endHour;
        std::cin >> endMinute;
        if (endHour >= 0 && endHour <= 23 && endMinute >= 0 && endMinute <= 59 && (startHour < endHour || (startHour == endHour && startMinute < endMinute)))
        {
            break;
        }
        std::cout << "Invalid Input!" << std::endl << "Please enter a valid ending time that is later than the starting time." << std::endl;
    }
    this->Schedule.push_back(endHour);
    this->Schedule.push_back(endMinute);

    std::cout << "Successfully scheduled!" << std::endl;



}

void Quiz::printSchedule()
{
    std::cout << "Date: " << this->Schedule.at(0) << "/" << this->Schedule.at(1) << std::endl;
    std::cout << "Time: " << this->Schedule.at(2) << ":" << this->Schedule.at(3);
    if (this->Schedule.at(3) == 0)
        std::cout << this->Schedule.at(3);
    std::cout << " -- " << this->Schedule.at(4) << ":" << this->Schedule.at(5);
    if (this->Schedule.at(5) == 0)
        std::cout << this->Schedule.at(5);
    std::cout << std::endl;
}