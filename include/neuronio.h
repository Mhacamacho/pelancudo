#ifndef NEURONIO
#define NEURONIO

#include <vector>

#define MAX_QT_POWER 25
#define K_STRENGTH_SZ 10

class Neuron;
enum tipo_neuronio	{
	SENSITIVO, MOTOR, CONECTOR
};

struct connection	{
	double k_strength[K_STRENGTH_SZ];
	Neuron * c_neuronio;
};

class Neuron	{
	private:
		double charge[MAX_QT_POWER];
		float threshold;
		char name[256];

	public:
		std::vector<connection> conexoes;
		char identifier[16];
		tipo_neuronio tipo;

		Neuron(char * a, tipo_neuronio tipo, float threshold, int id);
		Neuron(const char*);
		~Neuron();
		
		void output_to_file(const char*);
		void output_to_file(const char*, const char*);
		void make_connection(const Neuron&);
};

void make_connection(Neuron&, const Neuron&);
/*
void neuronio::makeconnection(neuronio *  b, float strength) {	
	connection temp;
	temp.strength = strength;
	temp.c_neuronio = b;
	conexoes.push_back(temp);
}
*/
#endif /* NEURONIO */
