#include <string>
#include <vector>
#include "../header/Question.hpp"
#include "../header/FileIO.hpp"

class QuestionPool{
private:
	vector <Question *> Questions;
public:
	QuestionPool();
	~QuestionPool();
	Question GetRandomQuestion();
	Question GetQuestionByID(int QuestionID);
	void CreateQuestion(unsigned QuestionID, unsigned Points, std::string);
	void RemoveQuestionByID(unsigned QuestionID);
	void EditQuestionByID(unsigned QuestionID);
	void PrintAllQuestions();
}
