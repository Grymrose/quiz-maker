#ifndef __USER_HEADER__
#define __USER_HEADER__

#include <string>

class User {
    protected:
        std::string username;
        std::string password;
        bool isInstructor;
    public:
        User(std::string username, std::string password, bool isInstructor);
        bool Login(usernameEntered, passwordEntered);
}

#endif