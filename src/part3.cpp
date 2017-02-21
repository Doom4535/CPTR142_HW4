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

//! Student Body structure
// Using a pointer to array of pointers could improve
// system performance (particularly for deletions)
StudentBody::StudentBody(){
	Student *StudentList = nullptr;
	//StudentList = *Student;
	StudentList = new Student[0];
	studentCount = 0;
}

//! General part 3 routine
void part3(void){
	//Student *StudentBody = nullptr;
	//StudentBody = new Student[];
	//MasterControl(StudentBody);
	StudentBody *StudentBodPTR;
	StudentBodPTR = new StudentBody;
	addNewStudent(StudentBodPTR);
	MasterControl(StudentBodPTR);

}

//! Adding in new student, console entry is managed in function,
// therefore, only a reference to the student body is needed
void addNewStudent(StudentBody *StudentBod){
	std::string LastName;
	std::string FirstName;
	std::string input;
	bool loop = true;
	while(loop){
		std::cout << "Please enter the last name of the student: ";
		std::cin >> LastName;
		std::cout << "Please enter the first name of the student: ";
		std::cin >> FirstName;
		//StudentBod.StudentList[StudentBod.studentCount].Student(LastName, FirstName);
		StudentBod.StudentList[StudentBod.studentCount].setName(LastName, FirstName);
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
void removeStudent(StudentBody *StudentBod){
	if(StudentBod.studentCount == 0){
		std::cout << "You already have zero students..." << std::endl;
	}
	else{
		int location;
		int studentID;
		std::cout << "Please enter the ID number of the student you would like to remove: ";
		std::cin >> studentID;
		std::cout << std::endl;
		bool found_student = false;
		std::string input;
		for(int i = 0; i < StudentBod.studentCount; i++){
			if(StudentBod.StudentList[i].getID() == studentID){
				location = i;
				found_student = true;
				break;	// We found them, no need to keep looking
			}
			found_student = false;
		}
		if(found_student == true){
			std::cout << "We found a student with the ID number: " << studentID << std::endl;
			studentName pupilName;
			pupilName = StudentBod.StudentList[location].getName();
			std::cout << "Their name is: " << pupilName.Lname << ", " << pupilName.Fname << std::endl;
			std::cout << "Is this information correct? (Y/n): ";
			std::cin >> input;
			std::cout << std::endl;
			if((input == "N") || (input == "n") || (input == "NO") || (input == "No") || (input == "no")){
				std::cout << "OK, we will cancel the deletion" << std::endl;
			}
			else{
				for(int j = location; j < StudentBod.studentCount; j++){
					// This would benefit from usig a pointer to each element instead of
					// a pointer to the array
					if(location < StudentBod.studentCount){
						StudentBod.StudentList[j] = StudentBod.StudentList[j + 1];
					}
					else{
						StudentBod.StudentList[j].~Student(); // We are now shrinking the total student count
						StudentBod.studentCount--;
					}
				}
			}
		}
	}
}

//! print all currently enrolled students
// Not sure on PTR type at this point in time.
// Could also try using pass by reference.
// This function only outputs to the console, another
// that provides manipulatable data might be useful to
// add later on, once the type of data to manipulate is
// determined
void printAllStudents(const StudentBody *StudentBod){
	if(StudentBod.studentCount == 0){
		std::cout << "You have no students..." << std::endl;
	}
	else{
		std::cout << "Listing all enrolled students and their enrollment status: " << std::endl;
		for(int i = 0; i < StudentBod.studentCount; i++){
			StudentBod.StudentList[i].displayEnrollment();
			std::cout << "-------------------------------------" << std::endl;
		}
	}

}

void MasterControl(StudentBody *StudentBod){
	bool loop = true;
	while(loop){
		int input;
		std::cout << "What would you like to do?: " << std::endl;
		std::cout << "1 Enter a new student?" << std::endl;
		std::cout << "2 Remove a student?" << std::endl;
		std::cout << "3 Print all enrolled students?" << std::endl;
		std::cout << "4 End/Close program" <<std::endl;
		std::cout << "Please enter the number for the entry you desire now: " << std::endl;
		std::cin >> input;
		switch (input){
			case 1:{
				addNewStudent(StudentBod);
				loop = true;
				break;
			}
			case 2:{
				removeStudent(StudentBod);
				loop = true;
				break;
			}
			case 3:{
				printAllStudents(StudentBod);
				loop = true;
				break;
			}
			case 4:{
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

void addStudentClasses(StudentBody *StudentBod, const int &student){
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
