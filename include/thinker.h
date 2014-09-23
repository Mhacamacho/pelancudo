#ifndef THINKER
#define THINKER

#include "neuronio.h"
#include <vector>

class Thinker;
class Thinker	{
	std::vector<Neuron> neural_network;
	int (*fitness)(Thinker);


	public:
		int pontuacao;
		Thinker();
		Thinker(std::vector<Neuron>;
		int (*)(Thinker));
		Thinker(const char*);
		
		void output_to_file(const char*);
		void output_to_file(const char*, const char*);

		void load_from_file(const char*);
};

#endif
