#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Room
{
public:

	string name;
	int count_people;
	int number;

};

Room* rooms = new Room[10]; 
int booked_room; // Запоминание занятых комнат
ofstream f, s; //Открытие файла


class Hotel
{
public:

	void booking() // функция заказа билета и его просмотра
	{
		f.open("booking_tickets.txt", ios::app);
		f << "Свободных номеров - " << 10 - booked_room << endl;
		f.close();
		cout << "Вас приветствует меню брониования номера." << endl;

		string name; // имя арендатора
		int count_people; // количество людей в номере 
		int your_number; // необходимо для записи номера в файл

		cout << "Введите ваше имя: " << endl;
		cin >> name;
		cout << "Введите количество въезжающих: " << endl;
		cin >> count_people;

		booked_room += 1;
		

		for (int i = 0; i < 1; i++) // создание занятой комнаты
		{
			rooms[i].name = name;
			rooms[i].count_people = count_people;
			rooms[i].number = booked_room;

			cout << "Номер " << rooms[i].number << " забронирован вами! \n \n" << endl;
			your_number = rooms[i].number;
			cout << "Так-же в отдельный файл под названием sort_rooms.txt занесены те номера \nкомнат, где проживает 3 и более человек. \n";
			if (rooms[i].count_people >= 3)
			{
				s.open("sort_rooms.txt", ios::app);
				s << "Номер комнаты: " << rooms[i].number << endl << "Количество человек - " << rooms[i].count_people << endl;
			}
		};

		cout << "\n\nВаш билет: \nИмя - " << name << endl << "Число людей - " << count_people << "\n\n" << endl;

		f.open("booking_tickets.txt", ios::app); // открытие файла на запись в конец
		f << "Забронированный билет: \nИмя - "<< name << endl <<"Номер вашей комнаты: - "<< your_number << endl << "Число людей - " << count_people << "\n\n" << endl;
		f.close();

			
	};
};

int main()
{
	setlocale(LC_ALL, "RU");

	Hotel a; // Обьект класса для заказа
	int start_choice; // выбор действия
	int continous = 1; // возврат в меню после выполнения функции

	while (continous == 1)
	{
		cout << "Вас приветствует система бронирования номеров нашего отеля!\nВыберите интересующую вас услугу:\n";

		cout << "1. Заказ номера\n2. Выход.\n";
		cin >> start_choice;

		if (start_choice == 1)
		{
			a.booking(); // вызов метода заказа
		}

		else if (start_choice == 2) // перывание программы
		{
			delete[] rooms;
			break;
			 // выход и предотвращение утечки памяти
		}
	}
}