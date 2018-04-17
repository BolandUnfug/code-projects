#include<iostream>
#include<fstream>

using namespace std;


int main() {
	fstream myfile("bubble.txt");
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	
	myfile >> num1;
	myfile >> num2;
	myfile >> num3;
	myfile >> num4;
	myfile >> num5;

	




	cout << num1 << '\n';
	cout << num2 << '\n';
	cout << num3 << '\n';
	cout << num4 << '\n';
	cout << num5 << '\n';
}