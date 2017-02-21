/*
 * part1.h
 *
 *  Created on: Feb 16, 2017
 *      Author: aaron
 */

#ifndef PART1_H_
#define PART1_H_

void createArray(float *&ptr, int &size);

void arrayAverage(const float *ptrArray, const int &arraySize, float &average);

void numAboveAverage(const float *ptrArray, const int &arraySize, const float &average, int &num);

void testArrayStuff(float *ptr, int &size);

void part1(void);


#endif /* PART1_H_ */
