#include "../filesh/mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	//local variables
		int *counter = 0;
		int *counter_matrix = 0;
		int *Order;
		int *QuantitiofMatrix;
		int stop = 0;
		int Counter_danger = 0;
		int Counter_Houses = 0;
		int sumOfItems = 0;
		signed short int StartRow;
		signed short int StartColunm;
		signed short int lives = 10;
		signed short int sum = 0;
		FILE  *file = fopen("dataset/input.data","r");
	//finished local variables
	
	//alocation pointers
		counter = (int *)malloc(1*sizeof(int));

		counter_matrix = (int *)malloc(1*sizeof(int));

		Order = (int*)malloc(1*sizeof(int));

		QuantitiofMatrix = (int*)malloc(1*sizeof(int));
	//finished alocation

		GetSize(Order,QuantitiofMatrix,&file);

		char **Matrix = (char**)malloc(*Order * sizeof(char*));//declarate the matrix, and alocate rows

		//allocate colunms
			for (int i = 0; i < *Order; i++) 
			{
				Matrix[i] = (char*)malloc(*Order * sizeof(char));
			}

		GenerateDiferentFiles(QuantitiofMatrix,&file,Matrix,Order);

		//start filling in
			FillingintheMatrix(counter_matrix,Order,QuantitiofMatrix,&sum,Matrix);
		//finished start filling in

		printf("(%d)\n",sum);

		printf("What Row you wanna start?");
		scanf("%hd",&StartRow);

		printf("What Colunm you wanna start?");
		scanf("%hd",&StartColunm);

		Walking(StartRow,StartColunm,&stop,&lives,&sum,Order,counter_matrix,QuantitiofMatrix,&Counter_danger,&Counter_Houses,&sumOfItems,Matrix);

		printf("The end!, you died\n");
	
	free(Order);
	free(counter);
	free(counter_matrix);
	free(QuantitiofMatrix);

	return 0;
}
