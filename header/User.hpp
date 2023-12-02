#ifndef __USER_HEADER__
#define __USER_HEADER__

#include <string>

class User {
    protected:
        std::string username;
        std::string password;
    public:
        User(std::string username, std::string password)
                    : username(username), password(password) {}
        void Login(usernameEntered, passwordEntered);
        void Logout();
}

#endif