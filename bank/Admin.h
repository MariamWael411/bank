#pragma once
#include"Employee.h"

class Admin : public Employee
{

	Admin():Employee()
	{

	}
	static Admin* admin;
public:
	static Admin* getAdmin() {
		if (admin == nullptr)
		{
			
			admin = new Admin;
		}
		return admin;
	}
	
	void addEmployee(Employee* employee) {
		employees.push_back(employee);
	}
	Employee* searchEmployee(int id) {
		for (int i = 0;i < employees.size();i++) {
			
			if (employees[i]->getId() == id) {
				return employees[i];
			}
		}
		return nullptr;
	}
	void listEmployee() {
		for (int i = 0;i < employees.size();i++) {
			cout << "\n==================== Employee " << i + 1 << " ========================\n";
			employees[i]->display();
			cout << endl;
		}
	}
	void editEmployee(Employee*e, string name, string password, double salary) {

		e->setName(name);
		e->setPassword(password);
		e->setSalary(salary);
	}

};
static vector<Admin*> admin;


