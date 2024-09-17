#pragma once
#include <iostream>
#include <fstream>
#include <string>


// ����������� ������������ ��� ����
enum Gender {
    Male = '�',
    Female = '�'
};

class Player {
private:
    int id;
    std::string name;
    int age;
    int rating;
    Gender gender;
    std::string registrationDate;
    bool isActive;
    double rankingPosition;

public:
    Player(); // �����������
    ~Player(); // ����������

    // ������� ��� ������ � ����������
    void readFromConsole();
    void displayToConsole() const;
    void readFromFile(std::ifstream& inputFile);
    void writeToFile(std::ofstream& outputFile) const;
};
