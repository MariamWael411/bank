#pragma once

#include"ClientManager.h"
#include"EmployeeManager.h"
#include"AdminManager.h"

class Screens
{

public:
	static void bankName() {
		system("color 9F");

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		string letters[8][9] = {

			{
				"             ***********  ",
				"             ***********  ",
				"             **           ",
				"             **           ",
				"             *********    ",
				"             *********    ",
				"             **           ",
				"             **           ",
				"             **           "
			},

			{
				"***********  ",
				"***********  ",
				"    ***      ",
				"    ***      ",
				"    ***      ",
				"    ***      ",
				"    ***      ",
				"***********  ",
				"***********  "
			},

			{
				"*********    ",
				"*********    ",
				"**     **    ",
				"**     **    ",
				"*********    ",
				"*********    ",
				"**     **    ",
				"**     **    ",
				"*********    "
			},

			{
				"     ",
				"     ",
				"     ",
				"     ",
				"     ",
				"     ",
				"     ",
				"     ",
				"     "
			},

			{
				"*********    ",
				"*********    ",
				"**     **    ",
				"**     **    ",
				"*********    ",
				"*********    ",
				"**     **    ",
				"**     **    ",
				"*********    "
			},

			{
				"    ***      ",
				"   *****     ",
				"  **   **    ",
				" **     **   ",
				"***********  ",
				"***********  ",
				"**       **  ",
				"**       **  ",
				"**       **  "
			},

			{
				"**       **  ",
				"***      **  ",
				"****     **  ",
				"** **    **  ",
				"**  **   **  ",
				"**   **  **  ",
				"**    ** **  ",
				"**     ****  ",
				"**      ***  "
			},

			{
				"**      **   ",
				"**     **    ",
				"**    **     ",
				"**   **      ",
				"*****        ",
				"*****        ",
				"**   **      ",
				"**    **     ",
				"**     **    "
			}
		};

		for (int row = 0; row < 9; row++) {
			for (int letter = 0; letter < 8; letter++) {
				cout << letters[letter][row];
			}
			cout << "\n";
		}



	}
	static void welcome() {

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		string letters[7][9] = {
			
			{
				"                   **       **  ",
				"                   **       **  ",
				"                   **       **  ",
				"                   **   *   **  ",
				"                   **  ***  **  ",
				"                    ** *** **   " ,
				"                    **** ****   " ,
				"                     ***  ***   ",
				"                      *    *    "
			},
			
			{
				"***********  ",
				"***********  ",
				"**           ",
				"**           ",
				"*********    ",
				"*********    ",
				"**           ",
				"***********  ",
				"***********  "
			},
			
			{
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"***********  ",
				"***********  "
			},
			
			{
				" *********   ",
				"***********  ",
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"**           ",
				"***********  ",
				" *********   "
			},
			
			{
				" *********   ",
				"***********  ",
				"**       **  ",
				"**       **  ",
				"**       **  ",
				"**       **  ",
				"**       **  ",
				"***********  ",
				" *********   "
			},
			
			{
				"**       **  ",
				"***     ***  ",
				"****   ****  ",
				"** *** ***   ",
				"**  ***  **  ",
				"**   *   **  ",
				"**       **  ",
				"**       **  ",
				"**       **  "
			},
			
			{
				"***********  ",
				"***********  ",
				"**           ",
				"**           ",
				"*********    ",
				"*********    ",
				"**           ",
				"***********  ",
				"***********  "
			}
		};

		for (int row = 0; row < 9; row++) {
			for (int letter = 0; letter < 7; letter++) {
				cout << letters[letter][row];
			}
			cout << "\n";
		}

	}


        
       
	
	
	static void loginOptions() {
		cout << endl;

		cout << "  Login As:  " << endl;
		cout << endl;
		cout << "  1.client" << endl;
		cout << endl;

		cout << "  2.Employee" << endl;
		cout << endl;

		cout << "  3.Admin" << endl;
		cout << endl;

		cout << "  Enter Your choice : ";

	}

	static int loginAs() {

		loginOptions();
		int num;

		cin >> num;

		invalid(num);
		system("cls");
		loginScreen(num);
		return num;
	}

	static void invalid(int c) {



		while (c < 1 || c>3) {
			system("cls");
			cout << "  Invalid Choice !!" << endl;

			loginAs();

		}
	}


	static void logout() {
		loginAs();
	}

	static void loginScreen(int c) {

		int id;
		string password;
		cout << endl;
		cout << "  Enter Your id : ";
		cin >> id;
		cout << endl;
		bool Op = true;

		password = Validation::EnterPassword("  Enter Your password : ");
		Client* client = nullptr;
		Employee* employee = nullptr;
		Admin* admin = nullptr;

		switch (c) {

		case 1:
			client = ClientManager::login(id, password);
			if (client != nullptr) {
				cout << endl;
				cout << "====================  " << client->getName() << "  ======================" << endl;

				while (Op) {
					Op = ClientManager::clientOptions(client);

				}

				logout();

			}
			break;

		case 2:


			employee = EmployeeManager::login(id, password);
			if (employee != nullptr)
			{
				cout << endl;

				cout << "====================  " << employee->getName() << "  ======================" << endl;
				while (Op) {
					Op = EmployeeManager::employeeOptions(employee);
				}
				logout();

			}
			break;
		case 3:
			admin = AdminManager::login(id, password);

			if (admin != nullptr)
			{
				cout << endl;

				cout << "====================  " << admin->getName() << "  ======================" << endl;
				while (Op) {
					Op = AdminManager::AdminOptions(admin);
				}
				logout();

			}
			break;

		}


	}







	static void runApp() {
		FileManager::getAllData();
		bankName();
		this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
		welcome();
		this_thread::sleep_for(std::chrono::seconds(2));
		system("cls");
		int c, num;


		do {
			cout << endl;
			cout << "  1.Login" << endl;
			cout << endl;
			cout << "  2.Exit" << endl;
			cout << endl;
			cout << "  Enter Your Choice : ";

			cin >> c;
			system("cls");

		} while (c < 1 || c>2);
		switch (c) {

		case 1:
			system("cls");
			c = loginAs();

			loginScreen(c);
			break;
		case 2:
			system("cls");

			exit(0);
			break;
		}


	}


};



