#include "Stdafx.h"

using namespace std;
void showbase(vector<Photoservice>& _clients) //������� ������� ��� �������� ���� ������
{
	ifstream fbin("photoservice.txt", ios::binary | ios::out | ios::app); //��������� ���� � �������� ������
	if (!fbin) //�������� ������ �� ����
		cout << "File does not open";
	else
	{
		Photoservice  client;
		cout << "____________________________________________________________________________________________________\n\n";
		cout << "N|\tCLIENT LASTNAME\t\tSERVANT NAME\t ORDER COUNT\t\tORDRECOST";
		cout << "\n__________________________________________________________________________________________________\n\n";
		for (int n = 0; n < _clients.size(); n++)
		{
			fbin.seekg(n * sizeof(Photoservice));
			fbin.read((char*)&client, sizeof(Photoservice));
			cout << n + 1 << "|       " << _clients[n].Lastname << "\t\t              " << _clients[n].Servantname << "      \t            " << _clients[n].Ordercount << "      \t\t       " << _clients[n].Ordercost << "\t" << endl;
		}
	}
	fbin.close();
}