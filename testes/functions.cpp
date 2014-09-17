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

	char teste[] = "Um teste do text_between quero o que esta entre: __isso:: e maisa08912_isso__:'";
	char resultado[20];
	char * isso1 = "__isso::";
	text_between(teste,isso1,"_isso__:'",resultado);
	std::cout << resultado;
}
