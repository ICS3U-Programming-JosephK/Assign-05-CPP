// Copyright (c) 2022 Immaculata HS All rights reserved.
//
// Created by: Joseph Kwon
// Created on: December 08 2022
// This program asks the user for the radius
// and height of a cylinder and outputs volume
// Additionally, it has a first letter capitalization program

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>

// Defining the function that formats the address
float cylinderCalculator(float radius, float height) {
    float volume;
    volume = M_PI * pow(radius, 2) * height;

    return volume;
}

// Defining the function that formats the address
float circleCalculator(float radius) {
    float circumference;

    circumference = 2 * M_PI * radius;

    return circumference;
}

float errorChecker(std::string userNumAsStr) {
    try {
        float numAsFloat = std::stof(userNumAsStr);
        return numAsFloat;
    } catch (...) {
        return -1;
    }
}

int main() {
    std::string userAnswer = "";

    do {
        // Declaring variables
        float floatRadiusFromUser = 0, floatHeightFromUser = 0;
        std::string circleNameFromUser,
        strRadiusFromUser, strHeightFromUser, wait;

        // input
        std::cout << "Enter the radius";
        std::cout << "(In decimals): ";
        std::cin >> strRadiusFromUser;

        // Gets height
        std::cout << "Enter the height: ";
        std::cin >> strHeightFromUser;

        // Checks user inputs for casting errors
        floatRadiusFromUser = errorChecker(strRadiusFromUser);
        floatHeightFromUser = errorChecker(strHeightFromUser);

        // Asks user to restart if casting errors were found
        if (floatRadiusFromUser == -1 || floatHeightFromUser == -1) {
            std::cout << "You must enter numbers for each input.";
            std::cout << "Enter any character to restart: ";
            std::cin >> wait;
            continue;
        }

        std::cout << "Enter your circle's name: ";
        std::cin >> circleNameFromUser;

        // Calling out function and passing the input as arguments
        float formattedAddress = cylinderCalculator(floatRadiusFromUser,
        floatHeightFromUser);

        std::cout << "\nThe volume of the cylinder is " << formattedAddress;

        if (circleNameFromUser != "") {
            float formattedCircle = circleCalculator(floatRadiusFromUser);
            std::cout << "\nThe name of the circle is " << circleNameFromUser <<
            " is and the circumference is " << formattedCircle;
        } else if (circleNameFromUser == "") {
            float formattedCircle = circleCalculator(floatRadiusFromUser);
            std::cout << "\nThe circumference of "
            "the circle is " << formattedCircle;
        }

        // Declaring variables
        std::string userAnswer;

        // users a while loop to give the user the option
        // to continue or not after the user finishes
        std::cout << "\nWould you like to try again? (y/n)\n";
        std::cout << ">> ";
        std::cin >> userAnswer;
        std::cout << "\n";

        if (userAnswer == "n") {
            break;
        }
    } while (true);
}
