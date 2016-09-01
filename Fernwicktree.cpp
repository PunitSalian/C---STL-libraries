#include "iostream"
#include "array"
#include "vector"

#define ARRAY_SIZE 12
using namespace std;



int getsumsearch(int index, array<int, ARRAY_SIZE>& tempfrentree)
{
	int sum = 0;
	index = index + 1;
	while (index > 0)
	{
		sum += tempfrentree[index];
		index -= index & -index;//go towards parent
	}
	return sum;
}

void updatetree(array<int, ARRAY_SIZE>& tempfrentree, int index, int ele)
{

	index = index + 1;
	while (index < tempfrentree.size())
	{
		tempfrentree[index] += ele;
		index += index & -index;//go to the next node
	}

}
void constructfentree(array<int, ARRAY_SIZE>& tempdata, array<int, ARRAY_SIZE>& tempfrentree)
{


	for (unsigned int i = 0; i < tempdata.size(); i++)
	{
		updatetree(tempfrentree, i, tempdata[i]);
	}
	
}


void main()
{
	array<int, ARRAY_SIZE> frentree;
	frentree.fill(0);

	array<int, ARRAY_SIZE> data = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };
	constructfentree(data, frentree);
	cout << "Sum of elements in arr[0..5] is " << getsumsearch(5, frentree) << endl;
	data[3] += 6;
	updatetree(frentree, 3, 6);
	cout << "Sum of elements after update in arr[0..5] is " << getsumsearch(5, frentree)<<endl;

}