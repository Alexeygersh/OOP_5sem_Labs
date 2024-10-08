#include "OnlinePlayer.h"
#include "utils.h"

OnlinePlayer::OnlinePlayer() : virtual_name("unknown"), email("unknown@gmail.com") {}

OnlinePlayer::~OnlinePlayer() {}

void OnlinePlayer::readFromConsole() {
    Player::readFromConsole();

    //int playerAge = getAge();

    //std::cout << "������� ���� ������ ����� (� �����): ";
    //experience = InputNum<int>(0, playerAge);
    std::cout << "������� ���: ";
    std::cin.ignore();
    std::getline(std::cin, virtual_name);

    std::cout << "������� ����� �����: ";
    std::cin.ignore();
    std::getline(std::cin, email);

    std::cout << "������� ����� �������� � ���� 9991010010: (+7)";
    tel = InputNum<unsigned long long int>(1000000000, 9999999999);
    /*std::cout << "������� ������� ������������\n(������������� = 0| ������ = 1| ������ = 2| ������ = 3| ���� ����� = 4): ";
    int levelInput = InputNum<int>(0, 4);
    switch (levelInput){
        case 0: { level = "�������������"; break; }
        case 1: { level = "������"; break; }
        case 2: { level = "������"; break; }
        case 3: { level = "������"; break; }
        case 4: { level = "���� �����"; break; }
    }*/



        
}

void OnlinePlayer::displayToConsole() const {
    Player::displayToConsole(); // ������� ������� ������ �������� ������
    std::cout << "��� ������������: " << virtual_name << ", ����� �����: " << email << ", ����� ��������: +7" << tel << std::endl;
}

void OnlinePlayer::readFromFile(std::ifstream& inputFile) {

    inputFile.ignore();
    std::getline(inputFile, virtual_name);
    
    inputFile.ignore();
    std::getline(inputFile, email);

    inputFile >> tel;
}

void OnlinePlayer::writeToFile(std::ofstream& outputFile) const {
    
    outputFile << virtual_name << std::endl
        << email << std::endl
        << tel << std::endl;
}