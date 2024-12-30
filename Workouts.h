#pragma once
#include "TimeHandler.h"
#include "AccountsData.h"

const vector<string>& getWorkoutNames();
const vector<double>& getWorkoutCalories();
const vector<tm>& getWorkoutDates();
const vector<int>& getWorkoutUsers();

void addWorkoutName(string workoutName);
void addWorkoutCalories(double workoutCal);
void addWorkoutUser(int workoutUser);
void addWorkoutDate(tm date);

void addWorkout(string workoutName, double burnedCalories);
