#include "Stdafx.h"
using namespace std;


void addclient(vector<Photoservice>& birds)
{
	Photoservice client1;

	char Lastname[25];
	char Servantname[25];
	int Ordercount;
	int Ordercost;

	cout << "Input the bird Name: ";
	cin.getline(client1.Lastname, sizeof(Lastname));
	while (client1.Lastname == "")
	{
		cout << setw(4) << "Enter one more time";
		cin.getline(client1.Lastname, sizeof(Lastname));
	}

	cout << "Input Servant name: ";
	cin >> client1.Servantname;

	cin.ignore();

	cout << "Input the count: ";
	cin >> client1.Ordercount;

	cin.ignore();

	cout << "Input the cost: ";
	cin >> client1.Ordercost;

	cin.ignore();

	clients.push_back(client1);

	ofstream fbin("Photosevice.txt", ios::binary | ios::out | ios::app); ///*Открываем файл для чтения в бинарном режиме и для чтения*/
	if (!fbin)
		cout << "Error, file cant be open";	// Проверка открытия файла
	else
	{
		fbin.write((char*)&client1, sizeof(Photoservice)); //Записываем объекты в открытый нами файл
		cout << "\n\nOperation succesfull!";
	}
	fbin.close();
}