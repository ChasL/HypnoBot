#include "AdvToolsForm.h"
#include <Windows.h>
#include "Functions.h"
#include <stdio.h>
#include <string>
#include <cstdio>
#include <iostream>

using namespace HypnoBot;
using namespace std;

System::String^ toSysString(std::string s){
	System::String^ t = gcnew String(s.c_str());
	return t;
}

string sreadBaseString, sreadOffsetString, swriteBaseString, swriteOffsetString, saobFromScan, saobToScan, saobScan;

void MarshalString2 ( String ^ s, string& os ) 
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}
 
void AdvToolsForm::ReadPointerBtn_Click(System::Object^  sender, System::EventArgs^  e){
	
	String ^ readBaseString = this->ReadPtrBaseText->Text;
	MarshalString2(readBaseString, sreadBaseString);
	String ^ readOffsetString = this->ReadPtrOffsetText->Text;
	MarshalString2(readOffsetString, sreadOffsetString);

	DWORD readBaseAddy = strtoul(sreadBaseString.c_str(), NULL, 16);
	const int readOffsetAddy = strtoul(sreadOffsetString.c_str(), NULL, 16);

	this->ReadPtrValueText->Text = ReadPointer(readBaseAddy, readOffsetAddy).ToString();
}

void AdvToolsForm::WritePointerBtn_Click(System::Object^  sender, System::EventArgs^  e){
	
	String ^ writeBaseString = this->WritePtrBaseText->Text;
	MarshalString2(writeBaseString, swriteBaseString);
	String ^ writeOffsetString = this->WritePtrOffsetText->Text;
	MarshalString2(writeOffsetString, swriteOffsetString);

	DWORD writeBaseAddy = strtoul(swriteBaseString.c_str(), NULL, 16);
	const int writeOffsetAddy = strtoul(swriteOffsetString.c_str(), NULL, 16);
	int writeValue = Convert::ToInt32(this->WritePtrValueText->Text);

	WritePointer(writeBaseAddy, writeOffsetAddy, writeValue);
}

void AdvToolsForm::AoBScanBtn_Click(System::Object^  sender, System::EventArgs^  e){

	Search item1;
	int iresult = 1;
	AoBResultsText->Text = "";

	String ^ aobScan = this->AoBSearchText->Text;
	MarshalString2(aobScan, saobScan);
	String ^ aobFromScan = this->AoBFromRangeText->Text;
	MarshalString2(aobFromScan, saobFromScan);
	String ^ aobToScan = this->AoBToRangeText->Text;
	MarshalString2(aobToScan, saobToScan);

	unsigned long sfaobFromScan = strtoul(saobFromScan.c_str(), NULL, 16);
	unsigned long sfaobToScan = strtoul(saobToScan.c_str(), NULL, 16);

	 item1 = setSearch(saobScan,
		sfaobFromScan,			//start
		sfaobToScan,			//end
		iresult);						//result number

	AoBResultsText->Text += toSysString(IntToHex(SearchForItem(&item1)))->ToUpper() + "\r\n";
}

