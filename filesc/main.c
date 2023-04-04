#include "/home/frank/Documentos/TODOS OS ARQUIVOS(ATIVIDADES, LIVROS, ETC)DA FACULDADE/TERCEIRO PERÍODO/AEDS/Actives/Active-Three-AEDS/Jack-Improved/filesh/mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	Matrix m;
	int *vet;
	int *contador;
	int *Row;
	int *QuantitiofMatrix;

	SetMatrixSignature();
	for(int i=0; i<NUMAT; i++)
		SaveMatrix(&m);
	
	FillingintheVector(&m,contador,Row,QuantitiofMatrix,vet);

	return 0;
}
