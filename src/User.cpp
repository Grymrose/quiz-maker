#include "../header/User.hpp"

User::User(std::string username, std::string password, bool isInstructor)
        : username(username), password(password), isInstructor(isInstructor) {}

bool User::Login(std::string usernameEntered, std::string passwordEntered) {
    return (username == usernameEntered && password == passwordEntered) ? true : false;
}