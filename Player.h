#pragma once
#include <iostream>
#include <fstream>
#include <string>


// Определение перечисления для пола
enum Gender {
    Male = 'М',
    Female = 'Ж'
};

class Player {
private:
    int id;
    std::string name;
    int age;
    int rating;
    Gender gender;
    std::string registrationDate;
    bool isActive;
    double rankingPosition;

public:
    Player(); // Конструктор
    ~Player(); // Деструктор

    // Функции для работы с атрибутами
    void readFromConsole();
    void displayToConsole() const;
    void readFromFile(std::ifstream& inputFile);
    void writeToFile(std::ofstream& outputFile) const;
};
