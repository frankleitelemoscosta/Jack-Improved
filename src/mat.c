#include "./mat.h"

void AlocateMatrix(int *Order,char ***Matrix)
{
	*Matrix = (char**)malloc(*Order * sizeof(char*));//declarate the matrix, and alocate rows

	//allocate colluns
		for (int i = 0; i < *Order; i++) 
		{
			(*Matrix)[i] = (char*)malloc(*Order * sizeof(char));
		}
}

void Alocatevet(int *Alocate_Counter,int *Counter_auxiliar,int **vet_aux,int **vet){

	if(*Alocate_Counter == *Counter_auxiliar){
			//init alloc the vector auxiliar
			*vet_aux = (int*)malloc(*Alocate_Counter * sizeof(int));

			//pass information
			for(int i = 0 ; i < *Alocate_Counter ; i++ )
			{
				(*vet_aux)[i] = (*vet)[i];
			}


			//free memory
			*vet = (int*)realloc(*vet, 0);

			*Alocate_Counter = *Counter_auxiliar + 1;

			//realoc
			*vet = (int*)malloc(*Alocate_Counter * sizeof(int));

			//pass information
			for(int i = 0 ; i < *Alocate_Counter ; i++ )
			{
				(*vet)[i] = (*vet_aux)[i]; 
			}

			*vet_aux = (int*)realloc(*vet_aux, 0);
	}

}	

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
			ClearArrey(name);

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

void ClearArrey(signed char *name){

 for (int i = 0; name[i] != '\0'; i++) {
        name[i] = '\0';
    }

}

void StartFillingMatrix(int *Order,char **Matrix)
{
	FILE *file;

	//open file
		file = fopen("Diferentinputs/input1.data","r");
		if(file == NULL){
			printf("file is not open\n");
			return; 
		}
	//finished

	//filling the matrix
		for (int i = 0; i < *Order; i++)
		{
			for (int j = 0; j < *Order; j++)
			{
				fscanf(file,"%s",&Matrix[i][j]);
			}
		}
	//finished filling in the matrix
}

void PrintPosition(int *Order,int *QuantitiofMatrix)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name_vector[30] = "Diferentvectors/output";
		signed int Counter = 1;
		int *vet;
		int tamanho;
		int lixo;
		int tamanho_vet = pow(*Order,2);
		int vet_check[tamanho_vet];
		int index;
		int Counter_Walking = 0;
		int QuantitiHouses = 0;
	//end local variables

	//for filling vet for check
		for(int i = 0; i < tamanho_vet; i++)
		{
			vet_check[i] = 0;
		}	


	while(Counter <= *QuantitiofMatrix)
	{

		sprintf(letter,"%d",Counter);
		strcat(name_vector,letter);
		strcat(name_vector,".data");

		file = fopen(name_vector,"r");
		if(file == NULL)
		{
			printf("file is not open\n");
			return;
		}

		//read the file with a array
			fscanf(file,"%d",&tamanho);

			fscanf(file,"%d",&lixo);

			vet = (int*)malloc(tamanho * sizeof(int));

			for (int i = 0; i < tamanho; i++)
			{
				fscanf(file,"%d",&vet[i]);
			}
		//finished

		printf("\n");

		for(int i = 0; i < tamanho; i++)
		{
			index = vet[i];

			if(vet_check[index] == 0)
			{
				vet_check[index] = index;
				Counter_Walking += 1;
			}

		}

		free(vet);

		//for clean the vet_chek
			for(int i = 0; i < tamanho_vet; i++)
			{
				vet_check[i] = 0;
			}
		//finished

		QuantitiHouses = tamanho_vet - Counter_Walking;

		printf("As CASAS que NÃO foram PASSADAS da matrix [%d] são: %d\n",Counter, QuantitiHouses);

		QuantitiHouses = 0;

		Counter_Walking = 0;
		

		Counter++;
		ClearArrey(name_vector);

		strcpy(name_vector,"Diferentvectors/output");
	}

}

void FillingMatrix(char **Matrix, int *Order,int *Counter_matrix, int *QuantitofMatrix)
{
	FILE *file;
	signed char letter[5];
	signed char name[30] = "Diferentinputs/input";

	(*Counter_matrix == *QuantitofMatrix)?(*Counter_matrix = 1):(*Counter_matrix = *Counter_matrix + 1);

	//for write new files for operate matrix
		sprintf(letter,"%d",*Counter_matrix);
		strcat(name,letter);
		strcat(name,".data");
	//finished

	//open file
	file = fopen(name,"r");
	if(file == NULL){
		printf("file is not open\n");
		return; 
	}
	//end open file

	//filling the matrix
		for (int i = 0; i < *Order; i++)
		{
			for (int j = 0; j < *Order; j++)
			{
				fscanf(file,"%s",&Matrix[i][j]);
			}
		}
	//finished filling in the matrix

	ClearArrey(name);

	strcpy(name,"Diferentinputs/input");

}

void WriteMatrixFile(int *counter_matrix,int *Order,char **Matrix,int **vet,int *Counter_auxiliar,int *Alocate_Counter)
{
	//local variables
		FILE *file;
		signed char letter[5];
		signed char name[30] = "Diferentinputs/input";
	//finished the variables

	//for record matrix after changed per program	
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
			//finished

			fclose(file);

			ClearArrey(name);

	//recorde finished
}

