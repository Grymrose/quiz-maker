#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "../header/Quiz.hpp"
#include "../header/Question.hpp"

// Quiz Tests

TEST(TestQuiz, AddQuestion) {
    Quiz aQuiz(0, "Test Quiz");
    std::shared_ptr<Question> question1 = std::make_shared<Question>(1, 10, "What is the capital of France?");
    std::shared_ptr<Question> question2 = std::make_shared<Question>(2, 5, "Who wrote Hamlet?");
    aQuiz.AddQuestion(question1);
    aQuiz.AddQuestion(question2);
    ASSERT_EQ(aQuiz.GetQuestions().size(), 2);
}

TEST(TestQuiz, SetAvailability) {
    Quiz aQuiz(0, "Test Quiz");
    aQuiz.setAvailability(false);
    EXPECT_FALSE(aQuiz.IsAvailable());
}

TEST(TestQuiz, SetAttempts) {
    Quiz aQuiz(0, "Test Quiz");
    aQuiz.setAttempts(3);
    EXPECT_EQ(aQuiz.GetAttempts(), 3);
}

TEST(TestQuiz, GetQuizID) {
    Quiz aQuiz(42, "Special Quiz");
    EXPECT_EQ(aQuiz.GetQuizID(), 42);
}

TEST(TestQuiz, GetTitle) {
    Quiz aQuiz(0, "English Quiz");
    EXPECT_EQ(aQuiz.GetTitle(), "English Quiz");
}

TEST(TestQuiz, DefaultTitle) {
    Quiz aQuiz(0);
    EXPECT_EQ(aQuiz.GetTitle(), "Untitled");
}

TEST(TestQuiz, DefaultAvailability) {
    Quiz aQuiz(0);
    EXPECT_TRUE(aQuiz.IsAvailable());
}

TEST(TestQuiz, DefaultAttempts) {
    Quiz aQuiz(0);
    EXPECT_EQ(aQuiz.GetAttempts(), -1);
}
