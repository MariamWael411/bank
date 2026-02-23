#pragma once

#include<string>
#include "Person.h"
class Employee :public Person
{
protected:
	static int countId2;
	double salary;
public:
	Employee();
	
	
	
	Employee(string name, string password, double salary);
	
	void setSalary(double salary) {
		if (Validation::isValidSalary(salary))
		{
			this->salary = salary;
		}
		else {
			cout << "Minimum Salary is 5000" << endl;
		}
	}
	double getSalary() {
		return salary;
	}
	void display() {
		Person::display();
		cout << "Salary is : " << salary << endl;

	}

};



