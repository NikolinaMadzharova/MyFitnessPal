#pragma once

void saveUnsignedToFile(ofstream& ofs, unsigned num);
void readUnsignedFromFile(ifstream& ifs, unsigned& num);
void saveDoubleToFile(ofstream& ofs, double num);
void readDoubleFromFile(ifstream& ifs, double& num);
void saveStringToFile(ofstream& ofs, string str);
void readStringFromFile(ifstream& ifs, string& str);
void readTmFromFile(ifstream& ifs, tm& date);
void saveTmToFile(ofstream& ofs, tm date);
void saveIntToFile(ofstream& ofs, int  num);
void readIntFromFile(ifstream& ifs, int& num);

void saveToFile();
void saveAccountData(ofstream& ofs);
void saveWorkouts(ofstream& ofs);
void saveMeals(ofstream& ofs);
void saveDailyReport(ofstream& ofs);

void readFromFile();
void readAccountData(ifstream& ifs);
void readWorkouts(ifstream& ifs);
void readMeals(ifstream& ifs);
void readDailyReport(ifstream& ifs);
