#include "Player.h"
#include "utils.h"


Player::Player()
    : id(0), name("Неизвестно"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true), rankingPosition(0.0) {}

Player::~Player() {}

void Player::readFromConsole() {
    std::cout << "Введите ID игрока (положительное целочисленое): ";

    id = InputNum<int>(0, 9999);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите имя игрока: ";
    std::getline(std::cin, name);
    
    std::cout << "Введите возраст игрока (0-120): ";
    age = InputNum<int>(0, 120);

    std::cout << "Введите рейтинг игрока (0-3000): ";
    rating = InputNum<int>(0, 3000);

    std::cout << "Введите пол | '0' для Мужского пола или '1' для женского: ";
    bool genderInput = InputNum<bool>(0, 1);
    gender = (genderInput == 0) ? Male : Female;

    std::cin.ignore();

    std::cout << "Введите дату регистрации (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "Игрок активен в данный момент? (1 - да, 0 - нет): ";
    isActive = InputNum<bool>(0, 1);

    std::cout << "Введите позицию игрока на турнире: ";
    rankingPosition = InputNum<double>(0, 500);
    std::cin.ignore();
}

void Player::displayToConsole() const {
    std::cout << "ID: " << id
        << ", Имя: " << name
        << ", Возраст: " << age
        << ", Рейтинг: " << rating
        << ", Пол: " << (gender == Male ? "М" : "Ж")
        << ", Дата регистрации: " << registrationDate
        << ", Активен?: " << (isActive ? "Да" : "Нет")
        << ", Позиция на турнире: " << rankingPosition
        << std::endl;
}

void Player::readFromFile(std::ifstream& inputFile) {
    inputFile >> id;
    inputFile.ignore();
    std::getline(inputFile, name);
    inputFile >> age >> rating;

    char genderChar;
    inputFile >> genderChar;
    gender = (genderChar == '1') ? Male : Female;
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
