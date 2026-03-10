#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
public:
   static void addClient(Client obj) {

        FileHelper::saveClient(obj);

    }
   static void addEmployee(Employee obj) {
        FileHelper::saveEmployee(obj);
    }
   static void addAdmin(Admin * obj) {
        FileHelper::saveAdmin(obj);
    }

   static void getAllClients() {
        FileHelper::getClients();
    }
   static void getAllEmployees() {
        FileHelper::getEmployees();
    }
   static void getAllAdmins() {
        FileHelper::getAdmin();
    }

   static void removeAllClients() {
        FileHelper::ClearFiles(ClientsFile, client_l_Id);
    }
   static void removeAllEmployees() {
        FileHelper::ClearFiles(EmployeesFile, employee_l_Id);
    }
   static void removeAllAdmins() {
        FileHelper::ClearFiles(AdminFile,admin_l_Id);
    }
   static int ReturnIndexOfClient(Client* c) {

       int index{};
       for (int i = 0; i < clients.size(); i++)
       {
           if (clients[i]->getId() == c->getId())
           {
               index = i;
               break;
           }
       }
       return index;

   }
};