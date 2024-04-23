#include <iostream>
using namespace std;

int main()
{   
 int n1, n2;
 char op;
 
 //Taking values
  cout <<"Enter first number : ";
	cin>>n1;
	
  cout <<"Enter operation : ";
	cin>>op;
	
  cout <<"Enter second number : ";
	cin>>n2;
	

  	//Using switch for operations
	switch(op){
	
	case '+':
	cout<<"Your answer is : "<<n1 + n2<< endl;
	break;
	
	case '-':
	cout<<"Your answer is : "<<n1 - n2<< endl;
	break;
	
	case '*':
	cout<<"Your answer is : "<<n1 * n2<< endl;
	break;
	
	case '/':
	cout<<"Your answer is : "<<n1 / n2<< endl;
	break;
	
	default:
		cout<<"Your answer is : "<<"Invalid Operator";
		
		return 0;
 }
}

