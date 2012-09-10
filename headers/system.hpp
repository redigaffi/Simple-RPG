#ifndef CORE_H
#define CORE_H

/*
	Jordi Hoock Castro
*/
#include <iostream>
#include <fstream>
using namespace std;


struct UserDetails
{
	string name;
	string password;
	string tempUser;
	string tempPass;

}*user, ud;

class core
{

	bool debugMode;
	bool isRegistered;
	bool canRegister;
	const bool maintence;
	bool registerCorrect;
	bool userCorrect;

	public:

		/*
			Save data introduced by user
			into variables
		*/
		core(string *n, string *p, bool debug, bool maint) ; 

		/*
			When we have the name that the user
			introduced we check existence.
		*/
		bool login();

		/*
			Register user
		*/
		bool reg();

		/*
			Destruying all open files
		*/
		~core();
};

#endif