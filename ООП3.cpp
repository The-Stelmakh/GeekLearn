#include <iostream>
#include <cassert>

class Figure
{
protected:
    double width;
    double height;
public:
    Figure(double _width, double _height) : width(_width), height(_height) {}
    virtual double area() = 0;
};

class Parallelograme : public Figure
{
public:
    Parallelograme(double width, double height) : Figure(width, height) {}
};

class Circle : public Figure
{
public:
    Circle(double radius) : Figure(radius, radius) {}
    double area() override { return 3.1415926 * width * height; }
};

class Rectangle : public Parallelograme
{
public:
    Rectangle(double width, double height) : Parallelograme(width, height) {}
    double area() override { return width * height; }
};

class Square : public Parallelograme
{
public:
    Square(double width, double height) : Parallelograme(width, height) {}
};

class Rhombus : public Parallelograme 
{
public:
    Rhombus(double width, double height) : Parallelograme(width, height) {}
    double area() override { return 0.5 * width * height; }
};

//=================================================================================================================================

class Car
{
    std::string company;
    std::string model;
public:
    Car(std::string company, std::string model) : company(std::move(company)), model(std::move(model)) {}
    virtual ~Car() {}
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar(const std::string &company, const std::string &model) : Car(company, model) {}
};

class Bus : virtual public Car
{
public:
    Bus(const std::string& company, const std::string& model) : Car(company, model) {}
};

class Minivan : public Bus, public PassengerCar
{
public:
    Minivan(const std::string& company, const std::string& model) : Car(company, model), Bus(company, model), PassengerCar(company, model) {}
};

//=================================================================================================================================

class Fraction
{
    int numerator;
    int denominator;
    void setDenominator(int _denominator) {
        if (_denominator != 0) {
            this->denominator = _denominator;
        }
        else {
            this->denominator = 1;
            std::cout << "Exception: denominator is set to 1!" << std::endl;
        }
        if (_denominator < 0) {
            this->denominator = -this->denominator;
            this->numerator = -this->denominator;
        }
    }
public:
    int getLCD(const Fraction& other) const {
        int l = this->denominator;
        int r = other.denominator;
        while (l != r) {
            if (l < r)
                l += this->denominator;
            else
                r += other.denominator;
        }
        return l;
    }
    Fraction(int _numerator, int _denominator) : numerator(_numerator) {
        setDenominator(_denominator);
    }
    void operator-() {
        numerator = -numerator;
    }
    Fraction operator+(Fraction const& rhs) const {
        int lcd = getLCD(rhs);
        Fraction res((numerator * (lcd / denominator)) +
            (rhs.numerator * (lcd / rhs.denominator)),
            lcd);
        return res;
    }
    Fraction operator-(Fraction const& rhs) const {
        int lcd = getLCD(rhs);
        Fraction res((numerator * (lcd / denominator)) -
            (rhs.numerator * (lcd / rhs.denominator)),
            lcd);
        return res;
    }
    Fraction operator*(Fraction const& rhs) const {
        Fraction res((numerator * rhs.numerator),
            denominator * rhs.denominator);
        return res;
    }
    Fraction operator/(Fraction const& rhs) const {
        Fraction res((numerator * rhs.denominator),
            denominator * rhs.numerator);
        return res;
    }
    bool operator<(const Fraction& rhs) const {
        int lcd = getLCD(rhs);
        return numerator * (lcd / denominator) < rhs.numerator * (lcd / rhs.denominator);
    }
    bool operator>(const Fraction& rhs) const {
        return rhs < *this;
    }
    bool operator<=(const Fraction& rhs) const {
        return !(rhs < *this);
    }
    bool operator>=(const Fraction& rhs) const {
        return !(*this < rhs);
    }
    bool operator==(const Fraction& rhs) const {
        int lcd = getLCD(rhs);
        return numerator * (lcd / denominator) == rhs.numerator * (lcd / rhs.denominator);
    }
    bool operator!=(const Fraction& rhs) const {
        return !(rhs == *this);
    }
    friend std::ostream& operator<< (std::ostream& s, const Fraction& f) {
        s << "F: " << f.numerator << "/" << f.denominator;
        return s;
    }
};

//=================================================================================================================================

enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum ECardValue {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10
};
class Card {
    ECardSuit suit;
    ECardValue value;
    bool isCoverUp;
public:
    Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
        isCoverUp = true;
    }

    void flip() {
        isCoverUp = !isCoverUp;
    }
    ECardValue getValue() const {
        return value;
    }
};

//=================================================================================================================================

int main() { // 1TBS
    Fraction f0(1, 5);
    Fraction f1(1, 7);
    std::cout << f0 + f1 << std::endl;

    Card c0(SPADES, ACE);
    std::cout << c0.getValue() << std::endl;
}