#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string formatDate(const tm& date);
bool compareDates(const tm& date1, const tm& date2);
int searchDate(const vector<tm>& dates, const tm& searchDate);
tm getCurrentDate();
int searchCurrentDate(const vector<tm>& dates);


















