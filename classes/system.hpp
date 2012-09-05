/*
	Jordi Hoock Castro
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream userFile("data/user.txt");

class core
{

	struct UserData
	{

		string name;
		string password;
		string tempId;
		string tempUser;
		string tempPass;

	}*uData, ud;

	bool debugMode;
	bool registerCorrect;
	const bool maintence;
	bool userCorrect;

	public:

		/*
			Save data introduced by user
			into variables
		*/
		core(string n, string p, bool debug, bool maint) 
		:debugMode(debug), maintence(maint)
		{
			uData = &ud;
			uData->name = n;
			uData->password = p;

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

				while (userFile >> uData->tempId >> uData->tempUser >> uData->tempPass) 
				{
					if (uData->tempUser == uData->name && uData->tempPass == uData->password)
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

