#ifndef NEURONIO
#define NEURONIO

#include <vector>

#define MAX_QT_POWER 25
#define K_STR 10

class Neuron;
enum tipo_neuronio	{
	SENSITIVO, MOTOR, CONECTOR
};

struct connection	{
	double k_strength[K_STR];
	Neuron * c_neuronio;
};

struct connection_to_make	{
	double k_strength[K_STR];
	char identifier[16];
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

		Neuron();
		Neuron(char * a, tipo_neuronio tipo, float threshold);
		Neuron(const char*);
		~Neuron();
		
		void output_to_file(const char*);
		void output_to_file(const char*, const char*);
		connection_to_make load_from_file(const char * arquivo);

		void make_connection(Neuron&, const double *);
};

void make_connection(Neuron&, Neuron&);
#endif /* NEURONIO */
