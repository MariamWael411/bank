#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"Parser.h"
#define ClientsFile "Files/Clients.txt"
#define EmployeesFile "Files/Employees.txt"
#define AdminFile "Files/Admin.txt"
#define client_l_Id "Files/ClientLastId.txt"
#define employee_l_Id "Files/EmployeeLastId.txt"
#define admin_l_Id "Files/AdminLastId.txt"
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
	static void saveClient( Client c) {
		fstream file;

		file.open(ClientsFile, ios::app);
		file << c.getId() << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << endl;
		SaveLast(client_l_Id, c.getId());
		file.close();
	}
	/// <summary>
	/// save information about Employee in file
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="lastIdFile"></param>
	/// <param name="e"></param>
	static void saveEmployee( Employee e) {
		fstream file;

		file.open(EmployeesFile, ios::app);
		file << e.getId() << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << endl;
		SaveLast(employee_l_Id, e.getId());

		file.close();
	}
	/// <summary>
	/// save information about Admin in file
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="lastIdFile"></param>
	/// <param name="a"></param>
	static void saveAdmin( Admin* a) {
		fstream file;

		file.open(AdminFile, ios::app);
		file << a->getId() << '&' << a->getName() << '&' << a->getPassword() << '&' << a->getSalary() << endl;
		SaveLast(admin_l_Id, a->getId());

		file.close();
	}
	/// <summary>
	/// return information about all Clients from file
	/// </summary>
	static void getClients() {
		fstream file;
		string line;
		
		file.open(ClientsFile, ios::in);
		while (getline(file, line)) {
			clients.push_back(Parser::ParserToClient(line));
		}
	
	}
	/// <summary>
	/// return information about all Employees from file
	/// </summary>
	static void getEmployees() {
		fstream file;
		string line;
		
		file.open(EmployeesFile, ios::in);
		while (getline(file, line)) {
			employees.push_back(Parser::ParserToEmployee(line));
		}
		
	}
	/// <summary>
	/// return information admin from file
	/// </summary>
	static void getAdmin() {
		fstream file;
		string line;
		
		file.open(AdminFile, ios::in);
		getline(file, line);
		admin.push_back(Parser::ParserToAdmin(line));

		
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

