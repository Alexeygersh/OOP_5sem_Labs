#pragma once
#include "Player.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/base_object.hpp>
#include <fstream>
#include <string>

class Judge : public Player {
private:

    int experience; // ���� ����� (� �����)
    std::string level; // ������� ������������

    // �������������� ������� � ��������� ������ ��� boost
    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar& boost::serialization::base_object<Player>(*this);
        ar& experience;
        ar& level;
    }

public:

    Judge();
    virtual ~Judge();

    virtual void readFromConsole() override;
    virtual void displayToConsole() const override;

    void readFromFile(std::ifstream& inputFile);
    void writeToFile(std::ofstream& outputFile) const;

};

