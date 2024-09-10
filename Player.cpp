#include "Player.h"
#include "utils.h"


Player::Player()
    : id(0), name("Unknown"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true), rankingPosition(0.0) {}

Player::~Player() {}

void Player::readFromConsole() {
    // ¬вод ID
    while (true) {
        std::cout << "Enter player's ID (positive integer): ";
        //id = InputNum<int>(0, 999999);
        std::cin >> id;
        if (std::cin.fail() || id <= 0 || (std::cin.peek() != '\n')) {
            std::cout << "Invalid input. Please enter a positive integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    std::cin.ignore();

    // им€
    std::cout << "Enter player's name: ";
    std::getline(std::cin, name);

    // возраст
    while (true) {
        std::cout << "Enter player's age (0-120): ";
        std::cin >> age;
        if (std::cin.fail() || age < 0 || age > 120 || (std::cin.peek() != '\n')) {
            std::cout << "Please enter an age between 0 and 120.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    // рейтинг
    while (true) {
        std::cout << "Enter player's rating (0-3000): ";
        std::cin >> rating;
        if (std::cin.fail() || rating < 0 || rating > 3000 || (std::cin.peek() != '\n')) {
            std::cout << "Please enter rating between 0 and 3000.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    // пол
    while (true) {
        char genderInput;
        std::cout << "Enter player's gender (M/F): ";
        std::cin >> genderInput;
        if (genderInput == 'M' || genderInput == 'm') {
            gender = Male;
            break;
        }
        else if (genderInput == 'F' || genderInput == 'f') {
            gender = Female;
            break;
        }
        else {
            std::cout << "Please enter 'M' for Male or 'F' for Female.\n";
        }
    }
    std::cin.ignore();

    // дата регистрации
    std::cout << "Enter registration date (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    // активность
    while (true) {
        int activeInput;
        std::cout << "Is the player active? (1 for Yes, 0 for No): ";
        std::cin >> activeInput;
        if (std::cin.fail() || (activeInput != 0 && activeInput != 1)) {
            std::cout << "Please enter 1 (Yes) or 0 (No).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            isActive = (activeInput == 1);
            break;
        }
    }

    // ¬вод позиции в рейтинге
    while (true) {
        std::cout << "Enter player's ranking position (positive double): ";
        std::cin >> rankingPosition;
        if (std::cin.fail() || rankingPosition < 0.0 || (std::cin.peek() != '\n')) {
            std::cout << "Please enter a positive number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    std::cin.ignore();
}

void Player::displayToConsole() const {
    std::cout << "ID: " << id
        << ", Name: " << name
        << ", Age: " << age
        << ", Rating: " << rating
        << ", Gender: " << (gender == Male ? "Male" : "Female")
        << ", Registration Date: " << registrationDate
        << ", Active: " << (isActive ? "Yes" : "No")
        << ", Ranking Position: " << rankingPosition
        << std::endl;
}

void Player::readFromFile(std::ifstream& inputFile) {
    inputFile >> id;
    inputFile.ignore();
    std::getline(inputFile, name);
    inputFile >> age >> rating;

    char genderChar;
    inputFile >> genderChar;
    gender = (genderChar == 'M' || genderChar == 'm') ? Male : Female;
    inputFile.ignore();

    std::getline(inputFile, registrationDate);
    inputFile >> isActive >> rankingPosition;
    inputFile.ignore();
}

void Player::writeToFile(std::ofstream& outputFile) const {
    outputFile << id << std::endl
        << name << std::endl
        << age << std::endl
        << rating << std::endl
        << (char)gender << std::endl
        << registrationDate << std::endl
        << isActive << std::endl
        << rankingPosition << std::endl;
}
