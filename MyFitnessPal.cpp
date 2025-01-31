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
* <main function file>
* 
*/

#include "Login.h"
#include "Register.h"
#include "FilesHandler.h"
#include "Menu.h"

int main()
{
	readFromFile();
	printHeader();	
	saveToFile();
}
