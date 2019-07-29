#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include "Header1.h"

const int row = 16;
const int col = 8;



void UIFunction::InvalidInput()
{
	cout << "Enter a valid input" << endl;
}

void UIFunction::Urban()
{
	cout << "For a hospital in an Urban area, we suggest the Intellivue range of monitors" << endl;
	cout << "Based on which of these factors you want to filter the monitors" << endl;
primary:
	cout << "Based on:\nA.Portability\nB.Screen Size\nC.Go Back" << endl;
	char input;
	FuncImplementation obj;
	cin >> input;		
	switch (input)
	{
	case 'A':obj.IntellivueBOPortability(row, col, Values);
		break;
	case 'B':obj.IntellivueBOScreenSize(row, col, Values);
		break;
	case 'C':ICU();
		break;
	default:InvalidInput();
		goto primary;
		break;
	}
}

void UIFunction::SemiUrban()
{
	cout << "For a hospital in a Semi-Urban area, we suggest the Efficia range of monitors" << endl;
	cout << "Based on which of these factors you want to filter the monitors" << endl;
primary:
	cout << "Based on:\nA.Touch Screen\nB.Screen Size\nC.Go Back" << endl;
	char input;
	cin >> input;
	FuncImplementation obj;
	switch (input)
	{
	case 'A':obj.EfficiaBOTouchScreen(row, col, Values);
		break;
	case 'B':obj.EfficiaBOScreenSize(row, col, Values);
		break;
	case 'C':ICU();
		break;
	default:InvalidInput();
		goto primary;
	}
}

void UIFunction::ICU()
{
	cout << "We suggest different monitors based on the location of the hospital\n";
primary:cout << "Is the hospital located in an Urban or a Semi Urban area?" << endl;
	cout << "A.Urban\nB.Semi-Urban\nC.Go Back" << endl;
	char UrbanvsSemi;
	cin >> UrbanvsSemi;
	if (UrbanvsSemi == 'A')
	{
		Urban();
	}
	else if (UrbanvsSemi == 'B')
	{
		SemiUrban();
	}
	else if (UrbanvsSemi == 'C')
	{
		icuvslabour();
	}
	else
	{
		InvalidInput();
		goto primary;
	}
}

void UIFunction::labourcare()
{
	cout << "We suggest Avalon monitors for labour care" << endl;
primary:
	cout << "On what factor do you want to filter the monitors?" << endl;
	cout << "A.Care Stage\nB.Weight\nC.Go Back" << endl;
	char CareStageVSWeight;
	cin >> CareStageVSWeight;	
	FuncImplementation obj;
	switch (CareStageVSWeight)
	{
	case 'A':obj.AvalonBOCareStage(row, col, Values);
		break;
	case 'B':obj.AvalonBOWeight(row, col, Values);
		break;
	case 'C':icuvslabour();
		break;
	default:		
		InvalidInput();
		goto primary;
	}
}

void UIFunction::icuvslabour()
{
	cout << "Are you looking for a monitor that is to be used in an ICU or in a labour care ward?" << endl;
primary:
	cout << "A.ICU\nB.Labour care\nC.Exit" << endl;
	char ICUVSLabour;
	cin >> ICUVSLabour;	
	switch (ICUVSLabour)
	{
	case 'A':ICU();
		break;
	case 'B':labourcare();
		break;
	case 'C':
		cout << "Thanks, Have a good day!!" << endl;
		exit(1);
	default:
		InvalidInput();		
		goto primary;
	}	
	goto primary;
}

void UIFunction::greeting()
{
	cout << "Hi" << endl;
	cout << "Hope you are having a good day" << endl;
	cout << "I am here to help you" << endl;
}
