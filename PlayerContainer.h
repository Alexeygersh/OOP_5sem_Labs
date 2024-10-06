#pragma once
#include "Player.h"
#include "Judge.h"
#include <vector>
#include <memory>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

class PlayerContainer {
private:
    std::vector<std::shared_ptr<Player>> players;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& players;
    }

public:
    PlayerContainer();
    ~PlayerContainer();

    void addPlayer();
    void addJudge();
    void displayPlayers() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
    void clearPlayers();

};
