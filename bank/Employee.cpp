#include "Employee.h"
#include"FileHelper.h"
int Employee::countId2 = 0;
Employee::Employee() : Person() {
	countId2++;
	id = countId2;
	FileHelper::SaveLast("Files/EmployeeLastId.txt", countId2);

}
Employee::Employee(string name, string password, double salary) : Person(name, password)
{
	countId2++;
	id = countId2;
	this->salary = salary;

	FileHelper::saveEmployee("Files/Employees.txt", "Files/EmployeeLastId.txt", *this);

}
