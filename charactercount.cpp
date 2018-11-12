//Character Count

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char D[10][10];
	int l[10];
	int n;
	cout << "\nEnter the number of frames:  ";				//getting the number of frames from user
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cout << "\nEnter the frame" <<  i+1 << "(only 0/1's): ";
		cin >> D[i];
		l[i] = strlen(D[i]);                                            //calculating the string length
	}
	cout << "Data code sent is :  ";
	for(int i=0; i<n;i++)
	{
		cout << l[i] << D[i];
	}
	cout << endl;

return(0);

}


