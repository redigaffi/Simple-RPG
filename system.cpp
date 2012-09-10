/*
	Jordi Hoock Castro
*/
	
#include "headers/system.hpp"
ifstream userFile("data/users.txt");
ofstream saveFile("data/users.txt", ios::binary | ios::ate | ios::out | ios::in);

core::core(string *n, string *p, bool debug, bool maint)
:debugMode(debug), maintence(maint)
{
	user = &ud;
	user->name = *n;
	user->password = *p;

	this->canRegister = true;
	
	if (this->debugMode)
		cout << "\nSystem Inicialized!\n With user: " << user->name << "\nAnd password: " << user->password << endl;
	try
	{
		if(! userFile.is_open())
			throw 0;
	}
	catch ( ... )
	{
		if (this->debugMode)
			cout << "\nCRITICAL SYSTEM ERROR - ";
	}	
}

bool core::login()
{
	try
	{
		while (userFile >> user->tempUser >> user->tempPass) 
		{
			if (user->name == user->tempUser && user->password == user->tempPass)
			{
				this->userCorrect = true;
				break;
			}
			else
			{
				this->userCorrect = false;
				continue;
			}
		}
	}
	catch ( ... ) 
	{ 
		if(this->debugMode)
			cout << "An error ocurred loggin in";
	}

	return (this->userCorrect);
}

bool core::reg()
{
	try
	{
		while(userFile >> user->tempUser >> user->tempPass)
		{
			if(user->name == user->tempUser)
			{
				this->canRegister = false;
				break;
			}
		}

		if(this->canRegister)
		{
			if(saveFile << " " << user->name << " " << user->password)
				this->isRegistered = true;	
		}

		
	}
	catch ( ... )
	{
		if(this->debugMode)
			cout << "An error ocurred saving your profile";
	}

	return (this->isRegistered);
}

core::~core()
{
	userFile.close();
}