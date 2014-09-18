#include "../include/neuronio.h"
#include "../include/functions.h"
#include "../include/prints.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

Neuron::Neuron(char * a, tipo_neuronio tipo, float threshold)	{
	strcpy(identifier,a);
	this->tipo = tipo;
	this->threshold = threshold;
}

Neuron::Neuron(const char* arquivo)	{
	load_from_file(arquivo);
}

Neuron::~Neuron()	{
	std::ofstream file;
	file.open(this->name,std::ofstream::out | std::ofstream::app);

	file << "Terminado em: " << time(NULL);

	file.close();
}

// Apaga essa funcao se ninguem usar
void Neuron::output_to_file(const char* path)	{
	output_to_file(identifier, path);
}
void Neuron::output_to_file(const char* identifier, const char* path)	{
	char name[256] = ""; 
	strcat(name,path);
	make_dir(path);
	std::cout << "Output";
	strcat(name,"/neuron_");
	strcat(name, identifier);
	strcpy(this->name,name);
	std::ofstream file;
	file.open(name,std::ofstream::out | std::ofstream::app);

	std::cout << name << std::endl;
	file << "Inicio: " << time(NULL) << "\n\n";

	file << "Neuronio " << identifier << ":..\n\n"; 
	file << "Tipo: " << tipo << "..\n";
	file << "Threshold: ";
	// file << "kVector:\n" << printVector(kVector) << "\n";
	file << "Connections: " << conexoes.size() << "..\n\n"  << printConnections(conexoes) << "..\n";

	file.close();
}

connection_to_make Neuron::load_from_file(const char * arquivo)	{
	std::ifstream file;
	file.open(arquivo);
	
	char curline[1024];
	char tempsto[128];
	int nline = 0;
	
	// file okay e n atingiu EOF
	while(file.good())	{
		file.getline(curline,sizeof(curline));
		nline++;
/*
		if(nline > 2)	{
			if(nline == 3)	{
				text_between(curline,"Neuronio ",":..",tempsto);
				strcpy(identifier,tempsto);
			}else if()	{
				text_between(curline,"Tipo: ","..",tempsto);
				tipo = atoi(tempsto);
			}
		}
*/
	}
}

void make_connection(Neuron& a, Neuron& b, const double* k)	{
	a.make_connection(b,k);
}
void Neuron::make_connection(Neuron& b, const double* k)	{
	connection temp;
	temp.c_neuronio = &b;
	for(int i=0;i<K_STR;++i)	{
		temp.k_strength[i] = k[i];
	}
	conexoes.push_back(temp);
}
