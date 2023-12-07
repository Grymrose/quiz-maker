#include "../header/MainMenu.hpp"

MainMenu::MainMenu() : isSignedIn(false), userID(0) {}

int main() {
    MainMenu mainMenu;
    int choice;

    do {
        mainMenu.DisplayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case 1:
                mainMenu.CreateQuiz();
                break;
            case 2:
                mainMenu.EditQuiz();
                break;
            case 3:
                mainMenu.TakeQuiz();
                break;
            case 4:
                mainMenu.AddUser();
                break;
            case 5:
                mainMenu.UserLogin();
                break;
            case 6:
                mainMenu.UserLogout();
                break;
            case 7:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 7);

    return 0;
}

void MainMenu::DisplayMenu() {
    std::cout << "=== Main Menu ===" << std::endl;
    std::cout << "1. Create Quiz" << std::endl;
    std::cout << "2. Edit Quiz" << std::endl;
    std::cout << "3. Take Quiz" << std::endl;
    std::cout << "4. Add User" << std::endl;
    std::cout << "5. User Login" << std::endl;
    std::cout << "6. User Logout" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "=================" << std::endl;
}

void MainMenu::CreateQuiz() {
    // Implement the creation of a quiz
    // Example: Let's assume an instructor is signed in to create a quiz
    if (isSignedIn) {
        Instructor* instructor = dynamic_cast<Instructor*>(&users[userID]);
        if (instructor) {
            std::string title;
            std::cout << "Enter the title of the quiz: ";
            std::getline(std::cin, title);

            Quiz newQuiz(users.size(), title);
            instructor->AddQuiz(newQuiz);

            std::cout << "Quiz created successfully." << std::endl;
        } else {
            std::cout << "Only instructors can create quizzes." << std::endl;
        }
    } else {
        std::cout << "Please sign in to create a quiz." << std::endl;
    }
}

void MainMenu::EditQuiz() {
    // Implement the editing of a quiz
    // Example: Let's assume an instructor is signed in to edit a quiz
    if (isSignedIn) {
        Instructor* instructor = dynamic_cast<Instructor*>(&users[userID]);
        if (instructor) {
            // Assume the instructor selects a quiz to edit
            std::vector<Quiz> quizzes = instructor->GetQuizzes();
            if (!quizzes.empty()) {
                std::cout << "Select a quiz to edit:" << std::endl;
                for (size_t i = 0; i < quizzes.size(); ++i) {
                    std::cout << i + 1 << ". " << quizzes[i].GetTitle() << std::endl;
                }

                unsigned int selection;
                std::cout << "Enter the number of the quiz: ";
                std::cin >> selection;

                if (selection > 0 && selection <= quizzes.size()) {
                    // Assume the instructor edits the selected quiz
                    quizzes[selection - 1].setAvailability(false);
                    quizzes[selection - 1].setAttempts(2);

                    std::cout << "Quiz edited successfully." << std::endl;
                } else {
                    std::cout << "Invalid selection." << std::endl;
                }
            } else {
                std::cout << "No quizzes available to edit." << std::endl;
            }
        } else {
            std::cout << "Only instructors can edit quizzes." << std::endl;
        }
    } else {
        std::cout << "Please sign in to edit a quiz." << std::endl;
    }
}

void MainMenu::TakeQuiz() {
    // Implement the process of taking a quiz
    // Example: Let's assume a student is signed in to take a quiz
    if (isSignedIn) {
        Student* student = dynamic_cast<Student*>(&users[userID]);
        if (student) {
            // Assume the student selects a quiz to take
            std::vector<Quiz> quizzes = student->ViewAvailableQuizzes();
            if (!quizzes.empty()) {
                std::cout << "Select a quiz to take:" << std::endl;
                for (size_t i = 0; i < quizzes.size(); ++i) {
                    std::cout << i + 1 << ". " << quizzes[i].GetTitle() << std::endl;
                }

                unsigned int selection;
                std::cout << "Enter the number of the quiz: ";
                std::cin >> selection;

                if (selection > 0 && selection <= quizzes.size()) {
                    // Assume the student takes the selected quiz
                    QuizSession quizSession(&quizzes[selection - 1]);
                    quizSession.SubmitAnswers({"A", "True", "Explanation"});

                    student->AddTakenQuiz(quizSession);

                    std::cout << "Quiz taken successfully." << std::endl;
                } else {
                    std::cout << "Invalid selection." << std::endl;
                }
            } else {
                std::cout << "No quizzes available to take." << std::endl;
            }
        } else {
            std::cout << "Only students can take quizzes." << std::endl;
        }
    } else {
        std::cout << "Please sign in to take a quiz." << std::endl;
    }
}

void MainMenu::AddUser() {
    // Implement the addition of a user
    std::string username, password;
    char userType;

    std::cout << "Enter the username: ";
    std::getline(std::cin, username);

    std::cout << "Enter the password: ";
    std::getline(std::cin, password);

    std::cout << "Enter the user type (I for instructor, S for student): ";
    std::cin >> userType;

    if (userType == 'I' || userType == 'i') {
        users.push_back(Instructor(username, password, true));
        std::cout << "Instructor added successfully." << std::endl;
    } else if (userType == 'S' || userType == 's') {
        users.push_back(Student(username, password, false));
        std::cout << "Student added successfully." << std::endl;
    } else {
        std::cout << "Invalid user type." << std::endl;
    }
}

void MainMenu::UserLogin() {
    // Implement the user login
    std::string username, password;
    std::cout << "Enter the username: ";
    std::getline(std::cin, username);

    std::cout << "Enter the password: ";
    std::getline(std::cin, password);

    bool loggedIn = false;

    for (unsigned int i = 0; i < users.size(); ++i) {
        if (users[i].Login(username, password)) {
            isSignedIn = true;
            userID = i;
            loggedIn = true;
            break;
        }
    }

    if (loggedIn) {
        std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
    } else {
        std::cout << "Login failed. Incorrect username or password." << std::endl;
    }
}

void MainMenu::UserLogout() {
    // Implement the user logout
    isSignedIn = false;
    std::cout << "Logout successful. Goodbye!" << std::endl;
}