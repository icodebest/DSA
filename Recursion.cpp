/*Recursion
The algorithmic steps for implementing recursion in a function are as follows:

Step1 - Define a base case: Identify the simplest case for which the solution is known or trivial. 
This is the stopping condition for the recursion, as it prevents the function from infinitely 
calling itself.

Step2 - Define a recursive case: Define the problem in terms of smaller subproblems. 
Break the problem down into smaller versions of itself, and call the function recursively to 
solve each subproblem.

Step3 - Ensure the recursion terminates: Make sure that the recursive function eventually reaches 
the base case, and does not enter an infinite loop.

step4 - Combine the solutions: Combine the solutions of the subproblems to solve the original 
problem.*/
#include <iostream>
using namespace std;

void Message(int times){
	if (times > 0){
		cout << "This is a recursive function.\n";
		Message(times - 1);
	}
	return;
} 


int main(){
	int times=3;
	Message(times);
}
