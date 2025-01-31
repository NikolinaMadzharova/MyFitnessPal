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
* <menu function>
*
*/

#include "Menu.h"

void printHeader() {
    cout << "*****************************************"<<endl;
    cout << "*                                       *"<<endl;
    cout << "*         welcome to myFitnessPal       *"<<endl;
    cout << "*                                       *"<< endl;
    cout << "*****************************************"<<endl;
    cout << endl;
    cout << "-----------------------------------------"<< endl;
    cout << "|        Your Fitness Tracker           |"<<endl;
    cout << "|     Track food, exercise, and goals   |" << endl;
    cout << "-----------------------------------------"<<endl;
    cout << endl;
    cout << "*****************************************"<<endl;
    cout << "*       Select an Option Below:         *"<<endl;
    cout << "*****************************************"<<endl;
    printLoginOrRegisterMenu();
}

void printLoginOrRegisterMenu() {
    cout << "----------- LOGIN / REGISTER -----------" << endl;
    cout << "              1. Login                " << endl;
    cout << "             2. Register              " << endl;
    cout << "              3. Quit                 " << endl;
    cout << "       Select an option (1-3): ";
    int option;
    cin >> option;
    cout << endl;
    switch (option)
    {

    case 1:inputForLogin();
        if (getLoggedUserIndex() == -1){
            printLoginOrRegisterMenu(); 
        }
        else {
            printMainMenu();
            addDailyReport();
        }
         break;
    case 2: registration();
        printLoginOrRegisterMenu(); break;
    case 3: break;
    default:
        cout << "Invalid option. Try again." << endl;
        printLoginOrRegisterMenu();
    }
}

void printMainMenu() {
    cout << "-------------- MAIN MENU ---------------" << endl;
    cout << "1. View Daily Report" << endl;
    cout << "2. View Report for Specific Date" << endl;
    cout << "3. Delete Report for Specific Date" << endl;
    cout << "4. Add Meal for the Day" << endl;
    cout << "5. Add Workout for the Day" << endl;
    cout << "6. Edit Meal for the Current Day" << endl;
    cout << "7. Edit Workout for the Current Day" << endl;
    cout << "8. Edit User Profile" << endl;
    cout << "9. Log Out" << endl;
    cout << "Select an option (1-9): ";

    int option;
    cin >> option;
    cout << endl;
   
    switch (option)
    {
    case 1: dailyReportMenu(); break;
    case 2: specificDateReportMenu(); break;
    case 3: deleteReportForSpecificDateMenu(); break;
    case 4: addMealMenu(); break;
    case 5: addWorkoutMenu(); break;
    case 6: editMealsForTheDayMenu(); break;
    case 7: editWorkoutsForTheDayMenu(); break;
    case 8: editUserProfileMenu(); break;
    case 9: printLoginOrRegisterMenu(); break;
        break;
    default:
        cout << "Invalid option. " << endl;
        messageToReturnToMainMenu();
    }
}

void addWorkoutMenu() {
    cout << "--------------- ADD WORKOUT ---------------" << endl;
    cout << "1. Cardio" << endl;
    cout << "2. Strength Training" << endl;
    cout << "3. Flexibility" << endl;
    cout << "4. Other (Enter custom workout)" << endl;
    cout << "Select workout type (1-4): ";

    int option;
    cin >> option;
    string workoutName;
    cout << endl;
    if (option == 4) {
        cout << "Enter the name of the workout: ";
        cin >> workoutName;
    }
    else {
        switch (option)
        {
        case 1: workoutName = "Cardio"; break;
        case 2: workoutName = "StrengthTraining"; break;
        case 3: workoutName = "Flexibility"; break;
        default: cout << "Invalid option. " << endl;
            messageToReturnToMainMenu();
        }
    }
    cout << endl;

    cout << "Enter the calories burned during the workout: ";
    double caloriesBurned;
    cin >> caloriesBurned;
    if (!areWorkoutCaloriesValid(caloriesBurned)) {
        cout << "Invalid number. ";
        messageToReturnToMainMenu();
    }
    else {
        cout << "Workout successfully added! " << endl;
        addWorkout(workoutName, caloriesBurned);
        messageToReturnToMainMenu();
    }
}

