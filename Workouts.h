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
* <workouts information>
*
*/
#pragma once
#include "TimeHandler.h"
#include "AccountsData.h"
#include "DailyReport.h"

unsigned getWorkoutsCount();

const vector<string>& getWorkoutNames();
const vector<double>& getWorkoutCalories();
const vector<tm>& getWorkoutDates();
const vector<int>& getWorkoutUsers();

void addWorkoutName(const string& workoutName);
void addWorkoutCalories(double workoutCal);
void addWorkoutUser(int workoutUser);
void addWorkoutDate(tm date);

void addWorkout(const string& workoutName, double burnedCalories);
bool areWorkoutCaloriesValid(double calories);
double kcalBurnedFromTodaysWorkouts();
void printWorkouts(tm date);
bool doesWorkoutExist();
bool checkWorkoutName(const string& name);
void editWorkoutName(const string& oldName,const string& newName);
void editWorkoutKcal(const string& name, double newCalories);
void deleteAllWorkoutsForSpecificDate(tm date);
void deleteWorkoutForTheDay(const string& name);
double caloriesBurnedFromWorkout(const string& nameWorkout);