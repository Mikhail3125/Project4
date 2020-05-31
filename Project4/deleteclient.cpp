#include "Stdafx.h"

using namespace std;


void deleteclient(vector<Photoservice>& _clients
	, int n)
{
	if (n >= 0 && n < _clients.size())
	{
		auto itr = _clients.begin();
		_clients.erase(itr + n);
		ofstream fbin("photoservice.txt", ios::binary | ios::out);
		if (!fbin)
			cout << "File can't be open";
		else
		{
			for (int i = 0; i < _clients.size(); i++)
			{
				fbin.write((char*)&_clients[i], sizeof(Photoservice));
			}
		}
		fbin.close();
		cout << "\n\nInformation deleted" << endl;

	}
	else
		cout << "The base is empty" << endl;
}