void addMealMenu() {
    cout << "---------------- ADD MEAL -----------------" << endl;
    cout << "1. Breakfast" << endl;
    cout << "2. Lunch" << endl;
    cout << "3. Dinner" << endl;
    cout << "4. Other" << endl;
    cout << "Select meal name(1-4): ";
    int option;
    cin >> option;
    string mealName;
    cout << endl;
    if (option == 4) {
        cout << "Enter the name of the meal: ";
        string mealName;
        cin >> mealName;
        if (mealName.empty()) {
            cout << "Invalid name. " << endl;
            messageToReturnToMainMenu();
        }
    }
    else {
        switch (option)
        {
        case 1: mealName = "Breakfast"; break;
        case 2: mealName = "Lunch"; break;
        case 3: mealName = "Dinner"; break;
        default: cout << "Invalid option. " << endl;
            messageToReturnToMainMenu();
        }
    }
    cout << endl;
    cout << "Enter the calories for the meal: ";
    double mealCalories;
    cin >> mealCalories;
    if (!areMealCaloriesValid(mealCalories)) {
        cout << "Invalid number. Please enter a positive value for calories." << endl;
        messageToReturnToMainMenu();
    }
    addMeal(mealName, mealCalories);
    cout << "Meal successfully added! " << endl;
    messageToReturnToMainMenu();
}

void dailyReportMenu() {
    tm currentDate = getCurrentDate();
    unsigned accountType = getAccountTypeLoggedUser();
    double recommendedKcal;
    double protein;
    double fat;
    double carbohydrates;
    double burnedKcal;
    double consumedKcal;
    getDailyReport(currentDate,recommendedKcal, protein, fat, carbohydrates, burnedKcal, consumedKcal);
    cout << "--------------- DAILY REPORT ---------------" << endl;
    cout << "Recommended daily calories: " <<recommendedKcal<< endl;
    if (accountType == 2) {
        cout << "Recommended daily macronutrients:" << endl;
        cout << "Protein: " << protein << " grams" << endl;
        cout << "Fat: " << fat << " grams" << endl;
        cout << "Carbohydrates: " << carbohydrates << " grams" << endl;
    }
    cout << "Total calories consumed: " << consumedKcal<<endl;
    cout << "Total calories burned: " << burnedKcal<<endl;
    cout << "Calorie balance (Consumed - Burned): " <<consumedKcal-burnedKcal<< endl;
    cout << "-------------------MEALS---------------------" << endl;
    printMeals(currentDate);
    cout << "------------------WORKOUTS-------------------" << endl;
    printWorkouts(currentDate);
    messageToReturnToMainMenu();
}

void specificDateReportMenu() {
    cout << "------------ SPECIFIC-DATE-REPORT ------------" << endl;
    cout << "For which day would you like to see a report ? " << endl;
    cout << "Enter the date (dd.mm.yyyy): ";
    string dateStr;
    cin >> dateStr;
    cout << endl;
    if (!isValidDate(dateStr)) {
        cout << "Invalid date." << endl;
        messageToReturnToMainMenu();
    }else if(!doesDailyReportExist(convertStringToTm(dateStr))) {
        cout << "No report for this date" << endl;
        messageToReturnToMainMenu();
    }
    else {
        tm date = convertStringToTm(dateStr);
        double recommendedKcal;
        double protein;
        double fat;
        double carbohydrates;
        double burnedKcal;
        double consumedKcal;
        int accountType = getAccountTypeLoggedUser();
        getDailyReport(date, recommendedKcal, protein, fat, carbohydrates, burnedKcal, consumedKcal);
        cout << "------------------ REPORT ------------------" << endl;
        cout << "Recommended daily calories: " << recommendedKcal << endl;
        if (accountType == 2) {
            cout << "Recommended daily macronutrients:" << endl;
            cout << "Protein: " << protein << " grams" << endl;
            cout << "Fat: " << fat << " grams" << endl;
            cout << "Carbohydrates: " << carbohydrates << " grams" << endl;
        }
        cout << "Total calories consumed: " << consumedKcal << endl;
        cout << "Total calories burned: " << burnedKcal << endl;
        cout << "Calorie balance (Consumed - Burned): " << consumedKcal - burnedKcal << endl;
        cout << "-------------------MEALS---------------------" << endl;
        printMeals(date);
        cout << endl;
        cout << "------------------WORKOUTS-------------------" << endl;
        printWorkouts(date);
        cout << endl;
        messageToReturnToMainMenu();
    }
}
   
void deleteReportForSpecificDateMenu() {
    cout << "----------- DELETE-REPORT-FOR-SPECIFIC-DATE -----------" << endl;
    cout << "Enter the date (dd.mm.yyyy) for the report to delete: ";
    string dateStr;
    cin >> dateStr;
    cout << endl;
    if (!isValidDate(dateStr)) {
        cout << "Invalid date. " << endl;;
        messageToReturnToMainMenu();
    }
    else if (!doesDailyReportExist(convertStringToTm(dateStr))){
        cout << "No report for this date! " << endl;
        messageToReturnToMainMenu();
    }
    else {
        tm date = convertStringToTm(dateStr);
        deleteDailyReport(date);
        deleteAllMealsForSpecificData(date);
        deleteAllWorkoutsForSpecificDate(date);
        cout << "Successfully deleted report! " << endl;
        messageToReturnToMainMenu();
    }
}

