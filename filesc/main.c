#include "mat.h"

int main(){
	srand( (unsigned)time(NULL) );

	Matrix m;

	SetMatrixSignature();
	for(int i=0; i<NUMAT; i++)
		SaveMatrix(&m);
	
	return 0;
}
