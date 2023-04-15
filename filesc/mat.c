#include "../filesh/mat.h"
#include<math.h>
#include<string.h>
#include<time.h>


void GenerateDiferentFiles(int *Quantitiofmatrix,FILE **file,char **Matrix,int *Order)
{
	//local variables
		signed char letter[5];
		signed char name[30] = "Diferentinputs/input";
		int Counter = 1;
	//finished the variables


	while(Counter <= *Quantitiofmatrix)
	{
		//for to bring toghter the  
			sprintf(letter,"%d",Counter);
			strcat(name,letter);
			strcat(name,".data");
		//finished

		Counter ++;

		FILE *file_aux = fopen(name,"w");

		//for not subscribe data 
			ClearArrey(name,letter);

		strcpy(name,"Diferentinputs/input");

		if (file_aux == NULL)
		{
			printf("file could not be opened");
			exit(-1);
		}

		//filling matrix
			for (int i = 0; i < *Order; i++)
			{
				for (int j = 0; j < *Order; j++)
				{
					fscanf(*file,"%s",&Matrix[i][j]);
				}
			}
		//finished filling in

		//write new file
			for (int i = 0 ; i < *Order ; i++)
			{
				for (int j = 0 ; j < *Order ; j ++)
				{
					fprintf(file_aux,"%c ",Matrix[i][j]); 
				}
				fprintf(file_aux,"\n");
			}

		fclose(file_aux);
	}
	fclose(*file);

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

void PrintMatrix(int *Order,char **Matrix)
{
	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			printf(" [%c]",Matrix[i][j]);
		}
		printf("\n");
	}
}

void ClearArrey(signed char name[20],signed char letter[20]){

 for (int i = 0; name[i] != '\0'; i++) {
        name[i] = '\0';
    }

}

void FillingintheMatrix(int *counter_matrix,int *Order,int *QuantitiofMatrix,signed short int *sum,char **Matrix)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name[30] = "Diferentinputs/input";
		char intermed;
		int value2;
	//finished the variables

	//for record matrix after changed per program	
		if(*counter_matrix > 0)
		{
			//for write new files for operate matrix
				sprintf(letter,"%d",*counter_matrix);
				strcat(name,letter);
				strcat(name,".data");
			//finished

			file = fopen(name,"w");
			if(file == NULL){
				printf("file is not open\n");
				return; 
			}

			//write in the file that in now they are open
				for (int i = 0 ; i < *Order ; i++){
					for (int j = 0 ; j < *Order ; j ++)
					{
						fprintf(file,"%c ",Matrix[i][j]); 
					}
					fprintf(file,"\n");
				}
				fprintf(file,"\n");
			//finished

				fclose(file);
			
			ClearArrey(name,letter);
			strcpy(name,"Diferentinputs/input");

			*sum = 0;
		}
	//recorde finished
	
	

	(*counter_matrix == *QuantitiofMatrix)?(*counter_matrix = 1):(*counter_matrix = *counter_matrix + 1);

	//for write new files for operate matrix
		sprintf(letter,"%d",*counter_matrix);
		strcat(name,letter);
		strcat(name,".data");
	//finished

	printf("Matrix atual: [%d]\n",*counter_matrix);

	file = fopen(name,"r");
	if(file == NULL){
		printf("file is not open\n");
		return; 
	}
	

	//filling the matrix
	for (int i = 0; i < *Order; i++)
	{
		for (int j = 0; j < *Order; j++)
		{
			fscanf(file,"%s",&Matrix[i][j]);
			if(Matrix[i][j] != '*' || Matrix[i][j] != '#')
			{
				intermed = Matrix[i][j];
				value2 = atoi(&intermed);
				intermed = '\0';
				*sum += value2;
				value2 = 0;
			}
		}
	}
	//finished filling in the matrix

	//PrintMatrix(Order,mat);

	fclose(file);

}

