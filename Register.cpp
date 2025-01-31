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
* <register function>
*
*/
#include "Register.h"
#include "DailyReport.h"
constexpr unsigned MIN_HEIGHT = 70;
constexpr unsigned MAX_HEIGHT = 300;
constexpr double MIN_WEIGHT = 20.0;
constexpr double MAX_WEIGHT = 400.0;
constexpr unsigned MAX_AGE = 150;

void registration() {
	enterUsername();
	enterPassword();
	enterAge();
	enterHeight();
	enterWeight();
	enterGender();
	enterActivityLevel();
	enterGoal();
	enterAccountType();
}

void enterUsername() {
	cout << "Enter your username: ";
	string username;
	cin >> username;
	cout << endl;

	if (!isUsernameValid(username)) {
		cout << "Invalid username. Try again" << endl;
		enterUsername();
	}
	else {
		addUsername(username);	
	}
}

void enterPassword() {
	cout << "Enter your password: ";
	string password;
	cin >> password;
	cout << endl;
	addPassword(password);
}

void enterAge() {
	cout << "Enter your age (in years): ";
	unsigned age;
	cin >> age;
	cout << endl;
	if (!isAgeValid(age)) {
		cout << "Invalid age. Try again" << endl;
		enterAge();
	}
	else {
		addAge(age);
	}
}

void enterGender() {
	cout << "Select your gender" << endl << "1.Male  2.Female" << endl;
	cout << "Your gender (enter a number 1 / 2): ";
	unsigned gender;
	cin >> gender;
	cout << endl;
	if (!isGenderValid(gender)) {
		cout << "Invalid gender. Try again." << endl;
		enterGender();
	}
	else {
		addGender(gender);
	}	
}

void enterHeight() {
	cout << "Enter your height (in centimeters): ";
	unsigned height;
	cin >> height;
	cout << endl;
	if (!isHeightValid(height)) {
		cout << "Invalid height. Try again." << endl;
		enterHeight();
	}
	else {
		addHeight(height);
	}
}

void enterWeight() {
	cout << "Enter your weight (in kilograms): ";
	double weight;
	cin >> weight;
	cout << endl;
	if (!isWeightValid(weight)) {
		cout << "Invalid weight. Try again." << endl;;
		enterWeight();
	}
	else {
		addWeight(weight);
	}
}

void enterActivityLevel() {
	cout << "Select your activity level " << endl << "1. Sendentary work, no exercise"
		<< endl << "2. Light activity (exercise 1-3 days per week)"
		<< endl << "3. Moderate activity (exercise 3-5 days per week)"
		<< endl << "4. Active work (exercise 6-7 days per week)"
		<< endl << "5. Very active (physical work or intense training)" << endl;

	cout << "Your activity level (enter a number 1-5): ";
	unsigned activityLevel;
	cin >> activityLevel;
	cout << endl;
	if (!isActivityLevelValid(activityLevel)) {
		cout << "Invalid activity level. Try again."<<endl;
		enterActivityLevel();
	}
	else {
		addActivityLevel(activityLevel);
	}
}

void enterGoal() {
	cout << "Select your goal " << endl << "1. Lose weight" << endl << "2. Maintain weight" << endl << "3. Gain weight" << endl;
	cout << "Your goal (enter a number 1-3): ";
	unsigned goal;
	cin >> goal;
	cout << endl;
	if (!isGoalValid(goal)) {
		cout << "Invalid goal. Try again" << endl;
		enterGoal();
	}
	else {
		addGoal(goal);
		while (true) {
			unsigned kgPerWeekGoal = 0; //The user wants to maintain weight - kgPerWeekGoal=0
			if (goal == 1) {
				cout << "How much weight would you like to lose per week? " << endl;
				cout << "1. 0.25" << endl << "2. 0.5" << endl << "3. 0.75" << endl << "4. 1.0" << endl;
				cout << "Your goal (enter a number 1-4): ";
				cin >> kgPerWeekGoal;
				cout << endl;
				if (!isKgForWeekGoalValid(kgPerWeekGoal)) {
					cout << "Invalid goal. Try again"<<endl;
					continue;
				}
				else {
					addKgPerWeekGoal(kgPerWeekGoal);
					break;
				}
			}
			else if (goal == 3) {
				cout << "How much weight would you like to gain per week? " << endl;
				cout << "1. 0.25" << endl << "2. 0.5" << endl << "3. 0.75" << endl << "4. 1.0" << endl;
				cout << "Your goal (enter a number 1-4): ";
				cin >> kgPerWeekGoal;
				cout << endl;
				if (!isKgForWeekGoalValid(kgPerWeekGoal)) {
					cout << "Invalid goal. Try again"<<endl;
					continue;
				}
				else {
					addKgPerWeekGoal(kgPerWeekGoal);
					break;
				}
			}
			else {
				break;
			}
		}
	}
}

void enterAccountType() {
	cout << "Select your account type" << endl << "1. Standard" << endl << "2. Premium (premium accounts get access to macronutrient calculation)" << endl;
	cout << "Select your account type (enter a number 1/2): ";
	unsigned accountType;
	cin >> accountType;
	cout << endl;
	if (!isAccountTypeValid(accountType)) {
		cout << "Invalid account type. Try again."<<endl;
		enterAccountType();
	}
	else {
		addAccountType(accountType);
	}
}

bool isUsernameValid(const string& username) {
	if (checkIfUserExist(username)) {
		return false;
	}
	return true;
}

bool isAgeValid(unsigned age) {
	return age <= MAX_AGE;
}

bool isGenderValid(unsigned gender) {
	return(gender == 1 || gender == 2);
}

bool isHeightValid(unsigned height) {
	return(height >= MIN_HEIGHT && height < MAX_HEIGHT);
}

bool isWeightValid(double weight) {
	return(weight >= MIN_WEIGHT && weight <= MAX_WEIGHT);
}

bool isActivityLevelValid(unsigned activityLevel) {
	return(activityLevel >= 1 && activityLevel <= 5);
}

bool isGoalValid(unsigned goal) {
	return (goal >= 1 && goal <= 3);
}

bool isAccountTypeValid(unsigned accountType) {
	return (accountType == 1 || accountType == 2);
}

bool isKgForWeekGoalValid(unsigned kgForWeekGoal) {
	return (kgForWeekGoal >= 1 && kgForWeekGoal <= 4);
}