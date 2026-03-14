#pragma once
#include"FileManager.h"
#include <thread>
#include <chrono>


class ClientManager
{

public:
	static void printClientMenu() {

		cout << endl;

		cout << "  1.Deposit" << endl;
		cout << endl;

		cout << "  2.Withdraw" << endl;
		cout << endl;

		cout << "  3.Transfer To" << endl;
		cout << endl;

		cout << "  4.Check Balance" << endl;
		cout << endl;

		cout << "  5.Print Transection History" << endl;
		cout << endl;

		cout << "  6.Display My Information" << endl;
		cout << endl;
		cout << "  7.Update Password" << endl;
		cout << endl;

		cout << "  8.Logout" << endl;

	}
	static void updatePassword(Person* person) {




		cout << "  Current Password : " << person->getPassword() << endl;
		cout << endl;

		string password;
		password = Validation::EnterPassword("  Enter New Password : ");
		person->setPassword(password);
		cout << endl;
		cout << "  Updated Password Successfully" << endl;
		FileManager::UpdateClient();

	}

	static Client* login(int id, string password) {

		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i]->getId() == id && clients[i]->getPassword() == password)
			{
				return clients[i];
			}
		}
		return nullptr;

	}

	static void Exit_Back(Client* client) {
		int choice;
		do {
			cout << endl;
			cout << "  1.Options " << endl;
			cout << endl;
			cout << "  2.Exit " << endl;
			cout << endl;
			cout << "  Enter Your Choice : ";
			cin >> choice;
		} while (choice < 1 || choice>2);

		switch (choice) {
		case 1:
			system("cls");
			clientOptions(client);

			break;
		case 2:
			system("cls");
			exit(0);

			break;

		}



	}

	static bool clientOptions(Client* client) {
		int choice;
		Employee e;


		do {
			printClientMenu();
			cout << endl;
			cout << "  Enter Your Choice : ";
			cin >> choice;
			system("cls");

		} while (choice < 1 || choice>8);
		int  amount{}, id;

		Client* c = nullptr;



		int index{};
		switch (choice) {
		case 1:
			system("cls");
			cout << endl;
			cout << "  Enter Amount do you want add : ";
			cin >> amount;
			client->deposit(amount);
			FileManager::UpdateClient();

			break;
		case 2:
			system("cls");
			cout << endl;

			cout << "  Enter Amount do you want withdraw : ";
			cin >> amount;
			client->withdraw(amount);
			FileManager::UpdateClient();

			break;

		case 3:
			system("cls");
			cout << endl;

			cout << "  Enter Amount do you want Transfer : ";
			cin >> amount;
			cout << endl;
			cout << "  Enter Recipient ID : ";
			cin >> id;
			cout << endl;
			c = e.searchClient(id);

			if (c == nullptr)
			{
				cout << "  Client Not found!!" << endl;
				break;
			}
			client->TransferTo(amount, *c);
			FileManager::UpdateClient();
			break;
		case 4:
			system("cls");

			client->CheckBalance();
			break;
		case 5:
			system("cls");
			cout << endl;
			client->printTransection();
			break;
		case 6:
			system("cls");

			client->display();
			break;
		case 7:
			system("cls");
			updatePassword(client);
			break;
		case 8:
			system("cls");
			return false;
			break;
		}
		this_thread::sleep_for(std::chrono::seconds(1));

		Exit_Back(client);
		return true;
	}

};

