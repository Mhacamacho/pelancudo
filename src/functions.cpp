#include "../include/error.h"
#include "../include/functions.h"
#include <vector>
#include <cmath>

// Eh bom testar todas essas funcoes antes de usar...

void QTvector(double QT, std::vector<double> &QTreturn)	{
	int a = MAX_QT_POWER;
	while(a--)
		QTreturn[a] = pow(QT, a);
}

void text_between
(const char * source, const char * init, const char * end, char * destination)	{
	int cur = 0;
	int match = 0;
	int ndest = 0;
	bool searching = true;
	while(source[cur])	{
		if(searching)	{
			while(source[cur+match] == init[match])	{
				match++;
			}
			if(init[match] == '\0')	{
				cur += match;
				searching = false;
				continue;
			}
			cur += 1 + match;
			match = 0;
		}
		else	{
			match = 0;
			while(source[cur+match] == end[match])	{
				if(end[match++] == '\0')	{
					destination[ndest] = '\0';
					return;
				}
			}
			do	{
				destination[ndest++] = source[cur++];
			}
			while(match-- > 0);
		}
	}
}
