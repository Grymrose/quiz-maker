#include "gtest/gtest.h"
#include "../header/QuestionPool.hpp"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuestionTF.hpp"

TEST(TestPool, TestConstructor){
	EXPECT_NO_THROW(QuestionPool MyQuestionPool);
}

TEST(TestPool, TestGetRandomQuestion){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	EXPECT_NO_THROW(Question * QuestionMystery = MyQuestionPool.GetRandomQuestion());
}

TEST(TestPool, TestGetQuestionByID){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	Question * MyQuestion;
	EXPECT_NO_THROW(MyQuestion = MyQuestionPool.GetQuestionByID(1234));
	EXPECT_EQ(MyQuestion->GetQuestionID(), 1234);
}

TEST(TestPool, TestGetQuestionAmount){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	EXPECT_EQ(MyQuestionPool.GetQuestionAmount(), 2);
}

TEST(TestPool, TestAddQuestionToPool){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	EXPECT_NO_THROW(MyQuestionPool.AddQuestionToPool(MCQ));
	EXPECT_NO_THROW(MyQuestionPool.AddQuestionToPool(FRQ));
}

TEST(TestPool, TestRemoveQuestionFromPool){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	EXPECT_NO_THROW(MyQuestionPool.RemoveQuestionFromPool(1234));
	EXPECT_EQ(MyQuestionPool.GetQuestionAmount(), 1);
}

TEST(TestPool, TestEditQuestionByID){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	MCQ->AddPossibleAnswer("19.");
	MCQ->AddPossibleAnswer("21.");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	MyQuestionPool.PrintAllQuestions();
	EXPECT_NO_THROW(MyQuestionPool.EditQuestionByID(1234));
}

TEST(TestPool, TestPrintAllQuestions){
	QuestionPool MyQuestionPool;
	QuestionMCQ * MCQ = new QuestionMCQ(1234, 8, "What's 9 + 10?");
	QuestionFRQ * FRQ = new QuestionFRQ(5678, 64, "What's Obama's last name?");
	MyQuestionPool.AddQuestionToPool(MCQ);
	MyQuestionPool.AddQuestionToPool(FRQ);
	EXPECT_NO_THROW(MyQuestionPool.PrintAllQuestions());
}
