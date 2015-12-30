//
//  library.hpp
//  Jacobs Training Assistant
//
//  Created by Jacob Molin Nielsen on 15/12/2015.
//  Copyright © 2015 Wussypants. All rights reserved.
//

#ifndef library_hpp
#define library_hpp
#include "global.h"

//MARK: Functions
void printCompletedWorkouts(std::vector<int> date);
void trainingDay(std::vector<int> &trainingDate);

string readFromFile(std::vector<int> &array, Workouts &workout);
string saveToFile(std::vector<int> &array, Workouts &workout);

int combine (int a, int b, int c);

bool readUserInput();

#endif /* library_hpp */
