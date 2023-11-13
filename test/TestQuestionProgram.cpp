#include <iostream>
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"

using namespace std;

int main(){
	vector<Question *> myQuestions;
	myQuestions.push_back(new QuestionFRQ(1234, 4, "Is this even legal?"));
	myQuestions.push_back(new QuestionMCQ(1234, 64, "Which are these are legal?"));

	myQuestions[0]->AddPossibleAnswer("LEL");
	myQuestions[0]->AddPossibleAnswer("LOL");
	myQuestions[1]->AddPossibleAnswer("LEL");
	myQuestions[1]->AddPossibleAnswer("LOL");
	myQuestions[1]->AddPossibleAnswer("LUL");

	for(Question * Q : myQuestions){
		cout << *Q << endl;
	}

	cout << "FRQ: " << endl;
	myQuestions[0]->EditPossibleAnswer();
	cout << "MCQ: " << endl;
	myQuestions[1]->EditPossibleAnswer();

	for(Question * Q : myQuestions){
		cout << *Q << endl;
	}

	cout << "FRQ T1 (LEL): " << myQuestions[0]->ScoreQuestion("LEL") << endl;
	cout << "FRQ T2 (LOL): " << myQuestions[0]->ScoreQuestion("LOL") << endl;

	cout << "MCQ T1 (A): " << myQuestions[1]->ScoreQuestion("A") << endl;
	cout << "MCQ T2 (AB): " << myQuestions[1]->ScoreQuestion("AB") << endl;
	cout << "MCQ T3 (NONE): " << myQuestions[1]->ScoreQuestion("") << endl;

	for(Question * Q : myQuestions){
		delete Q;
	}
}
