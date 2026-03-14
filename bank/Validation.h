#pragma once
#include<iostream>
#include <string>
using namespace std;
class Validation {
public:

	/// <summary>
	/// check the name is alphabetic
	/// </summary>
	/// <param name="name">
	/// Name
	/// </param>
	/// bool
	/// <returns></returns>
	static bool isAlphabetic(const string& name) {
		for (char c : name) {
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')||c==' ') {
				cout << endl;

				cout << "  Name must be Alphabetic.!! " << endl;
				return false;
			}
				
		}

		return true;
	}
	/// <summary>
	/// Check the name size between 3 to 20 and
	/// check the name is alphabetic
	/// </summary>
	/// <param name="name">
	/// Name
	/// </param>
	///
	/// <returns>
	///  bool
	/// </returns>
	static bool isValidName(const string& name) {
		if (name.size() < 3 || name.size() > 20) {
			cout << endl;

			cout << "  at least size 3 and max 20.!!" << endl;
			return false;

		}
		return isAlphabetic(name);
	}
	/// <summary>
	/// Check password at least 8 characters max 20 , 
	///  include special characters, number, capital litter,small
	/// letter and do not have spaces
	/// </summary>
	/// <param name="password"></param>
	/// <returns>
	/// bool
	/// </returns>
	static bool ValidatePassword(string password) {

		bool IsUpper, Islower, IsNum, IsSymbol, IsSpace;
		IsUpper = Islower = IsNum = IsSymbol = IsSpace = false;
		for (int i = 0; i < password.length(); i++)
		{
			if (islower(password[i]))
			{
				Islower = true;
			}
			else if (isupper(password[i]))
			{
				IsUpper = true;

			}
			else if (password[i] >= '0' && password[i] <= '9')
			{
				IsNum = true;
			}
			else if ((password[i] == ' ' || password[i] == '\t'))
			{
				IsSpace = true;
			}
			else
			{
				IsSymbol = true;

			}


		}
		if (IsUpper && Islower && IsNum && IsSymbol && !IsSpace && password.length() >= 8 && password.length() <= 20)
		{
			return true;
		}
		cout << endl;

			cout<<"  at least 8 characters , you should include special characters, number, capital litter,small letter and do not have spaces"<<endl;
			return false;
		
	}
/// <summary>
/// Check the min balance 1500
/// </summary>
/// <param name="balance"></param>
/// <returns>
/// bool
/// </returns>
static	bool isValidBalance(double balance) {
	if (balance<1500)
	{
		cout << endl;

		cout << "  The Minimum  balance is 1500.!!" << endl;
		return false;
	}
	return true;
	}
	/// <summary>
	/// tne min salary 5000
	/// </summary>
	/// <param name="salary"></param>
	/// <returns>
	/// bool
	/// </returns>
	static bool isValidSalary(double salary) {
		if (salary < 5000)
		{
			cout << endl;
			cout << "  The Minimum  salary is 5000.!!" << endl;
			return false;
		}
		return true;
	}

	static string EnterName(string message) {
		string name;
		do {

			cout << message;
			cin >> name;
			system("cls");

		} while (!Validation::isValidName(name));

		return name;
	}

	static string EnterPassword(string message) {
		string password;
		do {


			cout << message;
			cin >> password;
			system("cls");

		} while (!Validation::ValidatePassword(password));

		return password;
	}

	static double EnterBalance(string message) {
		double balance;
		do {

			cout << message;
			cin >> balance;
			system("cls");



		} while (!Validation::isValidBalance(balance));
		return balance;

	}

	static double EnterSalary(string message) {

		double salary;
		do {

			cout << message;
			cin >> salary;
			system("cls");



		} while (!Validation::isValidSalary(salary));

		return salary;
	}

};