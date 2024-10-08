#include "OnlinePlayer.h"
#include "utils.h"

OnlinePlayer::OnlinePlayer() : virtual_name("unknown"), email("unknown@gmail.com") {}

OnlinePlayer::~OnlinePlayer() {}

void OnlinePlayer::readFromConsole() {
    Player::readFromConsole();

    //int playerAge = getAge();

    //std::cout << "Введите опыт работы судьи (в годах): ";
    //experience = InputNum<int>(0, playerAge);
    std::cout << "Введите ник: ";
    std::cin.ignore();
    std::getline(std::cin, virtual_name);

    std::cout << "Введите адрес почты: ";
    std::cin.ignore();
    std::getline(std::cin, email);

    std::cout << "Введите номер телефона в виде 9991010010: (+7)";
    tel = InputNum<unsigned long long int>(1000000000, 9999999999);
    /*std::cout << "Введите уровень квалификации\n(Всероссийская = 0| Первая = 1| Вторая = 2| Третья = 3| Юный судья = 4): ";
    int levelInput = InputNum<int>(0, 4);
    switch (levelInput){
        case 0: { level = "Всероссийская"; break; }
        case 1: { level = "Первая"; break; }
        case 2: { level = "Вторая"; break; }
        case 3: { level = "Третья"; break; }
        case 4: { level = "Юный судья"; break; }
    }*/



        
}

void OnlinePlayer::displayToConsole() const {
    Player::displayToConsole(); // Сначала выводим данные базового класса
    std::cout << "Ник пользователя: " << virtual_name << ", Адрес почты: " << email << ", Номер телефона: +7" << tel << std::endl;
}

void OnlinePlayer::readFromFile(std::ifstream& inputFile) {

    inputFile.ignore();
    std::getline(inputFile, virtual_name);
    
    inputFile.ignore();
    std::getline(inputFile, email);

    inputFile >> tel;
}

void OnlinePlayer::writeToFile(std::ofstream& outputFile) const {
    
    outputFile << virtual_name << std::endl
        << email << std::endl
        << tel << std::endl;
}