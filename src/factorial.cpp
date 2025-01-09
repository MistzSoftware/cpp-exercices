/* Documentation Section
*/

// Linking section
#include <iostream>
using namespace std;

//Defining section
#define MAX_MONEY 200
typedef int MG_INT;

//Global declaration sections
MG_INT num = 0;
MG_INT fact = 1;
MG_INT storage = 0;

MG_INT factorial(MG_INT num)
{
	for(MG_INT i = 1; i <= num; i++)
	{
		fact *= i;
	}

	return fact;
}


MG_INT main()
{
    MG_INT num = 5;

    storage = factorial(num);

    cout << "Factorial of " << num << " is: " << storage << endl;
    return 0;
}