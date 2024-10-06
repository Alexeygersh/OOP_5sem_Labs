#include "Judge.h"
#include "utils.h"

Judge::Judge() : experience(0), level("Unknown") {}

Judge::~Judge() {}

void Judge::readFromConsole() {
    Player::readFromConsole();

    int playerAge = getAge();

    std::cout << "������� ���� ������ ����� (� �����): ";
    experience = InputNum<int>(0, playerAge);

    std::cout << "������� ������� ������������\n(������������� = 0| ������ = 1| ������ = 2| ������ = 3| ���� ����� = 4): ";
    int levelInput = InputNum<int>(0, 4);
    switch (levelInput){
        case 0: { level = "�������������"; break; }
        case 1: { level = "������"; break; }
        case 2: { level = "������"; break; }
        case 3: { level = "������"; break; }
        case 4: { level = "���� �����"; break; }
    }
        
}

void Judge::displayToConsole() const {
    Player::displayToConsole(); // ������� ������� ������ �������� ������
    std::cout << "���� ������: " << experience << " ���(����), ������� ������������: " << level << std::endl;
}

void Judge::readFromFile(std::ifstream& inputFile) {

    
    inputFile >> experience;
    inputFile.ignore();
    std::getline(inputFile, level);
}

void Judge::writeToFile(std::ofstream& outputFile) const {
    
    outputFile << experience << std::endl
        << level << std::endl;
}