#include "Client.h"
#include"FileHelper.h"
int Client::countId = 0;
Client::Client() :Person() {

	countId++;
	id = countId;
	FileHelper::SaveLast("ClientLastId.txt", countId);

}
Client::Client(string name, string password, double balance) : Person(name, password) {
	countId++;
	id = countId;
	this->balance = balance;
	FileHelper::saveClient("Clients.txt", "ClientLastId.txt", *this);


}





