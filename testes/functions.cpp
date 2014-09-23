#include "../include/functions.h"
#include <iostream>
#include <vector>

int main()	{
	// Testando dotproduct
	std::vector<int> a, b;
	for(int i=0;i<=4;++i)	{
		a.push_back(i);
		b.push_back(2*i);
	}
	std::cout << dotproduct<int>(a,b);

	char teste[] = "1231203 123131 3850534 018204";
	char resultado[20];
	char * isso1 = " ";
	text_between(teste,isso1," ",resultado);
	std::cout << resultado;
}
