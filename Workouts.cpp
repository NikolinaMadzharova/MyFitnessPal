#include "Workouts.h"

vector<string> workoutNames;
vector<double> workoutCalories;
vector<tm> workoutDates;
vector<int> workoutUsers;

unsigned getWorkoutsCount() {
	return workoutNames.size();
}

const vector<string>& getWorkoutNames() {
	return workoutNames;
}

const vector<double>& getWorkoutCalories() {
	return workoutCalories;
}

const vector<tm>& getWorkoutDates() {
	return workoutDates;
}

const vector<int>& getWorkoutUsers() {
	return workoutUsers;
}

void addWorkoutName(string trainingName) {
	workoutNames.push_back(trainingName);
}

void addWorkoutCalories(double workoutCal) {
	workoutCalories.push_back(workoutCal);
}

void addWorkoutUser(int workoutUser) {
	workoutUsers.push_back(workoutUser);
}

void addWorkoutDate(tm date) {
	workoutDates.push_back(date);
}

void addWorkout(string workoutName, double burnedCalories) {
	tm currentDate = getCurrentDate();
	int userIndex = getLoggedUserIndex();
	addWorkoutName(workoutName);
	addWorkoutCalories(burnedCalories);
	addWorkoutDate(currentDate);
	addWorkoutUser(userIndex);
	editBurnedCaloriesAfterAddingWorkout(burnedCalories);
}

bool areWorkoutCaloriesValid(double calories) {
	return(calories >= 1 && calories <= 5000);
}

double kcalBurnedFromTodaysWorkouts() {
	double result = 0.0;
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			result += workoutCalories[matchingPositions[i]];
		}
	}
	return result;
	delete[] matchingPositions;
}

void printWorkouts(tm date) {
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			cout << "Workout: " << workoutNames[matchingPosition] << " - " << workoutCalories[matchingPosition] << " calories " << endl;
		}
	}
	else {
		cout << "No workouts added for this date. " << endl;
	}
	
	delete[] matchingPositions;
}

bool doesWorkoutExist() {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	delete[] matchingPositions;
	if (countMatchingPositions == 0) {
		return false;
	}
	return true;
}

bool checkWorkoutName(string name) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (workoutNames[matchingPosition] == name) {
				delete[] matchingPositions;
				return true;
			}
		}
	}

	delete[] matchingPositions;
	return false;
}

void editWorkoutName(string oldName,string newName) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (workoutNames[matchingPosition] == oldName) {
				delete[] matchingPositions;
				workoutNames[matchingPosition] = newName;
				return;
			}
		}
	}

	delete[] matchingPositions;
}

void editWorkoutKcal(string name, double newCalories) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (workoutNames[matchingPosition] == name) {
				delete[] matchingPositions;
				workoutCalories[matchingPosition] = newCalories;
				return;
			}
		}
	}

	delete[] matchingPositions;
}

void deleteAllWorkoutsForSpecificDate(tm date) {
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int index = matchingPositions[i];
			workoutNames.erase(workoutNames.begin() + index);
			workoutCalories.erase(workoutCalories.begin() + index);
			workoutDates.erase(workoutDates.begin() + index);
			workoutUsers.erase(workoutUsers.begin() + index);
		}
	}

	delete[] matchingPositions;
}

void deleteWorkoutForTheDay(const string& name) {
	int countMatchingPositions = 0;
	tm date = getCurrentDate();
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int index = matchingPositions[i];
			if (workoutNames[index] == name) {
				workoutNames.erase(workoutNames.begin() + index);
				workoutCalories.erase(workoutCalories.begin() + index);
				workoutDates.erase(workoutDates.begin() + index);
				workoutUsers.erase(workoutUsers.begin() + index);
			}
		}
	}

	delete[] matchingPositions;
}

double caloriesBurnedFromWorkout(const string& nameWorkout) {
	tm date = getCurrentDate();
	int countMatchingPositions = 0;
	int* matchingPositions = findMatchingPositions(workoutDates, workoutUsers, date, countMatchingPositions);
	if (matchingPositions != nullptr) {
		for (int i = 0; i < countMatchingPositions; i++) {
			int matchingPosition = matchingPositions[i];
			if (workoutNames[matchingPosition] == nameWorkout) {
				delete[] matchingPositions;
				return workoutCalories[matchingPosition];
			}
		}
	}
	delete[] matchingPositions;
	return 0;
}