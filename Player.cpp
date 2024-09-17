#include "Player.h"
#include "utils.h"


Player::Player()
    : id(0), name("����������"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true), rankingPosition(0.0) {}

Player::~Player() {}

void Player::readFromConsole() {
    std::cout << "������� ID ������ (������������� ������������): ";

    id = InputNum<int>(0, 9999);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "������� ��� ������: ";
    std::getline(std::cin, name);
    
    std::cout << "������� ������� ������ (0-120): ";
    age = InputNum<int>(0, 120);

    std::cout << "������� ������� ������ (0-3000): ";
    rating = InputNum<int>(0, 3000);

    // ���
    while (true) {
        char genderInput;
        std::cout << "������� ��� (M/F): ";
        std::cin >> genderInput;
        if (genderInput == 'M' || genderInput == 'm') {
            gender = Male;
            break;
        }
        else if (genderInput == 'F' || genderInput == 'f') {
            gender = Female;
            break;
        }
        else {
            std::cout << "���������� ������� 'M' ��� �������� ���� ��� 'F' ��� ��������.\n";
        }
    }
    std::cin.ignore();

    std::cout << "������� ���� ����������� (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "����� ������� � ������ ������? (1 - ��, 0 - ���): ";
    isActive = InputNum<bool>(0, 1);

    std::cout << "������� ������� ������ �� ������� (������������� �������): ";
    rankingPosition = InputNum<double>(0, 500);
    std::cin.ignore();
}

void Player::displayToConsole() const {
    std::cout << "ID: " << id
        << ", ���: " << name
        << ", �������: " << age
        << ", �������: " << rating
        << ", ���: " << (gender == Male ? "�" : "�")
        << ", ���� �����������: " << registrationDate
        << ", �������?: " << (isActive ? "��" : "���")
        << ", ������� �� �������: " << rankingPosition
        << std::endl;
}

void Player::readFromFile(std::ifstream& inputFile) {
    inputFile >> id;
    inputFile.ignore();
    std::getline(inputFile, name);
    inputFile >> age >> rating;

    char genderChar;
    inputFile >> genderChar;
    gender = (genderChar == 'M' || genderChar == 'm') ? Male : Female;
    inputFile.ignore();

    std::getline(inputFile, registrationDate);
    inputFile >> isActive >> rankingPosition;
    inputFile.ignore();
}

void Player::writeToFile(std::ofstream& outputFile) const {
    outputFile << id << std::endl
        << name << std::endl
        << age << std::endl
        << rating << std::endl
        << (char)gender << std::endl
        << registrationDate << std::endl
        << isActive << std::endl
        << rankingPosition << std::endl;
}
