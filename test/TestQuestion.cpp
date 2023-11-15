#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"

//QuestionMCQ

TEST(TestQuestionMCQ, TestConstructor){
	EXPECT_NO_THROW(QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?"));
}

TEST(TestQuestionMCQ, TestAddPossibleAnswer){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	EXPECT_NO_THROW(MCQ->AddPossibleAnswer("21."));
	delete MCQ;
}

TEST(TestQuestionMCQ, TestEditPossibleAnswer){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	MCQ->AddPossibleAnswer("21.");
	MCQ->AddPossibleAnswer("20.");
	MCQ->AddPossibleAnswer("19.");
	std::cout << "Change \"A\" prompt to \"24\" and set to \"true\": " << std::endl;
	EXPECT_NO_THROW(MCQ->EditPossibleAnswer());
	unsigned Score = MCQ->ScoreQuestion("A");
	EXPECT_EQ(8, Score);
	delete MCQ;
}

TEST(TestQuestionMCQ, TestScoreQuestion){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	MCQ->AddPossibleAnswer("21.");
	MCQ->AddPossibleAnswer("20.");
	MCQ->AddPossibleAnswer("19.");
	std::cout << "Leave \"A\" prompt unchanged and set to \"true\": " << std::endl;
	MCQ->EditPossibleAnswer();
	std::cout << "Leave \"C\" prompt unchanged and set to \"true\": " << std::endl;
	MCQ->EditPossibleAnswer();
	unsigned Score = MCQ->ScoreQuestion("AC");
	EXPECT_EQ(8, Score);
	delete MCQ;
}

TEST(TestQuestionMCQ, TestPrintQuestion){
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	MCQ->AddPossibleAnswer("21.");
	MCQ->AddPossibleAnswer("20.");
	MCQ->AddPossibleAnswer("19.");
//	MCQ
	delete MCQ;
}

//QuestionFRQ

TEST(TestQuestionFRQ, TestConstructor){
	EXPECT_NO_THROW(QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?"));
}

TEST(TestQuestionFRQ, TestAddPossibleAnswer){
	QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?");
	EXPECT_NO_THROW(FRQ->AddPossibleAnswer("Nothing."));
	delete FRQ;
}

TEST(TestQuestionFRQ, TestEditPossibleAnswer){
	QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?");
	FRQ->AddPossibleAnswer("Nothing.");
	std::cout << "Edit to \"A\": ";
	EXPECT_NO_THROW(FRQ->EditPossibleAnswer());
	unsigned Score = FRQ->ScoreQuestion("A");
	EXPECT_EQ(16, Score);
	delete FRQ;
}

TEST(TestQuestionFRQ, TestScoreQuestiom){
	QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?");
	FRQ->AddPossibleAnswer("Everything.");
	FRQ->EditPossibleAnswer();
	std::cout << "Enter same answer as previous: ";
	std::string Answer;
	std::cin >> Answer;
	std::cout << std::endl;
	unsigned Score = FRQ->ScoreQuestion(Answer);
	EXPECT_EQ(16, Score);
	delete FRQ;
}

TEST(TestQuestionFRQ, TestPrintQuestion){

}
