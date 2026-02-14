#pragma once
#include <iostream>
#include <string>
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
        name = "";
        password = "";
    }

    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }

    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        if (Validation::isValidName(name))
            this->name = name;
        else
            cout << "Name must be Alphabetic and at least size 3 and max 20" << endl;
    }

    void setPassword(string password) {
        this->password = Validation::ValidatePassword(password);
            
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

    void display()  {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
};



