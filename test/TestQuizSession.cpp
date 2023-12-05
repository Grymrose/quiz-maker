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

TEST(TestQuizSession, SubmitAnswers) {
    Quiz aQuiz(1, "Science Quiz");
    auto mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What is the capital of France?");
    aQuiz.AddQuestion(mcqQuestion);
    auto tfQuestion = std::make_shared<QuestionTF>(2, 5, "Is the Earth round?");
    aQuiz.AddQuestion(tfQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    std::vector<std::string> answers = {"Paris", "True"};
    quizSession.SubmitAnswers(answers);

    EXPECT_EQ(quizSession.GetScore(), 15);
}

TEST(TestQuizSession, GetScore) {
    Quiz aQuiz(1, "Math Quiz");
    auto frqQuestion = std::make_shared<QuestionFRQ>(1, 15, "Solve for x: 2x + 5 = 15");
    aQuiz.AddQuestion(frqQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    std::vector<std::string> answers = {"5"};
    quizSession.SubmitAnswers(answers);

    EXPECT_EQ(quizSession.GetScore(), 15);
}

TEST(TestQuizSession, GetTimeElapsed) {
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(2, "History Quiz");
    QuizSession quizSession(quizPtr);

    quizSession.SetTimeElapsed(120);  // 2 minutes
    EXPECT_EQ(quizSession.GetTimeElapsed(), 120);
}

TEST(TestQuizSession, SetTimeElapsed) {
    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(3, "Geography Quiz");
    QuizSession quizSession(quizPtr);

    quizSession.SetTimeElapsed(180);  // 3 minutes
    EXPECT_EQ(quizSession.GetTimeElapsed(), 180);
}
