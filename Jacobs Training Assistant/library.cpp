//
//  library.cpp
//  Jacobs Training Assistant
//
//  Created by Jacob Molin Nielsen on 15/12/2015.
//  Copyright © 2015 Wussypants. All rights reserved.
//

#include "library.hpp"
#include "global.h"

//--- MARK: Enums
enum class WorkoutType {
    pushups,
    pullups,
    situps,
    squats
};

//--- MARK: Initialize time
time_t now = time(0);

tm *ltm = localtime(&now);

int currentDay = ltm->tm_mday;
int currentMonth = 1 + ltm->tm_mon;
int currentYear = 1900 + ltm->tm_year;

//--- MARK: Functions //

int combine (int a, int b, int c)
{
    std::ostringstream oss;
    oss << a << b << c;
    std::istringstream iss(oss.str());
    int d;
    iss >> d;
    return d;
}


void printCompletedWorkouts(std::vector<int> date){
    using namespace std;
    
    if (date.back() != 0) {
        int intCurrentDate = date.back();
        string currentDate = to_string(intCurrentDate);
        
        string day = currentDate.substr(0,2);
        string month = currentDate.substr(2,2);
        string year = currentDate.substr(4,4);
        cout << "Date: " << day << "/" << month << "-" << year << endl;
    }
    
    cout << "Push-ups: " << workouts.pushUps
         << " Pull-ups: " << workouts.pullUps
         << " Sit-ups: " << workouts.pullUps
         << " Squats: " << workouts.squats << endl;
}

// Adds 10 of each workout to the currentDay
void trainingDay(std::vector<int> &trainingDate){
    
    int errorNow = 0;
    
    int currentDate = combine(currentDay, currentMonth, currentYear);
    for (int count = 0; count < trainingDate.size(); ++count) {
        if (trainingDate[count] == currentDate) {
            errorNow = 1;
        }
    }
    
    if (errorNow != 1) {
        workouts.pushUps += 10;
        workouts.pullUps += 10;
        workouts.sitUps  += 10;
        workouts.squats  += 10;
        
        if (trainingDate[0] == 0){
            trainingDate[0] = currentDate;
        } else {
            trainingDate.push_back(currentDate);
        }
        
        
    } else {
        std::cout << "You have already trained today!"<< std::endl;
    }

}



// Parameter 'whatWorkout' tells the function what it which workout it should remove.
// [Add functionality to add multiple workouts. See learncpp.com for solution]
void addWorkout(WorkoutType workout){
    switch (workout) {
        case WorkoutType::pushups:
                workouts.pushUps += 10;
            break;
        case WorkoutType::pullups:
                workouts.pullUps += 10;
            break;
        case WorkoutType::situps:
                workouts.sitUps += 10;
            break;
        case WorkoutType::squats:
                workouts.squats += 10;
            break;
        default:
            break;
    }

}

// Parameter 'whatWorkout' tells the function what it which workout it should remove.
// [Add functionality to remove multiple workouts. See learncpp.com for solution]
void removeWorkout(WorkoutType workout, string &errorOut){
    
    switch (workout) {
        case WorkoutType::pushups:
            if (workouts.pushUps != 0)
                workouts.pushUps -= 10;
            break;
        case WorkoutType::pullups:
            if (workouts.pullUps != 0)
                workouts.pullUps -= 10;
        case WorkoutType::situps:
            if (workouts.sitUps != 0)
                workouts.sitUps -= 10;
        case WorkoutType::squats:
            if (workouts.squats != 0){
                workouts.squats -= 10;
            }
        default:
            errorOut = "You haven't done any workouts in this catagory";
            break;
    }
}

// [Make it a specefic date with a parameter]
void addDay(){
    workouts.pullUps += 10;
    workouts.pushUps += 10;
    workouts.sitUps  += 10;
    workouts.squats  += 10;
}

// [Make it a specefic date with an parameter]
void removeDay(){
    workouts.pullUps -= 10;
    workouts.pushUps -= 10;
    workouts.sitUps  -= 10;
    workouts.squats  -= 10;

}

string saveToFile(std::vector<int> &array, Workouts &workout){
    string attempt;
    
    // Save dates
    const string fileDates = "dataDates.txt";
    std::ofstream numberDates;
    numberDates.open(fileDates, std::ios::out);
    
    for (int count = 0; count < array.size(); ++count) {
        numberDates << array[count] << std::endl;
    }
    
    numberDates.close();
    
    // Save struc
    const string fileStruct = "dataStructs.txt";
    std::ofstream saveWorkouts;
    saveWorkouts.open(fileStruct, std::ios::out);
    
    saveWorkouts << workout.pullUps << std::endl;
    saveWorkouts << workout.pushUps << std::endl;
    saveWorkouts << workout.sitUps  << std::endl;
    saveWorkouts << workout.squats  << std::endl;
    
    attempt = "Data succesfully saved";
    return attempt;
}

string readFromFile(std::vector<int> &array, Workouts &workout)
{
    string attempt;
    string data;
    
    
    // Read dates
    const string fileDates = "dataDates.txt";
    std::ifstream numberDates;
    numberDates.open(fileDates,std::ios::in);
    //    numberDates >> data;
    int number;
    numberDates >> array[0];
    while (numberDates >> number) {
        array.push_back(number);
    }
    
    // Read struct
    const string fileStruct = "dataStructs.txt";
    std::ifstream loadWorkouts;
    loadWorkouts.open(fileStruct,std::ios::in);
    loadWorkouts >> workout.pullUps;
    loadWorkouts >> workout.pushUps;
    loadWorkouts >> workout.sitUps;
    loadWorkouts >> workout.squats;
    
    attempt = "Data succesfully loaded";
    return attempt;
}

void help(){
    std::cout << "Functionality:\n"
              << "\'exit\' - Saves the current progress and exits the program\n"
              << "\'training\' - Adds 10 of each workout to the current day\n"
              << "\'completed workouts\' - Shows the total amount of completed workouts\n"
    << std::endl;
}

bool readUserInput(){
    string input;
    std::getline(std::cin, input);
    
    if (input == "exit"){
        return false;
    } else if (input == "training"){
        trainingDay(dates);
    } else if (input == "completed workouts"){
        printCompletedWorkouts(dates);
    } else if (input == "help") {
        help();
    } else {
        std::cout << "Please enter a valid function type 'help' to available functions" << std::endl;
    }
    return true;
}