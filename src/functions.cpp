#include "../include/error.h"
#include <vector>
#include <cmath>

template <typename N>
N dotproduct(const std::vector<N> &a, const std::vector<N> &b)	{
	if(a.size() != b.size())	{
		throw error::size;
		return;
	}
	N sum;
	for(int i=0, c = a.size(); i < c; ++i)
		sum += a[i]*b[i];
	return sum;
}

void QTvector(const double QT, std::vector<double> &QTreturn)	{
	int a = MAX_QT_POWER;
	while(a--)
		// Ahhh, casts....
		QTreturn[a] = pow(QT, a);
}

