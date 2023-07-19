#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json/json.h"

struct Question {
    std::string question;
    std::string answer;
};

void loadQuestions(const std::string& filename, std::vector<Question>& questions) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the file: " filename << std::endl;
        return;
    }

    Json::Value root;
    file >> root;

    for (const auto& questionJson : root) {
        Question question;
        question.question = questionJson["question"].asString();
        question.answer = questionJson["answer"].asString();
        questions.push_back(question);
    }

    file.close();
}

void saveWrongAnswers(const std::string& filename, const std::vector<Question>& wrongAnswers) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cout << "Failed to open the file: " << filename << std::endl;
        return;
    }

    for (const auto& question : wrongAnswers) {
        file << "Question: " << question.question << std::endl;
        file << "Answer: " << question.answer << std::endl;
        file << std::endl;
    }

    file.close();
}

int main() {
 std::string filename = "questions.json";
    std::vector<Question> questions;
    std::vector<Question> wrongAnswers;

    loadQuestions(filename, questions);

    for (const auto& question : questions) {
        std::cout << "Question: " << question.question << std::endl;
        std::string userInput;
        std::cin >> userInput;

        if (userInput == "y") {
            // User knows the answer, move to the next question.
            continue;
        } else if (userInput == "n") {
            // User doesn't know the answer, display the correct answer and record it as a wrong answer.
            std::cout << "Answer: " << question.answer << std::endl;
            wrongAnswers.push_back(question);
        } else {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    }

    if (!wrongAnswers.empty()) {
        std::string wrongAnswersFilename = "wrong_answers.txt";
        saveWrongAnswers(wrongAnswersFilename, wrongAnswers);
        std::cout << "Wrong answers have been saved to: " << wrongAnswersFilename << std::endl;
    }

    return 0;
}
