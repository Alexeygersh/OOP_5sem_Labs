#include "PlayerContainer.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <boost/serialization/export.hpp>

int main() {

    setlocale(LC_ALL, "");
    std::system("chcp 1251");
    //std::locale::global(std::locale("rus_rus.866"));
    //wcin.imbue(std::locale());
    //wcout.imbue(std::locale());


    PlayerContainer container;
    int choice;

    do {
        std::cout << "������� ���������� �������\n";
        std::cout << "1. �������� ������\n";
        std::cout << "2. �������� ������ ������\n";
        std::cout << "3. ������� ���� �������\n";
        std::cout << "4. ��������� ������� �� �����\n";
        std::cout << "5. ��������� ������� � ����\n";
        std::cout << "6. �������� ���� �������\n";
        std::cout << "0. �����\n";
        std::cout << "������� ��� �����: ";
        choice = InputNum<int>(0, 6);
        
        switch (choice) {
        case 1: {
            container.addPlayer();
            break;
        }
        case 2: {
            container.addOnlinePlayer();
            break;
        }
        case 3: {
            container.displayPlayers();
            break;
        }
            
        case 4: {
            std::string filename;
            std::cout << "������� �������� �����: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, filename);
            container.readFromFile(filename);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "������� �������� �����: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, filename);
            container.writeToFile(filename);
            break;
        }
        case 6:
            container.clearPlayers();
            break;
        case 0:
            exit(0);
            break;
        default:
            std::cout << "�������� �����! ��������� ����.\n";
        }
    } while (choice != 0);

    return 0;
}

BOOST_CLASS_EXPORT(OnlinePlayer)
BOOST_CLASS_EXPORT(Player)