#include <iostream>
#include <string>
#include "QuestionFRQ.hpp"

QuestionFRQ::QuestionFRQ(unsigned ID, unsigned Points, std::string InputQuestion) : Question(ID, Points, InputQuestion){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = InputQuestion;
}

QuestionFRQ::~QuestionFRQ(){
}

void QuestionFRQ::AddPossibleAnswer(std::string InputAnswer){		//This function should only by called once.
	if(PossibleAnswer == ""){
		PossibleAnswer = InputAnswer;
	}
}

void QuestionFRQ::EditPossibleAnswer(){
	PossibleAnswer = QuestionOutput::GetUserInputString("New correct answer: ");
}

unsigned QuestionFRQ::ScoreQuestion(std::string StudentAnswer) {
    // Case-insensitive comparison
    std::transform(StudentAnswer.begin(), StudentAnswer.end(), StudentAnswer.begin(), ::toupper);
    std::string ExpectedAnswerUpper = PossibleAnswer;
    std::transform(ExpectedAnswerUpper.begin(), ExpectedAnswerUpper.end(), ExpectedAnswerUpper.begin(), ::toupper);

    // Compare student's answer with the expected answer
    return (StudentAnswer == ExpectedAnswerUpper) ? PossiblePoints : 0;
}

void QuestionFRQ::PrintQuestion() const {
	QuestionOutput::PrintQuestion(PossiblePoints, MyQuestion);
}