#include <string>
#include "Question.hpp"

Question::Question(unsigned ID, unsigned Points, std::string Question){
	QuestionID = ID;
	PossiblePoints = Points;
	MyQuestion = Question;
}

Question::~Question(){

}
