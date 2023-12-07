#include "../header/Question.hpp"

Question::Question(unsigned ID, unsigned Points, std::string Question){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = Question;
}

Question::~Question(){}

void Question::EditPossiblePoints() {
	std::cin >> PossiblePoints;
}

void Question::EditQuestion() {
	std::getline(std::cin, MyQuestion);
}

unsigned Question::GetQuestionID(){
	return QuestionID;
}