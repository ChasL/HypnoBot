#include <Windows.h>
#include <string>
#include "Functions.h"
#include "Pointers.h"

using namespace std;

DWORD ReadPointer(DWORD lpdwBase, CONST INT iOffset)
{
	__try{ return *(DWORD*)(*(DWORD*)lpdwBase + iOffset); }
    __except (EXCEPTION_EXECUTE_HANDLER){ return NULL; }
}

double ReadPointerDouble(DWORD lpdwBase, CONST INT iOffset)
{
	__try{ return *(double*)(*(DWORD*)lpdwBase + iOffset); }
    __except (EXCEPTION_EXECUTE_HANDLER){ return NULL; }
}

unsigned long GetValue(unsigned long ulBase, int iOffset)
{
   __try { return *(unsigned long*)(ulBase + iOffset); }
   __except (EXCEPTION_EXECUTE_HANDLER) { return 0; }
}
DWORD ReadIndefinitePointer(DWORD ulBase, DWORD ulLevels, ...)
{
	va_list va;
	va_start(va, ulLevels);

	__try
	{
		ulBase = *(DWORD*)ulBase;
		for (DWORD ulIndex = 1; ulIndex <= ulLevels; ulIndex++)
			ulBase = *(DWORD*)(ulBase + va_arg(va, int));
	}
	__except (EXCEPTION_EXECUTE_HANDLER) { ulBase = 0; }

	va_end(va);

	return ulBase;
}

bool WritePointer(DWORD ulBase, int iOffset, int iValue)
{
   __try { *(int*)(*(DWORD*)ulBase + iOffset) = iValue; return true; }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

void MakePageWritable(unsigned long ulAddress, unsigned long ulSize)
{
	MEMORY_BASIC_INFORMATION* mbi = new MEMORY_BASIC_INFORMATION;
	VirtualQuery((void*)ulAddress, mbi, ulSize);
	if (mbi->Protect != PAGE_EXECUTE_READWRITE)
	{
		unsigned long* ulProtect = new unsigned long;
		VirtualProtect((void*)ulAddress, ulSize, PAGE_EXECUTE_READWRITE, ulProtect);
		delete ulProtect;
	}
   delete mbi;
}

void WriteMemory(unsigned long ulAddress, unsigned long ulAmount, ...)
{
   va_list va;
   va_start(va, ulAmount);

	MakePageWritable(ulAddress, ulAmount);
   for (unsigned long ulIndex = 0; ulIndex < ulAmount; ulIndex++)
   {
		*(unsigned char*)(ulAddress + ulIndex) = va_arg(va, unsigned char);
   }

   va_end(va);
}

bool Jump(unsigned long ulAddress, void* Function, unsigned long ulNops)
{
   __try
   {
      MakePageWritable(ulAddress, 5 + ulNops);   *(unsigned char*)ulAddress = 0xE9;
      *(unsigned long*)(ulAddress + 1) = jmp(ulAddress, Function);
      memset((void*)(ulAddress + 5), 0x90, ulNops);
      return true;
   }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

#pragma region std::string toHexadecimal(int num)
std::string toHexadecimal(int num)
{
	int dividend, remain;
	
	std::string result = "";
	std::string hexArray[16];

	hexArray[0] = "0";
	hexArray[1] = "1";
	hexArray[2] = "2";
	hexArray[3] = "3";
	hexArray[4] = "4";
	hexArray[5] = "5";
	hexArray[6] = "6";
	hexArray[7] = "7";
	hexArray[8] = "8";
	hexArray[9] = "9";
	hexArray[10] = "A";
	hexArray[11] = "B";
	hexArray[12] = "C";
	hexArray[13] = "D";
	hexArray[14] = "E";
	hexArray[15] = "F";

	dividend = (int)num/16;
	remain = num%16;
	result = hexArray[remain];

	while (dividend != 0)
	{
		remain = dividend%16;
		dividend = (int)dividend/16;
		result = hexArray[remain]+result;
	}
	
	std::string last;
	
	if(result.length()==1)
		
		last.append("0");
	last.append(result);
	
	return last;
}
#pragma endregion

#pragma region std::string string_to_hex(const std::string& input)
std::string string_to_hex(const std::string& input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}
#pragma endregion

void KillThread(HANDLE hThread)
{
	if (hThread != NULL)
	{
		DWORD dwExitCode = 0;
		GetExitCodeThread(hThread, &dwExitCode);
		__try { TerminateThread(hThread, dwExitCode); }
		__except (EXCEPTION_EXECUTE_HANDLER) { SuspendThread(hThread); }
	}
}

void toClipboard(HWND hwnd, const std::string &s)
{
	OpenClipboard(hwnd);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size()+1);
	if (!hg)
	{
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg),s.c_str(),s.size()+1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);
}

