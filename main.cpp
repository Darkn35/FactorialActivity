#include <iostream>
#include <ios>
#include <limits>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mainProgram();
void factorizeFunc(int factorizeFunc);
void tryAgainFunc();

int main(int argc, char** argv) {
	mainProgram();
	return 0;
}

void mainProgram() // function for the main program, asks the user for a number to factorize
{
	cout << "Factorization Program \nEnter any number you wish to factorize.\n";
	
	int userInput;
	cin >> userInput;
	
	while(1) // checks whether userInput is int or not
	{
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout<<"Please input positive integers only!"<<endl;
			cin>>userInput;
		}
		if(!cin.fail())
	break;
	}
	
	factorizeFunc(userInput);
}

void factorizeFunc(int userInput) // back end of the program where it factorizes said userInput, while also error handling
{
	if (userInput == 0)
	{
		cout << "Factorial of " << userInput << " is 1.";
	}
	else if (userInput < 0)
	{
		cout << "Please input positive integers only!\n";
	}
	else
	{
		int productNumber = 1;
		int factorialNum = userInput;
		
		while(userInput > 1)
		{
			productNumber *= userInput;
			userInput--;
		}
		cout << "Factorial of " << factorialNum << " is " << productNumber << "\n";
	}
	tryAgainFunc();	
}

void tryAgainFunc() // separate try again function in order to not loop the main program
{
	char tryAgain;
	
	cout << "\nTry again? [y/n]: " ;
	cin >> tryAgain ;
	
	switch(tryAgain)
	{
		case 'y' :
		case 'Y' :
			{
				cout << "\n" ;
				mainProgram();
			}
			break;
		case 'n' :
		case 'N' :
			{
				return;
			}
			break;
		default :
			{
				cout << "Please do not input other characters!\n";
				tryAgainFunc();
			}
			break;
	}
}

