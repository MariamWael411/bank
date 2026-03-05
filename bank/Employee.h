#pragma once

#include<string>
#include "Person.h"
#include"Client.h"
class Employee :public Person
{
protected:
	static int countId2;
	double salary;
public:
	Employee() {
		salary = 0;
	}
	
	
	
	Employee(string name, string password, double salary) :Person(name, password) {
		setSalary(salary);
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
	
	void addClient(Client* client) {
		clients.push_back(client);

	}
	Client* searchClient(int id) {
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i]->getId()==id)
			{
				return clients[i];
			}
		}
		return nullptr;
	}
	void listClient() {

		for (int i = 0; i < clients.size(); i++)
		{
			cout << "\n==================== Client " << i + 1 << " ========================\n";
			  clients[i]->display();
			  cout << endl;
			
		}
	}
	void editClient(Client *c, string name, string password, double balance) {

		c->setName(name);
		c->setPassword(password);
		c->setBalance(balance);

	}
	

};
static vector<Employee*> employees;



