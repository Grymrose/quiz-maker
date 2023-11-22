#include <iostream>
#include <string>
#include <algorithm>
#include "../header/QuestionTF.hpp"

QuestionTF::QuestionTF(unsigned ID, unsigned Points, std::string InputQuestion) 
          : QuestionMCQ(ID, Points, InputQuestion), AnswerCount(0) {
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = InputQuestion;
}

QuestionTF::~QuestionTF() {}

void QuestionTF::AddPossibleAnswer(std::string PossibleAnswer) {
    if (AnswerCount == 2) {
        std::cout << "Cannot add more than 2 possible answers for True/False questions." << std::endl;
        return;
    }
    
	AnswerCount++;
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