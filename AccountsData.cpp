#include "AccountData.h"

int loggedUser = -1;

vector<string> usernames;
vector<string> passwords;
vector<unsigned> ages;
vector<unsigned> heights;
vector<double> weights;
vector<unsigned> genders;
vector<unsigned> activityLevels;
vector<unsigned> goals;
vector<unsigned> accountTypes;

string getUserByIndex(unsigned index) {
	return usernames[index];
}

unsigned getAccountTypeByIndex(unsigned index) {
	return accountTypes[index];
}

void setLoggedUser(string username) {
	loggedUser = getUserIndex(username);
}

unsigned getUsersCount() {
	return usernames.size();
}


void addUser(const string& username,const string& password, unsigned age, unsigned gender, unsigned height, double weight, unsigned activityLevel, unsigned goal, unsigned accountType) {
	addUsername(username);
	addPassword(password);
	addAge(age);
	addGender(gender);
	addHeight(height);
	addWeight(weight);
	addActivityLevel(activityLevel);
	addGoal(goal);
	addAccountType(accountType);
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

void addAccountType(unsigned accountType) {
	accountTypes.push_back(accountType);
}


bool checkIfUserExist(string username) {
	for (int i = 0; i < usernames.size(); i++) {
		if (usernames[i] == username) {
			return true;
		}
	}
	return false;
}

bool checkIfThePasswordIsCorrect(string username, string password) {
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

int getUserIndex(string username) {
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

const vector<unsigned>& getAccountTypes() {
	return accountTypes;
}