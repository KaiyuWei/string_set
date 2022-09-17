//
// Created by kaiyu.wei on 22/10/2020.
//
#include <vector>

#ifndef UNTITLED8_FUNCTIONS_H
#define UNTITLED8_FUNCTIONS_H

#endif //UNTITLED8_FUNCTIONS_H
double add(std::vector<double> data);

double add(std::vector<double> data) {
    double summation = 0;
    for (double& i : data){
        summation += i;
    }
    return summation;
}

double average(double summation, int size);
double average(double summation, int size){
    double average;
    average = summation / size;
}

double  stdev(std::vector<double> data, double mean, int size);
double  stdev(std::vector<double> data, double mean, int size) {
    double stdev = 0;
    for (double& i: data){
        stdev = stdev + (i-mean) * (i-mean);
    }
    stdev = stdev/size;
    return stdev;
}
