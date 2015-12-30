//
//  global.h
//  Jacobs Training Assistant
//
//  Created by Jacob Molin Nielsen on 28/12/2015.
//  Copyright © 2015 Wussypants. All rights reserved.
//

#ifndef global_h
#define global_h

//MARK: Includes
#include <stdio.h>
#include <iostream>
#include <string>
typedef std::string string;
#include <sstream>
#include <vector>
#include <ctime>
#include <fstream>
#include <cstdlib>

//--- MARK: Structs
struct Workouts {
    int pushUps = 0;
    int pullUps = 0;
    int sitUps  = 0;
    int squats  = 0;
};

extern Workouts workouts;
extern std::vector<int> dates;

#endif /* global_h */
