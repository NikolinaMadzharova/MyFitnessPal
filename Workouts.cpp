#include "Workouts.h"

vector<string> workoutNames;
vector<double> workoutCalories;
vector<tm> workoutDates;
vector<int> workoutUsers;

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
}


