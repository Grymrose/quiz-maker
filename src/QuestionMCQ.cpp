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

void QuestionMCQ::EditPossibleAnswer() {
    PossibleAnswers* temp = MyPossibleAnswers;  // Output all possible answers
    char letter = 'A';
    while (temp != nullptr) {
        QuestionOutput::PrintPossibleAnswer(letter, temp->PossibleAnswer);
        letter++;
        temp = temp->Next;
    }

    // User Prompt: Initial Guard
    char changeChoice = QuestionOutput::GetUserInputChar("Choose question to edit by entering the corresponding letter: ");
    
    letter--;   // User Prompt: Second Guard
    while (letter < changeChoice) {
        changeChoice = QuestionOutput::GetUserInputChar("Bad entry/not found. Input as a single, capital, and alphabetical input: ");
    }

    temp = MyPossibleAnswers;   // Start Edit
    unsigned answerNumber = (unsigned)changeChoice - 65;
    for (unsigned i = 0; i < answerNumber; i++) {
        temp = temp->Next;
    }

    std::string newAnswer;
    newAnswer = QuestionOutput::GetUserInputString("New answer (\"SKIP\" to keep original): ");
    if(newAnswer != "SKIP" && newAnswer != "skip"){
		temp->PossibleAnswer = newAnswer;
	}

    bool newCorrectness = QuestionOutput::GetCorrectnessFromUser();
    temp->Correctness = newCorrectness;
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

void QuestionMCQ::PrintQuestion() const {
	QuestionOutput::PrintQuestion(PossiblePoints, MyQuestion);
}

void QuestionMCQ::PrintPossibleAnswers() const {
	PossibleAnswers* temp = MyPossibleAnswers;
    char letter = 'A';
    while (temp != nullptr) {
        QuestionOutput::PrintPossibleAnswer(letter, temp->PossibleAnswer);
        letter++;
        temp = temp->Next;
    }
}