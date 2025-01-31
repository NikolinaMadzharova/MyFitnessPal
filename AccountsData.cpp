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
* <user information file>
*
*/

#include "AccountsData.h"
int loggedUser = -1;

vector<string> usernames;
vector<string> passwords;
vector<unsigned> ages;
vector<unsigned> heights;
vector<double> weights;
vector<unsigned> genders;
vector<unsigned> activityLevels;
vector<unsigned> goals;
vector<unsigned> kgPerWeekGoals;
vector<unsigned> accountTypes;

void setLoggedUser(string username) {
	loggedUser = getUserIndex(username);
}

int getLoggedUserIndex() {
	return loggedUser;
}

unsigned getUsersCount() {
	return usernames.size();
}

void addUsername(const string& username) {
	usernames.push_back(username);
}

void addPassword(const string& password) {
	passwords.push_back(password);
}

void addAge(unsigned age) {
	ages.push_back(age);
}

void addGender(unsigned gender) {
	genders.push_back(gender);
}

void addHeight(unsigned height) {
	heights.push_back(height);
}

void addWeight(double weight) {
	weights.push_back(weight);
}

void addActivityLevel(unsigned activityLevel) {
	activityLevels.push_back(activityLevel);
}

void addGoal(unsigned goal) {
	goals.push_back(goal);
}

void addKgPerWeekGoal(unsigned kgPerWeekGoal) {
	kgPerWeekGoals.push_back(kgPerWeekGoal);
}

void addAccountType(unsigned accountType) {
	accountTypes.push_back(accountType);
}

bool checkIfUserExist(const string& username) {
	for (int i = 0; i < usernames.size(); i++) {
		if (usernames[i] == username) {
			return true;
		}
	}
	return false;
}

bool checkIfThePasswordIsCorrect(const string& username,const string& password) {
	for (int i = 0; i < usernames.size(); i++) {
		if (usernames[i] == username) {
			if (passwords[i] == password) {
				return true;
			}
			return false;
		}
	}
	//never reached
	return false;
}

int getUserIndex(const string& username) {
	for (int i = 0; i < usernames.size(); i++) {
		if (usernames[i] == username) {
			return i;
		}
	}
	return -1;
}

const vector<string>& getUsernames() {
	return usernames;
}

const vector<unsigned>& getAges() {
	return ages;
}

const vector<unsigned>& getHeights() {
	return heights;
}

const vector<string>& getPasswords() {
	return passwords;
}

const vector<double>& getWeights() {
	return weights;
}

const vector<unsigned>& getGenders() {
	return genders;
}

const vector<unsigned>& getActivityLevels() {
	return activityLevels;
}

const vector<unsigned>& getGoals() {
	return goals;
}

const vector<unsigned>& getKgPerWeekGoals() {
	return kgPerWeekGoals;
}

const vector<unsigned>& getAccountTypes() {
	return accountTypes;
}

string getUserByIndex(unsigned index) {
	return usernames[index];
}

unsigned getAccountTypeLoggedUser() {
	return accountTypes[loggedUser];
}

unsigned getGenderLoggedUser() {
	return genders[loggedUser];
}

double getWeightLoggedUser() {
	return weights[loggedUser];
}

unsigned getHeightLoggedUser() {
	return heights[loggedUser];
}

unsigned getAgeLoggedUser() {
	return ages[loggedUser];
}

unsigned getActivityLevelLoggedUser() {
	return activityLevels[loggedUser];
}

unsigned getGoalLoggedUser() {
	return goals[loggedUser];
}

unsigned getKgPerWeekGoalLoggedUser() {
	return kgPerWeekGoals[loggedUser];
}

void editHeight(unsigned newHeight) {
	heights[loggedUser] = newHeight;
}

void editWeight(double newWeight) {
	weights[loggedUser] = newWeight;
}

void editActivityLevel(unsigned newActivityLevel) {
	activityLevels[loggedUser] = newActivityLevel;
}

void editGoal(unsigned newGoal) {
	goals[loggedUser] = newGoal;
}

void editKgPerWeekGoal(unsigned newKgPerWeekGoal) {
	kgPerWeekGoals[loggedUser] = newKgPerWeekGoal;
}
