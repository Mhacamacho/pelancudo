#include "../include/error.h"
#include "../include/functions.h"
#include "../include/neuronio.h"
#include <vector>
#include <cmath>
#include <cstdio>

#ifdef WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

// Eh bom testar todas essas funcoes antes de usar...

void QTvector(double QT, std::vector<double> &QTreturn)	{
	int a = MAX_QT_POWER;
	while(a--)
		QTreturn[a] = pow(QT, a);
}

int text_between
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
					return 1;
				}
			}
			do	{
				destination[ndest++] = source[cur++];
			}
			while(match-- > 0);
		}
	}
	if(searching) return 0;
	return 1;
}

int RGB_to_int(char R, char G, char B)	{
	return (int)( (R << 16) | (G << 8) | B);
}

void make_dir(const char * name)	{
	#ifdef WIN32
	mkdir(name);
	#else
	umask(000);
	mkdir(name,0777);
	#endif
}

char * itoa(int a, char * dest)	{
	// feio, mas faz o servico
	sprintf(dest,"%d",a);
	return dest;
}