void TheChoose(signed short int *Colunm,signed short int *Row, int *Order,bool parameter)
{
	//local variables	
		short int number_Row;
		short int number_Colunm ;
		short int choose;
	//finished

	if(parameter == true)
	{
		number_Colunm = rand()%7;
		number_Row = rand()%7;	
	}else
	{
		//seet semente
		srand(time(0));
		
		choose = rand()%20;

			if(choose > 5 && choose < 12)
			{
				number_Colunm = 1;
			}
			else if(choose > 0 && choose < 6)
			{
				number_Colunm = -1;
			}
			else{
				number_Colunm = 0; 
			}

		choose = rand()%20;

			if(choose > 5 && choose < 12)
			{
				number_Row = 1;
			}
			else if(choose > 0 && choose < 6)
			{
				number_Row = -1;
			}
			else{
				number_Row = 0; 
			}

	}

	*Colunm = number_Colunm + *Colunm;

	*Row = number_Row + *Row;

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
	
	//end function
}

void Walking(signed short int StartRow, signed short int StartColunm,int *stop, signed short int *lives,signed short int *sum, int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger, int *Counter_Houses,int *sumOfItems,char **Matrix)
{
	//local variables 
		signed short int Row;
		signed short int Colunm;
		signed short int Current_Row;
		signed short int Current_Colunm;
		signed short int Counter = 0;
		bool parameter;
	//finished

	Colunm = StartColunm;
	Row = StartRow;
	

	//start looping for walking per matrix
		while(*stop != 1){
			if(*Counter_Houses == 0){
				//checking if the decision predecessor maked the right
				while(*stop != 1)
				{
					if(Matrix[Row][Colunm] != '#')
					{
						*stop = 1;
					}
					else{
						printf("Teve de ser redecidido, então teremos mais de um print\n");
						TheChoose(&Colunm,&Row,Order,false);
					}

				}
			//finished
			}
		Current_Colunm = Colunm;
		Current_Row = Row;

		//for reuse of the variable in here
			*stop = 0;

		//check for subtract lives or subtract value of the house
			if(Matrix[Row][Colunm] == '*')
			{
				*lives -= 1;//for sobtract the lives
				*Counter_danger += 1;//for counter the dangers faced
				*Counter_Houses += 1;//for counter the houses that Jack it happened
			}
			else if(Matrix[Row][Colunm] != '0' && Matrix[Row][Colunm] != '*' && Matrix[Row][Colunm] != '#')
			{
				Counter++;//for counter subtration of elements of the houses
				*Counter_Houses += 1;
				Matrix[Row][Colunm] -= 1;
				*sumOfItems += 1;
			}
		//finished

		printf("\nVidas: %d\n",*lives);

		printf("Current Row:(%d)\n",Row);
		printf("Current Colunm:(%d)\n",Colunm);

		printf("\nsoma de itens: [%d]\n",*sumOfItems);
		printf("\nContador das casas: [%d]\n",*Counter_Houses);

		Current_Colunm = Colunm;
		Current_Row = Row;

		while(*stop != 1)
		{
			TheChoose(&Colunm,&Row,Order,false);
			if(Matrix[Row][Colunm] != '#')
					{
						*stop = 1;
					}
					else{
						Row = Current_Row;
						Colunm = Current_Colunm;
					}
		}

		*stop = 0;

		//for check if collected four items, if yes sum one live for jack		
			if(Counter == 4)
			{
				*lives += 1;
				Counter = 0;
			}
		//finished

		//for stop the loop, and close the program
			if(*lives < 1)
			{
				break;
			}

		//for changed the matrix that are in the program
			if(Row == 0 || Row == (*Order - 1) || Colunm == 0 ||
			Colunm == (*Order - 1))
			{
				FillingintheMatrix(Counter_matrix,Order,QuantitofMatrix,sum,Matrix);
				//checking if the decision predecessor maked the right
					while(*stop != 1)
					{
						if(Matrix[Row][Colunm] != '#')
						{
							*stop = 1;
						}
						else{
							printf("Teve de ser redecidido, então teremos mais de um print, porem repare que foi no segundo print sendo assim significa que o problema esta na matrix que acobou de ser recuperada\n");
							TheChoose(&Colunm,&Row,Order,true);
						}

					}
				//finished
				//for reuse of the variable in here
					*stop = 0;
			}
		//finished

		//for stop the loop, and close the program
			if(*lives < 1)
			{
				*stop = 1;
			}

			getchar();
			getchar();
		}
	//end of looping

}

//end of code







