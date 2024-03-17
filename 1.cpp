/*Задание 1. Создание данных типа «класс». Задание: для всех вариантов задач создать класс с указанными двумя полями (Поле 1, Поле 2) и тремя методами:
- конструктор для инициализации объекта;
- функция формирования строки с информацией об объекте;
- функция обработки значений полей по индивидуальному варианту.
В основной программе вводить значения полей каждого объекта из компонентов Edit и выводить результаты в компонент Memo.
Вещественное число, Вещественное число, Вычислить полуразность чисел*/
#include <iostream>
#include <string>
#include <sstream>

class PairOfRealNumbers {
private:
    double number1;
    double number2;

public:
    PairOfRealNumbers(double num1, double num2) : number1(num1), number2(num2) {}

    std::string getInfo() {
        std::stringstream ss;
        ss << "Pair of Real Numbers: " << number1 << ", " << number2;
        return ss.str();
    }

    double calculateHalfDifference() {
        return (number1 - number2) / 2.0;
    }
};

int main() {
    double input1, input2;
    std::cout << "Enter the first real number: ";
    std::cin >> input1;

    std::cout << "Enter the second real number: ";
    std::cin >> input2;

    PairOfRealNumbers pair(input1, input2);

    // Вывод информации о паре чисел
    std::cout << pair.getInfo() << std::endl;

    // Вычисление и вывод половины разности чисел
    double halfDiff = pair.calculateHalfDifference();
    std::cout << "Half difference: " << halfDiff << std::endl;

    return 0;
}
