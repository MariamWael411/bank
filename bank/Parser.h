#pragma once
#include<sstream>
#include<vector>
#include"Client.h"
#include"Admin.h"
class Parser
{
	/// <summary>
/// Splits a string into tokens and return them in a vector
/// </summary>
/// <param name="line"></param>
/// <returns></returns>
	static vector<string> split(string line) {
		string s;
		stringstream ss{ line };
		vector<string> v;
		while (getline(ss, s, '&'))
		{
			v.push_back(s);
		}
		return v;
	}
public:

	/// <summary>
	/// Parser a line of text and converts it into a client object
	/// </summary>
	/// <param name="line"></param>
	/// <returns>
	/// client
	/// </returns>
	static Client* ParserToClient(string line) {
		Client* c=new Client;
		vector<string> v = Parser::split(line);
		c->setId(stoi(v[0]));
		c->setName(v[1]);
		c->setPassword(v[2]);
		c->setBalance(stod(v[3]));
		return c;

	}
	/// <summary>
	///  Parser a line of text and converts it into a employee object
	/// </summary>
	/// <param name="line"></param>
	/// <returns>
	/// employee
	/// </returns>
	static Employee* ParserToEmployee(string line) {
		Employee* e=new Employee;
		vector<string> v = Parser::split(line);
		e->setId(stoi(v[0]));
		e->setName(v[1]);
		e->setPassword(v[2]);
		e->setSalary(stod(v[3]));
		return e;

	}
	/// <summary>
	///  Parser a line of text and converts it into a admin object
	/// </summary>
	/// <param name="line"></param>
	/// <returns>
	/// admin
	/// </returns>
	static Admin* ParserToAdmin(string line) {
		Admin *a=Admin::getAdmin();
		vector<string> v = Parser::split(line);
		a->setId(stoi(v[0]));
		a->setName(v[1]);
		a->setPassword(v[2]);
		a->setSalary(stod(v[3]));
		return a;
		
	}
};

