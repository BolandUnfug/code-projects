#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

int main() {
	srand(time(NULL));
	vector<string> bodyPart;
	vector<string> color;
	vector<string>::iterator bodyiter;
	vector<string>::iterator coloriter;
	string bodyinput;
	string colorinput;
	fstream bodyfile;
	fstream colorfile;
	bodyfile.open("body.txt");
	colorfile.open("color.txt");

	//load in colors and parts from file into vector
	while (!bodyfile.eof()) {
		getline(bodyfile, bodyinput);
		bodyPart.push_back(bodyinput);

	}
	while (!colorfile.eof()) {
		getline(colorfile, colorinput);
		color.push_back(colorinput);

	}

	//user gets to add a part/color into the vector too
	cout << " Type a body part. " << endl;
	getline(cin, bodyinput);
	bodyPart.push_back(bodyinput);

	cout << "Type a color." << endl;
	getline(cin, colorinput);
	color.push_back(colorinput);

	ofstream bfile;
	ofstream cfile;
	bfile.open("body.txt");
	cfile.open("color.txt");

	//write the contents of the vector back to the text file
	for (coloriter = color.begin(); coloriter != color.end(); coloriter++) {
		cfile << *coloriter << endl;
		if (coloriter == color.end()) {

		}
	}
	for (bodyiter = bodyPart.begin(); bodyiter != bodyPart.end(); bodyiter++) {
		bfile << *bodyiter << endl;
	}
	bfile.close;
	cfile.close;

	int randbody = rand() % bodyPart.size();
	int randcolor = rand() % color.size();

	cout << "the teacher says touch the color " << color.at(randcolor) << " with your " << bodyPart.at(randbody) << "!" << endl;
	system("pause");

}