DWORD GetSkillID(int index){
	switch(index){
		case 0:		return	1100002;	break; // Fighter
		case 1:		return	1200002;	break; // Page
		case 2:		return	1300002;	break; // Spearman
		case 3:		return	21100010;	break; // Aran
		case 4:		return	3100001;	break; // Hunter
		case 5:		return	3200001;	break; // Crossbow Man
		case 6:		return	13101002;	break; // Wind Archer
		case 7:		return	33100009;	break; // Wild Hunter
		case 8:		return	23100006;	break; // Mercedes
		case 9:		return	22150004;	break; // Evan [Spark]
		default:	return	0;	break;

	}
}

DWORD BPGetSkillID(int index){
	switch(index){
		case 0:		return	1100002;	break; // Fighter
		case 1:		return	1200002;	break; // Page
		case 2:		return	1300002;	break; // Spearman
		case 3:		return	21100010;	break; // Aran
		case 4:		return	3100001;	break; // Hunter
		case 5:		return	3200001;	break; // Crossbow Man
		case 6:		return	11101002;	break; // Mihile
		case 7:		return	13101002;	break; // Wind Archer
		case 8:		return	33100009;	break; // Wild Hunter
		case 9:		return	23100006;	break; // Mercedes
		case 10:	return	22150004;	break; // Evan [Spark]
		default:	return	0;	break;

	}
}

int GetKey(int index){
	switch(index){
		case 0:	return	0x10;	break; // Shift
		case 1:	return	0x11;	break; // Control
		case 2:	return	0x21;	break; // PageUp
		case 3:	return	0x22;	break; // PageDown
		case 4:	return	0x23;	break; // End
		case 5:	return	0x24;	break; // Home
		case 6:	return	0x2E;	break; // Delete
		case 7:	return	0x30;	break; // 0
		case 8:	return	0x31;	break; // 1
		case 9:	return	0x32;	break; // 2
		case 10: return	0x33;	break; // 3
		case 11: return	0x34;	break; // 4
		case 12: return	0x35;	break; // 5
		case 13: return	0x36;	break; // 6
		case 14: return	0x37;	break; // 7
		case 15: return	0x38;	break; // 8
		case 16: return	0x39;	break; // 9
		case 17: return	0x41;	break; // a
		case 18: return	0x42;	break; // b
		case 19: return	0x43;	break; // c
		case 20: return	0x44;	break; // d
		case 21: return	0x45;	break; // e
		case 22: return	0x46;	break; // f
		case 23: return	0x47;	break; // g
		case 24: return	0x48;	break; // h
		case 25: return	0x49;	break; // i
		case 26: return	0x4A;	break; // j
		case 27: return	0x4B;	break; // k
		case 28: return	0x4C;	break; // l
		case 29: return	0x4D;	break; // m
		case 30: return	0x4E;	break; // n
		case 31: return	0x4F;	break; // o
		case 32: return	0x50;	break; // p
		case 33: return	0x51;	break; // q
		case 34: return	0x52;	break; // r
		case 35: return	0x53;	break; // s
		case 36: return	0x54;	break; // t
		case 37: return	0x55;	break; // u
		case 38: return	0x56;	break; // v
		case 39: return	0x57;	break; // w
		case 40: return	0x58;	break; // x
		case 41: return	0x59;	break; // y
		case 42: return	0x5A;	break; // z
		default: return	NULL;	break;

	}
}

