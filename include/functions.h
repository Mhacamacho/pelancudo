#include <vector>


template <typename N>
N dotproduct(const std::vector<N> &a, const std::vector<N> &b)	{
	if(a.size() != b.size())	{
//		throw error::size;
		return (N) 0;
	}
	N sum;
	for(int i=0, c = a.size(); i <= c; ++i)
		sum += a[i]*b[i];
	return sum;
}
void QTVector(double, std::vector<double>&);
void text_between(const char*,const char*, const char*, char*);
