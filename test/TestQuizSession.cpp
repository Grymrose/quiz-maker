#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "../header/Quiz.hpp"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionOutput.hpp"
#include "../header/QuizSession.hpp"

TEST(TestQuizSession, TestSubmitAnswers) {
    // Create a dummy quiz for the session
    Quiz dummyQuiz(1, "Dummy Quiz");

    // Add MCQ, TF, and FRQ questions to the quiz
    std::vector<Question *> questions;

    QuestionMCQ mcqQuestion(1, 10, "What's 2 + 2?");
    mcqQuestion.AddPossibleAnswer("6");
    mcqQuestion.AddPossibleAnswer("5");
    mcqQuestion.AddPossibleAnswer("5");
    questions.push_back(&mcqQuestion);

    QuestionTF tfQuestion(2, 5, "Is the sky blue?");
    tfQuestion.AddPossibleAnswer("False");
    tfQuestion.AddPossibleAnswer("False");
    questions.push_back(&tfQuestion);

    QuestionFRQ frqQuestion(3, 15, "Explain Newton's second law.");
    questions.push_back(&frqQuestion);

    // Add questions to the quiz
    for (Question *question : questions) {
        dummyQuiz.AddQuestion(question);
    }

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(&dummyQuiz);

    // Submit answers for MCQ, TF, and FRQ questions
    std::vector<std::string> answers = {"4", "True", "Explanation"};

    std::cout << "Submitting answers:" << std::endl;

    // For MCQ question
    std::cout << "For MCQ question, change \"A\" prompt to \"4\" and set to \"true\":" << std::endl;
    mcqQuestion.EditPossibleAnswer();

    // For TF question
    std::cout << "For TF question, change \"A\" prompt to \"True\" and set to \"true\":" << std::endl;
    tfQuestion.EditPossibleAnswer();

    // For FRQ question
    std::cout << "For FRQ question, enter an explanation (literally type: \"Explanation\"):" << std::endl;
    std::cout << "New correct answer: ";
    std::string frqAnswer;
    std::getline(std::cin, frqAnswer);
    answers.push_back(frqAnswer);

    EXPECT_NO_THROW(quizSession.SubmitAnswers(answers));

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 30);
}

TEST(TestQuizSession, TestGetScore) {
    // Create a dummy quiz for the session
    Quiz dummyQuiz(1, "Dummy Quiz");

    // Add an MCQ question to the quiz
    std::vector<Question *> questions;

    QuestionMCQ mcqQuestion(1, 10, "What's 2 + 2?");
    mcqQuestion.AddPossibleAnswer("6");
    mcqQuestion.AddPossibleAnswer("5");
    mcqQuestion.AddPossibleAnswer("5");
    questions.push_back(&mcqQuestion);

    // Add questions to the quiz
    for (Question *question : questions) {
        dummyQuiz.AddQuestion(question);
    }

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(&dummyQuiz);

    // Submit incorrect answer for MCQ question
    std::vector<std::string> incorrectAnswer = {"3"};

    std::cout << "Submitting incorrect answer for MCQ question:" << std::endl;
    EXPECT_NO_THROW(quizSession.SubmitAnswers(incorrectAnswer));

    // Check if the score is 0 for an incorrect answer
    EXPECT_EQ(quizSession.GetScore(), 0);

    // Submit correct answer for MCQ question
    std::vector<std::string> correctAnswer = {"4"};

    std::cout << "Submitting correct answer for MCQ question:" << std::endl;
    std::cout << "For MCQ question, change \"A\" prompt to \"4\" and set to \"true\":" << std::endl;
    mcqQuestion.EditPossibleAnswer();

    EXPECT_NO_THROW(quizSession.SubmitAnswers(correctAnswer));

    // Check if the score is calculated correctly
    EXPECT_EQ(quizSession.GetScore(), 10);
}

TEST(TestQuizSession, TestGetTimeElapsed) {
    // Create a dummy quiz for the session
    Quiz dummyQuiz(1, "Dummy Quiz");

    // Create a QuizSession with the dummy quiz
    QuizSession quizSession(&dummyQuiz);

    // Set time elapsed for the quiz session
    quizSession.SetTimeElapsed(120);

    // Check if the time elapsed is retrieved correctly
    EXPECT_EQ(quizSession.GetTimeElapsed(), 120);
}