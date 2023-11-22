#include <iostream>
#include <string>
#include <vector>

class Quiz{
    private:
    int QuizID;
    string Title;
    vector <Question> Questions;
    Instructor Instructor; //first should be 
    bool Availablity;
    int Attempts;

    public:
    void AddQuestion(Question question);
    
}