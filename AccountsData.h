#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void setLoggedUser(string username);
unsigned getUsersCount();
void addUser(const string& username, const string& password, unsigned age, unsigned gender,
	unsigned height, double weight, unsigned activityLevel, unsigned goal, unsigned kgPerWeekGoal, unsigned accountType);
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
const vector<double>& getRecommendedDailyCalories();
const vector<double>& getFatt();
const vector<double>& getFatt();
const vector<double>& getCarbohydrates();
string getUserByIndex(unsigned index);
unsigned getAccountTypeLoggedUser();
unsigned getGenderLoggedUser();
double getWeightLoggedUser();
unsigned getHeightLoggedUser();
unsigned getAgeLoggedUser();
unsigned getActivityLevelLoggedUser();
unsigned getGoalLoggedUser();
unsigned getKgPerWeekGoalLoggedUser();
void addRecommendedDailyCalories(double dailyCalories);
void addMacronutrients(double protein, double fat, double carbohydrates);
void addProtein(double protein);
void addFat(double fat);
void addCarbohydrates(double carbohydrates);
