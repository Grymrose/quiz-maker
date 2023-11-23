#include <string>
#include <vector>
#include "../header/Question.hpp"
//#include "../header/FileIO.hpp"

class QuestionPool{
private:
	std::vector <Question *> Questions;
public:
	QuestionPool();
	~QuestionPool();
	Question * GetRandomQuestion();
	Question * GetQuestionByID(unsigned QuestionID);
	unsigned GetQuestionAmount();
	void AddQuestionToPool(Question *);
	void RemoveQuestionFromPool(unsigned QuestionID);
	void EditQuestionByID(unsigned QuestionID);
	void PrintAllQuestions();
};
