#pragma once
#include "TimeHandler.h"
#include "AccountsData.h"
#include "DailyReport.h"

unsigned getWorkoutsCount();

const vector<string>& getWorkoutNames();
const vector<double>& getWorkoutCalories();
const vector<tm>& getWorkoutDates();
const vector<int>& getWorkoutUsers();

void addWorkoutName(string workoutName);
void addWorkoutCalories(double workoutCal);
void addWorkoutUser(int workoutUser);
void addWorkoutDate(tm date);

void addWorkout(string workoutName, double burnedCalories);
bool areWorkoutCaloriesValid(double calories);
double kcalBurnedFromTodaysWorkouts();
void printWorkouts(tm date);
bool doesWorkoutExist();
bool checkWorkoutName(string name);
void editWorkoutName(string oldName, string newName);
void editWorkoutKcal(string name, double newCalories);
void deleteAllWorkoutsForSpecificDate(tm date);
void deleteWorkoutForTheDay(const string& name);
double caloriesBurnedFromWorkout(const string& nameWorkout);