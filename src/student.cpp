/*
 * part3.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include "../includes/student.h"

#include <iostream>
#include <string>


Student::Student(std::string Last_name, std::string First_name){
	ID = IDpool;
	IDpool++;
	Lname = Last_name;
	Fname = First_name;
	numClasses = 0;
	ClassList = new std::string;
}
void Student::setName(std::string Last_name, std::string First_name){
	Lname = Last_name;
	Fname = First_name;
}
std::string Student::getName(void){
	return(Lname, Fname);
}
int Student::getNumClasses(void){
	return(numClasses);
}
// something to list more about courses
void Student::addClass(std::string className){
	ClassList[numClasses] = className;
	numClasses++;
}
void Student::dropClass(std::string className){
	int location = 0;
	bool classFound = false;
	bool loop = true;
	while(loop){
		for(int i = 0; i < numClasses; i++){
			if(ClassList[i] == className){
				location = i;
				classFound = true;
				loop = false;
				break; // We found the class, no need to keep looking
			}
		}
		if(classFound == false){
			std::cout << "We were unable to Locate that class, did you misspell it?" << std::endl;
			std::string input;
			std::cout << "Would you like to try again? (y/N): ";
			std::cin >> input;
			std::cout << std::endl;
			if((input == "y") || (input == "Y") || (input == "Yes") || (input == "YES") || (input == "yes")){
				loop = true;
				std::cout << "Please enter the class name: ";
				std::cin >> input;
				std::cout << std::endl;
			}
			else{
				loop = false;
				std::cout << "We did not remove any classes because we could not find any matching the original input" << std::endl;
			}
		}
	}
	for(int i = location; i < numClasses; i++){
		if((i + 1) < numClasses){
			ClassList[i] = ClassList[i+1];
		}
		else{
			numClasses--;
		}
	}
}

void Student::displayEnrollment(){
	std::cout << Lname << ", " << Fname << " is enrolled in " << numClasses << " classes" << std::endl;
	std::cout << "The following are the classes: " << std::endl;
	for(int i = 0; i < numClasses; i++){
		std::cout << ClassList[i] << std::endl;
	}
}

void Student::resetClasses(void){
	delete [] ClassList;
	numClasses = 0;
}

// Overload assignment operator
Student& Student::operator=(const Student& rtSide){
	// Checking if both sides the same
	if(this == &rtSide){
		return *this;
	}
	else{
		ID = rtSide.ID;
		Lname = rtSide.Lname;
		Fname = rtSide.Fname;
		numClasses = rtSide.numClasses;
		delete [] ClassList;
		ClassList = new std::string[numClasses];
		for(int i = 0; i < numClasses; i++){
			ClassList[i] = rtSide.ClassList[i];
		}

		return *this;
	}
}

Student::~Student(){
	delete [] ClassList;
}
