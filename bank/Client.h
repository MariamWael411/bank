#pragma once
#include "Person.h"

using namespace std;

class Client : public Person
{
	static int countId;
	double balance;
	string TransectionHistory[5];
public:
	Client();
	
	Client(string name, string password, double balance);
	
	void setBalance(double balance) {
		if (Validation::isValidBalance(balance))
		{
			this->balance = balance;
		}
		
	}
	double getBalance() {
		return balance;
	}
	void deposit(double amount) {
		if (amount>0)
		{
			balance += amount;
			cout << "Deposit Done Successfully" << endl;
			string Deposit = to_string(amount) + " has been added to your account .Your  Current balance is : " + to_string(balance);
			addTransection(Deposit);
		}
		else
		{
			cout << "invalid amount" << endl;
		}
		

	}
	void withdraw(double amount) {
		if (amount > balance)
		{
			cout << "exceeded balance , your balance : " << to_string(balance) << endl;
		}
		else
		{
			balance -= amount;
			cout << "Withdraw Done Successfully" << endl;

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
			balance -= amount;
			c.balance += amount;
			string Transfer= to_string(amount)+" has been transferred to "+c.getName()+"successfully Your  Current balance is : " + 
				to_string(balance);
			addTransection(Transfer);

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
		Person::display();
		cout << "Balance is : " << balance << endl;

	}


};
static vector<Client*> clients;

