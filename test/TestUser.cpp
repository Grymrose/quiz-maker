#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "../header/User.hpp"
#include "../header/Instructor.hpp"
#include "../header/Student.hpp"
#include "../header/Quiz.hpp"

TEST(TestUser, LoginSuccess) {
    User aUser("Artoria", "Pendragon", true);
    std::vector<User> users;
    users.push_back(aUser);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user->Login("Artoria", "Pendragon")) {
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
        if (user->Login("Mordred", "Pendragon")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

TEST(TestInstructor, LoginSuccess) {
    Instructor aInstructor("Kiritsugu", "Emiya", true);
    std::vector<User> users;
    users.push_back(aInstructor);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user->Login("Kiritsugu", "Emiya")) {
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
        if (user->Login("Kirei", "Kotomine")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

TEST(TestInstructor, ?) {

}

TEST(TestStudent, LoginSuccess) {
    Student aStudent("Shirou", "Emiya", true);
    std::vector<User> users;
    users.push_back(aStudent);
    bool loggedIn = false;
    for (auto& user: users) {
        if (user->Login("Shirou", "Emiya")) {
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
        if (user->Login("Rin", "Tohsaka")) {
            loggedIn = true;
            break;
        }
    }
    EXPECT_FALSE(loggedIn==true);
}

TEST(TestStudent, ?) {

}

TEST(TestStudent, ?) {

}

TEST(TestStudent, ?) {

}