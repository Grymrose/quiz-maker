#include <string>
#include <vector>

class Question{
private:
	unsigned QuestionID;
	enum QuestionType{			//PLACEHOLDER: MCQ, FRQ
		MCQ, FRQ
	}
	std::string Question;
	std::vector <std::string> options;	//RECOMENDATION: Use linkedlist struct for options. Easy to differentiate, add, and to remove.
	std::string CorrectAnswer;
public:
	Question();
	~Question();
	void AddOption(std::string);
	void RemoveOption();			//It is only logical to have remove if add exits.
	void EditOptions(std::string);		//Passing a single string to edit all possible options is not an efficient implementation. It will be impossible to differentiate between which question to edit. Use linkedlist for better efficiency.
	void SetCorrectAnser(std::string);
}

/*
========ISSUES========
It seems that a vector<string> is being attempted for options type.
It is better to use a linkedlist with string payload, bool payload, and a struct next pointer.
Not only will editing each option be more efficient, but a bool payload will allow multiple selection MCQ type.

It seems that a strinng is being attempted for answer.
It is recommended to use a void type pointer in private data field and cast such void type pointer into either char for MCQ or string for FRQ upon construction.

No scoring system has been planned.
It is recommened that a scoring type function be implemented into the question class.
A score can be manually given if FRQ through instructor or be automatically calculated if MCQ.
*/
