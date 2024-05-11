// Errol James Minguez
// BSCS - 1
// CMSC 28 (K) - Programming Exercise 05
// This is a program that asks the user to input various numbers (positive or negative) and perform basic statistics on these numbers. Find the largest, smallest, average, standard deviation, and variance of the numbers inputted.

#include <iostream>
using namespace std;

// Function Prototype
void description();
void displayResult(int max, int min, float ave, float sDev, float variance);
float sqrtNum(float num);
int findMax(int num[], int length); 
int findMin(int num[], int length);
float average(int num[], int length);
float sDev(int num[], int length, float ave);
float var(float sdev);

// Function Definitions
// Function to display the description of the program
void description() {
    system("cls");
    cout << "=====================================================" << endl;
    cout << "\t\tProgramming Exercise 05" << endl;
    cout << "\t   Submitted by: Errol James Minguez" << endl;
    cout << "=====================================================" << endl;
    cout << "\tThis program will ask the user to input \n various numbers (positive or negative but not zero) \n\t    and perform basic statistics \n\t\t   on these numbers" << endl;
    cout << "\t    DISCLAIMER! INPUT INTEGER ONLY!" << endl;
    cout << "=====================================================" << endl;
}

// Function to display the results
void displayResult(int max, int min, float ave, float sDev, float variance){
    cout << "=====================================================" << endl;
    cout << "Largest: \t\t" << max << endl;
    cout << "Smallest: \t\t" << min << endl;
    cout << "Average: \t\t" << ave << endl;
    cout << "Standard Deviation: \t" << sDev << endl;
    cout << "Variance: \t\t" << variance << endl;
    cout << "=====================================================" << endl;

}

// Babylonian method to find the square root of a number
float sqrtNum(float num) {
    float x = num;
    float y = 1;
    float e = 0.000001; // precision

    while (x - y > e) {
        x = (x + y) / 2;
        y = num / x;
    }

    return x;
}

// Find the largest number in the array
int findMax(int num[], int length) {
    int temp = num[0];
    for (int i = 0; i < length; i++) {
        if (num[i] > temp) {
            temp = num[i];
        }
        if (num[i] == 0) {
            break;
        }
    }
    return temp;
}

// find the smallest number in the array
int findMin(int num[], int length) {
    int temp = num[0];
    for (int i = 0; i < length; i++) {
        if (num[i] < temp) {
            temp = num[i];
        }
    }
    return temp;
}

// Find the average of the numbers in the array
float average(int num[], int length) {
    float temp;
    for (int i = 0; i < length; i++) {
        temp = temp + num[i];
    } 
    temp = temp / length;
    return temp;
}

// Find the standard deviation of the numbers in the array
float sDev(int num[], int length, float ave) {
    float total = num[0], temp, temp2, temp3, temp4, temp5;
    for (int i = 1; i < length; i++) {
        total = total + num[i];
    }
    
    for (int j = 0; j < length; j++) {
        temp = num[j] - ave;
        temp2 = temp * temp;
        temp3 = temp3 + temp2;
    } 

    temp4 = temp3 / (length -1);
    temp5 = sqrtNum(temp4);
    return temp5;
}
// Find the variance of the numbers in the array
float var(float sdev) {
    return sdev * sdev;
}

// Main function
int main () {
    int arrayNum[10], max, min, arrayLength;
    float ave, standardDev, vari;
    arrayLength = sizeof(arrayNum) / sizeof(arrayNum[0]); // get the length of the array
    description();
    for (int i = 0; i < 10; i++) { // loop to input the numbers
        cout << "Input an integer: "; 
        cin >> arrayNum[i];
        if (arrayNum[i] == 0) {
            arrayLength = i;
            break;
        }
    }
    max = findMax(arrayNum, arrayLength);
    min = findMin(arrayNum, arrayLength);
    ave = average(arrayNum, arrayLength);
    standardDev = sDev(arrayNum, arrayLength, ave);
    vari = var(standardDev);
    displayResult(max, min, ave, standardDev, vari); // display the results

    return 0;
}