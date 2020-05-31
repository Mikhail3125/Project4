#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

struct  Photoservice //Главная структура
{
	char Lastname[25];
	char Servantname[25];
	int Ordercount;
	int Ordercost;
};
void deleteclient(vector<Photoservice>& clients, int n);
void showelement(vector<Photoservice>& clients, int n);
void clientedit(vector<Photoservice >& clients, int n) //Функция изменяет элемент базы данных по его номеру
{
	if (n >= 0 && n < clients.size())
	{
		cout << endl << "Before change: \n";
		showelement(clients, n);

		Photoservice  client;
		char Lastname[25];
		char Servantname[25];
		int Ordercount;
		int Ordercost;

		cout << endl << "Edit the lastname";

		cin.getline(client.Lastname, sizeof(Lastname));
		while (client.Lastname == "")
		{
			cout << "You have not entered anything";
			cin.getline(client.Lastname, sizeof(Lastname));
		}

		cin.ignore();

		cout << "Edit the Servant Name: ";
		cin >> client.Servantname;

		cin.ignore();

		cout << "Edit the order count: ";
		cin >> client.Ordercount;

		cin.ignore();

		cout << "Edit the price of order: ";
		cin >> client.Ordercost;

		cin.ignore();

		auto itr = clients.begin();

		*(itr + n) = client;

		ofstream fbin("Photoservice.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
		if (!fbin) //Проверка открыт ли файл
			cout << "File does not open";
		else {
			for (int i = 0; i < clients.size(); i++)
			{
				fbin.write((char*)&clients[i], sizeof(Photoservice));
			}
		}
		fbin.close();

		cout << endl << "After change: \n";
		showelement(clients, n);
	}
	else cout << "Wrong number\n";
}