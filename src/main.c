#include "./mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	//local variables
		int *counter = 0;
		int *counter_matrix = 0;
		int Order;
		int *QuantitiofMatrix;
		int stop = 0;
		int Counter_danger = 0;
		int Counter_Houses = 0;
		int sumOfItems = 0;
		signed short int StartRow;
		signed short int StartColunm;
		signed short int lives = 10;
		signed short int sum = 0;
		char **Matrix; 
		FILE  *file = fopen("dataset/input.data","r");
	//finished local variables
	
	//alocation pointers
		counter = (int *)malloc(1*sizeof(int));

		counter_matrix = (int *)malloc(1*sizeof(int));

		QuantitiofMatrix = (int*)malloc(1*sizeof(int));
	//finished alocation

	GetSize(&Order,QuantitiofMatrix,&file);

	AlocateMatrix(&Order,&Matrix);

	GenerateDiferentFiles(QuantitiofMatrix,&file,Matrix,&Order);

	printf("What Row you wanna start?");
	scanf("%hd",&StartRow);

	printf("What Colunm you wanna start?");
	scanf("%hd",&StartColunm);

	Walking(StartRow,StartColunm,&stop,&lives,&sum,&Order,counter_matrix,QuantitiofMatrix,&Counter_danger,&Counter_Houses,&sumOfItems,Matrix);

	printf("The end!, you died\n");

	printf("Quantas CASAS foram PERCORRIDAS ao todo?: %d\n",Counter_Houses);
	printf("Quantos PERIGOS foram ENFRENTADOS ao todo?: %d\n",Counter_danger);
	printf("Qual a Soma dos ELEMENTOS ao todo?: %d\n",sumOfItems);

	PrintPosition(&Order,QuantitiofMatrix);

	free(counter);
	free(counter_matrix);
	free(QuantitiofMatrix);
	free(Matrix);

	return 0;
}
