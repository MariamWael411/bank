#pragma once
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FileManager : public DataSourceInterface {
public:
    void addClient(Client obj) {

        FileHelper::saveClient(obj);

    }
    void addEmployee(Employee obj) {
        FileHelper::saveEmployee(obj);
    }
    void addAdmin(Admin * obj) {
        FileHelper::saveAdmin(obj);
    }

    void getAllClients() {
        FileHelper::getClients();
    }
    void getAllEmployees() {
        FileHelper::getEmployees();
    }
     void getAllAdmins() {
        FileHelper::getAdmin();
    }

    void removeAllClients() {
        FileHelper::ClearFiles(ClientsFile, client_l_Id);
    }
    void removeAllEmployees() {
        FileHelper::ClearFiles(EmployeesFile, employee_l_Id);
    }
    void removeAllAdmins() {
        FileHelper::ClearFiles(AdminFile,admin_l_Id);
    }
};