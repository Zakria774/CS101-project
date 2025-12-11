#include<iostream>

using namespace std;

int main()
{
	int num1 ,num2 ,operation ;
	float result ;
	cout<<"Enter a number"<<endl;
	cin>>num1;
	
	cout<<"Enter another number"<<endl;
	cin>>num2;
	
	cout<<"ADVANCED CALCULTOR"<<endl;
	cout<<"1. ADDITION(+)"<<endl;
	cout<<"2. SUBTRACTIO(-)"<<endl;
	cout<<"3. MULTIPLICATION(*)"<<endl;
	cout<<"4. DIVISION(/)"<<endl;
	cout<<"5. MODULUS(%)"<<endl;
	
	cout<<"Enter an operation"<<endl;
	cin>>operation;
	
	switch (operation)
	{
		case 1:
		cout<<"ADDITION"<<endl;
		result=num1+num2;
		cout<<result<<endl;
		break ;
		
		
		case 2:
		cout<<"SUBTRACTION"<<endl;
		result=num1-num2;
		cout<<result<<endl;
		break ;
		
		
		case 3:
		cout<<"MULTIPLICATION"<<endl;
		result=num1*num2;
		cout<<result<<endl;
		break ;
		
		
		case 4:
		cout<<"DIVISION"<<endl;
		if(num2==0){
			cout<<"undefined";
		}else{
		result=num1/num2;
			cout<<result<<endl;
		}
		break ;
		
		
		case 5:
		cout<<"MODULUS"<<endl;
		if(num2==0){
			cout<<"undefined";
		}else{
			result=num1%num2;
			cout<<result<<endl;
		}
		break ;
		
		
		default:
			cout<<"Invalid Number";
		
	
	
	
		
	}
	
	return 0;
}
