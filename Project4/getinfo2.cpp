#include "Stdafx.h"

using namespace std;


void getInfo(vector<Photoservice>& _client)
{
	ifstream fbin("Photosevice.txt", ios::binary);
	if (!fbin)
		cout << "Error, file can`t be open";
	else
	{
		Photoservice client2;
		fbin.read((char*)&client2, sizeof(Photoservice));
		cout << "Client lastname:" << "Servant name: " << "Order count: " << "Order costs: " << endl;
		for (int n = 1; n <= clients.size(); n++)
		{
			Photoservice client;
			fbin.seekg(n * sizeof(Photoservice));
			fbin.read((char*)&client, sizeof(Photoservice));
			cout << clients[n].Lastname << "  " << clients[n].Servantname << "  " << clients[n].Ordercount << "  " << clients[n].Ordercost << endl;
		}
	}
	fbin.close();
}