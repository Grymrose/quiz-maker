#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "../header/User.hpp"
#include "../header/Instructor.hpp"
#include "../header/Student.hpp"
#include "../header/Quiz.hpp"
#include "../header/QuizSession.hpp"

//  User Tests

TEST(TestUser, LoginSuccess) {
    User aUser("Artoria", "Pendragon", true);
    std::vector<User> users;
    users.push_back(aUser);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Artoria", "Pendragon")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_TRUE(loggedIn==true);
}

TEST(TestUser, LoginFail) {
    User aUser("Artoria", "Pendragon", true);
    std::vector<User> users;
    users.push_back(aUser);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Mordred", "Pendragon")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

//  Instructor Tests

TEST(TestInstructor, LoginSuccess) {
    Instructor aInstructor("Kiritsugu", "Emiya", true);
    std::vector<User> users;
    users.push_back(aInstructor);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Kiritsugu", "Emiya")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_TRUE(loggedIn==true);
}

TEST(TestInstructor, LoginFail) {
    Instructor aInstructor("Kiritsugu", "Emiya", true);
    std::vector<User> users;
    users.push_back(aInstructor);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Kirei", "Kotomine")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

TEST(TestInstructor, AddAndGetQuiz) {
    Instructor aInstructor("Kiritsugu", "Emiya", true);
    Quiz aQuiz;
    aInstructor.AddQuiz(aQuiz);
    std::vector<Quiz> quizzes = aInstructor.GetQuizzes();
    ASSERT_EQ(quizzes.size(), 1);
    EXPECT_TRUE(quizzes.at(0) == aQuiz);
}

//  Student Tests

TEST(TestStudent, LoginSuccess) {
    Student aStudent("Shirou", "Emiya", true);
    std::vector<User> users;
    users.push_back(aStudent);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Shirou", "Emiya")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_TRUE(loggedIn==true);
}

TEST(TestStudent, LoginFail) {
    Student aStudent("Shirou", "Emiya", true);
    std::vector<User> users;
    users.push_back(aStudent);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user.Login("Rin", "Tohsaka")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

TEST(TestStudent, JoinClass) {
    Student aStudent("Shirou", "Emiya", true);
    EXPECT_FALSE(aStudent.HasInstructor());
    aStudent.JoinClass("Pendragon");
    EXPECT_TRUE(aStudent.HasInstructor()); 
}

TEST(TestStudent, AddQuizzes) {
    Student aStudent("Shirou", "Emiya", true);
    Quiz quiz1, quiz2;
    std::vector<Quiz> quizzes = {quiz1, quiz2};
    aStudent.AddQuizzes(quizzes);
    ASSERT_EQ(aStudent.ViewAvailableQuizzes().size(), 2);
}

TEST(TestStudent, AddTakenQuiz) {
    Student aStudent("Shirou", "Emiya", true);
    QuizSession takenQuiz;
    aStudent.AddTakenQuiz(takenQuiz);
    ASSERT_EQ(aStudent.ViewCompletedQuizzes().size(), 1);
}