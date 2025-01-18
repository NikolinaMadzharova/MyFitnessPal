#pragma once
#include "AccountsData.h"

double basalMetabolicRate();
double calorieDeficitAndSurplus();
double recommendedDailyCalories();

void macronutrientsForLossWeight(double& protein, double& fat, double& carbohydrates);
void macronutrientsForGainWeight(double& protein, double& fat, double& carbohydrates);
void macronutrientsForMaintainWeight(double& protein, double& fat, double& carbohydrates);
void macronutrients(double& protein, double& fat, double& carbohydrates);