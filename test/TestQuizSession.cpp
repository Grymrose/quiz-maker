#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "../header/Quiz.hpp"
#include "../header/Question.hpp"
#include "../header/QuestionMCQ.hpp"
#include "../header/QuestionFRQ.hpp"
#include "../header/QuestionTF.hpp"
#include "../header/QuestionOutput.hpp"
#include "../header/QuizSession.hpp"

// QuizSession

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
    std::cout << "Submitting answers:" << std::endl;
    
    // For MCQ question
    std::cout << "For MCQ question, change \"A\" prompt to \"4\" and set to \"true\":" << std::endl;
    mcqQuestion->EditPossibleAnswer();
    
    // For TF question
    std::cout << "For TF question, change \"A\" prompt to \"True\" and set to \"true\":" << std::endl;
    tfQuestion->EditPossibleAnswer();
    
    // For FRQ question
    std::cout << "For FRQ question, enter an explanation (literally type: \"Newton's explanation\"):" << std::endl;
    std::cout << "New correct answer: ";
    std::string frqAnswer;
    std::getline(std::cin, frqAnswer);  // Use std::getline to read the entire line
    answers.push_back(frqAnswer);

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
    std::cout << "Submitting incorrect answer for MCQ question:" << std::endl;
    EXPECT_NO_THROW(quizSession.SubmitAnswers(incorrectAnswer));

    // Check if the score is 0 for an incorrect answer
    EXPECT_EQ(quizSession.GetScore(), 0);

    // Submit correct answer for MCQ question
    std::vector<std::string> correctAnswer = {"4"};
    std::cout << "Submitting correct answer for MCQ question:" << std::endl;
    std::cout << "For MCQ question, change \"A\" prompt to \"4\" and set to \"true\":" << std::endl;
    mcqQuestion->EditPossibleAnswer();
    EXPECT_NO_THROW(quizSession.SubmitAnswers(correctAnswer));

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
