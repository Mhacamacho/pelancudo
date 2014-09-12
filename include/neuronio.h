#ifndef _NEURONIO
#define _NEURONIO

#define MAX_QT_POWER 25

class neuronio;
enum tipo_neuronio	{
	SENSITIVO, MOTOR, CONECTOR
};

struct connection	{
	double k_strength[MAX_QT_POWER];
	neuronio * c_neuronio;
};

class neuronio	{
	private:
		double charge[MAX_QT_POWER];
		float threshold;

	public:
		std::vector <connection> conexoes;
		tipo_neuronio tipo;
		void discharge();
		void discharging();
		// makeconnection(neuronio&, neuronio&) ou
		// neuronio.makeconnection(neuronio&)
		void makeconnection(neuronio*,float);
		
};

void neuronio::makeconnection(neuronio *  b, float strength) {	
	connection temp;
	temp.strength = strength;
	temp.c_neuronio = b;
	conexoes.push_back(temp);
}
#endif /* _NEURONIO */
