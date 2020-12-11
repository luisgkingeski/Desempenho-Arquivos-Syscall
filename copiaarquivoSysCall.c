#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdio.h>
double converteBytes(int tam){
double t;
	switch(tam){	
		case 1:t = 1;break;
		case 2:t = 1024; break;
		case 3:t = 1024 * 1024; break;
		case 4:t = 1024 * 1024 * 1024; break;
		case 5:t = (double)( 1024 * 1024 * 1024 ) * 5; break;
		default: t = tam; break; 
	}
	return t;
}

void menu(){
	printf("Digite a quantidade de bytes para seu arquivo:\n");
	printf("[1] 1B\n");
	printf("[2] 1KB\n");
	printf("[3] 1MB\n");
	printf("[4] 1GB\n");
	printf("[5] 5GB\n");
	printf("[] Definida pelo usuario\n");
}
double tamArquivo(){
	double tam;
	menu();
	scanf("%lf",&tam);	
	return tam;
}
void escreverArquivo(double tam){
	int i=0,out;
    struct timeval tempo1, tempo2;
    struct timezone tzp;
    double tempo;
	int nread;
	out = open("file.out", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);
	while(i<tam){
		write(out,"X",1);
		i++;
	}
	gettimeofday(&tempo2,&tzp);
        tempo = (double)(tempo2.tv_sec - tempo1.tv_sec) + (((double)(tempo2.tv_usec - tempo1.tv_usec))/1000000);
	printf("\nTempo decorrido: %f\n",tempo);
}

int main()
{	double tamanhoArquivo;
	tamanhoArquivo = tamArquivo();
	escreverArquivo(converteBytes(tamanhoArquivo));
	return(0);
}




