/*
 * Part1.cpp
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#include <iostream>
#include <string>
#include "part1.h"

void createArray(float *&ptrFloatArray, int &size){
	std::cout << "Please enter the size of the array: ";
	std::cin >> size;
	std::cout << std::endl;
	ptrFloatArray = new float[size];
	bool repeat = true;
	std::cout << "Please enter the data separated by a space: " << std::endl;
	while(repeat){
		for(int i = 0; i < size; i++){
			std::cin >> ptrFloatArray[i];
		}
		std::cout << std::endl << "This is what I recorded: " << std::endl;
		for(int i = 0; i < size; i++){
			std::cout << ptrFloatArray[i] << " ";
		}
		std::string str;
		std::cout << std::endl << "Is this correct (Y/n): ";
		std::cin >> str;
		if((str == "N") || (str == "n") || (str == "No") || (str == "no" || (str == "NO"))){
			repeat = true;
			std::cout << "OK, please enter the correct " << size << " data points: ";
		}
		else{
			repeat = false;
		}
	}
}

void arrayAverage(const float *ptrArray, const int &arraySize, float &average){
	float sum = 0;
	for(int i = 0; i < arraySize; i++){
		sum += ptrArray[i];
	}
	average = sum / arraySize;
}

void numAboveAverage(const float *ptrArray, const int &arraySize, const float &average, int &num){
	num = 0;
	for(int i = 0; i < arraySize; i++){
		if(ptrArray[i] > average){
			num++;
		}
	}
}

void part1(void){
	int size = 0;
	float *ptrFloatArray = nullptr;
	createArray(ptrFloatArray, size);

	/*
	for(int i = 0; i < size; i++){
		std::cout << ptrFloatArray[i] << std::endl;
	}
	*/

	float average;
	arrayAverage(ptrFloatArray, size, average);
	std::cout << "The average value was: ";
	std::cout << average << std::endl;

	int num;
	numAboveAverage(ptrFloatArray, size, average, num);
	std::cout << "Computing how many grades are above average" << std::endl;
	std::cout << "There are: " << num << " above average entries" << std::endl;

}
