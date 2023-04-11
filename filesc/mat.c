#include "../filesh/mat.h"
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

	if ((f = fopen("dataset/input.data", "w")) == NULL){
		printf("file could not be opened");
    	exit(-1);
    }

    fprintf(f,"%d %d %d", MAXROWS, MAXCOLS, NUMAT); 
    fprintf(f,"\n");
    fclose(f);

}

void GenerateDiferentFiles(int *Counter)
{
	//local variables
		signed char letter[5];
		signed char name[20] = "dataset/input";
	//finished the variables

	FILE *file;

	//for counter in what is the matrix that will to create
		*Counter = *Counter + 1;

	//for to bring toghter the  
		sprintf(letter,"%d",*Counter);
		strcat(name,letter);
		strcat(name,".data");
	//finished

	if(*Counter != 1)
	{
		file = fopen(name,"w");
		if (file==NULL){
		printf("file could not be opened");
    	exit(-1);
		}
	}
	fclose(file);

}

void SaveMatrix(Matrix *mat){

	FILE *f = fopen("dataset/input.data","a");
	
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

void ClearArrey(signed char name[20],signed char letter[20]){

 for (int i = 0; name[i] != '\0'; i++) {
        name[i] = '\0';
    }

	printf(" %s",name);

}

void FillingintheMatrix(Matrix *mat,int *counter_matrix,int *Order,int *QuantitiofMatrix,signed short int *sum)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name[20] = "dataset/data";
		char value;
		char intermed;
		int value2;
	//finished the variables


	if(*counter_matrix > 0)
	{
		sprintf(letter,"%d",*counter_matrix);

		strcat(name,letter);
		strcat(name,".data");
		file = fopen(name,"w");
		if(file == NULL){
			printf("file is not open\n");
			return; 
		}

		if(*counter_matrix == 1){
			fprintf(file,"%d %d %d", MAXROWS, MAXCOLS, NUMAT); 
    		fprintf(file,"\n");
		}

		for (int i=0;i<MAXROWS;i++){
        	for (int j=0;j<MAXCOLS;j++){
            	fprintf(file,"%c ", mat->Matrix[i][j].val); }
        	fprintf(file,"\n");
		}
		fprintf(file,"\n");

		fprintf(file,"%d",*sum);
		fprintf(file,"\n");
		fclose(file);
		ClearArrey(name,letter);
		strcpy(name,"dataset/data");
		*sum = 0;
	}

	
	

	(*counter_matrix == 3)?(*counter_matrix = 1):(*counter_matrix = *counter_matrix + 1);

	sprintf(letter,"%d",*counter_matrix);

	strcat(name,letter);
	strcat(name,".data");

	printf("%s\n",name);

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
			if(mat->Matrix[i][j].val != '*' && mat->Matrix[i][j].val != '#')
			{
				intermed = mat->Matrix[i][j].val;
				value2 = atoi(&intermed);
				*sum += value2;
				value2 = 0;
			}
		}
	}
	//finished filling in the matrix

	//PrintMatrix(Order,mat);

	fclose(file);

}

void TheChoose(signed short int *Colunm,signed short int *Row, int *Order)
{
	//local variables	
		signed short int escolha_linha;
		signed short int escolha_coluna ;
		signed short int choose_Colunm;
		signed short int choose_Row;
		signed short int stop = 0;
		unsigned int seed = time(NULL);
	//finished

	//seet semente
	srand((seed));

	escolha_coluna = rand()%2;

	//change the semente and reset
	seed++;
	srand((seed));

	escolha_linha = rand()%2;

	seed++;
	srand((seed));

	choose_Colunm = rand()%2;

	seed++;
	srand((seed));

	choose_Row = rand()%2;

	//for include in randon decision houses that are before the Jack	
		if(choose_Colunm == 1)
		{
			escolha_coluna *= (-1);
		}

		if(choose_Row == 1)
		{
			escolha_linha *= (-1);
		}
	//finished

	//check for force that Jack change your position
		if(escolha_coluna == 0)
		{
			while(stop != 1)
			{
				if(escolha_linha == 0)
					escolha_linha = rand()%2;
				else{
					stop = 1;
				}
			}
			stop = 0;
		}
	//finished
	
	*Colunm = escolha_coluna + *Colunm;

	*Row = escolha_linha + *Row;

	//for the colunm or row don´t have positions that unexist
		if(*Colunm < 0)
		{
			*Colunm += 1;
		}

		if(*Row < 0)
		{
			*Row += 1;
		}
	//finished

	//for force the colunm or row the don´t have value bigger that 6
		if(*Colunm > (*Order - 1))
		{
			*Colunm = 5;
		}

		if(*Row > (*Order-1))
		{
			*Row = 5;
		}
	//finished

	printf("Row:(%d)\n",*Row);
	printf("Colunm:(%d)\n",*Colunm);
	
	//end function
}

void Walking(Matrix *m,signed short int StartRow, signed short int StartColunm,int *stop, signed short int *lives,signed short int *sum, int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger, int *Counter_Houses,int *sumOfItems)
{
	//local variables 
		signed short int Row;
		signed short int Colunm;
		signed short int Counter = 0;
	//finished

	Colunm = StartColunm;
	Row = StartRow;

	//start looping for walking per matrix
		while(*stop != 1){
		//check for subtract lives or subtract value of the house
			if(m->Matrix[Row][Colunm].val == '*')
			{
				*lives -= 1;
				*Counter_danger += 1;
				*Counter_Houses += 1;
			}
			else if(m->Matrix[Row][Colunm].val > 0 && m->Matrix[Row][Colunm].val != '*' && m->Matrix[Row][Colunm].val != '#')
			{
				Counter++;
				*Counter_Houses += 1;
				m->Matrix[Row][Colunm].val -= 1;
				*sumOfItems += 1;
				*sum -= 1;
				printf("\nsoma de itens: [%d]\n",*sumOfItems);
				printf("\nContador das casas: [%d]\n",*Counter_Houses);
			}
		//finished

		//randon decision for change the position of Jack	
			TheChoose(&Colunm,&Row,Order);
		//finished

		//checking if the decision predecessor maked the right
			while(*stop != 1)
			{
				if(m->Matrix[Row][Colunm].val != '#')
				{
					*stop = 1;
				}
				else{
					Colunm = StartColunm;
					Row = StartRow;
					TheChoose(&Colunm,&Row,Order);
				}

			}
		//finished

		//for reuse of the variable in here
			*stop = 0;

		//for check if collected four items, if yes sum one live for jack		
			if(Counter == 4)
			{
				*lives += 1;
				Counter = 0;
			}
		//finished

			printf("Vidas: %d\n",*lives);

		//for stop the loop, and close the program
			if(*lives < 1 || *sum == 0)
			{
				*stop = 1;
			}

		//for changed the matrix that are in the program
			if(Row == 0 || Row == (*Order - 1) || Colunm == 0 ||
			Colunm == (*Order - 1))
			{
				FillingintheMatrix(m,Counter_matrix,Order,QuantitofMatrix,sum);
			}
		//finished

			getchar();
			getchar();
		}
	//end of looping

}

//end of code







