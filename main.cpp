/*
	Jordi Hoock Castro
*/
#include <iostream>
#include <fstream>
#include "classes/system.hpp"
using namespace std;

/*
	Variables
*/
string text;
bool loggedIN = false;
const bool maintence = false;
string regorlog;

/*
	A structure from base of user details.
*/
struct user
{
	string username;
	string password;

}*player, u;

/*
	Principal Programm
*/
int main ()
{
	player = &u;

	if (! maintence)
	{

		/*	
			What do you want, register or login?
		*/
		cout << "\nWelcome to SimpleRPG, your funny and simple roleplay game! \n" << endl;
		cout << "Hey guest!, you must login or register in order to be able play! \n" << endl;
		cout << "MENU\n1. Use the command '/register' to register\n2. Use the command '/login' to login" << endl;
		cout << "\nOPTION: ";
		cin >> regorlog;
		cout << endl;

		/*
			Menu, is for register and login the same
		*/
		if (regorlog == "/register" || regorlog == "/login")
		{
			cout << "Username: ";
			cin >> player->username;
			cout << "Password: ";
			cin >> player->password;
		}
		else
		{
			cout << "What is your intention ;) ";
		}
			
		/*
			Creating the object with user details, and
			debug mode, maintence mode.
		*/
		core s(&player->username, &player->password, false, maintence);
		core *_system = &s;


		/*
			The user want to register
		*/
		if(regorlog == "/register")
		{
			if (_system->login())
				cout << "You're username already exists";
			else
				cout << "You can do it ;)";
		}

		/*
			Want the user login?, Yes? then check's if the user exists
		*/
		if(regorlog == "/login")
		{
			loggedIN = _system->login();
		}

	}
	else
	{
		/*
			Uh uh! Maintence is on.
		*/
		cout << "\nSystem is in maintence, please be patient!\n" << endl;
	}

	if (loggedIN)
	{

		cout << "\nWelcome " << player->username << " you Logged in\n" << endl;
		cout << "\nOPTIONS: \n";
		cout << "\nSee stats: '/stats'\n";
		cout << "Credits: '/credits'\n" << endl;
		cout << "OPTION: ";
		while (cin >> text)
		{
			cout << "OPTION: " ;
			if(text == "/exit")
				break; 
		}

	}
	else
		cout << "Username is wrong";


}

