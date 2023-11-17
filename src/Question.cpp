#include <iostream>
#include <string>
#include "Question.hpp"

Question::Question(unsigned ID, unsigned Points, std::string Question){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = Question;
}

Question::~Question(){

}

void Question::EditPossiblePoints() {
	std::cin >> PossiblePoints;
}

void Question::EditQuestion() { // Adding an EditQuestion function!!
	std::getline(std::cin, MyQuestion);
}

std::ostream & operator<<(std::ostream & out, const Question & Q){
	Q.PrintQuestion(out);
	return out;
}