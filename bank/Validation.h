#pragma once
#include <string>
using namespace std;
class Validation {
public:
	static bool isAlphabetic(const string& name) {
		for (char c : name) {
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
				return false;
		}

		return true;
	}

	static bool isValidName(const string& name) {
		if (name.size() < 5 || name.size() > 20) return false;
		return isAlphabetic(name);
	}

	static string ValidatePassword(string password) {

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
			return password;
		}
		else
		{
			return "at least 8 characters and you should include special characters , number and do not have spaces";
		}
	}

static	bool isValidBalance(double balance) {
		return balance >= 1500;
	}

	static bool isValidSalary(double salary) {
		return salary >= 5000;
	}
};