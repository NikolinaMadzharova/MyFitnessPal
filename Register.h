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

bool isUsernameValid(string username);
bool isAgeValid(unsigned age);
bool isGenderValid(unsigned gender);
bool isHeightValid(unsigned height);
bool isWeightValid(double weight);
bool isActivityLevelValid(unsigned activityLevel);
bool isGoalValid(unsigned goal);
bool isAccountTypeValid(unsigned accountType);
bool isKgForWeekGoalValid(unsigned kgForWeekGoal);