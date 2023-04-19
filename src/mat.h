#ifndef MAT_H 
#define MAT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>

void GenerateDiferentFiles(int *Quantitiofmatrix,FILE **file,char **Matrix,int *Order);
void StartFillingMatrix(int *Order,char **Matrix);
void WriteMatrixFile(int *counter_matrix,int *Order,char **Matrix,int **vet,int *Couter_auxiliar,int *Alocate_auxiliar);
void GetSize(int *Order, int *QuantitiofMatrix,FILE **file);
void Walking(signed short int StartRow, signed short int SartColunm,int *stop, signed short int *lives,signed short int *sum,int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger,int *Counter_Houses,int *sumOfItems,char **Matrix);
void PrintMatrix(int *Order,char **Matrix);
void TheChoose(signed short int *Colunm,signed short int *Row,int *Order,bool parameter);
void ClearArrey(signed char *name);
void FillingMatrix(char **Matrix,signed short int *sum, int *Order,int *Counter_matrix, int *QuantitofMatrix);
void PrintPosition(int *Order,int *QuantitiofMatrix);

#endif