#include<stdio.h>

int main(int argucount, char** arguval){
	
	int c;
	FILE *entrada, *saida;
	

	//for(int i=0;i<argucount;i++){
	//	fprintf(stdout, "O argumento %i é %s \n", i, arguval[i]);
	//}

	if(argucount!=3){
	
		fprintf(stderr,"Erro na chamada do comando. \n");	
		fprintf(stderr, "Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO] \n", arguval[0]);
		
		return 1;
	}



	entrada=fopen(arguval[1],"r");
	if(!entrada){
		fprintf(stderr, "O arquivo %s não pôde ser aberto para leitura. \n", arguval[1]);
		return 1;
	}


	saida=fopen(arguval[2],"w");
	if(!saida){

		fprintf(stderr, "O arquivo %s não pôde ser aberto para escrita.", arguval[2]);
		return 1;
	}


	//Copia caractere por caractere do arquivo de entrada
	c=fgetc(entrada);

	while(c != EOF){
	
		//Enquanto arquivo não tiver sido completamente lido, a cópia vai sendo realizada para o arquivo de saída, byte a byte
		fputc(c,saida);

		//Arquivo é percorrido (próximo caractere)
		c=fgetc(entrada);

	}



	fclose(entrada);
	fclose(saida);
	return 0;
}
