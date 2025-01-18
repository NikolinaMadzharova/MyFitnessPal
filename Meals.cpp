#include "Meals.h"

vector<tm> mealDates;
vector<string> mealNames;
vector<double> mealCalories;
vector<int>mealUsers;

unsigned getMealsCount() {
	return mealNames.size();
}

const vector<tm>& getMealDates() {
	return mealDates;
}

const vector<string>& getMealNames() {
	return mealNames;
}

const vector<double>& getMealCalories() {
	return mealCalories;
}

const vector<int>& getMealUsers() {
	return mealUsers;
}

void addMealDate(tm mealDate) {
	mealDates.push_back(mealDate);
}

void addMealName(string mealName) {
	mealNames.push_back(mealName);
}

void addMealCalories(double mealCal) {
	mealCalories.push_back(mealCal);
}

void addMealUser(int mealUser) {
	mealUsers.push_back(mealUser);
}

void addMeal(string mealName,double mealCalories) {
	tm date = getCurrentDate();
	int userInd = getLoggedUserIndex();
	addMealDate(date);
	addMealName(mealName);
	addMealCalories(mealCalories);
	addMealUser(userInd);
	editConsumedCaloriesAterAddingMeal(mealCalories);
}

bool areMealCaloriesValid(double calories) {
	return(calories >= 1 && calories <= 5000);
}

double kcalFromTodaysMeal() {
	double result = 0.0;
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			result += mealCalories[matchingPositions[i]];
		}
	}
	return result;
	delete[] matchingPositions;
}


void printMeals(tm date) {
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			cout << "Meal: " << mealNames[matchingPosition] << " - " << mealCalories[matchingPosition] << " calories " << endl;
		}
	}
	else {
		cout << "No meals added for this date. " << endl;
	}
	delete[] matchingPositions;
}

void deleteAllMealsForSpecificDate(tm date) {
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int index = matchingPositions[i];
			mealDates.erase(mealDates.begin() + index);
			mealNames.erase(mealNames.begin() + index);
			mealCalories.erase(mealCalories.begin() + index);
			mealUsers.erase(mealUsers.begin() + index);
		}
	}
}

bool doesMealExist() {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchinPosotions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	delete[] matchinPosotions;
	if (countMatchingPositions == 0) {
		return false;
	}
	return true;
}

bool checkMealName(const string& name) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (mealNames[matchingPosition] == name) {
				delete[] matchingPositions;
				return true;
			}
		}
	}
	delete[] matchingPositions;
	return false;
}

void editMealName(const string& oldName, const string& newName) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (mealNames[matchingPosition] == oldName) {
				delete[] matchingPositions;
				mealNames[matchingPosition] = newName;
				return;
			}
		}
	}
	delete[] matchingPositions;
}

void editMealKcal( const string& name, double newCalories) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (mealNames[matchingPosition] == name) {
				delete[] matchingPositions;
				mealCalories[matchingPosition] = newCalories;
				return;
			}
		}
	}
	delete[] matchingPositions;
}

void deleteAllMealsForSpecificData(tm date) {
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int index = matchingPositions[i];
			mealNames.erase(mealNames.begin() + index);
			mealCalories.erase(mealCalories.begin() + index);
			mealDates.erase(mealDates.begin() + index);
			mealUsers.erase(mealUsers.begin() + index);
		}
	}
	delete[] matchingPositions;
}

void deleteMealForTheDay(const string& name) {
	int countMatchingPositions = 0;
	tm date = getCurrentDate();
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int index = matchingPositions[i];
			if (mealNames[index] == name) {
				mealNames.erase(mealNames.begin() + index);
				mealCalories.erase(mealCalories.begin() + index);
				mealDates.erase(mealDates.begin() + index);
				mealUsers.erase(mealUsers.begin() + index);
			}
		}
	}
	delete[] matchingPositions;
}

double caloriesConsumedFromMeal(const string& mealName) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(mealDates, mealUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (mealNames[matchingPosition] == mealName) {
				delete[] matchingPositions;
				return mealCalories[matchingPosition];
			}
		}
	}
	delete[] matchingPositions;
	return 0;
}