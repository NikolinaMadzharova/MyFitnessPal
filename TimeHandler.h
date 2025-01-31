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
* <time functions>
*
*/

#pragma once
#include "AccountsData.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string formatDate(const tm& date);
bool compareDates(const tm& date1, const tm& date2);
tm getCurrentDate();
int* findMatchingPositions(const vector<tm>& dates, const vector<int> indexes, tm targetDate, int& resultSize);
int findSingleMatchingPosition(const vector<tm>& dates, const vector<int>& indexes, const tm& targetDate);
bool isLeapYear(int year);
int getDaysInMonth(int month, int year);
bool isValidYear(int year);
int convertStringToInt(const string& dateString, int start, int length);
bool isValidDateFormat(const string& dateString);
bool isValidDate(const string& dateString);
tm convertStringToTm(const string& dateString);
















