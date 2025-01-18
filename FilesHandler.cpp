#include "AccountsData.h"
#include <fstream>
#include <ctime>
#include "DailyReport.h"
#include "FilesHandler.h"

void saveUnsignedToFile(ofstream& ofs, unsigned num) {
	ofs.write((const char*)&num, sizeof(unsigned));
}

void readUnsignedFromFile(ifstream& ifs, unsigned& num) {
	ifs.read((char*)&num, sizeof(unsigned));
}

void saveDoubleToFile(ofstream& ofs, double num) {
	ofs.write((const char*)&num, sizeof(double));
}

void readDoubleFromFile(ifstream& ifs, double& num) {
	ifs.read((char*)&num, sizeof(double));
}

void saveStringToFile(ofstream& ofs, string str) {
	size_t size = str.length();
	saveUnsignedToFile(ofs, size);
	ofs.write(str.c_str(), size);
}

void readStringFromFile(ifstream& ifs, string& str) {
	unsigned size = 0;
	readUnsignedFromFile(ifs, size);
	char* data = new char[size + 1];
	ifs.read(data, size);
	data[size] = '\0';
	str = string(data);
	delete[] data;
}

void readTmFromFile(ifstream& ifs, tm& date) {
	ifs.read(reinterpret_cast<char*>(&date), sizeof(date));
}

void saveTmToFile(ofstream& ofs, tm date) {
	ofs.write(reinterpret_cast<const char*>(&date), sizeof(date));
}

void saveIntToFile(ofstream& ofs, int  num) {
	ofs.write((const char*)&num, sizeof(int));
}

void readIntFromFile(ifstream& ifs, int& num) {
	ifs.read((char*)&num, sizeof(int));
}

void saveToFile() {
	ofstream ofs("file.dat", ios::out | ios::binary | ios::trunc);

	if (!ofs.is_open())
	{
		throw "Error with opening the file.";
	}
	
	//ACCOUNT DATA
	saveUnsignedToFile(ofs, getUsersCount());
	vector<string> usernames = getUsernames();
	vector<string> passwords = getPasswords();
	vector <unsigned> ages = getAges();
	vector<unsigned> heights = getHeights();
	vector<double> weights = getWeights();
	vector<unsigned> genders = getGenders();
	vector<unsigned> activityLevels = getActivityLevels();
	vector<unsigned> goals = getGoals();
	vector<unsigned> kgPerWeekGoals = getKgPerWeekGoals();
	vector<unsigned> accountTypes = getAccountTypes();

	unsigned countUsers = getUsersCount();
	for (int i = 0; i < countUsers; i++) {
		saveStringToFile(ofs, usernames[i]);
		saveStringToFile(ofs, passwords[i]);
		saveUnsignedToFile(ofs, ages[i]);
		saveUnsignedToFile(ofs, heights[i]);
		saveDoubleToFile(ofs, weights[i]);
		saveUnsignedToFile(ofs, genders[i]);
		saveUnsignedToFile(ofs, activityLevels[i]);
		saveUnsignedToFile(ofs, goals[i]);
		saveUnsignedToFile(ofs, kgPerWeekGoals[i]);
		saveUnsignedToFile(ofs, accountTypes[i]);
	}

	//WORKOUTS
	saveUnsignedToFile(ofs, getWorkoutsCount());
	vector<string> workoutNames = getWorkoutNames();
	vector<double> workoutCalories = getWorkoutCalories();
	vector<tm> workoutDates = getWorkoutDates();
	vector<int> workoutUser = getWorkoutUsers();

	unsigned countWorkouts = getWorkoutsCount();
	for (int i = 0; i < countWorkouts; i++) {
		saveStringToFile(ofs, workoutNames[i]);
		saveDoubleToFile(ofs, workoutCalories[i]);
		saveTmToFile(ofs, workoutDates[i]);
		saveIntToFile(ofs, workoutUser[i]);
	}

	//MEALS
	saveUnsignedToFile(ofs, getMealsCount());
	vector<tm> mealDates = getMealDates();
	vector<string> mealNames = getMealNames();
	vector<double> mealCalories = getMealCalories();
	vector<int> mealUsers = getMealUsers();

	unsigned countMeals = getMealsCount();
	for (int i = 0; i < countMeals; i++) {
		saveTmToFile(ofs, mealDates[i]);
		saveStringToFile(ofs, mealNames[i]);
		saveDoubleToFile(ofs, mealCalories[i]);
		saveIntToFile(ofs, mealUsers[i]);
	}

	//DAILY REPORT
	saveUnsignedToFile(ofs, getDailyReportsCount());
	vector<tm> datesForDailyReport = getDatesForDailyCalorieReport();
	vector<double> recommendedDailyCalories = getRecommendedDailyKcal();
	vector<double> proteinGR = getProtein();
	vector<double> fattGR = getFatt();
	vector<double> carbohydratesGR = getCarbohydrates();
	vector<double> burnedCaloriesPerDay = getBurnedCaloriesPerDay();
	vector<double> consumedCaloriesPerDay = getConsumedCaloriesPerDay();
	vector<int> usersForDailyCalorieReport = getUsersForDailyCalorieReport();

	unsigned dailyReportCount = getDailyReportsCount();
	for (int i = 0; i < dailyReportCount; i++) {
		saveTmToFile(ofs, datesForDailyReport[i]);
		saveDoubleToFile(ofs, recommendedDailyCalories[i]);
		saveDoubleToFile(ofs, proteinGR[i]);
		saveDoubleToFile(ofs, fattGR[i]);
		saveDoubleToFile(ofs, carbohydratesGR[i]);
		saveDoubleToFile(ofs, burnedCaloriesPerDay[i]);
		saveDoubleToFile(ofs, consumedCaloriesPerDay[i]);
		saveIntToFile(ofs, usersForDailyCalorieReport[i]);
	}
	
	/*
	saveAccountData(ofs);
	saveWorkouts(ofs);
	saveMeals(ofs);
	saveDailyReport(ofs);
	*/
	ofs.close();
}

