#include "../header/MainMenu.hpp"

MainMenu::MainMenu() : isSignedIn(false), instructorID(0), studentID(0) {}

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

MainMenu::~MainMenu() { // Clean up dynamically allocated memory for users
    for (Instructor* instructor : instructors) {
        delete instructor;
    }
    for (Student* student : students) {
        delete student;
    }
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
    if (isSignedIn) {
        Instructor* instructor = instructors[instructorID];
        if (instructor) {
            std::string title;
            std::cout << "Enter the title of the quiz: ";
            std::getline(std::cin, title);

            Quiz newQuiz(instructors.size(), title);
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
    if (isSignedIn) {
        if (instructors[instructorID]->getIsInstructorBoolean()) {
            std::vector<Quiz>& quizzes = instructors[instructorID]->GetQuizzes();

            if (!quizzes.empty()) {
                std::cout << "Select a quiz to edit:" << std::endl;
                for (size_t i = 0; i < quizzes.size(); ++i) {
                    std::cout << i + 1 << ". " << quizzes[i].GetTitle() << std::endl;
                }

                unsigned int selection;
                std::cout << "Enter the number of the quiz: ";
                std::cin >> selection;

                if (selection > 0 && selection <= quizzes.size()) {
                    Question* newQuestion = new QuestionMCQ();  // Replace with appropriate Question type
                    quizzes[selection - 1].AddQuestion(newQuestion);

                    std::cout << "Question added to the quiz." << std::endl;
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
    if (isSignedIn) {
        Student* student = students[studentID];
        if (student) {
            // ViewAvailableQuizzes() returns a copy, not a reference
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
    std::string username, password;
    char userType;

    std::cout << "Enter the username: ";
    std::getline(std::cin, username);

    std::cout << "Enter the password: ";
    std::getline(std::cin, password);

    std::cout << "Enter the user type (I for instructor, S for student): ";
    std::cin >> userType;

    if (userType == 'I' || userType == 'i') {
        instructors.push_back(new Instructor(username, password, true));
        std::cout << "Instructor added successfully." << std::endl;
    } else if (userType == 'S' || userType == 's') {
        students.push_back(new Student(username, password, false));
        std::cout << "Student added successfully." << std::endl;
    } else {
        std::cout << "Invalid user type." << std::endl;
    }
}

void MainMenu::UserLogin() {
    std::string username, password;
    std::cout << "Enter the username: ";
    std::getline(std::cin, username);

    std::cout << "Enter the password: ";
    std::getline(std::cin, password);

    bool loggedIn = false;

    for (unsigned int i = 0; i < instructors.size(); ++i) {
        if (instructors[i]->Login(username, password)) {
            isSignedIn = true;
            instructorID = i;
            loggedIn = true;
            studentID = 0;  // Reset studentID when an instructor logs in
            break;
        }
    }

    if (!loggedIn) {
        for (unsigned int i = 0; i < students.size(); ++i) {
            if (students[i]->Login(username, password)) {
                isSignedIn = true;
                studentID = i;
                loggedIn = true;
                instructorID = 0;  // Reset instructorID when a student logs in
                break;
            }
        }
    }

    if (loggedIn) {
        std::cout << "Login successful. Welcome, " << username << "!" << std::endl;
    } else {
        std::cout << "Login failed. Incorrect username or password." << std::endl;
    }
}

void MainMenu::UserLogout() {
    isSignedIn = false;
    instructorID = 0;
    studentID = 0;
    std::cout << "Logout successful. Goodbye!" << std::endl;
}