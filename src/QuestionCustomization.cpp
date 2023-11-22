#include "../header/QuizCustomization.hpp"
#include <iostream>

void QuizCustomization::RecordFRQAmounts(){
    std::cout << "Enter the total numbers of FRQ:" << std::endl;
    std::cin >> FRQAmounts;
}

void QuizCustomization::RecordMCQAmounts(){
    std::cout << "Enter the total numbers of MCQ:" << std::endl;
    std::cin >> MCQAmounts;
}

void QuizCustomization::RecordTFAmounts(){
    std::cout << "Enter the total numbers of TF:" << std::endl;
    std::cin >> TFAmounts;
}