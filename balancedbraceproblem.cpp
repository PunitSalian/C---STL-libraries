
/*
 * commonancestor.cpp
 *
 *  Created on: May 17, 2016
 *      Author: punit
 */


#include<iostream>
#include<string>
#include<vector>
#include <stack>
using namespace std;

//arg to hold the input string
 string args[] = {"[(])", "[()]{}{[()()]()}","{}"}; //const char*
std::vector<string> inpstring(args, args+3); //get array size    sizeof(args)/sizeof(args[0])
vector<string> result;

/*

* Function name: check
* Description  : Takes the input string puts the character in stack to check whether parentheses is balanced or not
*
*
*

* Arguments    : string
* Return value : none


*/

void check(string str)
{
	stack<char> mystack;

	if((str.length()%2)==0)                           //if even enter this part else its unbalanced anyways
	{
		for (unsigned int i=0; i<str.length(); ++i)   // Traverse the given expression to check matching parenthesis
		{
			if(str[i]=='}'||str[i]==')'||str[i]==']') // If str[i] is a ending parenthesis then pop from stack and check if the popped parenthesis is a matching pair*/

			{

				char temp=mystack.top();
				if((str[i]=='}')&&(temp=='{'))
				{
					mystack.pop();
				}
				else if((str[i]==')')&&(temp=='('))
				{
					mystack.pop();
				}
				else if((str[i]==']')&&(temp=='['))
				{
					mystack.pop();
				}
				else
				{
					result.push_back("no");
					return;
				}
			}
			else
				mystack.push(str[i]);

		}


		result.push_back("yes");
	}
	else{
		result.push_back("no");
		return;
	}

}

/*

* Function name: brace
* Description  : Takes a vector of stings passes individual string to function check
*
*
*

* Arguments    : vector<string>
* Return value : none
*/

void brace(vector<string> myvector )
{

	string x;
	for (vector<string>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
	{
		x=*it;
		check(x);
	}


}

/*

* Function name: main
* Description  : displays the result
*
*
*

* Arguments    : none
* Return value : none
*/

int main() {

	brace(inpstring);
	for(vector<string>::iterator it=result.begin();it!=result.end();it++)
		cout<<*it<<endl;
	return 0;
}
