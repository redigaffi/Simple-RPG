/*
	Jordi Hoock Castro
*/

#include <iostream>
#include <fstream>
using namespace std;

char a ;
ifstream _check("data/users.txt");

class core
{
	string name;
	string password;
	const bool debugMode;
	bool registerCorrect;
	bool maintence;
	bool userCorrect;

	public:
		/*
			Save data introduced by user
			into variables
		*/
		core(string n, string p, bool debug, bool maint) 
		:name(n), password(p), debugMode(debug), maintence(maint)
		{
			if (this->debugMode)
				cout << "\nSystem Inicialized!\n" << endl;
			try
			{
				if(! _check.is_open())
					throw 0;
			}
			catch (int error)
			{
				if (this->debugMode)
					cout << "\nSYSTEM ERROR - " << error;
			}	
		}

		/*
			When we have the name that the user
			introduced we check existence.
		*/
		bool login ()
		{
			string tempUser;
			string tempPass;
			try
			{
				while (_check >> tempUser >> tempPass) 
				{
					if (tempUser == this->name && tempPass == password)
					{
						this->userCorrect = true;
						break;
					}
					else
					{
						this->userCorrect = false;
						throw 1;
					}

				}
			}
			catch ( ... ) { cout << "The're were an error"; }
			return (this->userCorrect);
		}

};

