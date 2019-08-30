#include "Header.h"

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Выберите способ задания скорости" << endl << "Автоматически - 0" << endl << "Вручную - 1" << endl;
	int speed_choice;
	cin >> speed_choice;
	cout << endl << "Включить возможность записи игрового времени?" << endl << "Да - 1" << endl << "Нет - 0" << endl;
	int time_choice;
	cin >> time_choice;

	if (speed_choice == 1) {
		float speed;
		cout << "Введите параметр скорости: ";
		cin >> speed;
		Realisation *realisation = new Realisation(speed);
		if (time_choice == 1) {
			clock_t start = clock() / CLOCKS_PER_SEC;
			realisation->move_abject_print_graph();
			clock_t end = clock() / CLOCKS_PER_SEC;
			wtime(realisation, start, end);
		}
		else if (time_choice == 0)
			realisation->move_abject_print_graph();
		else
			cout << "Некорректный ввод времени или скорости" << endl;

		delete realisation;
	}
	else if (speed_choice == 0) {
		cout << "Скорость задана автоматически" << endl << "Speed = 5.63" << endl;
		Realisation *realisation = new Realisation;
		if (time_choice == 1) {
			clock_t start = clock() / CLOCKS_PER_SEC;
			realisation->move_abject_print_graph();
			clock_t end = clock() / CLOCKS_PER_SEC;
			wtime(realisation, start, end);
		}
		else if (time_choice == 0)
			realisation->move_abject_print_graph();
		else
			cout << "Некорректный ввод времени или скорости" << endl;

		delete realisation;
	}
	else 
		cout << "Некорректный ввод времени или скорости"<< endl;

	system("pause");

	return 0;
}
