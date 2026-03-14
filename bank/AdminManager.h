#pragma once
#include"EmployeeManager.h"
#include <thread>
#include <chrono>
class AdminManager
{

public:

	static void printAdminMenu() {
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

		cout << "  6.Add New Employee" << endl;
		cout << endl;

		cout << "  7.Search of employee" << endl;
		cout << endl;

		cout << "  8.List All Employees" << endl;
		cout << endl;

		cout << "  9.Edit Employee Information" << endl;
		cout << endl;

		cout << "  10.Remove All Employees" << endl;
		cout << endl;
		cout << "  11.Display My Information" << endl;
		cout << endl;
		cout << "  12.Update Password" << endl;
		cout << endl;


		cout << "  13.Exit" << endl;
	}




	static void newEmployee(Admin* admin) {

		Employee e;

		string name, password;
		double salary;

		cout << endl;

		e.setName(Validation::EnterName("  Enter Employee Name : "));

		cout << endl;



		e.setPassword(Validation::EnterPassword("  Enter Employee Password : "));
		cout << endl;


		e.setSalary(Validation::EnterSalary("  Enter Employee salary : "));
		cout << endl;
		int id = FileHelper::getLast(employee_l_Id);
		id++;
		e.setId(id);
		admin->addEmployee(&e);

		FileManager::addEmployee(e);
	}
	static void listAllEmployees(Admin* admin) {

		admin->listEmployee();
	}
	static void searchForEmployee(Admin* admin) {

		int id;
		cout << endl;
		cout << "  Enter Employee ID : ";
		cin >> id;
		cout << endl;
		Employee* e = admin->searchEmployee(id);
		if (e == nullptr)
		{
			cout << "  Employee Not Found" << endl;
		}
		else
			e->display();


	}

	static void editEmployeeInfo(Admin* admin) {

		int id, index{};
		string name, password;
		double salary;
		cout << endl;
		cout << "  Enter Employee ID to Edit : ";
		cin >> id;
		Employee* e = admin->searchEmployee(id);
		if (e != nullptr)
		{
			cout << endl;
			name = Validation::EnterName("  Enter New Name : ");
			cout << endl;
			password = Validation::EnterPassword("  Enter New Password : ");
			cout << endl;
			salary = Validation::EnterSalary("  Enter New Salary : ");
			cout << endl;
			admin->editEmployee(e, name, password, salary);
			FileManager::UpdateEmployee();
			cout << endl;
			cout << "  Employee Edited Successfully" << endl;

		}
		else
		{
			cout << endl;
			cout << "  Employee Not Found!!" << endl;
		}

	}

	static Admin* login(int id, string password) {

		FileManager::getAllAdmins();
		for (int i = 0; i < admin.size(); i++)
		{
			if (admin[i]->getId() == id && admin[i]->getPassword() == password)
			{
				return admin[i];
			}
		}
		return nullptr;
	}

	static void Exit_Back(Admin* admin) {
		int choice;
		do {
			cout << endl;
			cout << "  1.Options " << endl;
			cout << endl;
			cout << "  2.Exit " << endl;
			cout << endl;
			cout << "  Enter Your Choice : ";
			cin >> choice;
			cout << endl;


		} while (choice < 1 || choice>2);

		switch (choice) {
		case 1:
			system("cls");
			AdminOptions(admin);

			break;
		case 2:
			system("cls");
			exit(0);

			break;

		}
	}
	static bool AdminOptions(Admin* admin) {
		int choice;
		do {
			printAdminMenu();
			cout << "  Enter your Choice : ";
			cin >> choice;
			cout << endl;

			system("cls");

		} while (choice < 1 || choice>13);

		switch (choice) {
		case 1:
			system("cls");
			EmployeeManager::newClient(admin);
			cout << "  Added Client Successfully" << endl;

			break;
		case 2:
			system("cls");
			EmployeeManager::searchForClient(admin);
			break;
		case 3:
			system("cls");

			EmployeeManager::listAllClients(admin);
			break;

		case 4:
			system("cls");

			EmployeeManager::editClientInfo(admin);
			break;
		case 5:
			system("cls");

			FileManager::removeAllClients();
			cout << "  Remove Done Successfully" << endl;
			break;

		case 6:
			system("cls");

			newEmployee(admin);
			cout << "  Added Employee Successfully" << endl;
			break;
		case 7:
			system("cls");

			searchForEmployee(admin);
			break;
		case 8:
			system("cls");

			listAllEmployees(admin);
			break;
		case 10:
			system("cls");
			FileManager::removeAllEmployees();
			cout << "  Remove Done Successfully" << endl;
			break;


		case 9:
			system("cls");

			editEmployeeInfo(admin);
			break;
		case 11:
			system("cls");

			admin->display();
			break;
		case 12:
			system("cls");

			ClientManager::updatePassword(admin);
			break;
		case 13:
			return false;
			break;
		}
		this_thread::sleep_for(std::chrono::seconds(1));
		Exit_Back(admin);

		return true;
	}


};



