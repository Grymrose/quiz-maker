void SubmitAnswers(std::vector<std::string> inputAnswers) {
    answers.insert(answers.end(), inputAnswers.begin(), inputAnswers.end());
}

int GetScore() {
    return 1;
}

int GetTimeElapsed() {
    return 1;
}