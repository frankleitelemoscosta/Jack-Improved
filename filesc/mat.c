#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"
#include<math.h>
#include<string.h>

void GenerateMatrix(Matrix *mat){
	int data = 0;

	for(int i=0; i<MAXROWS; i++)
        for(int j=0; j<MAXCOLS; j++){
        	data = rand()%20;
        	if(data <= 10)
            	mat->Matrix[i][j].val = (1 + rand()%5) + '0'; 
            else if ((data > 10) && (data < 16))
            	mat->Matrix[i][j].val = '*';
            else
            	mat->Matrix[i][j].val = '#';
        }
}


void SetMatrixSignature(){
	FILE *f;

	if ((f = fopen("dataset/data1.data", "w")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    fprintf(f,"%d %d %d", MAXROWS, MAXCOLS, NUMAT); 
    fprintf(f,"\n");
    fclose(f);

}

void SaveMatrix(Matrix *mat,int *counter){
	
	//local variables
		signed char letter[5];
		signed char name[20] = "dataset/data";
	//finished the variables


	*counter = *counter + 1;

	sprintf(letter,"%d",*counter);

	strcat(name,letter);
	strcat(name,".data");

	printf(" [%s]\n",name);


	FILE *f = fopen(name,"a");
		if (f==NULL){
		printf("file could not be opened");
    	exit(-1);
		}

	if(*counter != 1)
	{
		f = fopen(name,"w");
		if (f==NULL){
		printf("file could not be opened");
    	exit(-1);
		}
	}
	

    GenerateMatrix(mat);

	for (int i=0;i<MAXROWS;i++){
        for (int j=0;j<MAXCOLS;j++)
             fprintf(f,"%c ", mat->Matrix[i][j].val); 
        fprintf(f,"\n");
	}
	fprintf(f,"\n");
	fclose(f);
}

void GetSize(int *Order, int *QuantitiofMatrix,FILE **file)
{

	//read the quantiti of row
		fscanf(*file,"%d",Order);
	//finished

	//read the quantiti of matrix
		for(int i = 1 ; i < 3 ; i++)
		{
			fscanf(*file,"%d",QuantitiofMatrix);
		}
	//finished
}

void FillingintheMatrix(Matrix *mat,int *counter_matrix,int *Order,int *QuantitiofMatrix)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name[20] = "dataset/data";
		int value;
	//finished the variables


	*counter_matrix = *counter_matrix + 1;
	printf("%d\n",*counter_matrix);

	sprintf(letter,"%d",*counter_matrix);


	strcat(name,letter);
	strcat(name,".data");

	file = fopen(name,"r");
	if(file == NULL){
		printf("file is not open\n");
		return; 
	}

	
	if(*counter_matrix == 1) 
	{
		//alocate the space for the variable order
		Order = (int*)malloc(1*sizeof(int));
		//finished

		QuantitiofMatrix = (int*)malloc(1*sizeof(int));
		GetSize(Order,QuantitiofMatrix,&file);
		printf("[%d]",*Order);
		printf("[%d]\n",*QuantitiofMatrix);
	}

	int cont = 0;

	printf("\n started ff \n");
	//filling the matrix
	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			fscanf(file,"%ls",&value);
			//printf("[%c]",value);
			//printf("(%d)\n",*Order);
			mat->Matrix[i][j].val = value;
			cont++;
			printf("\n linha: %d | col : %d",i, j);
		}
		printf("  -  %d ",i);
		printf("\n");
	}
	//finished filling in the matrix
	printf("\n\n - %d - \n\n",cont);
	printf("a partir daqui se printa a matriz\n");


	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			printf(" [%c]",mat->Matrix[i][j].val);
		}
		printf("\n");
	}
	printf("\n\n\n\n");

	fclose(file);

}

//fim do código







