#include "Login.h"

void inputForLogin() {
	cout << "Enter username: ";
	string username;
	cin >> username;
	cout << endl << "Enter password: ";
	string password;
	cin >> password;
	cout << endl;
	if (checkIfUserExist(username)) {
		if(checkIfThePasswordIsCorrect(username, password)) {
			setLoggedUser(username); 
			cout << "Successfully logged in"<<endl;
		}
		else {
			cout << "Invalid password"<<endl;
			cout <<"Enter any character to return to the login/register menu: ";
		    char x;
			cin >> x;
			cout << endl; 
			printLoginOrRegisterMenu();
		}
	} else {
		cout << "User with this username does not exist"<<endl;
		cout << "Enter any character to return to the logIn/Register menu:  ";
		char x;
		cin >> x;
		cout << endl;
		printLoginOrRegisterMenu();
	}
}


