#include "../include/thinker.h"

Thinker::Thinker()	{}
Thinker::Thinker(const char * path>	{
	output_to_file(path);
}

void Thinker::output_to_file(const char * path)	{
	output_to_file(identifier, path);
}

void Thinker::output_to_file(const char * identifier, const char * path)	{
	for(std::vector<Neuron>::iterator i = network.begin(); i != network.end(); ++i)	{
		i->output_to_file(identifier);
	}
}

