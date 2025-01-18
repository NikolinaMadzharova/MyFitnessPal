#pragma once
#include "AccountsData.h"
#include "Menu.h"

void inputForLogin();
bool checkIfUserExist(string username);
bool checkIfThePasswordIsCorrect(string username, string password);
int getUserIndex(string username);
