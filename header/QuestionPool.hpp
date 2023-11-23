#include <string>
#include <vector>
#include "../header/Question.hpp"
#include "../header/FileIO.hpp"

class QuestionPool{
private:
	std::vector <Question> MCQPool;
	std::vector <Question> TFPool;
	std::vector <Question> FRQPool;
public:
	QuestionPool();
	~QuestionPool();
	Question GetRandomQuestion(std::string QuestionType);
	Question GetQuestionByID(unsigned QuestionID);
};