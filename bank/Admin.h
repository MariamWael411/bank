#pragma once
#include"Employee.h"
class Admin : public Employee
{

	Admin()
	{

	}
	static Admin* admin;
public:
	static Admin* getAdmin() {
		if (admin==nullptr)
		{
			admin = new Admin;
		}
		return admin;
	}



};

