#include <string>
#include "gtest/gtest.h"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"

TEST(TestQuestionMCQ, TestConstructor){
	EXPECT_NO_THROW(QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?"));
}

TEST(TestQuestionMCQ, TestAddPossibleAnswer){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	EXPECT_NO_THROW(MCQ->AddPossibleAnswer("21."));
}
/*
TEST(TestQuestionMCQ, TestGenerateAnswerString){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	MCQ->AddPossibleAnswer("21.");
	MCQ->AddPossibleAnswer("19.");
//	std::string Result = 
	EXPECT_STREQ(MCQ->GenerateAnswerString(), "AB");
}

*/
