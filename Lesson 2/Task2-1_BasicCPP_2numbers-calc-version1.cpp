// Задача 1. Калькулятор двух чисел
// В этом задании нужно будет создать класс, выполняющий простые арифметические операции для двух чисел, и продемонстрировать его работу
// Создайте класс Calculator. Класс должен содержать два поля num1 и num2 для хранения дробных чисел. Также класс должен другие методы
// Программа спрашивает пользователя бесконечно, пока он сам не закроет консоль

#include<iostream>
#include<limits>

class Calculator {
private:
	double num1;
	double num2;

public:
	// // инициализация чисел в классе
	Calculator() : num1(0.0), num2(0.0) {}

	// методы для арифметических операций
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

	double divide_1_2() {
		if (num2 != 0) {
			return num1 / num2;
		}
		else {
			std::cout << "делить на ноль нельзя" << std::endl;
			return 0;
		}
	}

	double divide_2_1() {
		if (num1 != 0) {
			return num2 / num1;
		}
		else {
			std::cout << "делить на ноль нельзя" << std::endl;
			return 0;
		}
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
	bool number1_correct = false;  // проверка, что первое число успешно введено и его не нужно снова запрашивать

	// создание цикла для ввода и вывода чисел
	while (true) {

		// запрос на ввод первого числа, если оно не было корректно введено до второго числа
		if (!number1_correct)
		{
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

		// ввод второго числа
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

		// вывод результатов на консоль
		std::cout << "num1 + num2  = " << calculator1.add() << std::endl;
		std::cout << "num1 * num2  = " << calculator1.multiply() << std::endl;
		std::cout << "num1 - num2  = " << calculator1.subtract_1_2() << std::endl;
		std::cout << "num2 - num1  = " << calculator1.subtract_2_1() << std::endl;
		std::cout << "num1 / num2  = " << calculator1.divide_1_2() << std::endl;
		std::cout << "num2 / num1  = " << calculator1.divide_2_1() << std::endl;

		number1_correct = false; // сброс значения логической переменной для ввода новых чисел
	}

	return 0;
}