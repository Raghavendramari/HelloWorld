#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>



using namespace std;
//https://www.programmerinterview.com/c-cplusplus/pure-virtual-function/
class Func
{
public:
	
	//virtual float ConvertToFloat(string SS) = 0;
	virtual void IntellivueBOScreenSize(int row, int col, string Values[][20]) = 0;
	virtual void IntellivueBOPortability(int row, int col, string Values[][20]) = 0;
	virtual void EfficiaBOScreenSize(int row, int col, string Values[][20]) = 0;
	//virtual void EfficiaBONoOfWaveform(int row, int col, string Values[][20]) = 0;
	virtual void EfficiaBOTouchScreen(int row, int col, string Values[][20]) = 0;
	virtual void AvalonBOCareStage(int row, int col, string Values[][20]) = 0;
	virtual void AvalonBOWeight(int row, int col, string Values[][20]) = 0;
	/*virtual void ReadCSVFile() = 0;*/
};
