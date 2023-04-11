#ifndef MAT_H 
#define MAT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>

void GenerateDiferentFiles(int *Quantitiofmatrix,FILE **file,char **Matrix,int *Order);
void FillingintheMatrix(int *counter_matrix,int *Order,int *QuantitiofMatrix,signed short int *sum,char **Matrix);
void GetSize(int *Order, int *QuantitiofMatrix,FILE **file);
void Walking(signed short int StartRow, signed short int SartColunm,int *stop, signed short int *lives,signed short int *sum,int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger,int *Counter_Houses,int *sumOfItems,char **Matrix);
void PrintMatrix(int *Order,char **Matrix);
void TheChoose(signed short int *Colunm,signed short int *Row,int *Order);
void ClearArrey(signed char name[20],signed char letter[20]);
void StartFillingin();

#endif