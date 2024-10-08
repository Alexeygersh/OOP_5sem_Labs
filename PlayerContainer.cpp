#include "PlayerContainer.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <locale>

PlayerContainer::PlayerContainer() {}

PlayerContainer::~PlayerContainer() {
    clearPlayers();
}

void PlayerContainer::addPlayer() {
    std::shared_ptr<Player> newPlayer = std::make_shared<Player>();
    newPlayer->readFromConsole();
    players.push_back(newPlayer);
}

void PlayerContainer::addOnlinePlayer() {
    std::shared_ptr<OnlinePlayer> newOnlinePlayer = std::make_shared<OnlinePlayer>();
    newOnlinePlayer->readFromConsole();
    players.push_back(newOnlinePlayer);
}

void PlayerContainer::displayPlayers() const {
    for (const auto& player : players) {
        player->displayToConsole();
    }
}

void PlayerContainer::readFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    //file.imbue(std::locale("en_US.UTF-8"));

    if (inputFile.is_open()) {
        boost::archive::text_iarchive ia(inputFile);
        ia >> *this;
    }
    

    /*while (!inputFile.eof()) {
        Player* newPlayer = new Player();
        newPlayer->readFromFile(inputFile);
        if (inputFile.is_open()) {
            players.push_back(newPlayer);
        }
        else {
            delete newPlayer;
        }
    }*/
    
    inputFile.close();
}


void PlayerContainer::writeToFile(const std::string& filename) const {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        boost::archive::text_oarchive oa(outputFile);
        oa << *this;
        /*for (const auto& player : players) {
            player->writeToFile(outputFile);
        }*/
    }
    outputFile.close();
}

void PlayerContainer::clearPlayers() {
    players.clear();
}