void saveAccountData(ofstream& ofs) {
	saveUnsignedToFile(ofs, getUsersCount());
	vector<string> usernames = getUsernames();
	vector<string> passwords = getPasswords();
	vector <unsigned> ages = getAges();
	vector<unsigned> heights = getHeights();
	vector<double> weights = getWeights();
	vector<unsigned> genders = getGenders();
	vector<unsigned> activityLevels = getActivityLevels();
	vector<unsigned> goals = getGoals();
	vector<unsigned> kgPerWeekGoals = getKgPerWeekGoals();
	vector<unsigned> accountTypes = getAccountTypes();

	unsigned countUsers = getUsersCount();
	for (int i = 0; i < countUsers; i++) {
		saveStringToFile(ofs, usernames[i]);
		saveStringToFile(ofs, passwords[i]);
		saveUnsignedToFile(ofs, ages[i]);
		saveUnsignedToFile(ofs, heights[i]);
		saveDoubleToFile(ofs, weights[i]);
		saveUnsignedToFile(ofs, genders[i]);
		saveUnsignedToFile(ofs, activityLevels[i]);
		saveUnsignedToFile(ofs, goals[i]);
		saveUnsignedToFile(ofs, kgPerWeekGoals[i]);
		saveUnsignedToFile(ofs, accountTypes[i]);
	}
}

void saveWorkouts(ofstream& ofs) {
	saveUnsignedToFile(ofs, getWorkoutsCount());
	vector<string> workoutNames = getWorkoutNames();
	vector<double> workoutCalories = getWorkoutCalories();
	vector<tm> workoutDates = getWorkoutDates();
	vector<int> workoutUser = getWorkoutUsers();

	unsigned countWorkouts = getWorkoutsCount();
	for (int i = 0; i < countWorkouts; i++) {
		saveStringToFile(ofs, workoutNames[i]);
		saveDoubleToFile(ofs, workoutCalories[i]);
		saveTmToFile(ofs, workoutDates[i]);
		saveIntToFile(ofs, workoutUser[i]);
	}
}

void saveMeals(ofstream& ofs) {
	saveUnsignedToFile(ofs, getWorkoutsCount());
	vector<tm> mealDates = getMealDates();
	vector<string> mealNames = getMealNames();
	vector<double> mealCalories = getMealCalories();
	vector<int> mealUsers = getMealUsers();

	unsigned countMeals = getMealsCount();
	for (int i = 0; i < countMeals; i++) {
		saveTmToFile(ofs, mealDates[i]);
		saveStringToFile(ofs, mealNames[i]);
		saveDoubleToFile(ofs, mealCalories[i]);
		saveIntToFile(ofs, mealUsers[i]);
	}
}

void saveDailyReport(ofstream& ofs) {
	saveUnsignedToFile(ofs, getDailyReportsCount());
	vector<tm> datesForDailyReport = getDatesForDailyCalorieReport();
	vector<double> recommendedDailyCalories = getRecommendedDailyKcal();
	vector<double> proteinGR = getProtein();
	vector<double> fattGR = getFatt();
	vector<double> carbohydratesGR = getCarbohydrates();
	vector<double> burnedCaloriesPerDay = getBurnedCaloriesPerDay();
	vector<double> consumedCaloriesPerDay = getConsumedCaloriesPerDay();
	vector<int> usersForDailyCalorieReport = getUsersForDailyCalorieReport();

	unsigned dailyReportCount = getDailyReportsCount();
	for (int i = 0; i < dailyReportCount; i++) {
		saveTmToFile(ofs, datesForDailyReport[i]);
		saveDoubleToFile(ofs, recommendedDailyCalories[i]);
		saveDoubleToFile(ofs, proteinGR[i]);
		saveDoubleToFile(ofs, fattGR[i]);
		saveDoubleToFile(ofs, carbohydratesGR[i]);
		saveDoubleToFile(ofs, burnedCaloriesPerDay[i]);
		saveDoubleToFile(ofs, consumedCaloriesPerDay[i]);
		saveIntToFile(ofs, usersForDailyCalorieReport[i]);
	}
}

