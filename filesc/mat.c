#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"
#include<math.h>
#include<string.h>
#include<time.h>

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

void PrintMatrix(int *Order,Matrix *mat)
{
	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			printf(" [%c]",mat->Matrix[i][j].val);
		}
		printf("\n");
	}
}

void FillingintheMatrix(Matrix *mat,int *counter_matrix,int *Order,int *QuantitiofMatrix)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name[20] = "dataset/data";
		char value;
	//finished the variables


	*counter_matrix = *counter_matrix + 1;

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
		GetSize(Order,QuantitiofMatrix,&file);
	}
	

	//filling the matrix
	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			fscanf(file,"%s",&mat->Matrix[i][j].val);
		}
	}
	//finished filling in the matrix

	PrintMatrix(Order,mat);

	fclose(file);

}

void TheChoose(signed short int *Colunm,signed short int *Row)
{
	srand(time(0));
	signed short int escolha_linha;
	signed short int escolha_coluna ;
	signed short int choose_Colunm;
	signed short int choose_Row;

	escolha_coluna = rand()%2;

	escolha_linha = rand()%2;

	choose_Colunm = rand()%2;

	choose_Row = rand()%2;

	if(choose_Colunm == 1)
	{
		escolha_coluna *= (-1);
	}

	if(choose_Row == 1)
	{
		escolha_linha *= (-1);
	}
	
	*Colunm = escolha_coluna + *Colunm;

	sleep(1);

	*Row = escolha_linha + *Row;

	if(*Colunm < 1)
	{
		*Colunm += 1;
	}

	if(*Row < 1)
	{
		*Row += 1;
	}


	printf("Row:(%d)\n",*Row);
	printf("Colunm:(%d)\n",*Colunm);


}

void Walking(Matrix *m,signed short int StartRow, signed short int StartColunm,int *stop, signed short int *lives)
{

	signed short int Row;
	signed short int Colunm;
	signed short int Counter = 0;
	int Order = 7;

	Colunm = StartColunm;
	Row = StartRow;

	while(*stop != 1){
		TheChoose(&Colunm,&Row);

		while(*stop != 1)
		{
			if(m->Matrix[Row][Colunm].val != '#')
			{
				*stop = 1;
			}
			else{
				Colunm = StartColunm;
				Row = StartRow;
				TheChoose(&Colunm,&Row);
			}

		}
		*stop = 0;
		
		if(m->Matrix[Row][Colunm].val == '*')
		{
			*lives -= 1;
		}
		else if(m->Matrix[Row][Colunm].val > 0){
			Counter++;
			m->Matrix[Row][Colunm].val -= 1;
		}

		if(Counter == 4)
		{
			*lives += 1;
			Counter = 0;
		}
		PrintMatrix(&Order,m);

		getchar();
	}

}

//fim do código







