#include "Stdafx.h"
using namespace std;


int main()
{
	fstream fbin("photoservice.txt", ios::binary | ios::out | ios::app); //��������� ���� � �������� ������
	streampos begin, end;
	begin = fbin.tellg(); //������ �����
	fbin.seekg(0, ios::end);
	end = fbin.tellg(); //����� �����
	int size = (end - begin) / sizeof(Photoservice); //������ �����
	fbin.close();
	Photoservice  client; //��������� ��� ���������
	for (int i = 0; i < size; i++)
		clients.push_back(client); //��������� ������

	fbin.open("birdfarm.txt", ios::binary | ios::in | ios::app); //��������� ���� � �������� ������
	for (int i = 0; i < size; i++)
	{
		fbin.read((char*)&clients[i], sizeof(Photoservice));
	}

	int choise; //����� ������������

	do //���� � ������� ���������� ��� �������
	{
		Choisemenu();

		cout << " ";
		cin >> choise;
		if (clients.size() == 0)
		{
			switch (choise)
			{
			case 1:
				cin.ignore();
				addclient(clients);
				break;
			case 7:
				break;
			default:
				cout << "The base is empty, sorry." << endl;

			}
		}
		else {
			switch (choise)
			{
			case 1:
				cin.ignore();
				addclient(clients);
				break;
			case 2:
				int num0;
				cout << "�hoose the client to delete (input number) ";
				cin >> num0;
				cin.ignore();
				deleteclient(clients, num0 - 1);
				break;
			case 3:
				showbase(clients);
				break;
			case 4:
				int num2;
				cout << "Choose the client to edit (input number) ";
				cin >> num2;
				cin.ignore();
				clientedit(clients, num2 - 1);
				break;
			case 7:
				break;
			default:
				cout << "The function doesn't exist." << endl;
			}
		}
	} while (choise != 7);
}