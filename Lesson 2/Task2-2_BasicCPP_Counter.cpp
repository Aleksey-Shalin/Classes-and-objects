// Задача 2. Счётчик
// Создайте класс Counter. Класс должен выполнять функцию счётчика
// Обратите внимание на то, что у внешнего кода не должно быть возможности изменить внутреннее значение счётчика напрямую

#include<iostream>
#include<string>
#include<Windows.h>

class Counter {
private:
	int counter_value; // внутреннее значение счётчика не может быть изменено внешним кодом

public:

	// метод для увеличения значения на 1
	void increment() {
		counter_value++;
	}

	// метод для уменьшения значения на 1
	void decrement() {
		counter_value--;
	}

	// метод для получения текущего значения
	int get_current_value() const {
		return counter_value;
	}

	// конструктор с параметром по умолчанию (1)
	Counter() : counter_value(1) {}

	// конструктор с параметром по умолчанию устанавливает переданное начальное значение 
	Counter(int init_value) : counter_value(init_value) {}
};


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	Counter counter1;
	char instruction;
	std::string init_value_choice;

	// цикл с проверкой, что выбрано да или нет
	while (true) {
		std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
		std::cin >> init_value_choice;

		if (init_value_choice == "да" || init_value_choice == "нет") {
			break;
		}
		std::cout << "Просьба указать да или нет" << std::endl;
	}

	if (init_value_choice == "да"){
			int initial;
			std::cout << "Введите начальное значение: ";
			std::cin >> initial;
			counter1 = Counter(initial); // применяется конструктор с параметром
		}
		else {
			counter1 = Counter(); // применяется конструктор по умолчанию (1)
		}

	// основая работа программы - использование команд
	std::cout << std::endl;
	while (true) {
		std::cout << "Введите команду ('+', '-', '=', 'x'): ";
		std::cin >> instruction;

		switch (instruction) {
		case '+':
			counter1.increment();
			break;

		case '-':
			counter1.decrement();
			break;

		case '=':
			std::cout << "Текущее значение: " << counter1.get_current_value() << std::endl;
			break;

		case 'x': // клавиша x/ч
		case 'X': // клавиша Х/Ч
		case 'х': // клавиша х[{
		case 'Х': // клавиша х[{
		case 'ч':
		case 'Ч':
			std::cout << "Финальное значение счётчика: " << counter1.get_current_value() << std::endl;
			std::cout << "До свидания";
			return 0;
		default:
			std::cout << "Неизвестная команда. Используйте +, -, = или x" << std::endl;
		}
	}
		return 0;
}