void TheChoose(signed short int *Colunm,signed short int *Row, int *Order,bool parameter)
{
	//local variables	
		short int number_Row;
		short int number_Colunm ;
		short int choose , stop = 0;
	//finished

	if(parameter == true)
	{
		number_Colunm = rand()%7;
		number_Row = rand()%7;	

		*Colunm = number_Colunm;
		*Row = number_Row;

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

	while(stop != 1)
	{
		if(number_Colunm == 0 && number_Row == 0){
			number_Row = 1;
		}
		else{
			stop = 1;
		}
	}

	stop = 0;

	*Colunm = number_Colunm + *Colunm;

	*Row = number_Row + *Row;

	}

	

	


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
	
}//end function

void Walking(signed short int StartRow, signed short int StartColunm,int *stop, signed short int *lives,signed short int *sum, int *Order,int *Counter_matrix, int *QuantitofMatrix,int *Counter_danger, int *Counter_Houses,int *sumOfItems,char **Matrix)
{
	//local variables 
		signed short int Row;
		signed short int Colunm;
		signed short int Current_Row;
		signed short int Current_Colunm;
		signed short int Counter = 0;
		int Alocate_Counter = 1;
		int Counter_auxiliar = 0;
		bool parameter;
		int *vet;
		int *vet_aux;
		FILE *file;
		signed char letter[5];
		signed char name_vector[30]="Diferentvectors/output";
		int variable_aux;
		int Counter_matrix_change = 0;
	//finished

	Colunm = StartColunm;
	Row = StartRow;
	*Counter_matrix = 1;

	//start filling in
		StartFillingMatrix(Order,Matrix);
	//finished start filling in

	vet = (int*)malloc(Alocate_Counter * sizeof(int));

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
						TheChoose(&Colunm,&Row,Order,false);
					}

				}
				//finished
			}else{

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
			}

			Alocatevet(&Alocate_Counter,&Counter_auxiliar,&vet_aux,&vet);


			//for reuse of the variable in here
				*stop = 0;

			//check for subtract lives or subtract value of the house
				if(Matrix[Row][Colunm] == '*')
				{
					vet[(Alocate_Counter - 1)] = ((Row * (*Order))+1) + (Colunm);
					Counter_auxiliar++;
					*lives -= 1;//for sobtract the lives
					*Counter_danger += 1;//for counter the dangers faced
					*Counter_Houses += 1;//for counter the houses that Jack it happened
				}
				else if(Matrix[Row][Colunm] != '0' && Matrix[Row][Colunm] != '*' && Matrix[Row][Colunm] != '#')
				{
					Counter++;//for counter subtration of elements of the houses
					vet[(Alocate_Counter - 1)] = ((Row * (*Order))+1) + (Colunm);
					Counter_auxiliar++;
					*Counter_Houses += 1;
					Matrix[Row][Colunm] -= 1;
					*sumOfItems += 1;				
				}
			//finished

			//for check if collected four items, if yes sum one live for jack		
				if(Counter == 4 && *lives < 10)
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
			if(Row == 0 || Row == (*Order - 1) || Colunm == 0 || Colunm == (*Order - 1) || (Row == 0 && Colunm == 0))
			{
				Counter_matrix_change += 1;

				WriteMatrixFile(Counter_matrix,Order,Matrix,&vet,&Counter_auxiliar,&Alocate_Counter);

				sprintf(letter,"%d",*Counter_matrix);
				strcat(name_vector,letter);
				strcat(name_vector,".data");

				file = fopen(name_vector,"w");
				if(file == NULL)
				{
					printf("file is not open,\n");
					return;
				}

				for (int i = 0 ; i < 1 ; i++)
				{
					fprintf(file,"%d\n",Counter_auxiliar);
					fprintf(file,"%d\n",Alocate_Counter);
				}

				//write array in the file
				for (int i = 0 ; i < Alocate_Counter ; i++)
				{
					fprintf(file,"%d\n",vet[i]);
				}
				//end write array

				fclose(file);

				vet = (int*)realloc(vet,0);//free memory

				ClearArrey(name_vector);//clear array for write again

				strcpy(name_vector,"Diferentvectors/output");

				FillingMatrix(Matrix,Order,Counter_matrix,QuantitofMatrix);

				//for write new files for operate matrix
						sprintf(letter,"%d",*Counter_matrix);
						strcat(name_vector,letter);
						strcat(name_vector,".data");
				//finished


					if(Counter_matrix_change > (*QuantitofMatrix - 1)){
						//open file
							file = fopen(name_vector,"r");
							if(file == NULL){
								printf("file is not open?\n");
								return; 
							}
						//end open file
						for (int i = 0 ; i < 1 ; i++)
						{
							fscanf(file,"%d",&Counter_auxiliar);
							fscanf(file,"%d",&Alocate_Counter);
						}
					
						vet = (int*)malloc(Alocate_Counter * sizeof(int));

						for (int i = 0 ; i < Counter_auxiliar ; i++)
						{
							fscanf(file,"%d",&variable_aux);
							vet[i] = variable_aux;
						}
					}else{
						Alocate_Counter = 1;
						Counter_auxiliar = 0;
						vet = (int*)malloc(Alocate_Counter * sizeof(int));
					}

				ClearArrey(name_vector);//clear array for write again

				strcpy(name_vector,"Diferentvectors/output");

				fclose(file);
				

				//checking if the decision predecessor maked the right
					while(*stop != 1)
					{
						if(Matrix[Row][Colunm] != '#')
						{
							*stop = 1;
						}
						else{
							TheChoose(&Colunm,&Row,Order,true);
						}

					}
				//finished
				//for reuse of the variable in here
					*stop = 0;
			}
		//finished

		*stop = 0;

		//for stop the loop, and close the program
			if(*lives < 1)
			{
				break;
			}
		}
	//end of looping
}

//end of code







