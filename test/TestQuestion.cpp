#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuestionTF.hpp"

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
	std::cout << "Print Question: " << std::endl;
    EXPECT_NO_THROW(MCQ->PrintQuestion(std::cout));
	delete MCQ;
}

// QuestionTF

TEST(TestQuestionTF, TestConstructor) {
    EXPECT_NO_THROW(QuestionTF * TF = new QuestionTF(5678, 10, "Is the sky blue?"));
}

TEST(TestQuestionTF, TestAddPossibleAnswer) {
    QuestionTF * TF = new QuestionTF(5678, 10, "Is the sky blue?");
    EXPECT_NO_THROW(TF->AddPossibleAnswer("True"));
    EXPECT_NO_THROW(TF->AddPossibleAnswer("False"));
    // Try adding more than 2 answers, it should not allow
    EXPECT_NO_THROW(TF->AddPossibleAnswer("InvalidAnswer"));
    EXPECT_NO_THROW(TF->AddPossibleAnswer("InvalidAnswer2"));

    std::cout << "Final Possible Answers: " << std::endl;
    EXPECT_NO_THROW(TF->PrintPossibleAnswers(std::cout));
    delete TF;
}

TEST(TestQuestionTF, TestEditPossibleAnswer) {
    QuestionTF * TF = new QuestionTF(5678, 10, "Is the sky blue?");
    TF->AddPossibleAnswer("True");
    TF->AddPossibleAnswer("False");
    std::cout << "Change \"True\" prompt to \"Yes\" and set to \"true\": " << std::endl;
    EXPECT_NO_THROW(TF->EditPossibleAnswer());
    unsigned Score = TF->ScoreQuestion("True");
    EXPECT_EQ(10, Score);
    delete TF;
}

TEST(TestQuestionTF, TestScoreQuestion) {
    QuestionTF * TF = new QuestionTF(5678, 10, "Is the sky blue?");
    TF->AddPossibleAnswer("True");
    TF->AddPossibleAnswer("False");
    std::cout << "Leave \"True\" prompt unchanged and set to \"true\": " << std::endl;
    TF->EditPossibleAnswer();
    std::cout << "Leave \"False\" prompt unchanged and set to \"false\": " << std::endl;
    TF->EditPossibleAnswer();
    unsigned Score = TF->ScoreQuestion("True");
    EXPECT_EQ(10, Score);
    delete TF;
}

TEST(TestQuestionTF, TestPrintQuestion) {
    QuestionTF * TF = new QuestionTF(5678, 10, "Is the sky blue?");
    TF->AddPossibleAnswer("True");
    TF->AddPossibleAnswer("False");
    std::cout << "Print Question: " << std::endl;
    EXPECT_NO_THROW(TF->PrintQuestion(std::cout));
    delete TF;
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
	std::cout << "Edit the answer to \"A\"" << std::endl;
	EXPECT_NO_THROW(FRQ->EditPossibleAnswer());
	unsigned Score = FRQ->ScoreQuestion("A");
	EXPECT_EQ(16, Score);
	delete FRQ;
}

TEST(TestQuestionFRQ, TestScoreQuestion){
	QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?");
	FRQ->AddPossibleAnswer("Everything.");
	std::cout << "Edit the answer to \"A\"" << std::endl;
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
    QuestionFRQ * FRQ = new QuestionFRQ(1234, 16, "What happened in 1986?");
    FRQ->AddPossibleAnswer("Everything.");
    std::cout << "Print Question: " << std::endl;
    EXPECT_NO_THROW(FRQ->PrintQuestion(std::cout));
    delete FRQ;
}