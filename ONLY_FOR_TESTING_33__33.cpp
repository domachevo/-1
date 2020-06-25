#include <iostream>

#include<windows.h>

#include<cstring>

using namespace std;

struct country

{

	char name[20];

	char capital[20];

	int population;

	int sqare;

};

enum work

{

	INs = 1,

	OUTs,

	SORTs,

	FINDs,

	CORRs,

	DELs,

	EXs

};

country in()

{

	int work;

	country* st = new country();

	cout << "Введите название страны" << endl;

	cin >> st->name;

	cout << "Введите название столицы" << endl;

	cin >> st->capital;

	cout << "Введите количество населения" << endl;

	cin >> st->population;

	cout << "Введите площадь страны" << endl;

	cin >> st->sqare;

	cout << "********" << endl;

	system("cls");

	return *st;

};

void out(country student)

{

	cout << student.name << endl;

	cout << student.capital << endl;

	cout << student.population << endl;

	cout << student.sqare << endl;

	cout << "********" << endl;

}

int main()

{

	setlocale(0, "");

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	cout << "Введите количество стран" << endl;

	int N;

	cin >> N;

	country* data = new country[N];



	bool t = true;

	while (t)

	{

		system("cls");

		cout << "Выберете: " << endl;

		cout << " 1 Ввод массива структур" << endl;

		cout << " 2 Вывод массива структур" << endl;

		cout << " 3 Сортировка массива структур" << endl;

		cout << " 4 Поиск в массиве структур по заданному параметру" << endl;

		cout << " 5 Изменение заданной структуры" << endl;

		cout << " 6 Удаление структуры из массива" << endl;

		cout << " 7 Выход. " << endl;

		int n;

		cin >> n;

		system("cls");

		switch (n)

		{

		case INs:

			for (int rr = 0; rr < N; rr++)

			{

				data[rr] = in();

			}

			break;

		case OUTs:

			for (int i = 0; i < N; i++)

			{

				out(data[i]);

			}

			char b[100];

			cout << "Введите любой символ, чтобы продолжить" << endl;

			cin >> b;

			break;

		case SORTs:



			country temp;

			for (int k = 0; k < N; k++) {

				for (int i = 0; i < N - 1; i++)

				{

					if ((int)data[i].name[0] > (int)data[i + 1].name[0])

					{

						temp = data[i];

						data[i] = data[i + 1];

						data[i + 1] = temp;

					}

				}

			}

			break;

		case FINDs:

			cout << "Выберете параметр для поиска" << endl;

			cout << "1 - Название страны" << endl;

			cout << "2 - Название Столицы" << endl;

			cout << "3 - Количество населения" << endl;

			cout << "4 - Площадь страны" << endl;

			int f;

			cin >> f;

			char find[20];

			cin >> find;

			switch (f)

			{

			case 1:

				for (int i = 0; i < N; i++)

				{

					if (strcmp(data[i].name, find) == 0)

					{

						out(data[i]); Sleep(4000);

						break;

					}

				}

			case 2:

				for (int i = 0; i < N; i++)

				{

					if (strcmp(data[i].capital, find) == 0)

					{

						out(data[i]); Sleep(4000);

						break;

					}

				}

			case 3:

				for (int i = 0; i < N; i++)

				{

					if (data[i].population = atoi(find))

					{

						out(data[i]); Sleep(4000);

						break;

					}

				}

			case 4:

				for (int i = 0; i < N; i++)

				{

					if (data[i].sqare = atoi(find))

					{

						out(data[i]); Sleep(4000);

						break;

					}

				}

				break;
			}
		case CORRs:

			cout << "Введите номер структуры" << endl;

			int number;

			cin >> number;

			number--;

			data[number] = in();

			break;

		

		case DELs:

			int num;

			cout << "Введите номер структуры" << endl;

			cin >> num;

			num--;

			for (int i = 1; i < N; i++)

			{

				strcpy_s(data[num + i - 1].name, data[num + i].name);

				strcpy_s(data[num + i - 1].capital, data[num + i].capital);

				data[num + i - 1].population= data[num + i].population;

				data[num + i - 1].sqare =data[num + i].sqare;


			}

			N--;

			break;

		case EXs:

			t = false;

			break;

		}

	}

	delete data;

	system("pause");

	return 0;

}