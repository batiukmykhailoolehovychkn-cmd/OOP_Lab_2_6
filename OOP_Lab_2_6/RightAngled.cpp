#include "RightAngled.h"
#include <sstream>
#include <cmath>
#include <algorithm>

constexpr double PI = 3.14159265;

// Ініціалізація статичних полів[cite: 25, 27]
int RightAngled::counter = 0;
int RightAngled::Triangle::counter = 0;

// ==========================================
// Реалізація вкладеного класу Triangle
// ==========================================

bool RightAngled::Triangle::isValid(double a, double b, double c) const {
    return (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a));
}

void RightAngled::Triangle::setSides(double a, double b, double c) {
    if (isValid(a, b, c)) {
        this->a = a; this->b = b; this->c = c;
    }
    else {
        cerr << "Помилка: Такий трикутник не існує. Встановлено 3, 4, 5." << endl;
        this->a = 3; this->b = 4; this->c = 5;
    }
}

RightAngled::Triangle::Triangle() {
    setSides(3, 4, 5);
    RightAngled::Triangle::counter++; // Збільшуємо лічильник[cite: 28]
}

RightAngled::Triangle::Triangle(double a, double b, double c) {
    setSides(a, b, c);
    RightAngled::Triangle::counter++;
}

RightAngled::Triangle::Triangle(const Triangle& other) {
    setSides(other.a, other.b, other.c);
    RightAngled::Triangle::counter++;
}

RightAngled::Triangle::~Triangle() {
    RightAngled::Triangle::counter--; // Зменшуємо лічильник[cite: 28]
}

double RightAngled::Triangle::getA() const { return a; }
double RightAngled::Triangle::getB() const { return b; }
double RightAngled::Triangle::getC() const { return c; }

double RightAngled::Triangle::Perimeter() const {
    return a + b + c;
}

void RightAngled::Triangle::Angles(double& alpha, double& beta, double& gamma) const {
    alpha = acos((b * b + c * c - a * a) / (2 * b * c)) * 180.0 / PI;
    beta = acos((a * a + c * c - b * b) / (2 * a * c)) * 180.0 / PI;
    gamma = acos((a * a + b * b - c * c) / (2 * a * b)) * 180.0 / PI;
}

RightAngled::Triangle& RightAngled::Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        setSides(other.a, other.b, other.c);
    }
    return *this;
}

RightAngled::Triangle::operator string() const {
    stringstream ss;
    ss << "Трикутник(" << a << ", " << b << ", " << c << ")";
    return ss.str();
}

RightAngled::Triangle& RightAngled::Triangle::operator++() {
    setSides(a + 1, b + 1, c + 1);
    return *this;
}

RightAngled::Triangle RightAngled::Triangle::operator++(int) {
    Triangle temp(*this);
    setSides(a + 1, b + 1, c + 1);
    return temp;
}

RightAngled::Triangle& RightAngled::Triangle::operator--() {
    setSides(a - 1, b - 1, c - 1);
    return *this;
}

RightAngled::Triangle RightAngled::Triangle::operator--(int) {
    Triangle temp(*this);
    setSides(a - 1, b - 1, c - 1);
    return temp;
}

int RightAngled::Triangle::getCounter() {
    return RightAngled::Triangle::counter;
}

ostream& operator<<(ostream& out, const RightAngled::Triangle& t) {
    out << string(t);
    return out;
}

istream& operator>>(istream& in, RightAngled::Triangle& t) {
    double ta = 0, tb = 0, tc = 0;
    cout << "Введіть сторони a, b, c: ";
    in >> ta >> tb >> tc;
    t.setSides(ta, tb, tc);
    return in;
}


// ==========================================
// Реалізація зовнішнього класу RightAngled
// ==========================================

bool RightAngled::isRightAngled(const Triangle& tr) const {
    double sides[3] = { tr.getA(), tr.getB(), tr.getC() };
    std::sort(sides, sides + 3);
    return std::abs((sides[0] * sides[0] + sides[1] * sides[1]) - (sides[2] * sides[2])) < 0.001;
}

void RightAngled::calculateArea() {
    double p = t.Perimeter() / 2.0;
    area = sqrt(p * (p - t.getA()) * (p - t.getB()) * (p - t.getC()));
}

void RightAngled::setTriangle(const Triangle& tr) {
    if (isRightAngled(tr)) {
        t = tr;
        calculateArea();
    }
    else {
        cerr << "Помилка: Трикутник не є прямокутним! Встановлено базовий (3, 4, 5)." << endl;
        t.setSides(3, 4, 5);
        calculateArea();
    }
}

RightAngled::RightAngled() {
    Triangle def(3, 4, 5);
    setTriangle(def);
    RightAngled::counter++; // Збільшуємо лічильник[cite: 26]
}

RightAngled::RightAngled(const Triangle& tr) {
    setTriangle(tr);
    RightAngled::counter++;
}

RightAngled::RightAngled(const RightAngled& other) {
    setTriangle(other.t);
    RightAngled::counter++;
}

RightAngled::~RightAngled() {
    RightAngled::counter--; // Зменшуємо лічильник[cite: 26]
}

RightAngled::Triangle RightAngled::getTriangle() const { return t; }
double RightAngled::getArea() const { return area; }

RightAngled& RightAngled::operator=(const RightAngled& other) {
    if (this != &other) {
        setTriangle(other.t);
    }
    return *this;
}

RightAngled::operator string() const {
    stringstream ss;
    ss << "Прямокутний " << string(t) << ", Площа: " << area;
    return ss.str();
}

RightAngled& RightAngled::operator++() {
    Triangle temp = t;
    ++temp;
    setTriangle(temp);
    return *this;
}

RightAngled RightAngled::operator++(int) {
    RightAngled temp(*this);
    ++(*this);
    return temp;
}

RightAngled& RightAngled::operator--() {
    Triangle temp = t;
    --temp;
    setTriangle(temp);
    return *this;
}

RightAngled RightAngled::operator--(int) {
    RightAngled temp(*this);
    --(*this);
    return temp;
}

int RightAngled::getCounter() {
    return RightAngled::counter;
}

ostream& operator<<(ostream& out, const RightAngled& ra) {
    out << string(ra);
    return out;
}

istream& operator>>(istream& in, RightAngled& ra) {
    RightAngled::Triangle temp;
    in >> temp;
    ra.setTriangle(temp);
    return in;
}