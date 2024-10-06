#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// Определение перечисления для пола
enum Gender {
    Male = 'М',
    Female = 'Ж'
};

class Player {
private:
    //int id;
    std::string name;
    int age;
    int rating;
    char gender;
    std::string registrationDate;
    bool isActive;
    //double rankingPosition;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& name;
        ar& age;
        ar& rating;
        ar& gender;
        ar& registrationDate;
        ar& isActive;
    }

public:
    Player();
    virtual ~Player();

    virtual void readFromConsole();
    virtual void displayToConsole() const;

    virtual void readFromFile(std::ifstream& inputFile);
    virtual void writeToFile(std::ofstream& outputFile) const;
    int getAge() const { return age; }
};

