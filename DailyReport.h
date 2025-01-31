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
* <daily report information>
*
*/

#pragma once
#include "AccountsData.h"
#include "TimeHandler.h"
#include "CalorieCalculation.h"
#include "Workouts.h"
#include "Meals.h"

unsigned getDailyReportsCount();

const vector<tm>& getDatesForDailyCalorieReport();
const vector<double>& getRecommendedDailyKcal();
const vector<double>& getProtein();
const vector<double>& getFatt();
const vector<double>& getCarbohydrates();
const vector<double>& getBurnedCaloriesPerDay();
const vector<double>& getConsumedCaloriesPerDay();
const vector<int>& getUsersForDailyCalorieReport();

void addDatesForDailyCalorieReport(tm date);
void addRecommendedDailyKcal(double dailyCalories);
void addMacronutrients(double protein, double fat, double carbohydrates);
void addProtein(double protein);
void addFat(double fat);
void addCarbohydrates(double carbohydrates);
void addBurnedCaloriesPerDay(double burnedCalories);
void addConsumedCaloriesPerDay(double consumedCalories);
void addUsersForDailyCalorieReport(int userIndex);
void addDailyReport();
void getDailyReport(tm date,double& recommendedKcal, double& protein, double& fat, double& carbohydrates, double& burnedKcal, double& consumedKcal);
void editBurnedCaloriesAfterAddingWorkout(double newBurnedCalories);
void editConsumedCaloriesAterAddingMeal(double newConsumedCalories);
void editBurnedCaloriesAfterEditingWorkout(double difference);
void editConsumedCaloriesAfterEditingMeal(double differnce);
void deleteDailyReport(tm date);
void editDailyReportAfterChangingAccountData();
bool doesDailyReportExist(tm date);