#include <Windows.h>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;
#include <algorithm>
#include <sstream>
#include <vector>

#define jmp(frm, to) (int)(((int)to - (int)frm) - 5)
#define NewThread(thread)	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&thread, NULL, NULL, NULL);
#define PressKey(key)		PostMessage(MShwnd, WM_KEYDOWN, key, (MapVirtualKey(key, 0) << 16) + 1);
#define UnPressKey(key)		PostMessage(MShwnd, WM_KEYUP, key, (MapVirtualKey(key, 0) << 16) + 1);
#define PressKey2(key)		PostMessageA(MShwnd, WM_KEYDOWN, key, (MapVirtualKey(key, 0) << 16) + 1);
#define UnPressKey2(key)	PostMessageA(MShwnd, WM_KEYUP, key, (MapVirtualKey(key, 0) << 16) + 1);

DWORD ReadPointer(DWORD lpdwBase, CONST INT iOffset);
double ReadPointerDouble(DWORD lpdwBase, CONST INT iOffset);
unsigned long GetValue(unsigned long ulBase, int iOffset);
DWORD ReadIndefinitePointer(DWORD ulBase, DWORD ulLevels, ...);
bool WritePointer(DWORD ulBase, int iOffset, int iValue);
void MakePageWritable(unsigned long ulAddress, unsigned long ulSize);
void WriteMemory(unsigned long ulAddress, unsigned long ulAmount, ...);
bool Jump(unsigned long ulAddress, void* Function, unsigned long ulNops);
std::string toHexadecimal(int num);
std::string string_to_hex(const std::string& input);
void toClipboard(HWND hwnd, const std::string &s);
void KillThread(HANDLE hThread);
int GetKey(int index);
DWORD GetSkillID(int index);
DWORD BPGetSkillID(int index);

enum DataType{
	ADDRESS,
	VALUE,
};

struct Search {
	string AoB;
	unsigned long RangeBegin, RangeEnd;
	DataType type;
	int result;
	int offset;
	int value_size;
};

Search setSearch(string arrayOfBytes, unsigned long begin, unsigned long end, int whichresult, int offset, int size);
Search setSearch(string arrayOfBytes, unsigned long begin, unsigned long end, int whichresult);
unsigned long SearchForItem(const Search *item);

void EraseSpaces(string &str);

int HexToInt(string str);
std::string IntToHex(int n);