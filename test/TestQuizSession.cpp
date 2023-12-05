#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../header/Quiz.hpp"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuizSession.hpp"

// Mock user input for testing
class MockUserInput {
public:
    MOCK_METHOD(char, GetUserInputChar, (const std::string& prompt), ());
    MOCK_METHOD(std::string, GetUserInputString, (const std::string& prompt), ());
};

TEST(TestQuizSession, SubmitAnswers) {
    MockUserInput userInputMock;

    Quiz aQuiz(1, "Science Quiz");
    auto mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What is the capital of France?");
    mcqQuestion->AddPossibleAnswer("Paris");
    mcqQuestion->AddPossibleAnswer("London");
    mcqQuestion->AddPossibleAnswer("Berlin");
    mcqQuestion->AddPossibleAnswer("Madrid");
    mcqQuestion->AddPossibleAnswer("Rome");
    mcqQuestion->AddPossibleAnswer("True");

    // Mock user input for setting correctness
    EXPECT_CALL(userInputMock, GetCorrectnessFromUser())
        .WillOnce(::testing::Return(true))  // Set "True" as correct
        .WillOnce(::testing::Return(false));

    mcqQuestion->EditPossibleAnswer();  // Use EditPossibleAnswer() to set correctness
    mcqQuestion->EditPossibleAnswer();

    aQuiz.AddQuestion(mcqQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // Set up expectations for user input
    EXPECT_CALL(userInputMock, GetUserInputString(::testing::_))
        .WillOnce(::testing::Return("Paris"))
        .WillOnce(::testing::Return("True"));

    // Inject the mock into the QuizSession
    quizSession.SetUserInputMock(&userInputMock);

    std::vector<std::string> answers = {"Paris", "True"};
    quizSession.SubmitAnswers(answers);

    // The expected score is calculated based on the percentage of correct answers
    // The question has 2 correct answers out of 6 total options, so the expected score is 5.
    EXPECT_EQ(quizSession.GetScore(), 5);
}

TEST(TestQuizSession, GetScore) {
    Quiz aQuiz(1, "Math Quiz");
    auto frqQuestion = std::make_shared<QuestionFRQ>(1, 15, "Solve for x: 2x + 5 = 15");
    frqQuestion->SetCorrectAnswer("5");
    aQuiz.AddQuestion(frqQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // For a free-response question, the entire score is awarded if the answer is correct
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
