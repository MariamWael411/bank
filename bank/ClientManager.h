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


	static void updatePassword(Client* client) {

		int id, index{};
		cout << "  Enter Your ID : ";
		cin >> id;

		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i]->getId() == id)
			{
				index = i;
				break;
			}
		}

		cout << "  Current Password : " << clients[index]->getPassword() << endl;
		cout << endl;
		cout << "  Enter New Password : ";
		string password;
		cin >> password;
		client->setPassword(password);
		cout << endl;
		cout << "  Updated Password Successfully" << endl;
		clients[index]->setPassword(password);
	}

	static Client* login(int id, string password) {
		FileManager::getAllClients();
		for (int i = 0; i < clients.size(); i++)
		{
			if (clients[i]->getId() == id && clients[i]->getPassword() == password)
			{
				return clients[i];
			}
		}
		return nullptr;

	}
	static bool clientOptions(Client* client) {
		int choice, amount{}, index{}, id;
		bool running = true;
		bool running2 = true;
		bool flag = false;

		Client* c = nullptr;
		while (running) {
			running2 = true;
			printClientMenu();
			cout << endl;
			cout << "  Enter Your Choice : ";
			cin >> choice;
			int index{};
			switch (choice) {
			case 1:
				system("cls");
				cout << endl;
				cout << "  Enter Amount do you want add : ";
				cin >> amount;
				client->deposit(amount);
				index = FileManager::ReturnIndexOfClient(client);
				clients[index]->setBalance(client->getBalance());
			

				break;
			case 2:
				system("cls");
				cout << endl;

				cout << "  Enter Amount do you want withdraw : ";
				cin >> amount;
				client->withdraw(amount);
				index = FileManager::ReturnIndexOfClient(client);
				clients[index]->setBalance(client->getBalance());
			
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
				for (int i = 0; i < clients.size(); i++)
				{
					if (clients[i]->getId() == id)
					{
						c = clients[i];
						break;
					}
				}
				if (c == nullptr)
				{
					cout << "  Client Not found!!" << endl;
					break;
				}
				client->TransferTo(amount, *c);
				index = FileManager::ReturnIndexOfClient(client);
				clients[index]->setBalance(client->getBalance());
				index = FileManager::ReturnIndexOfClient(c);
				clients[index]->setBalance(c->getBalance());
				

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

				running = false;
				return false;
				break;
			default:
				system("cls");
				cout << "  Invalid Choice!!" << endl;
				running2 = false;
				break;
			}
			this_thread::sleep_for(std::chrono::seconds(1));
			while (running2) {
				cout << endl;
				cout << "  1.Options " << endl;
				cout << endl;
				cout << "  2.Exit " << endl;
				cout << endl;
				cout << "  Enter Your Choice : ";
				cin >> choice;
				switch (choice) {
				case 1:
					system("cls");

					running2 = false;
					break;
				case 2:
					system("cls");

					running = false;
					flag = true;
					break;
				default:
					system("cls");
					cout << "Invalid Choice!!" << endl;

					break;
				}
				if (flag)
				{
					break;
				}


			}


		}

		return true;


	}




};

