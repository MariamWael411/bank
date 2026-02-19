#pragma once

#include<string>
#include "Person.h"
class Employee :public Person
{
protected:
	double salary;
public:
	Employee(): Person()
	{
		salary = 0;
	}
	Employee( int id, string name,string password, double salary) : Person(id, name, password)
	{
		this->salary = salary;
	}
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



