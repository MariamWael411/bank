#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Parser.h"
class FileHelper
{
public:
	/// <summary>
	/// save last Id in FileLastId
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="id"></param>
	static void SaveLast(string fileName, int id) {

		fstream file;
		file.open(fileName, ios::out);
		file << id;
		file.close();
	}
	/// <summary>
	/// return last Id from fileLastId
	/// </summary>
	/// <param name="fileName"></param>
	/// <returns>
	/// int
	/// </returns>
	static int getLast(string fileName) {
		int id;
		fstream file;
		file.open(fileName, ios::in);
		file >> id;
		file.close();
		return id;
	}
	/// <summary>
	/// save information about Client in file
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="lastIdFile"></param>
	/// <param name="c"></param>
	static void saveClient(string fileName, string lastIdFile, Client c) {
		fstream file;

		file.open(fileName, ios::app);
		file << c.getId() << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << endl;
		SaveLast(lastIdFile, c.getId());
		file.close();
	}
	/// <summary>
	/// save information about Employee in file
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="lastIdFile"></param>
	/// <param name="e"></param>
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		fstream file;

		file.open(fileName, ios::app);
		file << e.getId() << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << endl;
		SaveLast(lastIdFile, e.getId());

		file.close();
	}
	/// <summary>
	/// save information about Admin in file
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="lastIdFile"></param>
	/// <param name="a"></param>
	static void saveAdmin(string fileName, string lastIdFile, Admin* a) {
		fstream file;

		file.open(fileName, ios::app);
		file << a->getId() << '&' << a->getName() << '&' << a->getPassword() << '&' << a->getSalary() << endl;
		SaveLast(lastIdFile, a->getId());

		file.close();
	}
	/// <summary>
	/// return information about all Clients from file
	/// </summary>
	static void getClients() {
		fstream file;
		string line;
		vector<Client*> clients;
		file.open("Files/Clients.txt", ios::in);
		while (getline(file, line)) {
			clients.push_back(Parser::ParserToClient(line));
		}
		for (int i = 0; i < clients.size(); i++)
		{
			cout << "\n==================== Client " << i + 1 << " ========================\n";
			cout << "Client Id : " << clients[i]->getId() << endl;
			cout << "Client Name : " << clients[i]->getName() << endl;
			cout << "Client Password : " << clients[i]->getPassword() << endl;
			cout << "Client Balance : " << clients[i]->getBalance() << endl;
		}
	}
	/// <summary>
	/// return information about all Employees from file
	/// </summary>
	static void getEmployees() {
		fstream file;
		string line;
		vector<Employee*> Employees;
		file.open("Files/Employees.txt", ios::in);
		while (getline(file, line)) {
			Employees.push_back(Parser::ParserToEmployee(line));
		}
		for (int i = 0; i < Employees.size(); i++)
		{
			cout << "\n==================== Employee " << i + 1 << " ========================\n";
			cout << "Employee Id : " << Employees[i]->getId() << endl;
			cout << "Employee Name : " << Employees[i]->getName() << endl;
			cout << "Employee Password : " << Employees[i]->getPassword() << endl;
			cout << "Employee Salary : " << Employees[i]->getSalary() << endl;
		}
	}
	/// <summary>
	/// return information admin from file
	/// </summary>
	static void getAdmin() {
		fstream file;
		string line;
		
		vector<Admin*> admin;
		file.open("Files/Admin.txt", ios::in);
		getline(file, line);
		admin.push_back(Parser::ParserToAdmin(line));

		
			cout << "\n==================== Admin " << " ========================\n";
			cout << "Admin Id : " << admin[0]->getId() << endl;
			cout << "Admin Name : " << admin[0]->getName() << endl;
			cout << "Admin Password : " << admin[0]->getPassword() << endl;
			cout << "Admin Salary : " << admin[0]->getSalary() << endl;
	}
	/// <summary>
	/// remove all information from files
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="LastIdFile"></param>
	static void ClearFiles(string fileName, string LastIdFile) {
		fstream file, file2;
		file.open(fileName, ios::out);
		file.close();
		file2.open(LastIdFile, ios::out);
		file2.close();
	}
};

