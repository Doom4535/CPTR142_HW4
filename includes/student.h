/*
 * part3.h
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class Student{
	private:
		static int IDpool;
		int ID = 0;	//! Defaulting to '0', if this value occurs the sensor has had some initialization issues
		std::string Lname;
		std::string Fname;
		int numClasses = 0; // Number of enrolled classes
		std::string *ClassList = nullptr;

	public:
		Student(std::string Last_name, std::string First_name);
		void setName(std::string Last_name, std::string First_name);
		std::string getName(void);
		int getNumClasses(void);
		// something to list more about courses
		void addClass(std::string className);
		void dropClass(std::string className);
		void displayEnrollment(void);
		void resetClasses(void);
		// Overload assignment operator
		Student& operator=(const Student& rtSide);
		~Student();


};

int Student::IDpool = 1; // Starting ID value for the 1st sensor should be '1'


#endif /* STUDENT_H_ */
