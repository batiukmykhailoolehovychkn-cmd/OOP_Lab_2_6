#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2_6/RightAngled.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab26
{
	TEST_CLASS(UnitTestOOPLab26)
	{
    public:
        TEST_METHOD(TestCountersLogic)
        {
            // Запам'ятовуємо початковий стан лічильників
            int initialRA = RightAngled::getCounter();
            int initialTr = RightAngled::Triangle::getCounter();

            {
                // Створюємо об'єкти в локальному блоці
                RightAngled::Triangle tr(6, 8, 10);
                RightAngled ra(tr);

                // Лічильник вкладеного класу: +1 (від tr), +1 (від поля t всередині ra)
                Assert::AreEqual(initialTr + 2, RightAngled::Triangle::getCounter());

                // Лічильник зовнішнього класу: +1
                Assert::AreEqual(initialRA + 1, RightAngled::getCounter());
            }
            // Вийшли з блоку - деструктори мають зменшити лічильники назад

            Assert::AreEqual(initialRA, RightAngled::getCounter());
            Assert::AreEqual(initialTr, RightAngled::Triangle::getCounter());
        }

        TEST_METHOD(TestRightAngledValidation)
        {
            // Спроба створити з неправильними даними
            RightAngled::Triangle badTr(4, 4, 4);
            RightAngled ra(badTr);

            // Має скинути на базовий єгипетський трикутник (3,4,5)
            Assert::AreEqual(12.0, ra.getTriangle().Perimeter(), 0.001);
            Assert::AreEqual(6.0, ra.getArea(), 0.001);
        }

        TEST_METHOD(TestPrefixIncrement)
        {
            RightAngled ra; // (3,4,5)
            ra++; // (4,5,6) - не прямокутний, має скасувати зміни

            Assert::AreEqual(3.0, ra.getTriangle().getA(), 0.001);
            Assert::AreEqual(6.0, ra.getArea(), 0.001); // площа має залишитися 6
        }
    };
}