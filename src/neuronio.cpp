#include "../include/neuronio.h"
#include "../include/functions.h"
#include "../include/prints.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>
#include <ctime>

Neuron::Neuron()	{}
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

	file << "Inicio: " << time(NULL) << "\n\n";
	// Qualquer mudanca aqui afeta o Neuron::load_from_file()
	file << "Neuronio " << identifier << ":..\n\n"; 
	file << "Tipo: " << tipo << "..\n";
	file << "Charge(): " << charge_id << "..\n";
	file << "Action(): " << action_id << "..\n";
	file << "Threshold: " << threshold << "..\n";
	file << "Connections: " << conexoes.size() << "..\n\n"  << printConnections(conexoes) << "\n";

	file.close();
}

std::vector<connection_to_make> Neuron::load_from_file(const char * arquivo)	{
	std::ifstream file;
	file.open(arquivo);

	std::vector<connection_to_make> ret;
	
	char curline[1024];
	double temp_k[K_STR];
	connection_to_make temp_ctm;
	char tempsto[128];
	int nline = 0;
	
	// file okay e n atingiu EOF
	while(file.good())	{
		file.getline(curline,sizeof(curline));
		nline++;

		if(nline == 3)	{
			text_between(curline,"Neuronio ",":..",tempsto);
			strcpy(identifier,tempsto);
		}else if(nline==5)	{
			text_between(curline,"Tipo: ","..",tempsto);
			tipo = (tipo_neuronio) strtol(tempsto,NULL,10);
		}else if(nline==6)	{
			text_between(curline,"Charge(): ","..",tempsto);
			charge_id = strtol(tempsto,NULL,10);
		}else if(nline==7)	{
			text_between(curline,"Action(): ","..",tempsto);
			action_id = strtol(tempsto,NULL,10);
		}else if(nline==8)	{
			text_between(curline,"Threshold: ","..",tempsto);
			threshold = atof(tempsto);
		}else if(nline==9)	{
			text_between(curline,"Connections: ","..",tempsto);
			int i = strtol(tempsto,NULL,10);
			file.getline(curline,sizeof(curline)); /* pula uma linha */
			nline++;
			for(;i>0;i--)	{
				file.getline(curline,sizeof(curline));
				text_between(curline,"identifier: ","..",tempsto);
				strcpy(temp_ctm.identifier,tempsto);

				int offset = 0;
				file.getline(curline,sizeof(curline));

				for(int j=0;j<K_STR;j++)	{
					offset = text_between(curline," "," ",tempsto,offset);
					temp_ctm.k_strength[j] = atof(tempsto);
				}
				ret.push_back(temp_ctm);
			}
		}
	}
	return ret;
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

void Neuron::set_charge()	{
	int a = MAX_QT_POWER;
	while(a--)
		vcharge[a] = pow(charge, a);
}
