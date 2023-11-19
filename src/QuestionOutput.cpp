#include "../header/QuestionOutput.hpp"

void QuestionOutput::PrintQuestion(unsigned points, const std::string& question) {
    std::cout << "(" << points << " Points) " << question << std::endl;
}

void QuestionOutput::PrintPossibleAnswer(char letter, const std::string& possibleAnswer) {
    std::cout << letter << ": " << possibleAnswer << std::endl;       
}

char QuestionOutput::GetUserInputChar(const std::string& prompt) {
    std::cout << prompt;
    char input;
    std::cin >> input;
    while (std::cin.fail() || !isalpha(input)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
		std::cin >> input;
    }
    return input;
}

std::string QuestionOutput::GetUserInputString(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return input;
}

bool QuestionOutput::GetCorrectnessFromUser() {
    std::string input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    while (true) {
        if (input == "1") {
            return true;
        } else if (input == "0") {
            return false;
        } else if (input != "SKIP" && input != "skip") {
			std::cout << "Bad entry. Only use 0, 1, or \"SKIP\"!" << std::endl;
		}
        input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    }
    std::cout << std::endl << std::endl;
}

// void QuestionMCQ::EditPossibleAnswer(){
// 	PossibleAnswers * Temp = MyPossibleAnswers;					//Output all possible answers.
// 	char Letter = 'A';
// 	while(Temp != nullptr){
// 		std::cout << Letter << ": " << Temp->PossibleAnswer << std::endl;
// 		Letter++;
// 		Temp = Temp->Next;
// 	}

// 	std::cout << "Choose question to edit by entering the corresponding letter: ";	//User prompt: inital guard.
// 	char ChangeChoice;
// 	std::cin >> ChangeChoice;
// 	while(std::cin.fail() || !isalpha(ChangeChoice)){
// 		std::cin.clear();
// 		std::cin.ignore();
// 		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
// 		std::cin >> ChangeChoice;
// 	}

// 	Letter--;									//User prompt: second guard.
// 	while(Letter < ChangeChoice){
// 		std::cin.clear();
// 		std::cin.ignore();
// 		std::cout << "Bad entry/not found. Input as a single, capital, and alphabetical input: ";
// 		std::cin >> ChangeChoice;
// 	}

// 	Temp = MyPossibleAnswers;							//Start edit.
// 	unsigned AnswerNumber = (unsigned)ChangeChoice - 65;
// 	for(unsigned i = 0; i < AnswerNumber; i++){
// 		Temp = Temp->Next;
// 	}
// 	std::string NewAnswer;

// 	std::cout << "New answer (\"SKIP\" to keep original): ";
// 	std::cin >> NewAnswer;
// 	if(NewAnswer != "SKIP" && NewAnswer != "skip"){
// 		Temp->PossibleAnswer = NewAnswer;
// 	}
// 	std::cout << "Correctness state(1 for true, 0 for false, \"SKIP\" to keep original): ";
// 	while(true){
// 		std::cin >> NewAnswer;
// 		if(NewAnswer == "1"){
// 			Temp->Correctness = true;
// 			break;
// 		}else if(NewAnswer == "0"){
// 			Temp->Correctness = false;
// 			break;
// 		}else if(NewAnswer != "SKIP" && NewAnswer != "skip"){
// 			std::cout << "Bad entry. Only use 0, 1, or blank: ";
// 		}
// 	}

// 	std::cout << std::endl << std::endl;
// }



void QuestionOutput::PrintTFSpecific(const std::string& specificOutput) {
    std::cout << "TF-specific: " << specificOutput << std::endl;
}

void QuestionOutput::PrintMCQSpecific(const std::string& specificOutput) {
    std::cout << "MCQ-specific: " << specificOutput << std::endl;
}