void EraseSpaces(string &str)
{
	for (unsigned i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			str.erase(i, 1);
			i--;
		}
	}
}

int HexToInt(string str)
{
	int i;
	sscanf_s(str.c_str(), "%X", &i);
	return i;
}

std::string IntToHex(int n){
	stringstream ss;

	ss << hex << n;
	std::string val = ss.str();
	ss.str("");

	return val;
}

#pragma region AoB Scan
unsigned long SearchForItem(const Search *item){
	unsigned long address = 0;	//this will store the address that we find
	vector<string> bytes;
	int splitpos;
	int result = item->result;	//store information from item into another variable
	string aob = item->AoB;		//this is because we do not want to alter item so we alter these instead

	vector<unsigned long>			b;
	vector<vector<unsigned long>>	gp;

	EraseSpaces(aob);			//remove spaces

	splitpos = aob.find_first_of('?');				//locate the first '?'
	while(splitpos != string::npos){				//loop while we can find a '?'
		bytes.push_back(aob.substr(0,splitpos));	//split the aob and store it into a vector

		aob = aob.substr(splitpos+1);				//cut the part split from the aob

		splitpos = aob.find_first_of('?');			//find next '?'
	}

	bytes.push_back(aob);							//don't forget the last part of the aob

	for(unsigned int i = 0; i<bytes.size();i++){
		b.clear();											//clear the vector before storing
		while(bytes[i] != ""){
			b.push_back(HexToInt(bytes[i].substr(0,2)));	//add the bytes to find to the vector
			bytes[i] = bytes[i].substr(2);
		}
		gp.push_back(b);							//each pieve of the aob split will be stored into seperate vectors
													//so we can account for the wildcards
	}

	unsigned long first = (gp[0])[0];				//this isn't really neccessary but it's to speed it up

	for(unsigned long loc = item->RangeBegin; loc < item->RangeEnd;){
		//we'll do a quick search to see if the byte matches the first byte to find
		//this speeds up the process as any byte that does not even coorespond with
		//the first byte to find will be skipped immidietly
		//since there are more bytes that DON'T match than ones that do
		//this will save time
		if(*(unsigned char*)(loc) != first){
			loc++;
		}else{
			address = loc;		//store the location of the first byte found
								//this will double as both the result we might be returning
								//and the location to jump back to if the location is incorrect
			for(unsigned int i = 0; i< gp.size(); i++){
				for(unsigned int j = 0; j < gp[i].size(); j++){
					//loop through the AoB

					if(*(unsigned char*)(loc) != (gp[i])[j]){
						//check if the bytes match, if it doesn't we will jump back to where we were
						loc = address;
						i = gp.size();
						break;
					}else if(j == b.size()-1 && i == gp.size()-1){
						if(result == 1){
							//if this is the result we want, break out of the loop
							i = gp.size();
							loc = item->RangeEnd;
							break;
						}else{
							//if this isn't the result we want, get rid of it
							//and decrease the result counter
							result--;
							if( address !=0){
								loc = address;
							}
							address = 0;
							i = gp.size();
							break;
						}
					}
					loc++;
				}
				loc++;
			}
		}
	}

	switch(item->type){
case ADDRESS:
	//if the only thing we want is the address then we are done
	return address;
	break;
case VALUE:
	//or else we will have to retrieve the info from the location
	string result = "";

	for(int i = 0; i<item->value_size; i++){
		result = IntToHex(*(unsigned char*)(address+item->offset+i)) + result;
	}

	return HexToInt(result);
	break;
	}
}

Search setSearch(string arrayOfBytes, unsigned long begin, unsigned long end, int whichresult){
	Search temp;
	temp.AoB = arrayOfBytes;
	temp.type = ADDRESS;
	temp.RangeBegin = begin;
	temp.RangeEnd = end;
	temp.result = whichresult;

	return temp;
}
#pragma endregion