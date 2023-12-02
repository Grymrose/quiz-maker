#include <string>

class User {
    protected:
        std::string username;
        std::string password;
    public:
        void Login(username, password);
        void Logout();
}