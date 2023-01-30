// PruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

#define N 1000
#define CHUNK 500
#define SHOW 100

void printArray(float* d);

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "Adding arrays in parallel\n";
    float firstArray[N], secondArray[N], resultArray[N];
    int idx;

    for (idx = 0; idx < N; idx++) {
        firstArray[idx] = idx + 13;
        secondArray[idx] = (idx * 2) * 3;
    }

    int chunk = CHUNK;

#pragma omp parallel for \
    shared(firstArray, secondArray, resultArray, chunk) private(idx) \
    schedule(static, chunk)

    for (idx = 0; idx < N; idx++) {
        resultArray[idx] = firstArray[idx] + secondArray[idx];
    }

    std::cout << "Printing the first " << SHOW << " values of the first array: " << std::endl;
    printArray(firstArray);
    std::cout << "Printing the first " << SHOW << " values of the second array: " << std::endl;
    printArray(secondArray);
    std::cout << "Printing the first " << SHOW << " values of the result array: " << std::endl;
    printArray(resultArray);
}

void printArray(float* d) {

    for (int idx = 0; idx < SHOW; idx++) {
        std::cout << d[idx] << " - ";
    }
    std::cout << std::endl;
}