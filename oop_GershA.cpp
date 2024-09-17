#include "PlayerContainer.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>

int main() {

    setlocale(LC_ALL, "");
    std::system("chcp 1251");

    PlayerContainer container;
    int choice;

    do {
        std::cout << "Система шахматного турнира\n";
        std::cout << "1. Добавить игрока\n";
        std::cout << "2. Вывести всех игроков\n";
        std::cout << "3. Загрузить игроков из файла\n";
        std::cout << "4. Сохранить игроков в файл\n";
        std::cout << "5. Очистить всех игроков\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите ваш выбор: ";
        choice = InputNum<int>(0, 5);
        
        switch (choice) {
        case 1: {
            container.addPlayer();
            break;
        }
        case 2: {
            container.displayPlayers();
            break;
        }
            
        case 3: {
            std::string filename;
            std::cout << "Введите название файла: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, filename);
            container.readFromFile(filename);
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Введите название файла: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, filename);
            container.writeToFile(filename);
            break;
        }
        case 5:
            container.clearPlayers();
            break;
        case 0:
            exit(0);
            break;
        default:
            std::cout << "Неверный выбор! Повторите ввод.\n";
        }
    } while (choice != 0);

    return 0;
}
