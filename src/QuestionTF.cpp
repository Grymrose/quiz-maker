#include <iostream>
#include <string>
#include <algorithm>
#include "../header/QuestionTF.hpp"

QuestionTF::QuestionTF(unsigned ID, unsigned Points, std::string InputQuestion) : Question(ID, Points, InputQuestion) {
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = InputQuestion;
}

QuestionTF::~QuestionTF() {
	PossibleAnswers* temp;
	while(MyPossibleAnswers != nullptr){
		temp = MyPossibleAnswers->Next;
		delete MyPossibleAnswers;
		MyPossibleAnswers = temp;
	}
};

void QuestionTF::AddPossibleAnswer(std::string PossibleAnswer) {
    if (numberOfAnswers == 2) {
        std::cout << "Cannot add more than 2 possible answers for True/False questions." << std::endl;
        return;
    }
    
	if(MyPossibleAnswers == nullptr) {
		MyPossibleAnswers = new PossibleAnswers(PossibleAnswer);
		return;
	} else {
		PossibleAnswers* NewPossibleAnswer = new PossibleAnswers(PossibleAnswer);
		NewPossibleAnswer->Next = MyPossibleAnswers;
		MyPossibleAnswers = NewPossibleAnswer;
		return;
	}
}

void QuestionTF::EditPossibleAnswer() {
    PossibleAnswers* Temp = MyPossibleAnswers;
	char Letter = 'A';
	while(Temp != nullptr) {
		std::cout << Letter << ": " << Temp->PossibleAnswer << std::endl;
		Letter++;
		Temp = Temp->Next;
	}

	std::cout << "Choose question to edit by entering the corresponding letter: ";
	char ChangeChoice;
	std::cin >> ChangeChoice;
	while(std::cin.fail() || !isalpha(ChangeChoice)) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> ChangeChoice;
	}

	Letter--;
	while(Letter < ChangeChoice) {
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> ChangeChoice;
	}

	Temp = MyPossibleAnswers;
	unsigned AnswerNumber = (unsigned)ChangeChoice - 65;
	for(unsigned i = 0; i < AnswerNumber; i++) {
		Temp = Temp->Next;
	}
	std::string NewAnswer;

	std::cout << "New answer (\"SKIP\" to keep original): ";
	std::cin >> NewAnswer;
	if(NewAnswer != "SKIP" && NewAnswer != "skip") {
		Temp->PossibleAnswer = NewAnswer;
	}
	std::cout << "Correctness state(1 for true, 0 for false, \"SKIP\" to keep original): ";
	while(true) {
		std::cin >> NewAnswer;
		if(NewAnswer == "1") {
			Temp->Correctness = true;
            if(Temp->Next != nullptr) { // Different from MCQ!
                Temp->Next->Correctness = false;
            }
			break;
		} else if(NewAnswer == "0") {
			Temp->Correctness = false;
            if(Temp->Next != nullptr) { // Different from MCQ!
                Temp->Next->Correctness = true;
            }
			break;
		} else if(NewAnswer != "SKIP" && NewAnswer != "skip") {
			std::cout << "Bad entry. Only use 0, 1, or blank: ";
		}
	}

	std::cout << std::endl << std::endl;
}