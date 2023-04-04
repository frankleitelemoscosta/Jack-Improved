#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	Matrix m;
	int *contador = 0;
	int *Row;
	int *QuantitiofMatrix;

	contador = (int *)malloc(1*sizeof(int));

	SetMatrixSignature();
	for(int i=0; i<NUMAT; i++)
		SaveMatrix(&m,contador);

	//FillingintheVector(&m,contador,Row,QuantitiofMatrix);

	return 0;
}
