#include "FileManager.h"

void FileManager::addClient(Client obj) {
    FileHelper::saveClient("Files/Clients.txt",
        "Files/LastClientId.txt",
        obj);
}

void FileManager::addEmployee(Employee obj) {
    FileHelper::saveEmployee("Files/Employees.txt",
        "Files/LastEmployeeId.txt",
        obj);
}

void FileManager::addAdmin(Admin obj) {
    FileHelper::saveAdmin("Files/Admin.txt",
        "Files/LastAdminId.txt",
        &obj);
}

void FileManager::getAllClients() {
    FileHelper::getClients();
}

void FileManager::getAllEmployees() {
    FileHelper::getEmployees();
}

void FileManager::getAllAdmins() {
    FileHelper::getAdmin();
}

void FileManager::removeAllClients() {
    FileHelper::ClearFiles("Files/Clients.txt",
        "Files/LastClientId.txt");
}

void FileManager::removeAllEmployees() {
    FileHelper::ClearFiles("Files/Employees.txt",
        "Files/LastEmployeeId.txt");
}

void FileManager::removeAllAdmins() {
    FileHelper::ClearFiles("Files/Admin.txt",
        "Files/LastAdminId.txt");
}