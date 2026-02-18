// Задача 1. Калькулятор двух чисел
// В этом задании нужно будет создать класс, выполняющий простые арифметические операции для двух чисел, и продемонстрировать его работу
// Создайте класс Calculator. Класс должен содержать два поля num1 и num2 для хранения дробных чисел. Также класс должен другие методы
// Программа спрашивает пользователя бесконечно, пока он сам не закроет консоль

#include <iostream>
#include <limits>

class Calculator {
private:
    double num1;
    double num2;

public:
    // инициализация чисел в классе
    Calculator() : num1(0.0), num2(0.0) {}

    double add() { 
        return num1 + num2; 
    }

    double multiply() { 
        return num1 * num2; 
    }

    double subtract_1_2() { 
        return num1 - num2;
    }

    double subtract_2_1() { 
        return num2 - num1; 
    }

    // убрана проверка на 0, т.к. есть метод set_num1()
    double divide_1_2() {
        return num1 / num2; 
    }

    // убрана проверка на 0, т.к. есть метод set_num2()
    double divide_2_1() { 
        return num2 / num1; 
    }

    // методы для возврата аргумента, если его значение не равно 0
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Calculator calculator1;
    double number1 = 0.0, number2 = 0.0;
    bool number1_correct = false, number2_correct = false;

    // цикл для ввода и вывода числ
    while (true) {

        // вложенный цикл для ввода первого числа
        while (!number1_correct) {
            std::cout << "Введите num1: ";
            std::cin >> number1;

            // вывод на консоль ошибки, если первое число является буквой или недопустимым символом
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка: введите число" << std::endl;
                continue;
            }

            // вывод на консоль ошибки, если первое число равно 0
            if (!calculator1.set_num1(number1)) {
                std::cout << "Неверный ввод" << std::endl;
                continue;
            }

            number1_correct = true; // изменение значения логической переменной при корректном вводе первого числа
        }

        // вложенный цикл для ввода второго числа
        while (!number2_correct) {
            std::cout << "Введите num2: ";
            std::cin >> number2;

            // вывод на консоль ошибки, если второе число является буквой или недопустимым символом
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ошибка: введите число" << std::endl;
                continue;
            }

            // вывод на консоль ошибки, если второе число равно 0
            if (!calculator1.set_num2(number2)) {
                std::cout << "Неверный ввод" << std::endl;
                continue;
            }

            number2_correct = true; // изменение значения логической переменной при корректном вводе второго числа
        }


        // Вывод результатов
        std::cout << "num1 + num2 = " << calculator1.add() << std::endl;
        std::cout << "num1 * num2 = " << calculator1.multiply() << std::endl;
        std::cout << "num1 - num2 = " << calculator1.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calculator1.subtract_2_1() << std::endl;
        std::cout << "num1 / num2 = " << calculator1.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calculator1.divide_2_1() << std::endl;

        // сброс значения логических переменных для ввода новых чисел
        number1_correct = false;
        number2_correct = false;
    }
    return 0;
}
