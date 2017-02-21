/*
 * part3.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include <iostream>
#include <string>
#include "part3.h"
#include "student.h"

//struct StudentBody{
//	Student *StudentList;
//	int studentCount;
//};

StudentBody::StudentBody(){
	*StudentList = nullptr;
	StudentList = new Student[];
	studentCount = 0;
}

//! General part 3 routine
void part3(void){
	//Student *StudentBody = nullptr;
	//StudentBody = new Student[];
	//MasterControl(StudentBody);
	StudentBody mySchool;
	addNewStudent(StudentBody);
}

//! Adding in new student, console entry is managed in function,
// therefore, only a reference to the student body is needed
void addNewStudent(StudentBody &StudentBod){
	std::string LastName;
	std::string FirstName;
	std::string input;
	bool loop = true;
	while(loop){
		std::cout << "Please enter the last name of the student: ";
		std::cin >> LastName;
		std::cout << "Please enter the first name of the student: ";
		std::cin >> FirstName;
		StudentBod.StudentList[StudentBod.studentCount].Student(LastName, FirstName);
		std::cout << "OK, we will now verify that the following enrollment is correct: " << std::endl;
		StudentBod.StudentList[StudentBod.studentCount].displayEnrollment();
		std::cout << "Is this info correct? (Y/n): ";
		std::cout << std::endl;
		if((input == "N") || (input == "n") || (input == "NO") || (input == "No") || (input == "no")){
			loop = true;
			std::cout << "OK, we are going to go back and re-enter the student information" << std::endl;
		}
		else{
			loop = false;
		}
		StudentBod.studentCount++;
	}
}

//! \brief Removing a student
//
// Like in addNewStudent, this function takes in the
// location of the student body to modify, all behavior
// is managed internally
void removeStudent(StudentBody &StudentBod){
	if(StudentBod.studentCount == 0){
		std::cout << "You already have zero students..." << std::endl;
	}
	else{

	}
}

//! print all currently enrolled students
// Not sure on PTR type at this point in time.
// Could also try using pass by reference.
// This function only outputs to the console, another
// that provides manipulatable data might be useful to
// add later on, once the type of data to manipulate is
// determined
void printAllStudents(const Student *PTRtoStudents){

}

void MasterControl(StudentBody &StudentBod){
	bool loop = true;
	while(loop){
		std::string input;
		std::cout << "What would you like to do?: " << std::endl;
		std::cout << "1 Enter a new student?" << std::endl;
		std::cout << "2 Remove a student?" << std::endl;
		std::cout << "3 Print all enrolled students?" << std::endl;
		std::cout << "Please enter the number for the entry you desire now: " << std::endl;
		std::cin >> input;
		switch (input){
			case "1":{
				addNewStudent(StudentBod);
				loop = false;
				break;
			}
			case "2":{
				removeStudent(StudentBod)
				loop = false;
				break;
			}
			case "3":{
				loop = false;
				break;
			}
			default:{
				std::cout << "I'm sorry, I didn't understand that; Please try again" << std::endl;
				loop = true;
				break;
			}
		}
	}
}

void addStudentClasses(StudentBody &StudentBod, const int &student){
	std::cout << "We will enter the classes one at a time" << std::endl;
	std::cout << "Please entry names without spaces" << std::endl;
	bool loop = true;
	std::string input;
	while(loop){
		std::cout << "Please enter the class name: ";
		std::cin >> input;
		StudentBod.StudentList->addClass(input);
		std::cout << "Would you like to enter another class? (y/N): ";
		std::cin >> input;
		if((input == "y") || (input == "Y") || (input == "Yes") || (input == "YES") || (input == "yes")){
			loop = true;
		}
		else{
			std::cout << "OK, we are now done entering classes" << std::endl;
			loop = false;
		}
	}
}
