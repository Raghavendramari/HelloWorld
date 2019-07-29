#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include "Header.h"

string Values[20][20];
string Values1[20][20];
int cnt = 0;

class BusinessLayer
{
public:
	float ConvertToFloat(string);

	bool ReadCSVFile();

	string processing(string s);


	void IntellivueBOScreenSize1(int row, int col, string Values[][20], int flag);
	void IntellivueBOScreenSize2(int row, int col, string Values[][20], int flag);

	void IntellivueBOPortability1(int row, int col, string Values[][20], int flag);
	void IntellivueBOPortability2(int row, int col, string Values[][20], int flag);

	void EfficiaBOScreenSize1(int row, int col, string Values[][20], int flag);
	void EfficiaBOScreenSize2(int row, int col, string Values[][20], int flag);

	void EfficiaBOTouchScreen1(int row, int col, string Values[][20], int flag);
	void EfficiaBOTouchScreen2(int row, int col, string Values[][20], int flag);

	void AvalonBOCareStage1(int row, int col, string Values[][20], int flag);
	void AvalonBOCareStage2(int row, int col, string Values[][20], int flag);

	void AvalonBOWeight1(int row, int col, string Values[][20], int flag);
	void AvalonBOWeight2(int row, int col, string Values[][20], int flag);
};


class FuncImplementation :Func
{
public:

	void IntellivueBOScreenSize(int row, int col, string Values[][20]);

	void IntellivueBOPortability(int row, int col, string Values[][20]);

	void EfficiaBOScreenSize(int row, int col, string Values[][20]);
	
	void EfficiaBOTouchScreen(int row, int col, string Values[][20]);

	void AvalonBOCareStage(int row, int col, string Values[][20]);

	void AvalonBOWeight(int row, int col, string Values[][20]);
	
};

class UIFunction
{
public:
	void InvalidInput();
	void Urban();
	void SemiUrban();
	void ICU();
	void labourcare();
	void icuvslabour();
	void greeting();	
};


bool BusinessLayer::ReadCSVFile()
{
	ifstream ip;
	ip.open("data.txt");
	if (ip.fail())
	{
		cout << "File Error" << endl;
			return false;
	}

	string Name;
	string Model;
	string SS;
	string Portability;
	string TouchScreen;
	string NoOfWaveForm;
	string Weight;
	string CareStage;

	while (!ip.eof())
	{
		for (int i = 1; i < 17; i++)
		{
			int j = 1;

			getline(ip, Name, ',');
			if (i == 1)
				Values[i][j] = Name;
			if (i > 1)
				Values[i][j] = processing(Name);
			getline(ip, Model, ',');
			Values[i][j + 1] = Model;
			getline(ip, SS, ',');
			Values[i][j + 2] = SS;

			getline(ip, Portability, ',');
			Values[i][j + 3] = Portability;
			getline(ip, TouchScreen, ',');
			Values[i][j + 4] = TouchScreen;
			getline(ip, NoOfWaveForm, ',');
			Values[i][j + 5] = NoOfWaveForm;
			int NoOfWF;
			std::istringstream iss(NoOfWaveForm);
			iss >> NoOfWF;
			getline(ip, Weight, ',');
			Values[i][j + 6] = Weight;
			getline(ip, CareStage, ',');
			Values[i][j + 7] = CareStage;


		}
	}
	return true;
}



float BusinessLayer::ConvertToFloat(string SS)
{
	float ScreenSize = std::stof(SS);
	return ScreenSize;

}

string BusinessLayer::processing(string s)
{
	s.erase(0, 1);
	return s;
}


