#ifndef _QUIZ_CUSTOMIZATION_HEADER
#define _QUIZ_CUSTOMIZATION_HEADER

#include <string>

class QuizCustomization{
private:
    int MCQAmounts;
    int FRQAmounts;
    int TFAmounts;
public:
    void RecordMCQAmounts();
    void RecordFRQAmounts();
    void RecordTFAmounts();
};

#endif