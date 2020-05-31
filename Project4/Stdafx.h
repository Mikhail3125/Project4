#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h> 
#include <fstream> 
#include <vector>
struct  Photoservice //Главная структура
{
	char Lastname[25];
	char Servantname[25];
	int Ordercount;
	int Ordercost;
};
static  std::vector<Photoservice> clients;
void Choisemenu();
void showelement(std::vector<Photoservice>& _clients, int n);
void addclient(std::vector<Photoservice>& _clients); //Функция которая добавляет новые элементы структуры и сохраняет их в файл
void showbase(std::vector<Photoservice>& _clients); //Функция выводит элемент базы данных по его номеру
void deleteclient(std::vector<Photoservice>& _clients, int n); //Функция удаляет элемент базы данных по его номеру
void clientedit(std::vector<Photoservice>& _clients, int n); //Функция изменяет элемент базы данных по его номеру