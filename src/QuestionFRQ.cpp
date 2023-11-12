#include <string>
#include "QuestionFRQ.hpp"

QuestionFRQ::QuestionFRQ(unsigned ID, unsigned Points, std::string InputQuestion) : Question(ID, Points, InputQuestion){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = InputQuestion;
}

QuestionFRQ::~QuestionFRQ(){
}

void QuestionFRQ::AddPossibleAnswer(std::string InputAnswer){
	PossibleAnswer = InputAnswer;
}

void QuestionFRQ::EditPossibleAnswer(){
	
	
}

unsigned QuestionFRQ::ScoreQuestion(std::string StudentAnswer){
	if(PossibleAnswer == StudentAnswer){
		return PossiblePoints;
	}
}
/*
std::vector<std::string> QuestionFRQ::GetCorrectAnswers(){
	return CorrecAnswers;
}
*/
