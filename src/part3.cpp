/*
 * part3.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include <iostream>
#include <string>
#include "part3.h"


void part3(void){
	std::cout << "Creating an empty student object" << std::endl;
	Student A;
	std::cout << "Printing the unfilled contents" << std::endl;
	A.studentPrint();
	std::cout << "Filling the contents" << std::endl;
	A.studentEnroll();
	std::cout << "Printing the filled contents" << std::endl;
	A.studentPrint();
	Student *studPTRA = nullptr;
	studPTRA = new Student;
	std::string input;
	std::string LastName;
	std::string FirstName;
	int size = 2;
	for(int i = 0; i < size; i++){
		std::cout << "Adding in another student, please enter their First name: ";
		std::cin >> FirstName;
		std::cout << "Adding in another student, please enter their Last name: ";
		std::cin >> LastName;
		studPTRA->setName(FirstName, LastName);
		studPTRA->studentEnroll();

	}
	Student B;
	B.setName("John", "Smith");
	B.studentEnroll();
	B.studentPrint();
	Student *studPTRB;
	std::cout << "Using overload" << std::endl;
	studPTRB->operator =(B);
	Student *studPTRC = new Student;
	*studPTRC = B;
	std::cout << "Using Deconstructor" << std::endl;
	studPTRC->~Student();

	// deleting stuff
	int *p = new int[5];
	delete [] p;
}
/*
void testroutine(void){
	std::string *pupil = new std::string;
	//for(int i = 0; i < 100; i++){
	for(int i = 0; i < 100; i++){
		std::string input;
		std::cin >> input;
		*pupil = input;
		pupil++;
	}

}
*/
