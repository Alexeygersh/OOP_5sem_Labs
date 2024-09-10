#include "PlayerContainer.h"
#include <iostream>
#include <fstream>


PlayerContainer::PlayerContainer() {}

PlayerContainer::~PlayerContainer() {
    clearPlayers(); // ������� ��� �������� ����� ������������ ����������
}

void PlayerContainer::addPlayer() {
    Player* newPlayer = new Player();
    newPlayer->readFromConsole();
    players.push_back(newPlayer);
}

void PlayerContainer::displayPlayers() const {
    for (const Player* player : players) {
        player->displayToConsole();
    }
}

void PlayerContainer::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    clearPlayers(); // ������� ������ ����� ���������

    while (!inputFile.eof()) {
        Player* newPlayer = new Player();
        newPlayer->readFromFile(inputFile);
        if (inputFile) {
            players.push_back(newPlayer);
        }
        else {
            delete newPlayer; // ������������ ������, ���� ������ �� �������
        }
    }
    inputFile.close();
}

void PlayerContainer::writeToFile(const std::string& filename) const {
    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (const Player* player : players) {
        player->writeToFile(outputFile);
    }
    outputFile.close();
}

void PlayerContainer::clearPlayers() {
    for (Player* player : players) {
        delete player; // �������� ���� ������� �� ������
    }
    players.clear(); // ������� ������� ����������
}
