#ifndef MAT_H 
#define MAT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>

#define MAXCOLS 7
#define MAXROWS 7
#define NUMAT   3

typedef struct Item{
	char val;
}Item;

typedef struct Matrix{
	Item Matrix[MAXROWS][MAXCOLS];
}Matrix;

void GenerateMatrix(Matrix *mat);
void SetMatrixSignature();
void SaveMatrix(Matrix *mat, int *counter);
void FillingintheMatrix(Matrix *mat,int *counter_matrix,int *Order,int *QuantitiofMatrix,signed short int *sum);
void GetSize(int *Order, int *QuantitiofMatrix,FILE **file);
void Walking(Matrix *m,signed short int StartRow, signed short int SartColunm,int *stop, signed short int *lives,signed short int *sum,int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger,int *Counter_Houses,int *sumOfItems);
void PrintMatrix(int *Order, Matrix *mat);
void TheChoose(signed short int *Colunm,signed short int *Row,int *Order);
void ClearArrey(signed char name[20],signed char letter[20]);
void GenerateDiferentFiles(int *Counter);

#endif