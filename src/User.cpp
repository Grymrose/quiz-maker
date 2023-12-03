#include "../header/User.hpp"

User::User(std::string username, std::string password, bool isInstructor)
        : username(username), password(password), isInstructor(isInstructor) {}

bool User::Login(usernameEntered, passwordEntered) {
    (username == usernameEntered && password == passwordEntered) ? return true : return false;
}