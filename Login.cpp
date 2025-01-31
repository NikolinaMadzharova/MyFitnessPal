/**
* Solution to course project # 9
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author Nikolina Aleksandrova Madzharova
* @idnumber 0MI0600464
* @compiler VC
*
* <login information>
*
*/

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
		}
	} else {
		cout << "User with this username does not exist"<<endl;
	}
}


