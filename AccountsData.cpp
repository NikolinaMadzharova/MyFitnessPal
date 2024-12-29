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
vector<double> recommendedDailyCalories;
vector<double> proteinGR;
vector<double> fatGR;
vector<double> carbohydratesGR;

void setLoggedUser(string username) {
	loggedUser = getUserIndex(username);
}

unsigned getUsersCount() {
	return usernames.size();
}

void addUser(const string& username,const string& password, unsigned age, unsigned gender,
	unsigned height, double weight, unsigned activityLevel, unsigned goal,unsigned kgPerWeekGoal, unsigned accountType) {
	addUsername(username);
	addPassword(password);
	addAge(age);
	addGender(gender);
	addHeight(height);
	addWeight(weight);
	addActivityLevel(activityLevel);
	addGoal(goal);
	addKgPerWeekGoal(kgPerWeekGoal);
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

void addKgPerWeekGoal(unsigned kgPerWeekGoal) {
	kgPerWeekGoals.push_back(kgPerWeekGoal);
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

const vector<unsigned>& getKgPerWeekGoals() {
	return kgPerWeekGoals;
}

const vector<unsigned>& getAccountTypes() {
	return accountTypes;
}

const vector<double>& getRecommendedDailyCalories() {
	return recommendedDailyCalories;
}

const vector<double>& getProtein() {
	return proteinGR;
}

const vector<double>& getFatt() {
	return fatGR;
}

const vector<double>& getCarbohydrates() {
	return carbohydratesGR;
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

void addRecommendedDailyCalories(double dailyCalories) {
	recommendedDailyCalories.push_back(dailyCalories);
}

void addMacronutrients(double protein, double fat, double carbohydrates) {
	addProtein(protein);
	addFat(fat);
	addCarbohydrates(carbohydrates);
}

void addProtein(double protein) {
	proteinGR.push_back(protein);
}

void addFat(double fat) {
	fatGR.push_back(fat);
}

void addCarbohydrates(double carbohydrates) {
	carbohydratesGR.push_back(carbohydrates);
}