void editMealsForTheDayMenu() {
    tm date = getCurrentDate();
    cout << "----------------- EDIT-MEALS-----------------" << endl;
    if (!doesMealExist()) {
        cout << "No meals added for the day! " << endl;
        messageToReturnToMainMenu();
    }
    else {
        printMeals(date);
        cout << endl << "Enter the name of the meal you want to edit: ";
        string mealName;
        cin >> mealName;
        if (!checkMealName(mealName)) {
            cout << "There is no such meal name! " << endl;
            messageToReturnToMainMenu();
        }
        else {
            cout << "What do you want to edit? " << endl;
            cout << "1. Name" << endl << "2.Calories" << endl << "3.Delete meal" << endl;
            cout << "Enetr a num (1-3): ";
            int option;
            cin >> option;
            if (option == 1) {
                cout << "Enter the new meal name: ";
                string newName;
                cin >> newName;
                cout << endl;
                editMealName(mealName, newName);
                cout << "Meal name edited successfully! " << endl;
                messageToReturnToMainMenu();
            }
            else if (option == 2) {
                cout << "Enter the new calories for the meal: ";
                double mealCalories;
                cin >> mealCalories;
                if (!areMealCaloriesValid(mealCalories)) {
                    cout << "Invalid number. Please enter a positive value for calories. " << endl;
                    messageToReturnToMainMenu();
                }
                else {
                    double oldCalories = caloriesConsumedFromMeal(mealName);
                    double difference = mealCalories - oldCalories;
                    editConsumedCaloriesAfterEditingMeal(difference);
                    editMealKcal(mealName, mealCalories);

                    cout << "Successfully edited calories consumed for the meal! " << endl;
                    messageToReturnToMainMenu();
                }
            }
            else if (option == 3) {
                double oldCalories = caloriesConsumedFromMeal(mealName);
                double difference = -oldCalories;
                editConsumedCaloriesAfterEditingMeal(difference);
                deleteMealForTheDay(mealName);
                cout << "Successfully deleted meal! " << endl;
                messageToReturnToMainMenu();
            }
            else {
                cout << "Invalid option. " << endl;
                messageToReturnToMainMenu();
            }
        }
    }
}

void editWorkoutsForTheDayMenu() {
    tm date = getCurrentDate();
    cout << "----------------- EDIT-WORKOUTS-- ---------------" << endl;
    if (!doesWorkoutExist()) {
        cout << "No workots added for the day! " << endl;
        messageToReturnToMainMenu();
    }
    else {
        printWorkouts(date);
        cout << endl;
        cout <<endl<< "Enter the name of the workout you want to edit: ";
        string workoutName;
        cin >> workoutName;
        if (!checkWorkoutName(workoutName)) {
            cout << "There is no such workout name! " << endl;
            messageToReturnToMainMenu();
        }
        else {
            cout << "What do you want to edit? " << endl;
            cout << "1. Name" << endl << "2.Calories burned" << endl << "3. Delete workout" << endl;
            cout << "Enter a num (1-3): ";
            int option;
            cin >> option;
            if (option == 1) {
                cout << "Enter the new workout name: ";
                string newName;
                cin >> newName;
                cout << endl;
                editWorkoutName(workoutName, newName);
                cout << "Workout name edited successfully! " << endl;;
                messageToReturnToMainMenu();
            }
            else if (option == 2) {
                cout << "Enter the new calories burned: ";
                double newCalories;
                cin >> newCalories;
                if (!areWorkoutCaloriesValid(newCalories)) {
                    cout << "Invalid number. " << endl;
                    messageToReturnToMainMenu();
                }
                else {
                    double oldCalories = caloriesBurnedFromWorkout(workoutName);
                    double difference = newCalories - oldCalories;
                    editBurnedCaloriesAfterEditingWorkout(difference);
                    editWorkoutKcal(workoutName, newCalories);

                    cout << "Successfully edited calories burned from workout! " << endl;
                    messageToReturnToMainMenu();
                }
            }
            else if (option == 3) {
                double oldCalories = caloriesBurnedFromWorkout(workoutName);
                double difference = -oldCalories;
                editBurnedCaloriesAfterEditingWorkout(difference);
                deleteWorkoutForTheDay(workoutName);
                cout << "Successfully deleted workout! " << endl;
                messageToReturnToMainMenu();
            }
            else {
                cout << "Invalid option. " << endl;
                messageToReturnToMainMenu();
            }
        }
    }
}

void editUserProfileMenu() {
    cout << "--------------- EDIT-USER-PROFILE ---------------" << endl;
    cout << "What do you want to edit" << endl;
    cout << "1. Weight " << endl << "2. Height" << endl << "3. Goal" << endl << "4. Weekly goal"<<endl<<"5. Edit activity level" << endl;
    cout << "Enter a number 1-4: ";
    int option;
    cin >> option;
    switch(option){
    case 1: editWeightMenu(); break;
    case 2: editHeightMenu(); break;
    case 3: editGoalMenu(); break;
    case 4: editWeeklyGoalMenu(); break;
    case 5: editActivityLevelMenu(); break;
    default:cout << "Invalid optin. "<<endl;
        messageToReturnToMainMenu();
        break;
    }
}

