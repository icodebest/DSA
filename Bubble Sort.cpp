#include <iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size if array : ";
	cin>>n;
	float arr[n];
	cout<<"Enter the element of array : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	float counter=1;
	while(counter<n){
		for(int i=0;i<n-counter;i++){
			if(arr[i]>arr[i+1]){
				float temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
		counter++;
	}
	cout<<"Sorted array : \n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
		cout<<endl;
}
