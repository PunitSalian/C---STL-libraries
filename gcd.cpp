#include <iostream>

using namespace  std;
int GCD(int x, int y)
{

	if (x == y)
		return x;

	if (x > y)
		GCD(x - y, y);
	else
		GCD(x, y - x);

	

}

int main()
{
	cout<<GCD(18, 20);

	return(0);
}