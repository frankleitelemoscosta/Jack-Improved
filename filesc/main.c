#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	Matrix m;
	int *counter = 0;
	int *counter_matrix = 0;
	int *Order;
	int *QuantitiofMatrix;

		counter = (int *)malloc(1*sizeof(int));

		counter_matrix = (int *)malloc(1*sizeof(int));

		Order = (int*)malloc(1*sizeof(int));

	SetMatrixSignature();
	for(int i=0; i<NUMAT; i++)
		SaveMatrix(&m,counter);

	for (int i = 0; i < 2; i++)
	{
		FillingintheMatrix(&m,counter_matrix,Order,QuantitiofMatrix);
	}
	
	free(Order);
	free(counter);
	free(counter_matrix);

	return 0;
}
