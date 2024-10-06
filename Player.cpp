#include "Player.h"
#include "utils.h"


Player::Player()
    : name("Неизвестно"), age(0), rating(0), gender(Male), registrationDate("01-09-2024"), isActive(true) {}

Player::~Player() {}

void Player::readFromConsole() {

    //std::cout << "Введите ID игрока (положительное целочисленое): ";
    //id = InputNum<int>(0, 9999);

    std::cout << "Введите имя: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    
    std::cout << "Введите возраст (0-120): ";
    age = InputNum<int>(0, 120);

    std::cout << "Введите рейтинг (0-3000): ";
    rating = InputNum<int>(0, 3000);

    std::cout << "Введите пол | '0' для Мужского пола или '1' для женского: ";
    bool genderInput = InputNum<bool>(0, 1);
    gender = (genderInput == 0) ? Male : Female;

    std::cin.ignore();

    std::cout << "Введите дату регистрации (DD-MM-YYYY): ";
    std::getline(std::cin, registrationDate);

    std::cout << "Игрок активен в данный момент? (1 - да, 0 - нет): ";
    isActive = InputNum<bool>(0, 1);

    /*std::cout << "Введите позицию игрока на турнире: ";
    rankingPosition = InputNum<double>(0, 500);
    std::cin.ignore();*/
}

void Player::displayToConsole() const {
    std::cout << " Имя: " << name
        << ", Возраст: " << age
        << ", Рейтинг: " << rating
        << ", Пол: " << (gender == Male ? "М" : "Ж")
        << ", Дата регистрации: " << registrationDate
        << ", Активен?: " << (isActive ? "Да" : "Нет")
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
