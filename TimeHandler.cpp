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

#include "TimeHandler.h"
int loggedUserInd;
constexpr size_t SIZE_DATE_STRING = 11; //DD.MM.YYYY

string formatDate(const tm& date) {
	char buffer[SIZE_DATE_STRING];
	strftime(buffer, sizeof(buffer), "%d.%m.%Y", &date);
	return string(buffer);
}

bool compareDates(const tm& date1, const tm& date2) {
	return(date1.tm_mday == date2.tm_mday
		&& date1.tm_mon == date2.tm_mon
		&& date1.tm_year == date2.tm_year);
}

tm getCurrentDate() {
	time_t now = time(0);
	tm currentTime;
	localtime_s(&currentTime, &now);
	return currentTime;
}

//Matching Positions can be more than one
int* findMatchingPositions(const vector<tm>& dates, const vector<int> indexes, tm targetDate, int& resultSize) {
	resultSize = 0;
	
	for (int i = 0; i < indexes.size(); i++) {
		if (indexes[i] == getLoggedUserIndex() && compareDates(dates[i], targetDate)) {
			resultSize++;
		}
	}

	if (resultSize == 0) {
		return nullptr;
	}

	int* result = new int[resultSize];
	int currentIndex = 0;

	for (int i = 0; i < indexes.size(); i++) {
		if (indexes[i] == getLoggedUserIndex() && compareDates(dates[i], targetDate)) {
			result[currentIndex++] = i;
		}
	}
	return result;
}

//Only one matching position is possible
int findSingleMatchingPosition(const vector<tm>& dates, const vector<int>& indexes, const tm& targetDate) {
	
	for (int i = 0; i < dates.size(); i++) {
		if (indexes[i] == getLoggedUserIndex() && compareDates(dates[i], targetDate)) {
			return i;
		}
	}
	return -1;
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31; break;
	case 4:
	case 6:
	case 9:
	case 11: return 30; break;
	case 2: return isLeapYear(year) ? 29 : 28; break;
	}
}

bool isValidYear(int year) {
	tm currentDate = getCurrentDate();
	int currentYear = currentDate.tm_year + 1900;
	//1900 is added because tm_year starts from 1900
	return year >= 1900 && year <= currentYear;
}

int convertStringToInt(const string& dateString, int start, int length) {
	int result = 0;
	for (int i = start; i < start + length; i++) {
		result = result * 10 + (dateString[i] - '0');
	}
	return result;
}

bool isValidDateFormat(const string& dateString) {
	//DD.MM.YYYY
	if (dateString.length() != 10) {
		return false;
	}

	for (int i = 0; i < 10; i++) {
		switch (i){
		case 2:
		case 5:
			if (dateString[i] != '.') {
				return false;
			}
			break;
		default:
			if (dateString[i] < '0' || dateString[i]>'9') {
				return false;
			}
			break;
		}
	}
	return true;
}

bool isValidDate(const string& dateString) {
	if (!isValidDateFormat(dateString)) {
		return false;
	}
	//DD.MM.YYYY
	int day = convertStringToInt(dateString, 0, 2);
	int month = convertStringToInt(dateString, 3, 2);
	int year = convertStringToInt(dateString, 6, 4);

	if (!isValidYear(year)) {
		return false;
	}
	if (month < 1 || month>12) {
		return false;
	}
	if (!isValidYear(year)) {
		return false;
	}
	int daysInMonth = getDaysInMonth(month, year);
	return (day >= 1 && day <= daysInMonth);
}

tm convertStringToTm(const string& dateString) {
	tm date = {};
	int day = convertStringToInt(dateString, 0, 2);
	int month = convertStringToInt(dateString, 3, 2);
	int year = convertStringToInt(dateString, 6, 4);

	date.tm_mday = day;
	date.tm_mon = month - 1; //months are from 0 to 11 
	date.tm_year = year - 1900; //year from 1900
	return date;
}


