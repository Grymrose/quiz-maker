#include <string>
#include <vector>
#include "../header/Question.hpp"
#include "../header/FileIO.hpp"

class QuestionPool{
private:
	vector <Question> Questions;
public:
	QuestionPool();
	~QuestionPool();
	Question GetRandomQuestion();
	Question GetQuestionByID(unsigned QuestionID);
}
