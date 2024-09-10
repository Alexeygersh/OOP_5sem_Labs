#pragma once
#include "Player.h"
#include <vector>


class PlayerContainer {
private:
    std::vector<Player*> players;

public:
    PlayerContainer();
    ~PlayerContainer();

    void addPlayer();
    void displayPlayers() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
    void clearPlayers();
};