void FuncImplementation::IntellivueBOScreenSize(int row, int col, string Values[][20])
{
	primary:
	cout << "Choose any one of these categories\nA.Small Screen\nB.Large Screen\nC.Go Back" << endl;
	char choice;
	cin >> choice;
	UIFunction obj;
	BusinessLayer object;
	switch (choice)
	{
	case 'A':object.IntellivueBOScreenSize1(row, col,Values,1);
		break;
	case 'B':object.IntellivueBOScreenSize2(row, col,Values,1);
		break;	
	case 'C':
		obj.Urban();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}		
}
void BusinessLayer::IntellivueBOScreenSize1(int row, int col, string Values[][20],int flag)
{	
	cout << endl << "Monitors with Screen Size < 10" << endl;
	cnt = 0;
	
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Intellivue" && ConvertToFloat(Values[i][3]) < 10)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;	
	if (flag == 1)
	{		
		IntellivueBOPortability1(cnt, col, Values1, 2);
		IntellivueBOPortability2(cnt2, col, Values1, 2);
	}
	if (flag == 2 && cnt == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}
}
void BusinessLayer::IntellivueBOScreenSize2(int row, int col, string Values[][20],int flag)
{
	cout << endl << "Monitors with Screen Size > 10" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Intellivue" && ConvertToFloat(Values[i][3]) > 10)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		IntellivueBOPortability1(cnt, col, Values1, 2);
		IntellivueBOPortability2(cnt2, col, Values1, 2);
	}
	if (flag == 2 && cnt == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}

}
void FuncImplementation::IntellivueBOPortability(int row, int col, string Values[][20])
{
primary:
	cout << "Choose any one of these categories\nA.Portable\nB.Non-Portable\nC.Go Back " << endl;
	char choice;
	cin >> choice;
		UIFunction obj;
		BusinessLayer object;
	switch (choice)
	{
	case 'A':object.IntellivueBOPortability1(row, col, Values, 1);
		break;
	case 'B':object.IntellivueBOPortability2(row, col, Values, 1);
		break;
	case 'C':obj.Urban();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}	
}

void BusinessLayer::IntellivueBOPortability1(int row, int col, string Values[][20], int flag)
{
	if (flag == 2 && row == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}
	cnt = 0;
	cout << endl << "Portable Monitors" << endl;
	for (int i = 1; i <= row; i++)
	{		
		if (Values[i][1] == "Intellivue" && Values[i][4] == "Yes")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)Values1[cnt][j] = Values[i][j];
			}

			cout << endl;
		}
	}	
	int cnt2 = cnt;
	if (flag == 1)
	{
		IntellivueBOScreenSize1(cnt, col, Values1, 2);
		IntellivueBOScreenSize2(cnt2, col, Values1, 2);
	}
	if (flag == 2 && cnt == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}


}

void BusinessLayer::IntellivueBOPortability2(int row, int col, string Values[][20], int flag)
{
	if (flag == 2 && row == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}
	cnt = 0;
	cout << endl << "Non-Portable Monitors" << endl;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Intellivue" && Values[i][4] == "No")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)Values1[cnt][j] = Values[i][j];
			}

			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		IntellivueBOScreenSize1(cnt, col, Values1, 2);
		IntellivueBOScreenSize2(cnt2, col, Values1, 2);
	}
	if (flag == 2 && cnt == 0)
	{
		cout << "Sorry, there are no products available in this category" << endl;
		return;
	}


}


void FuncImplementation::EfficiaBOScreenSize(int row, int col, string Values[][20])
{
primary:
	cout << "Choose any one of these categories\nA.Small Screen\nB.Large Screen\nC.Go Back " << endl;
	char choice;
	cin >> choice;
	UIFunction obj;
	BusinessLayer object;
	switch (choice)
	{
	case 'A':object.EfficiaBOScreenSize1(row, col, Values, 1);
		break;
	case 'B':object.EfficiaBOScreenSize2(row, col, Values, 1);
		break;
	case 'C':obj.SemiUrban();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}
}

void BusinessLayer::EfficiaBOScreenSize1(int row, int col, string Values[][20], int flag)
{	
	cout << endl << "Monitors with Screen Size < 12" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Efficia" && ConvertToFloat(Values[i][3]) < 12)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		EfficiaBOTouchScreen1(cnt, col, Values1, 2);
		EfficiaBOTouchScreen2(cnt2, col, Values1, 2);
	}
}

void BusinessLayer::EfficiaBOScreenSize2(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Monitors with Screen Size > 12" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Efficia" && ConvertToFloat(Values[i][3]) >= 12)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		EfficiaBOTouchScreen1(cnt, col, Values1, 2);
		EfficiaBOTouchScreen2(cnt2, col, Values1, 2);
	}
}