void readFromFile() {
	std::ifstream ifs("file.dat", ios::in | ios::binary);
	
	if (!ifs.is_open())
	{
		return;
	}
	
	readAccountData(ifs);
	readWorkouts(ifs);;
	readMeals(ifs);
	readDailyReport(ifs);
	
	ifs.close();
}

void readAccountData(ifstream& ifs) {
	unsigned accountsDataVectorsSize;
	readUnsignedFromFile(ifs, accountsDataVectorsSize);

	for (int i = 0; i < accountsDataVectorsSize; i++) {
		string username;
		readStringFromFile(ifs, username);
		addUsername(username);

		string password;
		readStringFromFile(ifs, password);
		addPassword(password);

		unsigned age;
		readUnsignedFromFile(ifs, age);
		addAge(age);

		unsigned height;
		readUnsignedFromFile(ifs, height);
		addHeight(height);

		double weight;
		readDoubleFromFile(ifs, weight);
		addWeight(weight);

		unsigned gender;
		readUnsignedFromFile(ifs, gender);
		addGender(gender);

		unsigned activityLevel;
		readUnsignedFromFile(ifs, activityLevel);
		addActivityLevel(activityLevel);

		unsigned goal;
		readUnsignedFromFile(ifs, goal);
		addGoal(goal);

		unsigned kgPerWeekGoal;
		readUnsignedFromFile(ifs, kgPerWeekGoal);
		addKgPerWeekGoal(kgPerWeekGoal);

		unsigned accountType;
		readUnsignedFromFile(ifs, accountType);
		addAccountType(accountType);

	}
}

void readWorkouts(ifstream& ifs) {
	unsigned workoutsVecorsSize;
	readUnsignedFromFile(ifs, workoutsVecorsSize);
	for (int i = 0; i < workoutsVecorsSize; i++) {
		string workoutName;
		readStringFromFile(ifs, workoutName);
		addWorkoutName(workoutName);

		double workoutCalories;
		readDoubleFromFile(ifs, workoutCalories);
		addWorkoutCalories(workoutCalories);

		tm workoutDate;
		readTmFromFile(ifs, workoutDate);
		addWorkoutDate(workoutDate);

		int workoutUser;
		readIntFromFile(ifs, workoutUser);
		addWorkoutUser(workoutUser);
	}
}

void readMeals(ifstream& ifs) {
	unsigned mealsVectorSize;
	readUnsignedFromFile(ifs, mealsVectorSize);
	for (int i = 0; i < mealsVectorSize; i++) {
		tm mealDate;
		readTmFromFile(ifs, mealDate);
		addMealDate(mealDate);

		string mealName;
		readStringFromFile(ifs, mealName);
		addMealName(mealName);

		double mealCalories;
		readDoubleFromFile(ifs, mealCalories);
		addMealCalories(mealCalories);

		int mealUser;
		readIntFromFile(ifs, mealUser);
		addMealUser(mealUser);
	}
}

void readDailyReport(ifstream& ifs) {
	unsigned dailyReportVectorSize;
	readUnsignedFromFile(ifs, dailyReportVectorSize);
	for (int i = 0; i < dailyReportVectorSize; i++) {
		tm dateForDailyReport;
		readTmFromFile(ifs, dateForDailyReport);
		addDatesForDailyCalorieReport(dateForDailyReport);

		double recommendedDailyCalories;
		readDoubleFromFile(ifs, recommendedDailyCalories);
		addRecommendedDailyKcal(recommendedDailyCalories);

		double protein;
		readDoubleFromFile(ifs, protein);
		addProtein(protein);

		double fatt;
		readDoubleFromFile(ifs, fatt);
		addFat(fatt);

		double carbohydrates;
		readDoubleFromFile(ifs, carbohydrates);
		addCarbohydrates(carbohydrates);

		double burnedCaloriesPerDay;
		readDoubleFromFile(ifs, burnedCaloriesPerDay);
		addBurnedCaloriesPerDay(burnedCaloriesPerDay);

		double consumedCaloriesPerDay;
		readDoubleFromFile(ifs, consumedCaloriesPerDay);
		addConsumedCaloriesPerDay(consumedCaloriesPerDay);

		int userForDailyReport;
		readIntFromFile(ifs, userForDailyReport);
		addUsersForDailyCalorieReport(userForDailyReport);
	}
}