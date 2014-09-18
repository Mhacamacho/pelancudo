#include "../include/neuronio.h"
#include "../include/functions.h"
#include <cstdlib>
#include <cstring>

int main()	{
	srand(712395);
	int num = 1;
	double temp_k[11];
	char str[3];
	Neuron * teste[11];
	for(int i=0;i<11;++i)	{
		itoa(num++,str);
		char name[20] = "teste_00000000";
		teste[i] = new Neuron(strcat(name,str),CONECTOR,rand()%100);
	}
	for(int i=0;i<11;++i)	{
		for(int j=i;j<11;++j)	{
			for(int k=0;k<11;++k)
				temp_k[k] = (double) (rand()%100);
			teste[i]->make_connection(*(teste[j]), temp_k);
		}
	}
	for(int i=0;i<11;++i)	{
		teste[i]->output_to_file("luis");
	}
}
