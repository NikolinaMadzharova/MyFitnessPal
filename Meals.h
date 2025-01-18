#pragma once
#include "AccountsData.h"
#include "TimeHandler.h"
#include "DailyReport.h"

unsigned getMealsCount();

const vector<tm>& getMealDates();
const vector<string>& getMealNames();
const vector<double>& getMealCalories();
const vector<int>& getMealUsers();

void addMealDate(tm mealDate);
void addMealName(string mealName);
void addMealCalories(double mealCal);
void addMealUser(int mealUser);

void addMeal(string mealName, double mealCalories);
bool areMealCaloriesValid(double calories);
double kcalFromTodaysMeal();
void printMeals(tm date);
void deleteAllMealsForSpecificDate(tm date);
bool doesMealExist();
bool checkMealName(const string& name);
void editMealName(const string& oldName, const string& newName);
void editMealKcal(const string& name, double newCalories);
void deleteAllMealsForSpecificData(tm date);
void deleteMealForTheDay(const string& name);

