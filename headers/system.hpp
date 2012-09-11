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

struct stats
{
	string name;
	string type;
	string money;
	string Tempname;
	string Temptype;
	string Tempmoney;

}*stat, st;

class core
{

	private:

		// Is debugging mode On?
		const bool debugMode;
		// Stats system processed correctly (true:false)
		bool STAT;
		// Have registered succesfylly (true:false)
		bool isRegistered;
		// Exists username already (true:false)
		bool canRegister;
		// Maintence mode on (true:false)
		const bool maintence;
		// Is the register correct (true:false)
		bool registerCorrect;
		// Is user acces correct (true:false)
		bool userCorrect;

	public:

		/*	
			User data stored in an array
		*/
		string userstats[3];
		
		/*
			Save data introduced by user
			into variables
		*/
		core(string *n, string *p, bool debug, bool maint);
		core(); 

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
			Showing statistics of users
		*/
		bool InitStats(bool print);

		/*
			Working with the user stats (data returned as an array of type string)
		*/
		void WorkWithStats(string saveto[]);

		/*
			Destruying all open files
		*/
		~core();
};

#endif