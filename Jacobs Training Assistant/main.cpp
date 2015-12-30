//
//  main.cpp
//  Jacobs Training Assistant
//
//  Created by Jacob Molin Nielsen on 13/12/2015.
//  Copyright © 2015 Wussypants. All rights reserved.
//

#include "library.hpp"
#include "global.h"

int main(int argc, const char * argv[]) {
    
    //MARK: Initialize array to store date
//    std::vector<int> dates = {0};
    readFromFile(dates, workouts);
    // example ⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇⬇
    // int myDate = combine(currentDay, currentMonth, currentYear);
    // dates = {myDate};
    
    
    std::cout << "Hello! Welcome to Jacob's Training Assistant.\n"
              << "Type 'help' to see available functionality\n"
              << "Your current progress is as of date: \n" << std::endl;
    
    printCompletedWorkouts(dates);
    
    while (readUserInput() != false);
    
    saveToFile(dates, workouts);
    std::cout << std::endl;
    return 0;
}
