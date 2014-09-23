#include "../include/neuronio.h"
#include "../include/functions.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

int main()	{
	srand(712395);
	int num = 1;
	double temp_k[11];
	char str[10] = {0};
	Neuron * teste[11];
	for(int i=0;i<11;++i)	{
		itoa(num++,str);
		char name[20] = {0};
		memset(name,0,sizeof(name));
		strcat(name,"teste_0000000");
		strcat(name,str);
		teste[i] = new Neuron(name,CONECTOR,rand()%100);
	}
	for(int i=0;i<11;++i)	{
		for(int j=i;j<11;++j)	{
			for(int k=0;k<11;++k)
				temp_k[k] = (double) (rand()%100);
			teste[i]->make_connection(*(teste[j]), temp_k);
		}
	}
	for(int i=0;i<1;++i)	{
		teste[i]->output_to_file("luis");
	}
	Neuron * repeat = new Neuron();
	std::vector<connection_to_make> t = repeat->load_from_file("luis/neuron_teste_00000001");
	for(std::vector<connection_to_make>::iterator a = t.begin(); a != t.end(); ++a)	{
		for(int i=0;i<11;++i)	{
			if(strcmp(teste[i]->identifier, a->identifier) == 0)	{
				repeat->make_connection(*(teste[i]), a->k_strength);
			}
		}
	}
	repeat->output_to_file("l2");
}
