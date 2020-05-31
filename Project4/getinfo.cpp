#include "Stdafx.h"
using namespace std;


void showelement(vector<Photoservice>& _clients, int n) //Функция выводит элемент базы данных по его номеру
{
	ifstream fbin("Photoservice.txt", ios::binary | ios::out | ios::app); //Открываем файл в бинарном режиме
	if (!fbin) //Проверка открыт ли файл 
		cout << "File does not open";
	else
	{
		if (n >= 0 && n < _clients.size())
		{
			Photoservice  client;
			fbin.seekg(n * sizeof(Photoservice)); //Переход к нужному элементу в файле
			fbin.read((char*)&client, sizeof(Photoservice));
			cout << "Last name clients " << _clients[n].Lastname << endl;
			cout << "Name of Servant " << _clients[n].Servantname << endl;
			cout << "Order count " << _clients[n].Ordercount << endl;
			cout << "Order cost" << _clients[n].Ordercost << endl;
		}
		else cout << "Wrong number\n";
	}
	fbin.close();
}