#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h> 
#include <fstream> 
#include <vector>
struct  Photoservice //������� ���������
{
	char Lastname[25];
	char Servantname[25];
	int Ordercount;
	int Ordercost;
};
static  std::vector<Photoservice> clients;
void Choisemenu();
void showelement(std::vector<Photoservice>& _clients, int n);
void addclient(std::vector<Photoservice>& _clients); //������� ������� ��������� ����� �������� ��������� � ��������� �� � ����
void showbase(std::vector<Photoservice>& _clients); //������� ������� ������� ���� ������ �� ��� ������
void deleteclient(std::vector<Photoservice>& _clients, int n); //������� ������� ������� ���� ������ �� ��� ������
void clientedit(std::vector<Photoservice>& _clients, int n); //������� �������� ������� ���� ������ �� ��� ������