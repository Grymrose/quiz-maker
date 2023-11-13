#include <iostream>
#include <sstream>
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
	PossibleAnswers * Temp = MyPossibleAnswers;					//Output all possible answers.
	char Letter = 'A';
	while(Temp != nullptr){
		std::cout << Letter << ": " << Temp->PossibleAnswer << std::endl;
		Letter++;
		Temp = Temp->Next;
	}

	std::cout << "Choose question to edit by entering the corresponding letter: ";	//User prompt: inital guard.
	char ChangeChoice;
	std::cin >> ChangeChoice;
	while(std::cin.fail() || !isalpha(ChangeChoice)){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> ChangeChoice;
	}

	Letter--;									//User prompt: second guard.
	while(Letter < ChangeChoice){
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> ChangeChoice;
	}

	Temp = MyPossibleAnswers;							//Start edit.
	unsigned AnswerNumber = (unsigned)ChangeChoice - 65;
	for(unsigned i = 0; i < AnswerNumber; i++){
		Temp = Temp->Next;
	}
	std::string NewAnswer;

	std::cout << "New answer (\"SKIP\" to keep original): ";
	std::cin >> NewAnswer;
	if(NewAnswer != "SKIP" && NewAnswer != "skip"){
		Temp->PossibleAnswer = NewAnswer;
	}
	std::cout << "Correctness state(1 for true, 0 for false, \"SKIP\" to keep original): ";
	while(true){
		std::cin >> NewAnswer;
		if(NewAnswer == "1"){
			Temp->Correctness = true;
			break;
		}else if(NewAnswer == "0"){
			Temp->Correctness = false;
			break;
		}else if(NewAnswer != "SKIP" && NewAnswer != "skip"){
			std::cout << "Bad entry. Only use 0, 1, or blank: ";
		}
	}

	std::cout << std::endl << std::endl;
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
		if(Temp->Correctness){
			NumberTotal++;
		}
		Temp = Temp->Next;
	}
//std::cout<< NumberCorrect << "*(1/" << NumberTotal << ")-((" << StudentAnswer.size() << '-' << NumberCorrect << ")*(1/" << NumberTotal << ")))*" << PossiblePoints <<std::endl;
	double Ratio = (NumberCorrect * (1 / (double)StudentAnswer.size()));
	return abs(Ratio * PossiblePoints);
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

void QuestionMCQ::PrintQuestion(std::ostream & Out) const{
	Out << '(' << PossiblePoints << " Points) " << MyQuestion << std::endl;
	PrintPossibleAnswers(Out);
}

void QuestionMCQ::PrintPossibleAnswers(std::ostream & Out) const{
	PossibleAnswers * Temp = MyPossibleAnswers;
	char Letter = 'A';
	while(Temp != nullptr){
		Out << Letter << ": " << Temp->PossibleAnswer << std::endl;
		Letter++;
		Temp = Temp->Next;
	}
}
