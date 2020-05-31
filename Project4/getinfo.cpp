#include "Stdafx.h"
using namespace std;


void showelement(vector<Photoservice>& _clients, int n) //������� ������� ������� ���� ������ �� ��� ������
{
	ifstream fbin("Photoservice.txt", ios::binary | ios::out | ios::app); //��������� ���� � �������� ������
	if (!fbin) //�������� ������ �� ���� 
		cout << "File does not open";
	else
	{
		if (n >= 0 && n < _clients.size())
		{
			Photoservice  client;
			fbin.seekg(n * sizeof(Photoservice)); //������� � ������� �������� � �����
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