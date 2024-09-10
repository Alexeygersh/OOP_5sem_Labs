#include "Player.h"
#include <iostream>
#include <fstream>


Player::Player()
    : id(0), name("Unknown"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true), rankingPosition(0.0) {}

Player::~Player() {}

void Player::readFromConsole() {
    std::cout << "Enter player's ID: ";
    std::cin >> id;
    std::cin.ignore();

    std::cout << "Enter player's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter player's age: ";
    std::cin >> age;

    std::cout << "Enter player's rating: ";
    std::cin >> rating;

    char genderInput;
    std::cout << "Enter player's gender (M/F): ";
    std::cin >> genderInput;
    gender = (genderInput == 'M' || genderInput == 'm') ? Male : Female;
    std::cin.ignore();

    std::cout << "Enter registration date (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "Is the player active? (1 for Yes, 0 for No): ";
    std::cin >> isActive;

    std::cout << "Enter player's ranking position: ";
    std::cin >> rankingPosition;
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
