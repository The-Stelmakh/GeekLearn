#include <iostream>
#include <cstdint>

class Person 
{
    std::string name;
    std::uint8_t age;
    std::string gender;
    std::uint8_t weight;
protected:
    Person(std::string _name, std::string _gender, std::uint8_t _age, std::uint8_t _weight) :
        name(_name), gender(_gender), age(_age), weight(_weight) { }
public:
    void setName(std::string name) { this->name = name; }
    void setAge(std::uint8_t age) { this->age = age; }
    void setWeight(std::uint8_t weight) { this->weight = weight; }
    std::string getInfo() const {
        return "Person " + name + " is " + gender + " of age " + std::to_string(age) + " has weight " + std::to_string(weight) + " ";
    }
};

class Student : public Person 
{
    std::uint16_t learnYear;
    static std::uint8_t counter;
public:
    Student(std::string _name, std::string _gender, std::uint8_t _age, std::uint8_t _weight, std::uint16_t learnYear) :
        Person(_name, _gender, _age, _weight) {
        Student::counter++;
        this->learnYear = learnYear;
    }
    static std::uint8_t get_counter() {
        return Student::counter;
    }
    void set_learnYear(std::uint16_t learnYear) { this->learnYear = learnYear; }
    std::uint16_t get_learnYear() const { return learnYear; }
    std::string getInfo() const {
        return Person::getInfo() + "and learns from " + std::to_string(learnYear) + " ";
    }
};
std::uint8_t Student::counter = 0;

//=========================================================================================================

class Fruit 
{
    std::string name;
    std::string color;
public:
    Fruit(std::string _name, std::string _color) : name(_name), color(_color) { }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
};

class Apple : public Fruit 
{
public:
    Apple(std::string _color = "red", std::string _name = "Apple") : Fruit(_name, _color) { }
};

class Banana : public Fruit 
{
public:
    Banana(std::string _name = "Banana", std::string _color = "yellow") : Fruit(_name, _color) { }
};

class GrannySmith : public Apple 
{
public:
    GrannySmith() : Apple("green", "GrannySmith") { }
};

//=========================================================================================================

int main(int argc, const char** argv) 
{
    Student s("Ivan", "male", 36, 110, 2021);
    std::cout << s.getInfo() << std::to_string(s.get_counter()) << std::endl;
    Student t("Petr", "male", 35, 100, 2021);
    std::cout << t.getInfo() << std::to_string(Student::get_counter()) << std::endl;
    Student u("Fedor", "male", 34, 90, 2021);
    std::cout << u.getInfo() << std::to_string(u.get_counter()) << std::endl;

    std::cout << std::to_string(Student::get_counter()) << std::endl;

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

//=========================================================================================================

/*
    Количество игроков в Блэк Джек зависит от количества блоков, от одного до семи, обычно.
    Возьму пример с одним блоком для ставок, т.е. есть диллер и один игрок.
    Основных классов будет три: Person, Coloda, Fishki. Dealer and Player — дочерние классы Person. Им можно присвоить имена для интереса
    В классе колода будут прописаны размеры колоды, масть и номинал. Туз будет 1 либо 11, в зависимости от ситуации. 
    Это можно реализовать через elif.
    Каждому игроку будет выдано по 500 фишек. Шаг ставки 10 фишек, то есть ни Дилер, ни игрок не могут поставить 13 фишек
    Дилер останавливает набор карт себе, в случае, если сумма карт 17 или больше.
    Игрок берёт, пока не решит, что ему хватит либо перебор, либо 21 - Блэк Джек.
    Если побеждает Дилер, то все фишки, что поставил игрок переходят, если игрок, то наоборот.
*/