#include "../include/neuronio.h"
#include "../include/prints.h"
#include <iostream>
#include <fstream>
#include <cstring>

Neuron::Neuron(Neuron& neuronio)	{
	this->makeneuron(neuronio);
}

Neuron::Neuron(const char* arquivo)	{
	std::ifstream file;
	file.open(arquivo);
	
	// file okay e n atingiu EOF
	while(file.good())	{
		// criar um neuronio temp a partir disso
		// e chamar Neuron;:Neuron makeneuron
	}
}

Neuron::~Neuron()	{

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

	file << "Neurionio " << identifier << ":\n\n"; 
	file << "Tipo: " << tipo << "\n";
	file << "Threshold: ";
	// file << "kVector:\n" << printVector(kVector) << "\n";
	file << "Connections: " << conexoes.size() << "\n\n"  << printConnections(conexoes) << "\n";

	file.close();
}
