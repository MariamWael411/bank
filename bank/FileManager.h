#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
public:
   static void addClient(Client c) {

        FileHelper::saveClient("Files/Clients.txt", "Files/ClientLastId.txt", c);

    }
   static void addEmployee(Employee e) {
        FileHelper::saveEmployee("Files/Employees.txt", "Files/EmployeeLastId.txt", e);
    }
   static void addAdmin(Admin *a) {
        FileHelper::saveAdmin("Files/Admin.txt", "Files/AdminLastId.txt", a);
    }

   static void getAllClients() {
        FileHelper::getClients();
    }
   static void getAllEmployees() {
        FileHelper::getEmployees();
    }
   static  void getAllAdmins() {
        FileHelper::getAdmin();
    }

   static void removeAllClients() {
        FileHelper::ClearFiles("Files/Clients.txt", "Files/ClientLastId.txt");
    }
   static void removeAllEmployees() {
        FileHelper::ClearFiles("Files/Employees.txt", "Files/EmployeeLastId.txt");
    }
   static void removeAllAdmins() {
        FileHelper::ClearFiles("Files/Admin.txt", "Files/AdminLastId.txt");
    }
};