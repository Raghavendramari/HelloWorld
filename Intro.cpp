#include<iostream>
#include<fstream>
#include<string>
#include "Header2.h"
//#include "csvfile.cpp"

using namespace std;


	int main()
	{	
		bool filopen;
		UIFunction object;
		BusinessLayer obj;
		object.greeting();		
		filopen=obj.ReadCSVFile();		
		object.icuvslabour();
		getchar();
		getchar();
		
		return 0;
	}

