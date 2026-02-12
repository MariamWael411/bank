#pragma once
#include<string>
#include "Person.h"
#include"Validation.h"
using namespace std;

class Client : public Person
{
	double balance;
	string TransectionHistory[5];
public:
	Client() : Person()
	{

	}
	Client(string name, int id, string password, double balance) : Person(id, name, password)
	{
		this->balance = balance;
	}
	void setBalance(double balance) {
		if (Validation::isValidBalance(balance))
		{
			this->balance = balance;
		}
		else {
			cout << "The Minimum  balance is 1500" << endl;
		}
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		balance += amount;
		string Deposit = to_string(amount) + " has been added to your account .Your  Current balance is : " + to_string(balance);
		addTransection(Deposit);

	}
	void withdraw(double amount) {
		if (amount > balance)
		{
			cout << "exceeded balance , your balance : " << to_string(balance) << endl;
		}
		else
		{
			balance -= amount;
			string Withdraw = to_string(amount) + " has been withdrawn to your account .Your  Current balance is : " + to_string(balance);
			addTransection(Withdraw);


		}
	}
	void TransferTo(double amount, Client& c) {
		if (amount > balance)
		{
			cout << "exceeded balance , your balance is " << to_string(balance) << endl;
		}
		else
		{
			c.deposit(amount);
			withdraw(amount);
			cout << "Transfer done Successfully" << endl;

		}
	}
	void CheckBalance() {
		cout << "your current balance is : " << balance << endl;
	}
	void addTransection(string transection) {

		for (int i = 4; i > 0; i--)
		{

			TransectionHistory[i] = TransectionHistory[i - 1];
		}
		TransectionHistory[0] = transection;

	}
	void printTransection() {
		for (int i = 0; i < 5; i++)
		{
			if (!TransectionHistory[i].empty())
			{
				cout << TransectionHistory[i] << endl;

			}
		}
	}
	void display() {

		cout << "Balance is : " << balance << endl;

	}


};

