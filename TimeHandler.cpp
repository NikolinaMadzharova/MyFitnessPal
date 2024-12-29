#include "TimeHandler.h"
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

int searchDate(const vector<tm>& dates, const tm& searchDate) {
	for (int i = 0; i < dates.size(); i++) {
		if (compareDates(dates[i], searchDate)) {
			return i;
		}
	}
	return -1;
}

tm getCurrentDate() {
	time_t now = time(0);
	tm currentTime;
	localtime_s(&currentTime, &now);
	return currentTime;
}

int searchCurrentDate(const vector<tm>& dates) {
	tm currentDate = getCurrentDate();
	for (int i = 0; i < dates.size(); i++) {
		if (compareDates(dates[i], currentDate)) {
			return i;
		}
	}
	return -1;
}