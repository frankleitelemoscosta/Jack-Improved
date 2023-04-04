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

void SaveMatrix(Matrix *mat,int *contador){
	
	
	signed char letter[5];
	int valor;
	signed char name[20] = "dataset/data";

	*contador = *contador + 1;

	valor = *contador;

	sprintf(letter,"%d",valor);

	strcat(name,letter);
	strcat(name,".data");

	printf(" [%s]\n",name);


	FILE *f = fopen(name,"a");
		if (f==NULL){
		printf("file could not be opened");
    	exit(-1);
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

/*void FillingintheVector(Matrix *mat, int *contador, int *Row,int *QuantitiofMatrix,int *vet)
{
	FILE *file;
	int *element;

	element = (int *)malloc(1*sizeof(int));

	file = fopen("dataset/data.data","r");
	if(file == NULL){
		printf("file is not open\n");
		return; 
	}

	//alocate the space for the variable row
		Row = (int*)malloc(1*sizeof(int));
	//finished

	QuantitiofMatrix = (int*)malloc(1*sizeof(int));

	//read the quantiti of row
		fscanf(file,"%d",Row);
	//finished

	//read the quantiti of matrix
		for(int i = 1 ; i < 3 ; i++)
		{
			fscanf(file,"%d",QuantitiofMatrix);
		}
	//finished

	//filling the matrix
		for(int i = 0 ; i < *Row ; i ++)
		{
			for(int j = 0 ; j < *Row ; j ++)
			{
				fscanf(file,"%d",*element);
				mat->Matrix[i][j].val = *element;
			}
		}
	//finished

	//filling the matrix
		for(int i = 0 ; i < *Row ; i ++)
		{
			for(int j = 0 ; j < *Row ; j ++)
			{
				printf("[%d]",mat->Matrix[i][j].val);
			}
			printf("\n");
		}
	//finished


}*/

//fim do código







