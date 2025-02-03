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
#include "DailyReport.h"

vector<tm> datesForDailyCalorieReport;
vector<double> recommendedDailyKcal;
vector<double> proteinGR;
vector<double> fatGR;
vector<double> carbohydratesGR;
vector<double> burnedCaloriesPerDay;
vector<double> consumedCaloriesPerDay;
vector<int> usersForDailyCalorieReport;

unsigned getDailyReportsCount() {
	return usersForDailyCalorieReport.size();
}

const vector<tm>& getDatesForDailyCalorieReport() {
	return datesForDailyCalorieReport;
}

const vector<double>& getRecommendedDailyKcal() {
	return recommendedDailyKcal;
}

const vector<double>& getProtein() {
	return proteinGR;
}

const vector<double>& getFatt() {
	return fatGR;
}

const vector<double>& getCarbohydrates() {
	return carbohydratesGR;
}

const vector<double>& getBurnedCaloriesPerDay() {
	return burnedCaloriesPerDay;
}

const vector<double>& getConsumedCaloriesPerDay() {
	return consumedCaloriesPerDay;
}

const vector<int>& getUsersForDailyCalorieReport() {
	return usersForDailyCalorieReport;
}

void addDatesForDailyCalorieReport(tm date) {
	datesForDailyCalorieReport.push_back(date);
}

void addRecommendedDailyKcal(double dailyCalories) {
	recommendedDailyKcal.push_back(dailyCalories);
}

void addMacronutrients(double protein, double fat, double carbohydrates) {
	addProtein(protein);
	addFat(fat);
	addCarbohydrates(carbohydrates);
}

void addProtein(double protein) {
	proteinGR.push_back(protein);
}

void addFat(double fat) {
	fatGR.push_back(fat);
}

void addCarbohydrates(double carbohydrates) {
	carbohydratesGR.push_back(carbohydrates);
}

void addBurnedCaloriesPerDay(double burnedCalories) {
	burnedCaloriesPerDay.push_back(burnedCalories);
}

void addConsumedCaloriesPerDay(double consumedCalories) {
	consumedCaloriesPerDay.push_back(consumedCalories);
}

void addUsersForDailyCalorieReport(int userIndex) {
	usersForDailyCalorieReport.push_back(userIndex);
}

void addDailyReport() {
	double recommendedKcal = recommendedDailyCalories();
	addRecommendedDailyKcal(recommendedKcal);
	double protein = 0.0;
	double fat = 0.0;
	double carbohydrates = 0.0;
	macronutrients(protein, fat, carbohydrates);
	addMacronutrients(protein, fat, carbohydrates);
	double burnedKcal = kcalBurnedFromTodaysWorkouts();
	addBurnedCaloriesPerDay(burnedKcal);
	double mealsKcal = kcalFromTodaysMeal();
	addConsumedCaloriesPerDay(mealsKcal);
	tm date = getCurrentDate();
	addDatesForDailyCalorieReport(date);
	addUsersForDailyCalorieReport(getLoggedUserIndex());
}

void getDailyReport(tm date,double& recommendedKcal, double& protein,double& fat, double& carbohydrates, double& burnedKcal, double& consumedKcal) {

	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	if (dailyReportIndex != -1) {
		recommendedKcal = recommendedDailyKcal[dailyReportIndex];
		protein = proteinGR[dailyReportIndex];
		fat = fatGR[dailyReportIndex];
		carbohydrates = carbohydratesGR[dailyReportIndex];
		burnedKcal = burnedCaloriesPerDay[dailyReportIndex];
		consumedKcal = consumedCaloriesPerDay[dailyReportIndex];
	}
}

void editBurnedCaloriesAfterAddingWorkout(double newBurnedCalories) {
	tm date = getCurrentDate();
	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	burnedCaloriesPerDay[dailyReportIndex] += newBurnedCalories;	
}

void editConsumedCaloriesAterAddingMeal(double newConsumedCalories) {
	tm date = getCurrentDate();
	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	consumedCaloriesPerDay[dailyReportIndex] += newConsumedCalories;
}

void editBurnedCaloriesAfterEditingWorkout(double difference) {
	tm date = getCurrentDate();
	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	burnedCaloriesPerDay[dailyReportIndex] += difference;
}

void editConsumedCaloriesAfterEditingMeal(double differnce) {
	tm date = getCurrentDate();
	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	consumedCaloriesPerDay[dailyReportIndex] += differnce;
}

void deleteDailyReport(tm date) {
	int index = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	if (index != -1) {
		if (!datesForDailyCalorieReport.empty() && (index >= 0 && index < datesForDailyCalorieReport.size())) {
			
			datesForDailyCalorieReport.erase(datesForDailyCalorieReport.begin() + index);
			recommendedDailyKcal.erase(recommendedDailyKcal.begin() + index);
			proteinGR.erase(proteinGR.begin() + index);
			fatGR.erase(fatGR.begin() + index);
			carbohydratesGR.erase(carbohydratesGR.begin() + index);
			burnedCaloriesPerDay.erase(burnedCaloriesPerDay.begin() + index);
			consumedCaloriesPerDay.erase(consumedCaloriesPerDay.begin() + index);
			usersForDailyCalorieReport.erase(usersForDailyCalorieReport.begin() + index);
		}
	}
}

void editDailyReportAfterChangingAccountData() {
	tm date = getCurrentDate();
	int dailyReportIndex = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	double recommendedKcal = recommendedDailyCalories();
	recommendedDailyKcal[dailyReportIndex] = recommendedKcal;
	double protein = 0.0;
	double fat = 0.0;
	double carbohydrates = 0.0;
	macronutrients(protein, fat, carbohydrates);
	proteinGR[dailyReportIndex] = protein;
	fatGR[dailyReportIndex] = fat;
	carbohydratesGR[dailyReportIndex] = carbohydrates;
}

bool doesDailyReportExist(tm date) {
	int index = findSingleMatchingPosition(datesForDailyCalorieReport, usersForDailyCalorieReport, date);
	if (index == -1) {
		return false;
	}
	return true;
}