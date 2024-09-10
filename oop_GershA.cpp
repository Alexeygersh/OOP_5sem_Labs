#include "PlayerContainer.h"
#include <iostream>


int main() {
    PlayerContainer container;
    int choice;

    do {
        std::cout << "Chess Tournament System\n";
        std::cout << "1. Add a player\n";
        std::cout << "2. Display all players\n";
        std::cout << "3. Load players from file\n";
        std::cout << "4. Save players to file\n";
        std::cout << "5. Clear all players\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Игнорирование символа новой строки

        switch (choice) {
        case 1:
            container.addPlayer();
            break;
        case 2:
            container.displayPlayers();
            break;
        case 3: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            container.readFromFile(filename);
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Enter filename: ";
            std::cin >> filename;
            container.writeToFile(filename);
            break;
        }
        case 5:
            container.clearPlayers();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
