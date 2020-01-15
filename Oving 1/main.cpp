/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: oyvind
 *
 * Created on January 9, 2019, 12:21 PM
 */

#include <cstdlib>
#include <iostream>
#include "../include/std_lib_facilities.h"

using namespace std;

int MaxOfTwo(int a, int b){
    if (a > b) {
        cout << "A is greater than B\n";
        return a;
    }
    cout << "B is greater than A\n";
    return b;
}

int Fibonacci(int n){
    int a = 0, b = 1;
    cout << "Fibonacci numbers: \n";
    int temp;
    for (int i = 1; i < n; i++){
        cout << i << " " << b << "\n";
        temp = b;
        b += a;
        a = temp;
    }
    cout << "----\n";
    return b;
}

int SquareNumSum(int n){
    int totalSum;
    int square;
    for (int i = 0; i < n; i++){
        square = pow(i,2);
        totalSum += square;
        cout << square << "\n";
    }
    cout << totalSum << "\n";
    return totalSum;
}

void TriangleNumBelow(int n){
    int acc = 1, num = 2;
    cout << "Triangle numbers below " << n << ": \n";
    while (acc < n){
        cout << acc << "\n";
        acc += num;
        num++;
    }
}

bool IsPrime(int n){
    for (int i = 2; i < n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

void NaivePrimeNumSearch(int n){
    for (int i = 2; i < n; i++){
        if (IsPrime(i))
            cout << i << " is a prime!\n";
    }
}

int FindGreatestDivisor(int n){
    for (int d = n - 1; d > 0; d--){
        if (n % d == 0)
            return d;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "\nTask 2a: \n" << MaxOfTwo(5,6) << "\n";
    cout << "\nTask 2c: \n" << Fibonacci(10) << "\n";
    cout << "\nTask 2d: \n" << SquareNumSum(10) << "\n";
    cout << "\nTask 2e: \n" << "\n";
    TriangleNumBelow(100);
    cout << "\nTask 2f: \n" << IsPrime(17) << "\n";
    cout << "\nTask 2g: \n" << "\n";
    NaivePrimeNumSearch(100);
    cout << "\nTask 2h: \n" << FindGreatestDivisor(294) << "\n";
    return 0;
}







