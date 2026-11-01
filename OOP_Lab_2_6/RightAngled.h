#pragma once
#include <iostream>
#include <string>

using namespace std;

class RightAngled {
public: // Робимо вкладений клас публічним, щоб мати змогу створювати його об'єкти
    class Triangle {
    private:
        double a, b, c;
        static int counter; // Лічильник об'єктів вкладеного класу

        bool isValid(double a, double b, double c) const;

    public:
        Triangle();
        Triangle(double a, double b, double c);
        Triangle(const Triangle& other);
        ~Triangle(); // Деструктор для зменшення лічильника

        double getA() const;
        double getB() const;
        double getC() const;
        void setSides(double a, double b, double c);
        double Perimeter() const;
        void Angles(double& alpha, double& beta, double& gamma) const;

        Triangle& operator=(const Triangle& other);
        operator string() const;
        Triangle& operator++();
        Triangle operator++(int);
        Triangle& operator--();
        Triangle operator--(int);

        friend ostream& operator<<(ostream& out, const Triangle& t);
        friend istream& operator>>(istream& in, Triangle& t);

        static int getCounter(); // Отримання кількості об'єктів
    };

private:
    Triangle t;
    double area;
    static int counter; // Лічильник об'єктів зовнішнього класу

    bool isRightAngled(const Triangle& tr) const;
    void calculateArea();

public:
    RightAngled();
    RightAngled(const Triangle& tr);
    RightAngled(const RightAngled& other);
    ~RightAngled(); // Деструктор[cite: 25]

    Triangle getTriangle() const;
    double getArea() const;
    void setTriangle(const Triangle& tr);

    RightAngled& operator=(const RightAngled& other);
    operator string() const;
    RightAngled& operator++();
    RightAngled operator++(int);
    RightAngled& operator--();
    RightAngled operator--(int);

    friend ostream& operator<<(ostream& out, const RightAngled& ra);
    friend istream& operator>>(istream& in, RightAngled& ra);

    static int getCounter(); // Отримання кількості об'єктів
};