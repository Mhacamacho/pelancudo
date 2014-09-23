#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include "../include/neuronio.h"

#define PFLOAT_PREC "%.3f"
#define BUFFERSIZE 8192

char buffer[BUFFERSIZE];

char * printConnections(std::vector<connection> &conexoes)	{
	memset(buffer,0,sizeof(buffer));
	int where = 0, temp = 0;
	for(std::vector<connection>::iterator i = conexoes.begin(); i != conexoes.end(); ++i)	{
		strcat(buffer,"identifier: ");
		where += 12;
		strcat(buffer,i->c_neuronio->identifier);
		where += strlen(i->c_neuronio->identifier);
		buffer[where++] = '.';
		buffer[where++] = '.';
		buffer[where++] = '\n';
		strcat(buffer,"k_strength:");
		where += 11;
		for(int j = 0; j < K_STR; j++)	{
			buffer[where++] = ' ';
			temp = sprintf(buffer + where,PFLOAT_PREC,i->k_strength[j]);
			where += temp;
			buffer[where++] = ' ';
		}
		buffer[where++] = '\n';
	}

	return buffer;
}

