#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

long long fab(int n);
int maxFromThreeNumber(int a, int b, int c);
int maxFromTwoNumber(int a, int b);
int minFromThreeNumber(int a, int b, int c);
int minFromTwoNumber(int a, int b);
int findRootOfSecondPoly(double a, double b, double c, double* x_pointer);
int sort(double* array, int arraySize,int direction);
void exchange(int* q1, int* q2, int* q3);
void swap(int* pt1, int* pt2);

typedef struct    //申明结构体类型
{
    int id;
    char name[20];
    int gender;
    int gradeID;
    int classID;
    int age;
}student;

struct studentNode      //申明结构体类型
{
    student oneStudent;
    struct studentNode* next;
    struct studentNode* previous;
};
