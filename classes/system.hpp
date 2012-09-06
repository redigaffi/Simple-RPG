/*
	Jordi Hoock Castro
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream userFile("data/users.txt");

struct UserDetails
{
	string name;
	string password;
	string tempId;
	string tempUser;
	string tempPass;

}*user, ud;


class core
{

	bool debugMode;
	const bool maintence;
	bool registerCorrect;
	bool userCorrect;

	public:

		/*
			Save data introduced by user
			into variables
		*/
		core(string *n, string *p, bool debug, bool maint) 
		:debugMode(debug), maintence(maint)
		{
			user = &ud;
			user->name = *n;
			user->password = *p;

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

		/*
			When we have the name that the user
			introduced we check existence.
		*/
		bool login ()
		{

			try
			{
				while (userFile >> user->tempId >> user->tempUser >> user->tempPass) 
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

		~core()
		{
			userFile.close();
		}
};

