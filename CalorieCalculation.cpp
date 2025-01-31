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
* <calorie calculation functions>
*
*/
#include "CalorieCalculation.h"


double basalMetabolicRate() {
	unsigned gender = getGenderLoggedUser();
	//1. Male
	//2. Female

	double weight = getWeightLoggedUser();
	unsigned height = getHeightLoggedUser();
	unsigned age = getAgeLoggedUser();
	double BMR = 0.0;
	if (gender == 1) {
		BMR += 88.362 + 13.397 * weight + 4.799 * height - 5.677 * age;
	}
	else {
		BMR += 447.593 + 9.247 * weight + 3.098 * height - 4.330 * age;
	}

	unsigned activityLevel = getActivityLevelLoggedUser();
	switch (activityLevel)
	{
	case 1: BMR *= 1.2; break;
	case 2: BMR *= 1.375; break;
	case 3: BMR *= 1.55; break;
	case 4: BMR *= 1.725; break;
	case 5: BMR *= 1.9; break;
	}

	return BMR;
}

double calorieDeficitAndSurplus() {
	unsigned kgPerWeekGoal = getKgPerWeekGoalLoggedUser();
	// 0 if the user wants to maintain weight
	// 1 - 0.25 kg per week 
	// 2 - 0.5 kg per week
	// 3 - 0.75 kg per week
	// 4 - 1.0 kg per week

	double calories = 0.0;
	switch (kgPerWeekGoal)
	{
	case 1: calories = 275.0; break;
	case 2: calories = 550.0; break;
	case 3: calories = 825.0; break;
	case 4: calories = 1100.0; break;
	}

	return calories;
}

double recommendedDailyCalories() {
	unsigned goal = getGoalLoggedUser();
	// 1. Lose weight
	// 2. Maintain weight
	// 3. Gain weight

	double dailyCalories = basalMetabolicRate();
	if (goal == 1) {
		double calorieDeficit = calorieDeficitAndSurplus();
		dailyCalories -= calorieDeficit;
	}
	else if(goal==3) {
		double calorieSurplus = calorieDeficitAndSurplus();
		dailyCalories += calorieSurplus;
	}
	
	return dailyCalories;
}

void macronutrientsForLossWeight(double& protein, double& fat, double& carbohydrates) {
	double dailyCalorie = recommendedDailyCalories();
	 protein = 0.35 * dailyCalorie / 4;
	 fat = 0.3 * dailyCalorie / 9;
	 carbohydrates = 0.35 * dailyCalorie / 4;
	
}

void macronutrientsForGainWeight(double& protein, double& fat, double& carbohydrates) {
	double dailyCalorie = recommendedDailyCalories();
	 protein = 0.4 * dailyCalorie / 4;
	  fat = 0.25 * dailyCalorie / 9;
	 carbohydrates = 0.35 * dailyCalorie / 4;
}

void macronutrientsForMaintainWeight(double& protein, double& fat, double& carbohydrates) {
	double dailyCalorie = recommendedDailyCalories();
	 protein = 0.25 * dailyCalorie / 4;
	 fat = 0.30 * dailyCalorie / 9;
	 carbohydrates = 0.45 * dailyCalorie / 4;
}

void macronutrients(double& protein, double& fat, double& carbohydrates) {
	unsigned goal = getGoalLoggedUser();
	if (goal == 1) {
		macronutrientsForLossWeight(protein, fat, carbohydrates);
	}
	else if (goal == 2) {
		macronutrientsForMaintainWeight(protein, fat, carbohydrates);
	}
	else if (goal == 3) {
		macronutrientsForGainWeight(protein, fat, carbohydrates);
	}
}