#ifndef MAT_H 
#define MAT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include <unistd.h>

void AlocateMatrix(int *Order,char ***Matrix);//this function allocate the size of matrix 
void Alocatevet(int *Alocate_Counter,int *Counter_auxiliar,int **vet_aux,int **vet);//this function makes the procedure of increasing the size of the vet, when the index amount ends
void Readvet(int *Counter_matrix_change,int *QuantitofMatrix,int *Counter_matrix,int *Alocate_Counter, int **vet,int *Counter_auxiliar);//this function makes te read a array that be in a file
void Writevet(int *Counter_matrix,int *Alocate_Counter, int **vet,int *Counter_auxiliar);//this function save the positions coleted in the walking oh Jack
void GenerateDiferentFiles(int *Quantitiofmatrix,FILE **file,char **Matrix,int *Order);//this function to divide the input.data in diferent files for operate one matrix at a time
void StartFillingMatrix(int *Order,char **Matrix);//this function filling in the matrix of the program in the first time
void WriteMatrixFile(int *counter_matrix,int *Order,char **Matrix,int **vet,int *Couter_auxiliar,int *Alocate_auxiliar);//this function save the matrix operated in this program
void GetSize(int *Order, int *QuantitiofMatrix,FILE **file);//this function received the size of the all matrix and received the quantity of matrix that the input file have
void Walking(signed short int StartRow, signed short int SartColunm,int *stop, signed short int *lives,signed short int *sum,int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger,int *Counter_Houses,int *sumOfItems,char **Matrix);//this function have the walking logic in your body
void TheChoose(signed short int *Colunm,signed short int *Row,int *Order,bool parameter);//this function choose the number of random way
void ClearArrey(signed char *name);
void FillingMatrix(char **Matrix, int *Order,int *Counter_matrix, int *QuantitofMatrix);//this function change the matrix of be in the program in the moment that he is execute 
void PrintPosition(int *Order,int *QuantitiofMatrix);//this function show for user in the finish of procedurer that execute in the past

#endif