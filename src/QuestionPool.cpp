#include <iostream>
#include "../header/QuestionPool.hpp"
#include "../header/Question.hpp"

QuestionPool::QuestionPool(){

}

QuestionPool::~QuestionPool(){

}

Question * QuestionPool::GetRandomQuestion(){
	
}

QUestion * QuestionPool::GetQuestionByID(){
	



	return null;
}

unsigned GetQuestionAmount(){
	return Questions.size();
}

void QuestionPool::AddQuestionToPool(Question * MyQuestion){
	Questions.push_back(MyQuestion);
}

void QuestionPool::RemoveQuestionFromPool(unsigned Question){

}

void QuestionPool::EditQuestionById(unsigned QuestionID){

}

void QuestionPool::PrintAllQuestions(){
	for(Question : Questions){
		std::cout << Question << std::endl;
	}
}
