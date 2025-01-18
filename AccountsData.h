#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void setLoggedUser(string username);
int getLoggedUserIndex();
unsigned getUsersCount();
void addUsername(const string& username);
void addPassword(const string& password);
void addAge(unsigned age);
void addGender(unsigned gender);
void addHeight(unsigned height);
void addWeight(double weight);
void addActivityLevel(unsigned activityLevel);
void addGoal(unsigned goal);
void addKgPerWeekGoal(unsigned kgPerWeekGoal);
void addAccountType(unsigned accountType);
bool checkIfUserExist(string username);
bool checkIfThePasswordIsCorrect(string username, string password);
int getUserIndex(string username);
const vector<string>& getUsernames();
const vector<unsigned>& getAges();
const vector<unsigned>& getHeights();
const vector<string>& getPasswords();
const vector<double>& getWeights();
const vector<unsigned>& getGenders();
const vector<unsigned>& getActivityLevels();
const vector<unsigned>& getGoals();
const vector<unsigned>& getKgPerWeekGoals();
const vector<unsigned>& getAccountTypes();

string getUserByIndex(unsigned index);
unsigned getAccountTypeLoggedUser();
unsigned getGenderLoggedUser();
double getWeightLoggedUser();
unsigned getHeightLoggedUser();
unsigned getAgeLoggedUser();
unsigned getActivityLevelLoggedUser();
unsigned getGoalLoggedUser();
unsigned getKgPerWeekGoalLoggedUser();
void editHeight(unsigned newHeight);
void editWeight(double newWeight);
void editActivityLevel(unsigned newActivityLevel);
void editGoal(unsigned newGoal);
void editKgPerWeekGoal(unsigned newKgPerWeekGoal);
