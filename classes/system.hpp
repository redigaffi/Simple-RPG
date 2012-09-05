/*
	Jordi Hoock Castro
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream userFile("data/user.txt");

class core
{

	string name;
	string password;
	string tempId;
	string tempUser;
	string tempPass;
	const bool debugMode;
	bool registerCorrect;
	bool maintence;
	bool userCorrect;

	public:

		/*
			Save data introduced by user
			into variables
		*/
		core(string *n, string *p, bool debug, bool maint) 
		:name(*n), password(*p), debugMode(debug), maintence(maint)
		{

			if (this->debugMode)
				cout << "\nSystem Inicialized!\n" << endl;
			try
			{
				if(! userFile.is_open())
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

			try
			{

				while (userFile >> this->tempId >> this->tempUser >> this->tempPass) 
				{
					if (this->tempUser == this->name && this->tempPass == this->password)
					{
						this->userCorrect = true;	
						break;			
					}
					else
						this->userCorrect = false;	
				}

			}
			catch ( ... ) { }

			return (this->userCorrect);

		}

};

