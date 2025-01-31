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
* <register function>
*
*/
#pragma once
#include "AccountsData.h"

void registration();
void enterUsername();
void enterPassword();
void enterAge();
void enterGender();
void enterHeight();
void enterWeight();
void enterActivityLevel();
void enterGoal();
void enterAccountType();

bool isUsernameValid(const string& username);
bool isAgeValid(unsigned age);
bool isGenderValid(unsigned gender);
bool isHeightValid(unsigned height);
bool isWeightValid(double weight);
bool isActivityLevelValid(unsigned activityLevel);
bool isGoalValid(unsigned goal);
bool isAccountTypeValid(unsigned accountType);
bool isKgForWeekGoalValid(unsigned kgForWeekGoal);