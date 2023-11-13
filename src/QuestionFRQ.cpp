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
	std::cout << "New correct answer: ";
	std::cin >> PossibleAnswer;
	std::cout << std::endl;
}

unsigned QuestionFRQ::ScoreQuestion(std::string StudentAnswer){
	if(PossibleAnswer == StudentAnswer){
		return PossiblePoints;
	}else{
		return 0;
	}
}

void QuestionFRQ::PrintQuestion(std::ostream & Out) const{
	Out << '(' << PossiblePoints << " Points) " << MyQuestion << std::endl;
}
