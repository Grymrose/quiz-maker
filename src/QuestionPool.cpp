#include <iostream>
#include <vector>
#include "../header/QuestionPool.hpp"
#include "../header/Question.hpp"

QuestionPool::QuestionPool(){

}

QuestionPool::~QuestionPool(){
	for(unsigned i = 0; i < Questions.size(); i++){
		delete Questions[i];
	}
}

Question * QuestionPool::GetRandomQuestion(){
	unsigned RandomQuestionNumber = rand()%(GetQuestionAmount());
	return Questions[RandomQuestionNumber];
}

Question * QuestionPool::GetQuestionByID(unsigned QuestionID){
	Question * MyQuestion = nullptr;
	for(unsigned i = 0; i < Questions.size(); i++){
		if(Questions[i]->GetQuestionID() == QuestionID){
			MyQuestion = Questions[i];
		}
	}
	return MyQuestion;
}

unsigned QuestionPool::GetQuestionAmount(){
	return Questions.size();
}

void QuestionPool::AddQuestionToPool(Question * MyQuestion){
	Questions.push_back(MyQuestion);
}

void QuestionPool::RemoveQuestionFromPool(unsigned QuestionID){
	Question * MyQuestion = nullptr;
	unsigned i;
	for(i = 0; i < Questions.size(); i++){

		if(Questions[i]->GetQuestionID() == QuestionID){
			Questions.erase(Questions.begin() + i);
			break;
		}
	}
	if(MyQuestion == nullptr){
		std::cout << "Question not found." << std::endl;
	}
}

void QuestionPool::EditQuestionByID(unsigned QuestionID){
	Question * MyQuestion = nullptr;
	for(unsigned i = 0; i < Questions.size(); i++){
		if(Questions[i]->GetQuestionID() == QuestionID){
			MyQuestion = Questions[i];
		}
	}
	if(MyQuestion == nullptr){
		std::cout << "Question not found." << std::endl;
	}else{
		MyQuestion->EditPossibleAnswer();
	}
}

void QuestionPool::PrintAllQuestions(){
	for(unsigned i = 0; i < Questions.size(); i++){
		Questions[i]->PrintQuestion();
	}
}
