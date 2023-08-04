#pragma once

#ifndef HEADER_H
#define HEADER_H
double CubicEquation(double a, double b, double c, double d, double x);
double poh1(double a, double b, double c, double x);
double poh2(double a, double b, double x);
double ChordeMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
double DychotomyMethod(double a, double b, double c, double d, double l, double r, double eps, int* count);
int checker(double a, double b, double c, double d, double l, double r);
#endif