void FuncImplementation::EfficiaBOTouchScreen(int row, int col, string Values[][20])
{
primary:
	cout << "Choose any one of these categories\nA.Touch Screen\nB.No Touch Screen\nC.Go Back " << endl;
	char choice;
	cin >> choice;
	UIFunction obj;
	BusinessLayer object;
	switch (choice)
	{
	case 'A':object.EfficiaBOTouchScreen1(row, col, Values, 1);
		break;
	case 'B':object.EfficiaBOTouchScreen2(row, col, Values, 1);
		break;
	case 'C':obj.SemiUrban();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}
}

void BusinessLayer::EfficiaBOTouchScreen1(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Monitors that have a touch screen" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Efficia" && Values[i][5] == "Yes")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		EfficiaBOScreenSize1(cnt, col, Values1, 2);
		EfficiaBOScreenSize2(cnt2, col, Values1, 2);
	}
}

void BusinessLayer::EfficiaBOTouchScreen2(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Monitors that don't have a touch screen" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Efficia" && Values[i][5] == "No")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		EfficiaBOScreenSize1(cnt, col, Values1, 2);
		EfficiaBOScreenSize2(cnt2, col, Values1, 2);
	}
}



void FuncImplementation::AvalonBOCareStage(int row, int col, string Values[][20])
{
primary:
	cout << "Choose any one of these categories\nA.Intrapartum\nB.Antepartum\nC.Go Back " << endl;
	char choice;
	UIFunction obj;
	cin >> choice;
	BusinessLayer object;
	switch (choice)
	{
	case 'A':object.AvalonBOCareStage1(row, col, Values, 1);
		break;
	case 'B':object.AvalonBOCareStage2(row, col, Values, 1);
		break;
	case 'C':obj.labourcare();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}	
}

void BusinessLayer::AvalonBOCareStage1(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Monitors that are used during the Intrapartum care stage" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Avalon" && Values[i][8] == "Intrapartum")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		AvalonBOWeight1(cnt, col, Values1, 2);
		AvalonBOWeight2(cnt2, col, Values1, 2);
	}
}

void BusinessLayer::AvalonBOCareStage2(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Monitors that are used during the Antepartum care stage" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Avalon" && Values[i][8] == "Antepartum")
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		AvalonBOWeight1(cnt, col, Values1, 2);
		AvalonBOWeight2(cnt2, col, Values1, 2);
	}
}


void FuncImplementation::AvalonBOWeight(int row, int col, string Values[][20])
{
primary:
	cout << "Choose any one of these categories\nA.Light Weight Avalon Monitors\nB.Heavy Weight Avalon Monitors\nC.Go Back " << endl;
	char choice;
	cin >> choice;
	UIFunction obj;
	BusinessLayer object;
	switch (choice)
	{
	case 'A':object.AvalonBOWeight1(row, col, Values, 1);
		break;
	case 'B':object.AvalonBOWeight2(row, col, Values, 1);
		break;
	case 'C':obj.labourcare();
		break;
	default:
		obj.InvalidInput();		
		goto primary;		
	}

}


void BusinessLayer::AvalonBOWeight1(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Light Weight Avalon Monitors" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Avalon" && ConvertToFloat(Values[i][7])<6)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		AvalonBOCareStage1(cnt, col, Values1, 2);
		AvalonBOCareStage2(cnt2, col, Values1, 2);
	}
}

void BusinessLayer::AvalonBOWeight2(int row, int col, string Values[][20], int flag)
{
	cout << endl << "Heavy Weight Avalon Monitors" << endl;
	cnt = 0;
	for (int i = 1; i <= row; i++)
	{
		if (Values[i][1] == "Avalon" && ConvertToFloat(Values[i][7])>8)
		{
			cnt++;
			for (int j = 1; j <= col; j++)
			{
				cout << Values[i][j] << "		";
				if (flag == 1)
					Values1[cnt][j] = Values[i][j];
			}
			cout << endl;
		}
	}
	int cnt2 = cnt;
	if (flag == 1)
	{
		AvalonBOCareStage1(cnt, col, Values1, 2);
		AvalonBOCareStage2(cnt2, col, Values1, 2);
	}
}



