/*
 * part3.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include "../includes/student.h"

#include <iostream>
#include <string>
#include <vector>
#include "student.h"

/*
Student(void);
		//Student(std::string Last_name, std::string First_name);
		void setName(std::string Last_name, std::string First_name);
		studentName getName(void);
		void studentEnroll();
		void studentPrint(void);
		void courseReset(void);
		// Overload assignment operator
		Student& operator=(const Student& rtSide);
		~Student();
*/

int Student::IDpool = 1; // Starting ID value for the 1st sensor should be '1'

Student::Student(void){
	ID = IDpool;
	IDpool++;
	numClasses = 0;
	ClassList = nullptr;
	ClassList = new std::string;
	//ClassList = new std::vector<std::string>;
	//ClassList;

}

void Student::setName(std::string Last_name, std::string First_name){
	Name.Lname = Last_name;
	Name.Fname = First_name;
}

studentName Student::getName(void){
	studentName pupil;
	pupil.Lname = Name.Lname;
	pupil.Fname = Name.Fname;
	return(pupil);
}

void Student::studentEnroll(){
	std::string input;
	bool loop = true;
	while(loop){
		std::cout << "Please enter the course to add: ";
		std::cin >> input;
		numClasses++;
		*ClassList = input;
		ClassList++;
		std::cout << "Would you like to add another class? (y/N): ";
		std::cin >> input;
		if((input == "y") || (input == "Y") || (input == "Yes") || (input == "YES") || (input == "yes")){
			loop = true;
		}
		else{
			loop = false;
		}
	}
	ClassList = ClassList - numClasses;
}

void Student::studentPrint(void){
	std::cout << "ID#: " << ID << std::endl;
	std::cout << Name.Lname << ", " << Name.Fname << std::endl;
	for(int i = 0; i < numClasses; i++){
		std::cout << *ClassList << std::endl;
		ClassList++;
	}
	ClassList = ClassList - numClasses; // undoing increment
	std::cout  << "Total number of classes: " << numClasses << std::endl;
}

void Student::courseReset(void){
	delete [] ClassList;
	numClasses = 0;
}

// Overload assignment operator, only copies courses
Student& Student::operator=(const Student& rtSide){
	// Checking if both sides the same
	if(this == &rtSide){
		return *this;
	}
	else{
		//ID = rtSide.ID;
		//Name.Lname = rtSide.Name.Lname;
		//Name.Fname = rtSide.Name.Fname;
		numClasses = rtSide.numClasses;
		delete [] ClassList;
		ClassList = new std::string[numClasses];
		//ClassList = new std::vector;
		for(int i = 0; i < numClasses; i++){
			ClassList[i] = rtSide.ClassList[i];
		}

		return *this;
	}
}

Student::~Student(){
	delete [] ClassList;
}
