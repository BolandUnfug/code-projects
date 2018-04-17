#include <iostream>
#include<fstream>
using namespace std;

int main()
{
	unsigned long long num1 = 0;
	unsigned long long num2 = 1;
	unsigned long long num3 = 0;
	int n = 0;
	

	fstream infile;
	fstream outfile;
	infile.open("Prob04.in.txt");
	outfile.open("Prob04.out.txt");



	infile >> n;

	for (int i = 1; i <= n; ++i) {
		
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
		outfile << i << " = " << num3 << endl;

	}
	outfile << endl;
	num1 = 0;
	num2 = 1;
	num3 = 0;
	system("pause");
}
