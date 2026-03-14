#pragma once
#include"ClientManager.h"
#include <thread>
#include <chrono>
class EmployeeManager
{

public:
	static void printEmployeMenu() {

		cout << endl;

		cout << "  1.Add New Client" << endl;
		cout << endl;

		cout << "  2.Search of client" << endl;
		cout << endl;

		cout << "  3.List All Clients" << endl;
		cout << endl;

		cout << "  4.Edit Client Information" << endl;
		cout << endl;

		cout << "  5.Remove All Clients" << endl;
		cout << endl;
		cout << "  6.Display My Information" << endl;
		cout << endl;
		cout << "  7.Update Password" << endl;
		cout << endl;
		cout << "  8.Logout" << endl;
	}

	static void newClient(Employee* employee) {

		Client c;

		string name, password;
		double balance;

		cout << endl;

		c.setName(Validation::EnterName("  Enter Client Name : "));

		cout << endl;



		c.setPassword(Validation::EnterPassword("  Enter Client Password : "));
		cout << endl;


		c.setBalance(Validation::EnterBalance("  Enter Client Balance : "));
		cout << endl;
		int id = FileHelper::getLast(client_l_Id);
		id++;
		c.setId(id);
		employee->addClient(&c);

		FileManager::addClient(c);
	}
	static void listAllClients(Employee* employee) {

		employee->listClient();
	}
	static void searchForClient(Employee* employee) {

		int id;
		cout << endl;
		cout << "  Enter Client ID : ";
		cin >> id;
		cout << endl;
		Client* c = employee->searchClient(id);
		if (c == nullptr)
		{
			cout << "  Client Not Found" << endl;
		}
		else {
			c->display();

		}


	}

	static void editClientInfo(Employee* employee) {
		int id, index{};
		string name, password;
		double balance;
		cout << endl;

		cout << "  Enter Client ID to Edit : ";
		cin >> id;
		Client* c = employee->searchClient(id);
		if (c != nullptr)
		{
			cout << endl;
			name = Validation::EnterName("  Enter New Name : ");

			cout << endl;
			password = Validation::EnterPassword("  Enter New Password : ");

			cout << endl;
			balance = Validation::EnterBalance("  Enter New Balance : ");

			cout << endl;
			employee->editClient(c, name, password, balance);
			FileManager::UpdateClient();
			cout << endl;
			cout << "  Client Edited Successfully" << endl;
		}
		else
		{
			cout << endl;
			cout << "  Client Not Found!!" << endl;
		}
	}
	static Employee* login(int id, string password) {

		for (int i = 0; i < employees.size(); i++)
		{
			if (employees[i]->getId() == id && employees[i]->getPassword() == password)
			{
				return employees[i];
			}
		}
		return nullptr;
	}

	static void Exit_Back(Employee* employee) {
		int choice;
		do {
			cout << endl;
			cout << "  1.Options " << endl;
			cout << endl;
			cout << "  2.Exit " << endl;
			cout << endl;
			cout << "  Enter Your Choice : ";
			cin >> choice;
		} while (choice < 1 || choice>2);

		switch (choice) {
		case 1:
			system("cls");
			employeeOptions(employee);

			break;
		case 2:
			system("cls");
			exit(0);

			break;

		}
	}
	static bool employeeOptions(Employee* employee) {

		int choice;
		do {
			printEmployeMenu();

			cout << "  Enter your Choice : ";
			cin >> choice;
			system("cls");

		} while (choice < 1 || choice>8);

		cout << endl;
		switch (choice) {


		case 1:
			system("cls");

			newClient(employee);
			cout << "  Added Client Successfully" << endl;

			break;
		case 2:
			system("cls");

			searchForClient(employee);
			break;
		case 3:
			system("cls");

			listAllClients(employee);
			break;
		case 4:
			system("cls");

			editClientInfo(employee);
			break;
		case 5:
			FileManager::removeAllClients();
			break;
		case 6:
			system("cls");
			employee->display();
			break;
		case 7:
			system("cls");

			ClientManager::updatePassword(employee);
			break;
		case 8:
			system("cls");


			return false;
			break;

		}
		this_thread::sleep_for(std::chrono::seconds(1));

		Exit_Back(employee);
		return true;
	}





};



