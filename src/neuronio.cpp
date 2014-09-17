#include "../include/neuronio.h"
#include "../include/functions.h"
#include "../include/prints.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

Neuron::Neuron(char * a, tipo_neuronio tipo, float threshold, int id)	{
	strcpy(identifier,a);
	this->tipo = tipo;
	this->threshold = threshold;
}

Neuron::Neuron(const char* arquivo)	{
	std::ifstream file;
	file.open(arquivo);
	
	char curline[1024];
	
	// file okay e n atingiu EOF
	while(file.good())	{
		file.getline(curline,sizeof(curline));
	}
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
	char name[256]; 
	strcat(name,path);
	strcat(name,"\\neuron_");
	strcat(name, identifier);
	std::ofstream file;
	file.open(name,std::ofstream::out | std::ofstream::app);

	file << "Inicio: " << time(NULL) << "\n\n";

	file << "Neuronio " << identifier << ":\n\n"; 
	file << "Tipo: " << tipo << "\n";
	file << "Threshold: ";
	// file << "kVector:\n" << printVector(kVector) << "\n";
	file << "Connections: " << conexoes.size() << "\n\n"  << printConnections(conexoes) << "\n";

	file.close();
}
void make_connection(Neuron& a, const Neuron& b)	{
	a.make_connection(b);
}
void Neuron::make_connection(const Neuron& b)	{
	// isso ta errado, outro parametro eh o strength, que eh std::vector
}
