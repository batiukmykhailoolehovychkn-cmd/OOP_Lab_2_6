#include <iostream>
#include "RightAngled.h"
#include <windows.h>

// Демонстрація впливу вирівнювання пам'яті
#pragma pack(push, 1)
class RightAngledPacked {
    RightAngled::Triangle t;
    double area;
};
#pragma pack(pop)

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "--- Перевірка розміру класу ---" << endl;
    cout << "Розмір без #pragma pack(1): " << sizeof(RightAngled) << " байт" << endl;
    cout << "Розмір з #pragma pack(1): " << sizeof(RightAngledPacked) << " байт\n" << endl;

    cout << "--- Демонстрація лічильників (До створення) ---" << endl;
    cout << "Кількість RightAngled: " << RightAngled::getCounter() << endl;
    cout << "Кількість RightAngled::Triangle: " << RightAngled::Triangle::getCounter() << "\n" << endl;

    {
        // 1. Створення об'єктів (ініціалізація, за умовчанням, копіювання)
        RightAngled::Triangle tr1(5, 12, 13);
        RightAngled ra1(tr1);
        cout << "ra1 (ініціалізація): " << ra1 << endl;

        RightAngled ra2;
        cout << "ra2 (за умовчанням): " << ra2 << endl;

        RightAngled ra3 = ra1;
        cout << "ra3 (копія ra1): " << ra3 << endl;

        // Перевірка лічильників всередині блоку
        cout << "\n--- Лічильники (Всередині блоку) ---" << endl;
        cout << "Кількість RightAngled: " << RightAngled::getCounter() << endl;
        cout << "Кількість RightAngled::Triangle: " << RightAngled::Triangle::getCounter() << endl;

        // 2. Демонстрація специфічних методів Triangle
        double a, b, c;
        ra1.getTriangle().Angles(a, b, c);
        cout << "\nКути ra1: " << a << "°, " << b << "°, " << c << "°" << endl;
        cout << "Периметр ra1: " << ra1.getTriangle().Perimeter() << endl;

        // 3. Демонстрація операцій інкременту
        cout << "\nСпроба інкрементації ra2 (зламає прямий кут):" << endl;
        ra2++;
        cout << "ra2 після ra2++: " << ra2 << endl;

        // 4. Масив об'єктів
        cout << "\nМасив об'єктів:" << endl;
        RightAngled arr[2] = { RightAngled(RightAngled::Triangle(6, 8, 10)), RightAngled() };
        for (int i = 0; i < 2; i++) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

        // Перевірка лічильників після масиву
        cout << "\n--- Лічильники (Після створення масиву) ---" << endl;
        cout << "Кількість RightAngled: " << RightAngled::getCounter() << endl;
        cout << "Кількість RightAngled::Triangle: " << RightAngled::Triangle::getCounter() << endl;

        // 5. Ввід з клавіатури
        cout << "\nВведіть прямокутний трикутник (напр. 8 15 17):" << endl;
        RightAngled ra4;
        cin >> ra4;
        cout << "Введено: " << ra4 << endl;

    } // Кінець блоку: тут спрацьовують деструктори і лічильники зменшуються

    cout << "\n--- Лічильники (Після виходу з локального блоку) ---" << endl;
    cout << "Кількість RightAngled: " << RightAngled::getCounter() << endl;
    cout << "Кількість RightAngled::Triangle: " << RightAngled::Triangle::getCounter() << endl;

    return 0;
}