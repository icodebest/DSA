#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int> > maxheap;
	maxheap.push(10);
	maxheap.push(20);
	maxheap.push(40);
	maxheap.push(34);
	
	cout<<"Top element of the max heap is : "<<maxheap.top()<<endl;
	
	maxheap.pop();
	
	cout<<"All element if the max heap are : ";
	while(!maxheap.empty()){
		cout<<maxheap.top()<<" ";
		maxheap.pop();
	}
	
	return 0;
}

