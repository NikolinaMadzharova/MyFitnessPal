#pragma once
#include "Register.h"
#include "Login.h"
#include "Meals.h"
#include "Workouts.h"
#include "DailyReport.h"

void printHeader();
void printLoginOrRegisterMenu();
void printMainMenu();
void addWorkoutMenu();
void addMealMenu();
void dailyReportMenu();
void specificDateReportMenu();
void deleteReportForSpecificDateMenu();
void editMealsForTheDayMenu();
void editWorkoutsForTheDayMenu();
void editUserProfileMenu();
void editWeightMenu();
void editHeightMenu();
void editGoalMenu();
void editWeeklyGoalMenu();
void editActivityLevelMenu();
double caloriesConsumedFromMeal(const string& mealName);
void messageToReturnToMainMenu();
