#include <iostream>
using namespace std;

int searchList(int list[], int numElems, int value)
{
	int index = 0; // Used as a subscript to search array
	int position = -1; // To record position of search value
	bool found = false; // Flag to indicate if the value was found
	while (index < numElems && !found)
	{
		if (list[index] == value)
		{ 
			found = true;
			position = index;
		}
		index++;
	}
	return position;
}

int main(){
	const int arrSize = 5;
	int tests[arrSize] = {87, 75, 98, 100, 82};
	int find=82;
	int result=searchList(tests,arrSize,find);
	if (result == -1){
		cout << "You did not earn 100 points on any test\n";
	}
	else{
		cout << "You earned 100 points on test ";
		cout << (result + 1) << endl;
	}
	
}

