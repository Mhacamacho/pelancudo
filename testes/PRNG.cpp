#include <iostream>
#include <cstdlib>
#include <ctime>

int main()	{
	srand(time(NULL));
	int i, j, matches, k;
	int days[366];
	for(i=2;i<=365;++i)	{
		matches = 0;
		for(j=0;j<1000000;++j)	{
			for(k=0;k<366;++k)
				days[k] = 0;
			for(k=0;k<i;++k)
				days[rand()%365]++;
			for(k=0;k<366;k++)	{
				if(days[k] >= 2)	{
					matches++;
					break;
				}
			}
		}
		using namespace std;
		cout << "Pessoas: " << i << endl;
		cout << "Probabilidade: " << (double) matches/1000000 << endl << endl;
	}
}
