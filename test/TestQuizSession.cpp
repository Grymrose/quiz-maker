#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "../header/Quiz.hpp"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuizSession.hpp"

// QuizSession Tests

TEST(TestQuizSession, SubmitAnswers) {
    // Create a Quiz with multiple questions
    Quiz aQuiz(1, "Science Quiz");
    auto mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What is the capital of France?");
    aQuiz.AddQuestion(mcqQuestion);
    auto tfQuestion = std::make_shared<QuestionTF>(2, 5, "Is the Earth round?");
    aQuiz.AddQuestion(tfQuestion);

    // Create a QuizSession with the Quiz
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // Submit answers
    std::vector<std::string> answers = {"A", "True"};  // Assuming A is the correct answer for the MCQ
    quizSession.SubmitAnswers(answers);

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 15);
}

TEST(TestQuizSession, GetScore) {
    // Create a Quiz with a single question
    Quiz aQuiz(1, "Math Quiz");
    auto frqQuestion = std::make_shared<QuestionFRQ>(1, 15, "Solve for x: 2x + 5 = 15");
    aQuiz.AddQuestion(frqQuestion);

    // Create a QuizSession with the Quiz
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // Submit answer
    std::vector<std::string> answers = {"5"};
    quizSession.SubmitAnswers(answers);

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 15);
}

TEST(TestQuizSession, GetTimeElapsed) {
    // Create a QuizSession
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(2, "History Quiz");
    QuizSession quizSession(quizPtr);

    // Set and get the time elapsed
    quizSession.SetTimeElapsed(120);  // 2 minutes
    EXPECT_EQ(quizSession.GetTimeElapsed(), 120);
}

TEST(TestQuizSession, SetTimeElapsed) {
    // Create a QuizSession
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(3, "Geography Quiz");
    QuizSession quizSession(quizPtr);

    // Set and get the time elapsed
    quizSession.SetTimeElapsed(180);  // 3 minutes
    EXPECT_EQ(quizSession.GetTimeElapsed(), 180);
}
