#ifndef __QUESTION_HEADER__
#define __QUESTION_HEADER__

#include <string>
#include <vector>
#include <iostream>

class Question{
protected:
	unsigned QuestionID;
	unsigned PossiblePoints;
	std::string MyQuestion;
public:
	Question(unsigned ID, unsigned Points, std::string MyQuestion);
	virtual ~Question();
	void EditPossiblePoints();
	void EditQuestion();
	virtual void AddPossibleAnswer(std::string PossibleAnswer) = 0;
	virtual void EditPossibleAnswer() = 0;
	virtual unsigned ScoreQuestion(const std::string& studentAnswer) = 0;
	unsigned GetQuestionID();
	virtual void PrintQuestion() const = 0;
	// friend std::ostream & operator<<(std::ostream & out, const Question & Q);
};

#endif
