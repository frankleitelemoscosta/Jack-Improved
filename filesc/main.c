#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	Matrix m;
	int *counter = 0;
	int *counter_matrix = 0;
	int *Order;
	int *QuantitiofMatrix;
	int stop = 0;
	signed short int StartRow;
	signed short int StartColunm;

		counter = (int *)malloc(1*sizeof(int));

		counter_matrix = (int *)malloc(1*sizeof(int));

		Order = (int*)malloc(1*sizeof(int));

		QuantitiofMatrix = (int*)malloc(1*sizeof(int));

	SetMatrixSignature();
	for(int i=0; i<NUMAT; i++)
		SaveMatrix(&m,counter);

	while(stop != 1)
	{
		FillingintheMatrix(&m,counter_matrix,Order,QuantitiofMatrix);

		printf("What Row you wanna start?");
		scanf("%hd",&StartRow);

		printf("What Colunm you wanna start?");
		scanf("%hd",&StartColunm);

		Walking(m,StartRow,StartColunm);

	}
	
	free(Order);
	free(counter);
	free(counter_matrix);
	free(QuantitiofMatrix);

	return 0;
}
