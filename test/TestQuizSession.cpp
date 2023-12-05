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

// Helper function to simulate user input for correctness
bool GetUserInputCorrectness() {
    std::string input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    while (true) {
        if (input == "1") {
            return true;
        } else if (input == "0") {
            return false;
        } else if (input != "SKIP" && input != "skip") {
            std::cout << "Bad entry. Only use 0, 1, or \"SKIP\"!" << std::endl;
        }
        input = QuestionOutput::GetUserInputString("Correctness state (1 for true, 0 for false, \"SKIP\" to keep original): ");
    }
    return false;
}

// Test QuizSession for multiple-choice question (MCQ)
TEST(TestQuizSession, SubmitAnswersMCQ) {
    // Create a quiz with an MCQ
    Quiz aQuiz(1, "Science Quiz");
    auto mcqQuestion = std::make_shared<QuestionMCQ>(1, 10, "What is the capital of France?");
    mcqQuestion->AddPossibleAnswer("Paris");
    mcqQuestion->AddPossibleAnswer("London");
    mcqQuestion->AddPossibleAnswer("Berlin");
    mcqQuestion->AddPossibleAnswer("Madrid");
    mcqQuestion->EditPossibleAnswer();
    mcqQuestion->AddPossibleAnswer("Rome");
    aQuiz.AddQuestion(mcqQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // Simulate user input for MCQ correctness
    bool mcqCorrectness = GetUserInputCorrectness();
    mcqQuestion->GetPossibleAnswers()->Correctness = mcqCorrectness;

    // The student answers "Paris"
    std::vector<std::string> answers = {"Paris"};
    quizSession.SubmitAnswers(answers);

    // The expected score is 10 if the MCQ answer is correct
    EXPECT_EQ(quizSession.GetScore(), mcqCorrectness ? 10 : 0);
}

// Test QuizSession for free-response question (FRQ)
TEST(TestQuizSession, SubmitAnswersFRQ) {
    // Create a quiz with an FRQ
    Quiz aQuiz(1, "Math Quiz");
    auto frqQuestion = std::make_shared<QuestionFRQ>(1, 15, "Solve for x: 2x + 5 = 15");
    frqQuestion->AddPossibleAnswer("5");
    aQuiz.AddQuestion(frqQuestion);

    std::shared_ptr<Quiz> quizPtr = std::make_shared<Quiz>(aQuiz);
    QuizSession quizSession(quizPtr);

    // The student answers "5"
    std::vector<std::string> answers = {"5"};
    quizSession.SubmitAnswers(answers);

    // The expected score is 15 if the FRQ answer is correct
    EXPECT_EQ(quizSession.GetScore(), 15);
}

// Add more tests as needed for different question types or scenarios

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
