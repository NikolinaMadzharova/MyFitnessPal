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
#pragma once
#include "AccountsData.h"

double basalMetabolicRate();
double calorieDeficitAndSurplus();
double recommendedDailyCalories();

void macronutrientsForLossWeight(double& protein, double& fat, double& carbohydrates);
void macronutrientsForGainWeight(double& protein, double& fat, double& carbohydrates);
void macronutrientsForMaintainWeight(double& protein, double& fat, double& carbohydrates);
void macronutrients(double& protein, double& fat, double& carbohydrates);