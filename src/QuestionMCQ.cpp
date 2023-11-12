#include <string>
#include <cmath>
#include <algorithm>
#include "../header/QuestionMCQ.hpp"

QuestionMCQ::QuestionMCQ(unsigned ID, unsigned Points, std::string InputQuestion) : Question(ID, Points, InputQuestion){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = InputQuestion;
}

QuestionMCQ::~QuestionMCQ(){
	PossibleAnswers * temp;
	while(MyPossibleAnswers != nullptr){
		temp = MyPossibleAnswers->Next;
		delete MyPossibleAnswers;
		MyPossibleAnswers = temp;
	}
};

void QuestionMCQ::AddPossibleAnswer(std::string PossibleAnswer){
	if(MyPossibleAnswers == nullptr){
		MyPossibleAnswers = new PossibleAnswers(PossibleAnswer);
		return;
	}else{
		PossibleAnswers * NewPossibleAnswer = new PossibleAnswers(PossibleAnswer);
		NewPossibleAnswer->Next = MyPossibleAnswers;
		MyPossibleAnswers = NewPossibleAnswer;
		return;
	}
}

void QuestionMCQ::EditPossibleAnswer(){
	
	
}

unsigned QuestionMCQ::ScoreQuestion(std::string StudentAnswer){
	std::transform(StudentAnswer.begin(), StudentAnswer.end(), StudentAnswer.begin(), ::toupper);
	std::string AnswerString = GenerateAnswerString();
	std::sort(begin(StudentAnswer), end(StudentAnswer));
	std::string Intersection;
	std::set_intersection(begin(AnswerString), end(AnswerString), begin(StudentAnswer), end(StudentAnswer), back_inserter(Intersection));
	unsigned NumberCorrect = Intersection.size();
	unsigned NumberTotal = 0;
	PossibleAnswers * Temp = MyPossibleAnswers;
	while(Temp != nullptr){
		NumberTotal++;
		Temp = Temp->Next;
	}
	return abs((NumberCorrect * (1 / NumberTotal) - ((StudentAnswer.size() - NumberCorrect) * (1 / NumberTotal))) * PossiblePoints);
}

std::string QuestionMCQ::GenerateAnswerString(){
	std::string AnswerString = "";
	char Letter = 'A';
	PossibleAnswers * Temp = MyPossibleAnswers;
	while(Temp != nullptr){
		if(Temp->Correctness){
			AnswerString += Letter;
		}
		Letter++;
		Temp = Temp->Next;
	}
	return AnswerString;
}
