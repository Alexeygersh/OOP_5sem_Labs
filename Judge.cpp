#include "Judge.h"
#include "utils.h"

Judge::Judge() : experience(0), level("Unknown") {}

Judge::~Judge() {}

void Judge::readFromConsole() {
    Player::readFromConsole();

    int playerAge = getAge();

    std::cout << "Введите опыт работы судьи (в годах): ";
    experience = InputNum<int>(0, playerAge);

    std::cout << "Введите уровень квалификации\n(Всероссийская = 0| Первая = 1| Вторая = 2| Третья = 3| Юный судья = 4): ";
    int levelInput = InputNum<int>(0, 4);
    switch (levelInput){
        case 0: { level = "Всероссийская"; break; }
        case 1: { level = "Первая"; break; }
        case 2: { level = "Вторая"; break; }
        case 3: { level = "Третья"; break; }
        case 4: { level = "Юный судья"; break; }
    }
        
}

void Judge::displayToConsole() const {
    Player::displayToConsole(); // Сначала выводим данные базового класса
    std::cout << "Опыт работы: " << experience << " лет(года), Уровень квалификации: " << level << std::endl;
}

void Judge::readFromFile(std::ifstream& inputFile) {

    
    inputFile >> experience;
    inputFile.ignore();
    std::getline(inputFile, level);
}

void Judge::writeToFile(std::ofstream& outputFile) const {
    
    outputFile << experience << std::endl
        << level << std::endl;
}