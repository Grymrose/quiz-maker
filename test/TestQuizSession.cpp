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

TEST(TestQuizSession, TestConstructor) {
    // Create a dummy quiz for the session
    std::shared_ptr<Quiz> dummyQuiz = std::make_shared<Quiz>(1, "Dummy Quiz");

    // Check if the QuizSession constructor works without errors
    EXPECT_NO_THROW(QuizSession quizSession(dummyQuiz));
}

TEST(TestQuizSession, TestSubmitAnswers) {
    // Create a dummy quiz for the session
    std::shared_ptr<Quiz> dummyQuiz = std::make_shared<Quiz>(1, "Dummy Quiz");

    // Add MCQ, TF, and FRQ questions to the quiz
    std::shared_ptr<QuestionMCQ> mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What's 2 + 2?");
    mcqQuestion->AddPossibleAnswer("3");
    mcqQuestion->AddPossibleAnswer("4");
    mcqQuestion->AddPossibleAnswer("5");
    dummyQuiz->AddQuestion(mcqQuestion);

    std::shared_ptr<QuestionTF> tfQuestion = std::make_shared<QuestionTF>(2, 5, "Is the sky blue?");
    tfQuestion->AddPossibleAnswer("True");
    tfQuestion->AddPossibleAnswer("False");
    dummyQuiz->AddQuestion(tfQuestion);

    std::shared_ptr<QuestionFRQ> frqQuestion = std::make_shared<QuestionFRQ>(3, 15, "Explain Newton's second law.");
    dummyQuiz->AddQuestion(frqQuestion);

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(dummyQuiz);

    // Submit answers for MCQ, TF, and FRQ questions
    std::vector<std::string> answers = {"4", "True", "Newton's explanation"};
    EXPECT_NO_THROW(quizSession.SubmitAnswers(answers));

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 30);
}

TEST(TestQuizSession, TestGetScore) {
    // Create a dummy quiz for the session
    std::shared_ptr<Quiz> dummyQuiz = std::make_shared<Quiz>(1, "Dummy Quiz");

    // Add an MCQ question to the quiz
    std::shared_ptr<QuestionMCQ> mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What's 2 + 2?");
    mcqQuestion->AddPossibleAnswer("3");
    mcqQuestion->AddPossibleAnswer("4");
    mcqQuestion->AddPossibleAnswer("5");
    dummyQuiz->AddQuestion(mcqQuestion);

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(dummyQuiz);

    // Submit incorrect answer for MCQ question
    std::vector<std::string> incorrectAnswer = {"3"};
    quizSession.SubmitAnswers(incorrectAnswer);

    // Check if the score is 0 for incorrect answer
    EXPECT_EQ(quizSession.GetScore(), 0);

    // Submit correct answer for MCQ question
    std::vector<std::string> correctAnswer = {"4"};
    quizSession.SubmitAnswers(correctAnswer);

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 10);
}

TEST(TestQuizSession, TestGetTimeElapsed) {
    // Create a dummy quiz for the session
    std::shared_ptr<Quiz> dummyQuiz = std::make_shared<Quiz>(1, "Dummy Quiz");

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(dummyQuiz);

    // Set time elapsed for the quiz session
    quizSession.SetTimeElapsed(120);

    // Check if the time elapsed is retrieved correctly
    EXPECT_EQ(quizSession.GetTimeElapsed(), 120);
}

