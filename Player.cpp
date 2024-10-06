#include "Player.h"
#include "utils.h"


Player::Player()
    : name("����������"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true) {}

Player::~Player() {}

void Player::readFromConsole() {

    //std::cout << "������� ID ������ (������������� ������������): ";
    //id = InputNum<int>(0, 9999);

    std::cout << "������� ���: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "������� ������� (0-120): ";
    age = InputNum<int>(0, 120);

    std::cout << "������� ������� (0-3000): ";
    rating = InputNum<int>(0, 3000);

    std::cout << "������� ��� | '0' ��� �������� ���� ��� '1' ��� ��������: ";
    bool genderInput = InputNum<bool>(0, 1);
    gender = (genderInput == 0) ? Male : Female;

    std::cin.ignore();

    std::cout << "������� ���� ����������� (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "����� ������� � ������ ������? (1 - ��, 0 - ���): ";
    isActive = InputNum<bool>(0, 1);

    /*std::cout << "������� ������� ������ �� �������: ";
    rankingPosition = InputNum<double>(0, 500);
    std::cin.ignore();*/
}

void Player::displayToConsole() const {
    std::cout << " ���: " << name
        << ", �������: " << age
        << ", �������: " << rating
        << ", ���: " << (gender == Male ? "�" : "�")
        << ", ���� �����������: " << registrationDate
        << ", �������?: " << (isActive ? "��" : "���")
        << std::endl;
}

void Player::readFromFile(std::ifstream& inputFile) {
    //inputFile >> id;
    //inputFile.ignore();
    std::getline(inputFile, name);
    inputFile >> age >> rating;

    char genderChar;
    inputFile >> genderChar;
    gender = (genderChar == '1') ? Male : Female;
    inputFile.ignore();

    std::getline(inputFile, registrationDate);
    inputFile >> isActive;
    inputFile.ignore();
}

void Player::writeToFile(std::ofstream& outputFile) const {

    //boost::archive::text_oarchive oa(outputFile);

    outputFile << name << std::endl
        << age << std::endl
        << rating << std::endl
        << (char)gender << std::endl
        << registrationDate << std::endl
        << isActive << std::endl;
}



//template<class Archive>
//void save(Archive& ar, const unsigned int version) const
//{
//    ar& boost::serialization::base_object<Base>(*this);
//    ar << m_S;
//    ar << m_K;
//}
//
//template<class Archive>
//void load(Archive& ar, const unsigned int version)
//{
//    ar >> boost::serialization::base_object<Base>(*this);
//    ar >> m_S;
//    if (version > 0)
//    {
//        ar >> m_K;
//    }
//}
