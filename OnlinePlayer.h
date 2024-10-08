#pragma once
#include "Player.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <fstream>
#include <string>

class OnlinePlayer : public Player {
private:

    //int experience; // Стаж судьи (в годах)
    //std::string level; // Уровень квалификации
    std::string virtual_name;
    std::string email;
    unsigned long long int tel;

    // предоставление доступа к приватным данным для boost
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Player>(*this);
        ar& virtual_name;
        ar& email;
        ar& tel;
    }

public:

    OnlinePlayer();
    virtual ~OnlinePlayer();

    virtual void readFromConsole() override;
    virtual void displayToConsole() const override;

    void readFromFile(std::ifstream& inputFile);
    void writeToFile(std::ofstream& outputFile) const;

};

