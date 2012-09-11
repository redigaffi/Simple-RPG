/*
	Jordi Hoock Castro
*/
	
#include "headers/system.hpp"
ifstream userFile("data/users.txt");
ofstream saveFile("data/users.txt", ios::binary | ios::ate | ios::out | ios::in);
ifstream readStats("data/stats.txt");

core::core(string *n, string *p, bool debug, bool maint)
:debugMode(debug), maintence(maint)
{
	user = &ud;
	stat = &st;
	user->name = *n;
	user->password = *p;

	this->canRegister = true;
	
	/*
		Initalizing user stats
	*/


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

bool core::InitStats(bool print = false)
{
	while(readStats >> stat->Tempname >> stat->Temptype >> stat->Tempmoney)
	{
		if (stat->Tempname == user->name)
		{
			stat->name = user->name;
			stat->type = stat->Temptype;
			stat->money = stat->Tempmoney;
			/*
				Saving in a public var for get public acces
			*/
			this->userstats[0] = stat->name;
			this->userstats[1] = stat->type;
			this->userstats[2] = stat->money;
			this->STAT = true;
			break;
		}
		else
			this->STAT = false;
	}

	if(print)
	{
		cout << stat->name << " " << stat->type << " " << stat->money << endl;
	}

	return (this->STAT);

}

core::~core()
{
	userFile.close();
	saveFile.close();
}