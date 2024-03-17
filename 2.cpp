/*Задание: создать класс с полями. Реализовать в классе методы: - конструктор по умолчанию; - конструктор перезагрузки с параметрами; - деструктор для освобождения памяти (с сообщением об уничтожении объекта); - функции обработки данных (1 и 2); - функцию формирования строки информации об объекте. Создать проект для демонстрации работы: сформировать объекты со значениями-константами и с введенными значениями полей объекта из компонентов Edit. Выводить результаты в компонент Memo.
Книга: название, количество страниц, цена; Вычислить среднюю стоимость одной страницы; Увеличить цену книги в два раза, если название начинается со слова «Программирование»*/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Book {
private:
    std::string title;
    int pageCount;
    double price;

public:
    // Конструктор по умолчанию
    Book() : title(""), pageCount(0), price(0.0) {}

    // Конструктор с параметрами
    Book(std::string t, int pc, double p) : title(t), pageCount(pc), price(p) {}

    // Деструктор
    ~Book() {
        std::cout << "Object destroyed: " << title << std::endl;
    }

    // Функция обработки данных 1
    double averagePricePerPage() {
        if (pageCount == 0) {
            return 0.0;
        }
        return price / pageCount;
    }

    // Функция обработки данных 2
    void doublePriceIfProgrammingBook() {
        if (title.find("Программирование") == 0) {
            price *= 2;
        }
    }

    // Функция формирования строки информации об объекте
    std::string getInfo() {
        std::stringstream ss;
        ss << "Book: " << title << ", Pages: " << pageCount << ", Price: $" << std::fixed << std::setprecision(2) << price;
        return ss.str();
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    // Создание объекта с константными значениями
    Book book1("Программирование на C++", 500, 50.0);

    // Создание объекта с введенными значениями из компонентов Edit
    std::string title;
    int pageCount;
    double price;

    std::cout << "Enter the title of the book: ";
    std::cin >> title;

    std::cout << "Enter the number of pages: ";
    std::cin >> pageCount;

    std::cout << "Enter the price of the book: ";
    std::cin >> price;

    Book book2(title, pageCount, price);

    // Вывод результатов в компонент Memo
    std::cout << book1.getInfo() << std::endl;
    std::cout << "Average price per page: $" << book1.averagePricePerPage() << std::endl;
    book1.doublePriceIfProgrammingBook();
    std::cout << "Price after doubling if title starts with 'Программирование': $" << book1.getInfo() << std::endl;

    std::cout << std::endl;

    std::cout << book2.getInfo() << std::endl;
    std::cout << "Average price per page: $" << book2.averagePricePerPage() << std::endl;
    book2.doublePriceIfProgrammingBook();
    std::cout << "Price after doubling if title starts with 'Программирование': $" << book2.getInfo() << std::endl;

    return 0;
}
