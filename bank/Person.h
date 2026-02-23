#pragma once

#include "Validation.h"
using namespace std;

class Person {
protected:
    int id;
    string name;
    string password;

public:
    Person() {
        id = 0;
    }

    Person( string name, string password) {
        
        setName(name);
        setPassword(password);
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        if (Validation::isValidName(name))
            this->name = name;
           }

    void setPassword(string password) {
        if (Validation::ValidatePassword(password)) {
            this->password = password;
       }
            
    }

    int getId()  {
        return id;
    }

    string getName()  {
        return name;
    }

    string getPassword()  {
        return password;
    }

    virtual void display()  {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
};