void editWeightMenu() {
    cout << "Enter your new weight: ";
    double newWeight;
    cin >> newWeight;
    if (!isWeightValid(newWeight)) {
        cout << "Invalid weight." << endl;
        messageToReturnToMainMenu();
    }
    else {
        editWeight(newWeight);
        cout << "Successfully edited weight! ";
        editDailyReportAfterChangingAccountData();
        messageToReturnToMainMenu();
    }
}

void editHeightMenu() {
    cout << "Enter your new height: " << endl;
    unsigned newHeight;
    cin >> newHeight;
    editHeight(newHeight);
    if (!isHeightValid(newHeight)){
        cout << "Invalid height.  " << endl;
        messageToReturnToMainMenu();
    }
    else {
        editHeight(newHeight);
        cout << "Successfully edited height! " << endl;
        editDailyReportAfterChangingAccountData();
        messageToReturnToMainMenu();
    }
   
}

void editGoalMenu() {
    cout << "Select your new goal " << endl << "1. Lose weight" << endl << "2. Maintain weight" << endl << "3. Gain weight" << endl;
    cout << "Your new goal (enter a number 1-3): ";
    unsigned newGoal;
    cin >> newGoal;
    if (!isGoalValid(newGoal)) {
        cout<<"Invalid goal. ";
        messageToReturnToMainMenu();
    }
    else {
        editGoal(newGoal);
        cout << "Successfully edited goal! " << endl;
        editDailyReportAfterChangingAccountData();
        if (newGoal == 2) {
            editKgPerWeekGoal(0);
        }
        messageToReturnToMainMenu();
    }
}

void editWeeklyGoalMenu() {
    unsigned goal = getGoalLoggedUser();
    switch (goal)
    {
    case 1: cout << "How much weight would you like to lose per week? " << endl;
        cout << "1. 0.25" << endl << "2. 0.5" << endl << "3. 0.75" << endl << "4. 1.0" << endl;
        cout << "Your new goal (enter a number 1-4): ";
        unsigned newKgPerWeekGoal;
        cin >> newKgPerWeekGoal;
        cout << endl;
        if (!isKgForWeekGoalValid(newKgPerWeekGoal)) {
            cout << "Invalid goal." << endl;
            messageToReturnToMainMenu();
        }
        else {
            editKgPerWeekGoal(newKgPerWeekGoal);
            editDailyReportAfterChangingAccountData();
            cout << "Successfully edited goal! " << endl;
            messageToReturnToMainMenu();
        }
        break;
    case 2:
        cout << "How much weight would you like to gain per week? " << endl;
        cout << "1. 0.25" << endl << "2. 0.5" << endl << "3. 0.75" << endl << "4. 1.0" << endl;
        cout << "Your goal (enter a number 1-4): ";
        unsigned newKgPerWeekGoalOption;
        cin >> newKgPerWeekGoalOption;
        cout << endl;
        if (newKgPerWeekGoalOption > 4) {
            cout << "Invalid goal. " << endl;
            messageToReturnToMainMenu();
        }
        else {
            cout << "Successfully edited goal! " << endl;
            editKgPerWeekGoal(newKgPerWeekGoalOption);
            editDailyReportAfterChangingAccountData();
            messageToReturnToMainMenu();
        }
        break;
    case 3:cout << "Your goal is to maintain weight." << endl; break;
    }
}
  
void editActivityLevelMenu() {
    cout << "Select your new activity level "
        << endl << "1. Sendentary work, no exercise"
        << endl << "2. Light activity (exercise 1-3 days per week)"
        << endl << "3. Moderate activity (exercise 3-5 days per week)"
        << endl << "4. Active work (exercise 6-7 days per week)"
        << endl << "5. Very active (physical work or intense training)" << endl;

    cout << "Your new activity level (enter a number 1-5): ";
    unsigned newActivityLevel;
    cin >> newActivityLevel;
    cout << endl;
    if (!isActivityLevelValid(newActivityLevel)) {
        cout << "Invalid activity level. " << endl;
        messageToReturnToMainMenu();
    }
    else {
        cout << "Successfully edited activity level! " << endl;
        editActivityLevel(newActivityLevel);
        editDailyReportAfterChangingAccountData();
        messageToReturnToMainMenu();
    }
}

void messageToReturnToMainMenu() {
    cout << "Enter any character to return to the main menu: ";
    char x;
    cin >> x;
    cout << endl;
    printMainMenu();
}