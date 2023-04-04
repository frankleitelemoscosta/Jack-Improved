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
void SaveMatrix(Matrix *mat, int *contador);
void FillingintheVector(Matrix *mat,int *contador,int *Row,int *QuantitiofMatrix);

#endif