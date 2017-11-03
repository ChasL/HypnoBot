#include "MainForm.h"
#include <Windows.h>
#include "Functions.h"
#include "Pointers.h"
#include <stdio.h>


using namespace HypnoBot;
using namespace System::IO;

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 
	Application::Run(gcnew MainForm);
}

#pragma region Variables

//MapleStory Window
HWND MShwnd;

//AutoPot
int UserSetHP, UserSetMP, HPKey, MPKey;
bool HPExit, MPExit;

//Auto Attack
int AtkKey, AtkDelay;
bool AutoAtkOn;

//Auto Skills
int Skill1Key, Skill1Delay, Skill2Key, Skill2Delay, Skill3Key, Skill3Delay, Skill4Key, Skill4Delay;
bool AutoSkill1On, AutoSkill2On, AutoSkill3On, AutoSkill4On, noMacWait = true;

//NDFA
//unsigned long NDFAAddy1 = NDFAAddy;
unsigned long NDFARet = NDFAAddy + 5;
DWORD BPNDFASkillID = 0;
int NDFASkillID, ndfaInterval;
bool ndfaOn;

//FMA/FGM
unsigned long ulIntersectRect = (DWORD)GetProcAddress(GetModuleHandle(L"user32.dll") , "IntersectRect");
unsigned long ulIntersectRectRet = ulIntersectRect + 5;
bool bGM = false;
bool bFMA = false;

//Item Vac
unsigned long ItemVacCall = 0x00438300;
DWORD itemVacX = 0, itemVacY = 0;

//Item Hook
long int iItemX = 0, iItemY = 0;

//StatHook
unsigned long ulStatHook = (DWORD)StatHook, ulStatHookRet = ulStatHook + 5;
int HP = 0, MaxHP = 0, MP = 0, MaxMP = 0, Exp = 0, MaxExp = 0;
bool StHook = false;

//Kami
unsigned char ucMonsterIndex = 0; 
unsigned long ulMobStruct = 0;
int iOriginalX = 0, iOriginalY = 0, iRangeX, iRangeY, KamiSetItems;
int TeleDelay = 200, KamiLootDelay = 250;
bool kamiLoot = false, fStopKami = true, lootWhenNoMobs = false;

//Auto Loot
int ReturnX, ReturnY, AutoLootDelay = 200, AutoLootItems;
bool returnToXY = false, autoLoot = false;

//Basic Hacks
bool TubiOn;

bool UAOn;
int randAtkCount, randBuffCount;

bool teleUA;
int UAReturnX, UAReturnY;

bool ClickFlyOn;

bool morphGMOn;

bool NoBreathOn;

//Auto CC
int CCDelay, curChannel;
bool AutoCCOn, LootBfrCC;

//People CC
int CCPplAmt;
bool AutoCCPplOn;

//Auto CS
int CSDelay;
bool AutoCSOn;

//Teleport Walk

int teleWalkDist;
bool teleWalk;

//2 Point Tele
bool twoPointTele;
int point1X, point1Y, point2X, point2Y, twoPointInterval;

//Flags
bool ccing = false, usingSkill = false, looting = false, teleporting = true, potting = false, wallCheck = true;

#pragma endregion

#pragma region Wallcheck + Teleport

bool LeftWall(int X) { return ((int)ReadPointer(WallBase, LeftWallOff) <= X); }
bool TopWall(int Y) { return ((int)ReadPointer(WallBase, LeftWallOff + 4) <= Y); }
bool RightWall(int X) { return ((int)ReadPointer(WallBase, LeftWallOff + 8) >= X); }
bool BottomWall(int Y) { return ((int)ReadPointer(WallBase, LeftWallOff + 12) >= Y); }

void Teleport(int X, int Y)
{
	if(wallCheck)
	{
		if (LeftWall(X) && RightWall(X) && TopWall(Y) && BottomWall(Y) && wallCheck)
		{
			if (!teleporting) teleporting = true;
			WritePointer(CharBase, TeleportX, X);
			WritePointer(CharBase, TeleportY, Y);
			WritePointer(CharBase, TeleportToggle, 1);
			WritePointer(CharBase, TeleportToggle + 4, 1);
		}
		else if(!LeftWall(X) || !RightWall(X) || !TopWall(Y) || !BottomWall(Y))
		{
			teleporting = false;
		}
	}
	else if(!wallCheck)
	{
		WritePointer(CharBase, TeleportToggle + 8, X);
		WritePointer(CharBase, TeleportToggle + 12, Y);
		WritePointer(CharBase, TeleportToggle, 1);
		WritePointer(CharBase, TeleportToggle + 4, 1);
	}
}
#pragma endregion

#pragma region Return Values

int ItemCount() { return ReadPointer(ItemBase, ItemCountOff); }
int MobCount() { return ReadPointer(MobBase, MobCountOff); }
int CurHP() { return ReadPointer(GUIBase, HPOff); }
int CurMP() { return ReadPointer(GUIBase, MPOff); }
int CharacterX() { PressKey(0x28); Sleep(30); return (int)ReadPointer(CharBase,CharXOff); }
int CharacterY() { PressKey(0x28); Sleep(30); return (int)ReadPointer(CharBase,CharYOff); }

#pragma endregion

// ALL THE HACKS //

#pragma region ItemHook

void __declspec(naked) _stdcall ItemHookASM()
{
   __asm
    {
        cmp dword ptr [esp], 0x00694B1A
        jne NormalAPICall
        push eax
        mov eax,[esp+0x0C]
        mov [iItemX],eax
        mov eax,[esp+0x10]
        mov [iItemY],eax
        pop eax

        NormalAPICall:
        jmp dword ptr [PtInRect]
    }
}

void HookItemXY(bool state){
	if(state)
		*(unsigned long*) PtInRectAddy = (unsigned long)ItemHookASM;
	else
		*(unsigned long*) PtInRectAddy = (unsigned long)PtInRect;
}
#pragma endregion

#pragma region AutoPots
void AutoHP()
{
	while(!HPExit)
	{
		if(CurHP() < UserSetHP && !ccing)
		{
			potting = true;
			Sleep(300);
            PressKey(HPKey);
			Sleep(30);
			UnPressKey(HPKey);
			potting = false;
			Sleep(700);
		}
		Sleep(100);
	}
}

void AutoMP()
{
	while(!MPExit)
	{
		if(CurMP() < UserSetMP && !ccing)
		{
			potting = true;
			Sleep(300);
			PressKey(MPKey);
			Sleep(30);
			UnPressKey(MPKey);
			potting = false;
			Sleep(700);
		}
		Sleep(100);
	}
}
#pragma endregion

#pragma region Auto Attack / Auto Skills

void AutoAtk()
{
	for(;AutoAtkOn;Sleep(AtkDelay))
	{
		if(!usingSkill && !potting && !looting && teleporting && !ccing && MobCount() > 1){
			PressKey(AtkKey);
			Sleep(30);
			UnPressKey(AtkKey);
		}
	}
	Sleep(100);
}

void AutoSkill1()
{	
	if(AutoSkill1On && !ccing)
	{
		usingSkill = true;
		if(AutoAtkOn) Sleep(1000);
		PressKey(Skill1Key);
		Sleep(30);
		UnPressKey(Skill1Key);
		if(!noMacWait) Sleep(3000);
		usingSkill = false;
		AutoSkill1On = false;
	}

	return;
}

void AutoSkill2()
{
	if(AutoSkill2On && !ccing)
	{
		usingSkill = true;
		if(AutoAtkOn) Sleep(1000);
		PressKey(Skill2Key);
		Sleep(30);
		UnPressKey(Skill2Key);
		if(!noMacWait) Sleep(3000);
		usingSkill = false;
		AutoSkill2On = false;
	}

	return;
}

void AutoSkill3()
{
	if(AutoSkill3On && !ccing)
	{
		usingSkill = true;
		if(AutoAtkOn) Sleep(1000);
		PressKey(Skill3Key);
		Sleep(30);
		UnPressKey(Skill3Key);
		if(!noMacWait) Sleep(3000);
		usingSkill = false;
		AutoSkill3On = false;
	}

	return;
}

void AutoSkill4()
{
	if(AutoSkill4On && !ccing)
	{
		usingSkill = true;
		if(AutoAtkOn) Sleep(1000);
		PressKey(Skill4Key);
		Sleep(30);
		UnPressKey(Skill4Key);
		if(!noMacWait) Sleep(3000);
		usingSkill = false;
		AutoSkill4On = false;
	}

	return;
}
#pragma endregion

#pragma region Bypassless Hacks + NDFA

void ClickFly()
{
	while(ClickFlyOn)
	{
		while(ReadPointer(MouseBase, MouseAnimOff) == 12)
		{
		int MouseX = (int)ReadIndefinitePointer(MouseBase, 2, MouseLocOff, MouseXOff);
		int MouseY = (int)ReadIndefinitePointer(MouseBase, 2, MouseLocOff, MouseYOff);

			Teleport(MouseX, MouseY);
			Sleep(65);
		}
		Sleep(50);
	}
}

void Tubi()
{
	while(TubiOn)
	{
		WritePointer(ServerBase, TubiOff, 0);
		Sleep(25);
	}
	Sleep(100);
}

void NoBreath()
{
	while(NoBreathOn || ccing)
	{
		if(ReadPointer(CharBase,BreathOff) > 0){
			WritePointer(CharBase, BreathOff, 0);
			Sleep(50);
		}
		Sleep(100);
	}
}

void UnlimAtk()
{
	while(UAOn){

		randAtkCount = (rand()%50)+50;
		randBuffCount = (rand()%10)+10;

		if((int)ReadPointer(CharBase, AtkCountOff) >= randAtkCount)
		{
			WritePointer(CharBase, AtkCountOff, 1);
		}

		if((int)ReadPointer(CharBase, BuffCountOff) >= randBuffCount)
		{
			WritePointer(CharBase, BuffCountOff, 1);
		}
		Sleep(1000);
	}
}

void MorphGM()
{
	while(morphGMOn)
	{
		//WritePointer(CharBase,MorphOff,9);
		Sleep(10);
	}
}

void TeleUA(){

	while(teleUA){

		if((int)ReadPointer(CharBase, AtkCountOff) >= (rand()%50)+50 && !ccing && !looting && !usingSkill)
		{
			PressKey(0x28);
			Sleep(200);
			
			UAReturnX = (int)ReadPointer(CharBase, CharXOff);
			UAReturnY = (int)ReadPointer(CharBase, CharYOff);
			
			Sleep(100);
			Teleport((UAReturnX + 50), UAReturnY);
			PressKey(AtkKey);
			Sleep(2000);
			Teleport(UAReturnX, UAReturnY);
		}
		Sleep(50);
	}
}

void NDFA(){
	while(ndfaOn){
		if(!ccing && !looting){
//			WritePointer(CharBase, FAOff, NDFASkillID);
			Sleep(ndfaInterval);
		}
	}
}

#pragma region oldFMA

/*void __declspec(naked) FGMFMA_ASM(){ 
	__asm { 

		cmp [bFMA],00
		je FGM

		cmp dword ptr [esp],FMAAddy
		je return_true

		FGM:
		cmp [bFGM],00
		je Disable

		cmp dword ptr [esp],FGMAddy
		je return_false
		cmp dword ptr [esp],Silence1Addy
		je return_false
		cmp dword ptr [esp],Silence2Addy
		je return_false
		cmp dword ptr [esp],Silence3Addy
		je return_false
		cmp dword ptr [esp],Silence4Addy
		je return_false
		cmp dword ptr [esp],Silence5Addy
		je return_false
		jmp Disable

		return_true:
		mov eax,1
		ret 0x0C

		return_false:
		mov eax,0
		ret 0x0C

		Disable:
		mov edi,edi
		push ebp
		mov ebp,esp
		jmp dword ptr [ulIntersectRectRet]

	}
}
void fFMA(bool enable){
	if(enable){
		bFMA = true;
		Jump(ulIntersectRect, FGMFMA_ASM,0);
	}else{
		bFMA = false;
		Jump(ulIntersectRect, FGMFMA_ASM,0);
	}
}	
void fFGM(bool enable){
	if(enable){
		bFGM = true;
		Jump(ulIntersectRect, FGMFMA_ASM,0);
	}else{
		bFGM = false;
		Jump(ulIntersectRect, FGMFMA_ASM,0);
	}
}*/
#pragma endregion


/*void __declspec(naked) PGM_ASM(){ 
	__asm 
	{
		cmp[bGM],00
		je Disable

		jmp PGMHook

		PGMHook:
		cmp dword ptr [esp], 0x00487CC5
		jne PGMReturn
		cmp dword ptr [esp+10], 0x0218167F
		jne PGMReturn
		mov dword ptr [esp+10], 0x0121993B

		PGMReturn:
		jmp InterlockInc

		Disable:
		dd InterlockInc
	}
}
void fGM(bool enable){
	if(enable){
		bGM = true;
		Jump(0x016400C0, PGM_ASM,0);
	}else{
		bGM = false;
		Jump(0x016400C0, PGM_ASM,0);
	}
}*/

#pragma endregion

#pragma region Auto CC/CS + People CC

void AutoCC()
{
	Sleep(CCDelay*1000);
	for(;AutoCCOn;Sleep(CCDelay*1000)){
		
		curChannel = (int)(ReadPointer(ServerBase, ChannelOff)+1);
		ccing = true;

		if(!NoBreathOn) NewThread(NoBreath);
		Sleep(5200);

		while((ReadPointer(ServerBase, ChannelOff)+1) == curChannel && (int)ReadPointer(MapInfoBase, MapIDOff) != 0 && (ReadPointer(CharBase, CharXOff) && ReadPointer(CharBase,CharYOff)) != 0){
			if(!AutoCCOn) goto turnedOff;
			PressKey(0x1B);
			Sleep(800);
			PressKey(0x0D);
			Sleep(500);
			PressKey(0x27);
			Sleep(500);
			PressKey(0x0D);
		}
		
		PressKey(0x1B);
		Sleep(30);
		UnPressKey(0x1B);

		if(returnToXY && fStopKami){
				Sleep(2000);
				Teleport(ReturnX, ReturnY);
		}else	Sleep(2000);

		turnedOff:
		ccing = false;
	}
}

void AutoCCPpl()
{
	while(AutoCCPplOn){

		if((int)ReadPointer(PeopleBase, PeopleCountOff) >= CCPplAmt && ReadPointer(MapInfoBase, MapIDOff) != 0 && (ReadPointer(CharBase, CharXOff) && ReadPointer(CharBase,CharYOff)) != 0){
			
			curChannel = (int)(ReadPointer(ServerBase, ChannelOff)+1);
			ccing = true;

			if(!NoBreathOn) NewThread(NoBreath);

			Sleep(5200);

			while((ReadPointer(ServerBase, ChannelOff)+1) == curChannel && (int)ReadPointer(MapInfoBase, MapIDOff) != 0){
				if(!AutoCCPplOn) goto turnedOff;
				PressKey(0x1B);
				Sleep(800);
				PressKey(0x0D);
				Sleep(500);
				PressKey(0x27);
				Sleep(500);
				PressKey(0x0D);
			}

			PressKey(0x1B);
			Sleep(30);
			UnPressKey(0x1B);

			if(returnToXY && fStopKami){
				Sleep(2000);
				Teleport(ReturnX, ReturnY);
			}
			else Sleep(2000);

			turnedOff:
			ccing = false;
		}
		Sleep(100);
	}
}

void AutoCS()
{
	Sleep(CSDelay*1000);
	for(;AutoCSOn;Sleep(CSDelay*1000)){
		if(!AutoCSOn) return;

		ccing = true;

		Sleep(5200);

		if(!NoBreathOn) NewThread(NoBreath);

		while(ReadPointer(MapInfoBase, MapIDOff) != 0 && (ReadPointer(CharBase, CharXOff) && ReadPointer(CharBase,CharYOff)) != 0){
			PressKey(0xC0);
			Sleep(1000);
		}

		Sleep(5000);
		PressKey(0x1B);
		Sleep(300);
		PressKey(0x20);
		UnPressKey(0x20);
		Sleep(2000);
		
		if(returnToXY && fStopKami){
			Sleep(2000);
			Teleport(ReturnX, ReturnY);
		}
		else Sleep(2000);

		ccing = false;
	}
}

#pragma endregion

#pragma region Bypass NDFA

void __declspec(naked) NDFA_ASM(){ 
	__asm { 
		
		push ecx
		mov ecx,[BPNDFASkillID]
		mov dword ptr [esi+0x00007788],ecx
		pop ecx
		jmp [NDFARet]

	}
}

void fNDFA(bool enable){
	if(enable){
		Jump(NDFAAddy, NDFA_ASM,20);
	}else{
		WriteMemory(NDFAAddy, 25, 0x83, 0xBE, 0x88, 0x77, 0x00, 0x00, 0x00, 0x0F, 0x84, 0x49, 0x01, 0x00, 0x00, 0x2B, 0xAE, 0x90, 0x77, 0x00, 0x00, 0x0F, 0x88, 0x3D, 0x01, 0x00, 0x00);
	}
}

#pragma endregion

#pragma region Full Bypass Required Hacks

void MainForm::FullGMCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->FullGMCB->Checked){
		WriteMemory(FullGodMode, 2, 0x0F, 0x84);
	}else{
		WriteMemory(FullGodMode, 2, 0x0F, 0x85);
	}
}

void MainForm::MultiDmgCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->MultiDmgCB->Checked){
		WriteMemory(MultiDamage, 1, 0x74);
	}else{
		WriteMemory(MultiDamage, 1, 0x75);
	}
}

void MainForm::AirLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->AirLootCB->Checked){
		WriteMemory(InstantAirLoot, 1, 0x74);
	}else{
		WriteMemory(InstantAirLoot, 1, 0x75);
	}
}

void MainForm::InstantDropCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->InstantDropCB->Checked){
		WriteMemory(InstantDrop, 1, 0x25);
	}else{
		WriteMemory(InstantDrop, 1, 0x0D);
	}
}

void MainForm::HideDamageCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->HideDamageCB->Checked){
		WriteMemory(HideDamage, 1, 0x7F);
	}else{
		WriteMemory(HideDamage, 1, 0x7E);
	}
}

void MainForm::NoLootAnimCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->NoLootAnimCB->Checked){
		WriteMemory(NoLootAnimation, 6, 0x81, 0xFE, 0x00, 0x00, 0x00, 0x00);
	}else{
		WriteMemory(NoLootAnimation, 6, 0x81, 0xFE, 0xBC, 0x00, 0x00, 0x00);
	}
}

void MainForm::NoMobLagCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->NoMobLagCB->Checked){
		WriteMemory(NoMobLag, 2, 0xB8, 0x00);
	}else{
		WriteMemory(NoMobLag, 2, 0xB8, 0x01);
	}
}

void MainForm::SlowMobsCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->SlowMobsCB->Checked){
		WriteMemory(SlowMobs, 5, 0xB8, 0x00, 0x00, 0x00, 0x00);
	}else{
		WriteMemory(SlowMobs, 5, 0xB8, 0xE8, 0x03, 0x00, 0x00);
	}
}

void MainForm::UnlimAtkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->UnlimAtkCB->Checked){
		WriteMemory(UnlimAttack, 1, 0xEB);
	}else{
		WriteMemory(UnlimAttack, 1, 0x7E);
	}
}

void MainForm::FLACCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->FLACCCB->Checked){
		WriteMemory(FLEnterMap, 11, 0xB9, 0x07, 0x00, 0x00, 0x00, 0x90, 0x07, 0x00, 0x00, 0x00, 0x90);
	}else{
		WriteMemory(FLEnterMap, 6, 0x83, 0xE1, 0x01, 0x83, 0xC9, 0x06);
	}
}

void MainForm::NoKBCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->NoKBCB->Checked){
		WriteMemory(NoKnockBack, 1, 0x00);
	}else{
		WriteMemory(NoKnockBack, 1, 0x01);
	}
}

void MainForm::UnlimKaiserCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->UnlimKaiserCB->Checked){
		WriteMemory(UnlimKaiserCast, 2, 0xEB, 0x2E);
		WriteMemory(UnlimKaiserGauge, 1, 0xEB); 
	}else{
		WriteMemory(UnlimKaiserCast, 2, 0x81, 0xFE);
		WriteMemory(UnlimKaiserGauge, 1, 0x7D);
	}
}

void MainForm::CPUHack1CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->CPUHack1CB->Checked){
		CPUHack2CB->Enabled = false;
		WriteMemory(CPUBackGround1, 5, 0x90, 0x90, 0x90, 0x90, 0x90);
		WriteMemory(CPUBackGround2, 5, 0x90, 0x90, 0x90, 0x90, 0x90);
	}else{
		CPUHack2CB->Enabled = true;
		WriteMemory(CPUBackGround1, 5, 0xE8, 0x60, 0xC6, 0xFF, 0xFF);
		WriteMemory(CPUBackGround2, 5, 0xE8, 0xF2, 0xC3, 0xFF, 0xFF);
	}
}

void MainForm::CPUHack2CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->CPUHack2CB->Checked){
		CPUHack1CB->Enabled = false;
		WriteMemory(CPUBackGround1, 5, 0x90, 0x90, 0x90, 0x90, 0x90);
		WriteMemory(CPUBackGround2, 5, 0x90, 0x90, 0x90, 0x90, 0x90);
		WriteMemory(CPUPlatforms, 5, 0x90, 0x90, 0x90, 0x90, 0x90);
	}else{
		CPUHack1CB->Enabled = true;
		WriteMemory(CPUBackGround1, 5, 0xE8, 0x60, 0xC6, 0xFF, 0xFF);
		WriteMemory(CPUBackGround2, 5, 0xE8, 0xF2, 0xC3, 0xFF, 0xFF);
		WriteMemory(CPUPlatforms, 5, 0xE8, 0x32, 0xD9, 0xFF, 0xFF);
	}
}

void MainForm::NoAtkLimitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(this->NoAtkLimitCB->Checked){
		WriteMemory(NoAtkLimit, 1, 0xEB);
	}else{
		WriteMemory(NoAtkLimit, 1, 0x7C);
	}
}

#pragma endregion

#pragma region Kami + Auto Loot

void Kami()
{
	for (;!fStopKami; Sleep(TeleDelay))
	{
		if(!ccing){
			if((kamiLoot && ItemCount() >= KamiSetItems && !ccing) || (kamiLoot && lootWhenNoMobs && MobCount() <= 1 && !ccing))
			{
				looting = true;
				Sleep(100);
				for(unsigned char uc = 0; uc <= 100 && ItemCount(); uc++, Sleep(KamiLootDelay))
				{
					restart:
					if(!kamiLoot || fStopKami || ccing) break;
					if(potting || usingSkill) goto restart;
					Teleport(iItemX, iItemY);
					PressKey(0x60);
				}
				UnPressKey(0x60);
				Sleep(300);
				looting = false;

				continue;
			}
			if (!MobCount()) continue;
			ulMobStruct = ReadPointer(MobBase, Mob1Off);

			if (ucMonsterIndex == 0)
			{
				ulMobStruct = GetValue(ulMobStruct, Mob2Off);
			}
			else if (ucMonsterIndex == 1)
			{
				ulMobStruct = GetValue(ulMobStruct, -0x0C);
				ulMobStruct = GetValue(ulMobStruct, 0x14);
			}
			else if (ucMonsterIndex == 2)
			{
				ulMobStruct = GetValue(ulMobStruct, -0x0C);
				ulMobStruct = GetValue(ulMobStruct, Mob2Off);
				ulMobStruct = GetValue(ulMobStruct, 0x14);
			}
			else if (ucMonsterIndex == 3)
			{
				ulMobStruct = GetValue(ulMobStruct, -0x0C);
				ulMobStruct = GetValue(ulMobStruct, Mob2Off);
				ulMobStruct = GetValue(ulMobStruct, Mob2Off);
				ulMobStruct = GetValue(ulMobStruct, 0x14);
			}

			if (!GetValue(ulMobStruct, MobDeathOff))
			{
				if (++ucMonsterIndex > 3) ucMonsterIndex = 0;
				continue;
			}

			ulMobStruct = GetValue(ulMobStruct, Mob3Off);
			ulMobStruct = GetValue(ulMobStruct, Mob4Off);

			Teleport((int)GetValue(ulMobStruct, MobXOff) - iRangeX, 
				(int)GetValue(ulMobStruct, MobYOff) - iRangeY);
		}
		Sleep(100);
	}
}

void AutoLoot()
{
	for(;autoLoot; Sleep(100))
	{
		if((!ccing && ItemCount() >= AutoLootItems)||(!ccing && lootWhenNoMobs && MobCount() <= 1))
		{ 
			looting = true;
			for (unsigned char loot = 0; loot <= 100 && ItemCount(); loot++, Sleep(AutoLootDelay))
			{
				restart:
				if(!autoLoot || ccing) break;
				if(potting || usingSkill) goto restart;
				Teleport(iItemX, iItemY);
				PressKey(0x60);
			}
			UnPressKey(0x60);
			if(returnToXY)
			{
				Sleep(300);
				Teleport(ReturnX, ReturnY);
			}
			Sleep(300);
			looting = false;
		}
	}
}

void _Kami(bool state){
	if(state){
		usingSkill = true;
		PressKey(0x28);
		usingSkill = false;
		Sleep(100);
		iOriginalX = ReadPointer(CharBase, CharXOff);
		iOriginalY = ReadPointer(CharBase, CharYOff);
		fStopKami = false;
		NewThread(Kami);
	}else{
		fStopKami = true;
	}
}
#pragma endregion

#pragma region Fixed Item Vac

void __declspec(naked) ITEMVAC_ASM(){ 
	__asm { 
		
		call [ItemVacCall]
		mov ecx,eax
		mov eax,[esp+0x0C]
		push ecx
		mov ecx,[itemVacX]
		mov [eax],ecx
		pop edi
		mov ecx,[itemVacY]
		mov [eax+0x04],ecx
		pop ecx
		pop esi
		ret 4
	}
}
void fItemVac(bool enable){
	if(enable){
		Jump(ItemVacAddy, ITEMVAC_ASM,0);
	}else{
		WriteMemory(ItemVacAddy, 5, 0xE8, 0x97, 0xDC, 0xD1, 0xFF);
	}
}

#pragma endregion

#pragma region 2 Point Tele

void TwoPointTele(){
	for(;twoPointTele;){

		if(!looting && !ccing)
		{
			Teleport(point1X, point1Y);
			Sleep(twoPointInterval);
			Teleport(point2X, point2Y);
			Sleep(twoPointInterval);
		}
	}
}

#pragma endregion

#pragma region Teleport Walk

void TeleportWalk(){
	
	while(teleWalk){

		if(GetAsyncKeyState(0x25)){
			Teleport(CharacterX() - teleWalkDist, CharacterY());
		}

		if(GetAsyncKeyState(0x27)){
			Teleport(CharacterX() + teleWalkDist, CharacterY());
		}

		if(GetAsyncKeyState(0x26)){
			Teleport(CharacterX(), CharacterY() - teleWalkDist);
		}

		if(GetAsyncKeyState(0x28)){
			Teleport(CharacterX(), CharacterY() + teleWalkDist);
		}

		Sleep(35);
	}
}

#pragma endregion

#pragma region Auto Gourd Quest

void AutoGourdQuest(){
	
	PressKey(0x59);
	Sleep(3000);
	PressKey(0x59);
	Sleep(3000);
	PressKey(0x59);
	Sleep(3000);
	PressKey(0x59);
}

#pragma endregion

// CHECKBOXES | BUTTONS | TIMERS //

#pragma region Form Load

void MainForm::MainForm_Load(System::Object^  sender, System::EventArgs^  e){

	if(ReadPointer(MapInfoBase, MapIDOff) == 0)
	{
	MessageBox::Show("You have injected the bot incorrectly.\n"+
		"The correct way to inject is by injecting ingame using Injector Gadget.\n"+
		"If you want to avoid a 10 minute autoban, restart MapleStory and reinject the bot correctly.\n\n"+
		"More info can be found in the main thread at www.gamekiller.net",
         "READ: Injected Incorrectly", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}

	HookItemXY(true);

	AutoHPCombo->SelectedIndex = 2;
	AutoMPCombo->SelectedIndex = 3;
	AutoAtkCombo->SelectedIndex = 1;
	AutoSkill1Combo->SelectedIndex = 5;
	AutoSkill2Combo->SelectedIndex = 6;
	AutoSkill3Combo->SelectedIndex = 4;
	AutoSkill4Combo->SelectedIndex = 8;
}

#pragma endregion

#pragma region AutoPot CheckBoxes

void MainForm::AutoHPCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoHPCB->Checked){
		HPExit = false;
		HPKey = GetKey(AutoHPCombo->SelectedIndex);
		UserSetHP = Convert::ToInt32(AutoHPText->Text);
		NewThread(AutoHP);
	}else{
		HPExit = true;
	}
}

void MainForm::AutoMPCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoMPCB->Checked){
		MPExit = false;
		MPKey = GetKey(AutoMPCombo->SelectedIndex);
		UserSetMP = Convert::ToInt32(AutoMPText->Text);
		NewThread(AutoMP);
	}else{
		MPExit = true;
	}
}

#pragma endregion

#pragma region Auto Attack + Auto Skill Checkboxes and Timers

void MainForm::AutoAtkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoAtkCB->Checked){
		AutoAtkOn = true;
		AtkKey = GetKey(AutoAtkCombo->SelectedIndex);
		AtkDelay = Convert::ToInt32(AutoAtkText->Text);
		NewThread(AutoAtk);
	}else{
		AutoAtkOn = false;
	}
}

void MainForm::AutoSkill1CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoSkill1CB->Checked){
		Skill1Key = GetKey(AutoSkill1Combo->SelectedIndex);
		
		if(noMacWait) AutoSkill1Timer->Interval = (Convert::ToInt32(AutoSkill1Text->Text));
		else AutoSkill1Timer->Interval = (Convert::ToInt32(AutoSkill1Text->Text)) + 4000;

		AutoSkill1On = true;
		NewThread(AutoSkill1);
		AutoSkill1Timer->Enabled = true;
	}else{
		AutoSkill1Timer->Enabled = false;
		AutoSkill1On = false;
	}
}

void MainForm::AutoSkill1Timer_Tick(System::Object^  sender, System::EventArgs^  e){
	AutoSkill1On = true;
	NewThread(AutoSkill1);
}

void MainForm::AutoSkill2CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoSkill2CB->Checked){
		Skill2Key = GetKey(AutoSkill2Combo->SelectedIndex);
		
		if(noMacWait) AutoSkill2Timer->Interval = (Convert::ToInt32(AutoSkill2Text->Text));
		else AutoSkill2Timer->Interval = (Convert::ToInt32(AutoSkill2Text->Text)) + 4000;

		AutoSkill2On = true;
		NewThread(AutoSkill2);
		AutoSkill2Timer->Enabled = true;
	}else{
		AutoSkill2Timer->Enabled = false;
		AutoSkill2On = false;
	}
}

void MainForm::AutoSkill2Timer_Tick(System::Object^  sender, System::EventArgs^  e){
	AutoSkill2On = true;
	NewThread(AutoSkill2);
}

void MainForm::AutoSkill3CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoSkill3CB->Checked){
		Skill3Key = GetKey(AutoSkill3Combo->SelectedIndex);
		
		if(noMacWait) AutoSkill3Timer->Interval = (Convert::ToInt32(AutoSkill3Text->Text));
		else AutoSkill3Timer->Interval = (Convert::ToInt32(AutoSkill3Text->Text)) + 4000;

		AutoSkill3On = true;
		NewThread(AutoSkill3);
		AutoSkill3Timer->Enabled = true;
	}else{
		AutoSkill3Timer->Enabled = false;
		AutoSkill3On = false;
	}
}

void MainForm::AutoSkill3Timer_Tick(System::Object^  sender, System::EventArgs^  e){
	AutoSkill3On = true;
	NewThread(AutoSkill3);
}

void MainForm::AutoSkill4CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoSkill4CB->Checked){
		Skill4Key = GetKey(AutoSkill4Combo->SelectedIndex);

		if(noMacWait) AutoSkill4Timer->Interval = (Convert::ToInt32(AutoSkill4Text->Text));
		else AutoSkill4Timer->Interval = (Convert::ToInt32(AutoSkill4Text->Text)) + 4000;

		AutoSkill4On = true;
		NewThread(AutoSkill4);
		AutoSkill4Timer->Enabled = true;
	}else{
		AutoSkill4Timer->Enabled = false;
		AutoSkill4On = false;
	}
}

void MainForm::AutoSkill4Timer_Tick(System::Object^  sender, System::EventArgs^  e){
	AutoSkill4On = true;
	NewThread(AutoSkill4);
}

void MainForm::DisableSkillWaitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(DisableSkillWaitCB->Checked){
		noMacWait = true;
	}else{
		noMacWait = false;
	}
}
#pragma endregion

#pragma region Auto CC/CS & People CC Checkboxes

void MainForm::AutoCCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoCCCB->Checked){
		CCDelay = Convert::ToInt32(AutoCCText->Text);
		AutoCCOn = true;
		NewThread(AutoCC);
	}else{
		AutoCCOn = false;
	}
}

void MainForm::AutoCSCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoCSCB->Checked){
		CSDelay = Convert::ToInt32(AutoCSText->Text);
		AutoCSOn = true;
		NewThread(AutoCS);
	}else{
		AutoCSOn = false;
	}
}

void MainForm::PeopleCCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(PeopleCCCB->Checked){
		CCPplAmt = Convert::ToInt32(PeopleCCText->Text);
		AutoCCPplOn = true;
		NewThread(AutoCCPpl);
	}else{
		AutoCCPplOn = false;
	}
}

#pragma endregion

#pragma region Bypassless Hacks Checkboxes + NDFA

void MainForm::ClickFlyCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(ClickFlyCB->Checked){
		ClickFlyOn = true;
		NewThread(ClickFly);
	}else{
		ClickFlyOn = false;
	}
}

void MainForm::TubiCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TubiCB->Checked){
		TubiOn = true;
		NewThread(Tubi);
	}else{
		TubiOn = false;
	}
}

void MainForm::NoBreathCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(NoBreathCB->Checked){
		NoBreathOn = true;
		NewThread(NoBreath);
	}else{
		NoBreathOn = false;
	}
}

void MainForm::BLUACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(BLUACB->Checked){
		UAOn = true;
		NewThread(UnlimAtk);
	}else{
		UAOn = false;
	}
}

void MainForm::TeleUACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TeleUACB->Checked){
		teleUA = true;
		NewThread(TeleUA);
	}else{
		teleUA = false;
	}
}

void MainForm::MorphGMCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(MorphGMCB->Checked){
		morphGMOn = true;
		NewThread(MorphGM);
	}else{
		morphGMOn = false;
//		WritePointer(CharBase,MorphOff,0);
	}
}

void MainForm::MobDisarmCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(MobDisarmCB->Checked){
		//fGM(true);
	}else{
		//fGM(false);
	}
}

void MainForm::FMACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(FMACB->Checked){
//		fFMA(true);
	}else{
//		fFMA(false);
	}
}

void MainForm::NDFACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(NDFACB->Checked){
		
		if(NDFAAFACB->Checked){
			if(NDFAClassCombo->SelectedIndex == 0){
				NDFASkillID = 1120013;
			}
			else if(NDFAClassCombo->SelectedIndex == 3){
				NDFASkillID = 21120012;
			}
			else if(NDFAClassCombo->SelectedIndex == 4){
				NDFASkillID = 3120008;
			}
			else if(NDFAClassCombo->SelectedIndex == 7){
				NDFASkillID = 33120011;
			}
			else if(NDFAClassCombo->SelectedIndex == 8){
				NDFASkillID = 23120012;
			}
			else{
				NDFASkillID = GetSkillID(NDFAClassCombo->SelectedIndex);
			}
		}
		else{
			NDFASkillID = GetSkillID(NDFAClassCombo->SelectedIndex);
		}

		ndfaInterval = Convert::ToInt32(NDFASpeedText->Text);
		ndfaOn = true;
		NewThread(NDFA);
	}else{
		ndfaOn = false;
	}
}
#pragma endregion

#pragma region Kami/Kami Loot & Auto Loot Checkboxes

void MainForm::KamiCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(KamiCB->Checked){
		TeleDelay = Convert::ToInt32(KamiDelayText->Text);
		iRangeX = Convert::ToInt32(KamiXText->Text);
		iRangeY = Convert::ToInt32(KamiYText->Text);
		AutoLootVacGB->Enabled = false;
		_Kami(true);
	}else{
		Teleport(iOriginalX,iOriginalY);
		KillThread(Kami);
		AutoLootVacGB->Enabled = KamiLootCB->Checked ? false : true;
		_Kami(false);
	}
}

void MainForm::KamiLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(KamiLootCB->Checked){
		AutoLootVacGB->Enabled = false;
		KamiSetItems = Convert::ToInt32(this->KamiItemsText->Text);
		KamiLootDelay = Convert::ToInt32(this->KamiLootDelText->Text);
		kamiLoot = true;
	}else{
		kamiLoot = false;
		AutoLootVacGB->Enabled = KamiCB->Checked ? false : true;
	}
}

void MainForm::AutoLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoLootCB->Checked){
		KamiGroup->Enabled = false;
		AutoLootItems = Convert::ToInt32(this->AutoLootItemsText->Text);
		AutoLootDelay = Convert::ToInt32(this->AutoLootDelText->Text);
		autoLoot = true;
		NewThread(AutoLoot);
	}else{
		KamiGroup->Enabled = true;
		autoLoot = false;
	}
}

#pragma endregion

#pragma region Teleport (To Original Spot)

void MainForm::TeleportCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TeleportCB->Checked){
		ReturnX = Convert::ToInt32(TeleXText->Text);
		ReturnY = Convert::ToInt32(TeleYText->Text);
		returnToXY = true;
	}else{
		returnToXY = false;
	}
}

void MainForm::TeleDelayCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TeleDelayCB->Checked){
		TeleIntervalTimer->Interval = Convert::ToInt32(TeleDelayText->Text);
		TeleIntervalTimer->Enabled = true;
	}else{
		TeleIntervalTimer->Enabled = false;
	}
}

void MainForm::TeleIntervalTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	Teleport(ReturnX, ReturnY);
}

void MainForm::TeleGetPosBtn_Click(System::Object^  sender, System::EventArgs^  e){
	PressKey(0x28);

	Sleep(100);

	TeleXText->Text = ((short signed)(ReadPointer(CharBase,CharXOff))).ToString();
	TeleYText->Text = ((short signed)(ReadPointer(CharBase,CharYOff))).ToString();

	ReturnX = Convert::ToInt32(TeleXText->Text);
	ReturnY = Convert::ToInt32(TeleYText->Text);
}

void MainForm::TeleTeleBtn_Click(System::Object^  sender, System::EventArgs^  e){
	Teleport(ReturnX, ReturnY);
}

void MainForm::TeleportInfoBtn_Click(System::Object^  sender, System::EventArgs^  e){
	MessageBox::Show("What this allows you to do is"+
		" teleport back to the set spot after an auto CC, CS, or after Auto Loot."+
		" Only use this if you are not using Kami.\n\nThe \"Get Pos\" button allows you to get the"+
		" current position of your character.\n The Teleport button teleports you manually to the set location.", "Teleport Help", 
		MessageBoxButtons::OK, MessageBoxIcon::Question);
}

#pragma endregion

#pragma region Fixed Item Vac Checkbox + Button

void MainForm::ItemVacCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(ItemVacCB->Checked){
		itemVacX = Convert::ToInt32(ItemVacXText->Text);
		itemVacY = Convert::ToInt32(ItemVacYText->Text);
		fItemVac(true);
	}else{
		fItemVac(false);
	}
}

void MainForm::ItemVacGetPosBtn_Click(System::Object^  sender, System::EventArgs^  e){
	PressKey(0x28);

	Sleep(100);

	ItemVacXText->Text = ((short signed)(ReadPointer(CharBase,CharXOff))).ToString();
	ItemVacYText->Text = ((short signed)(ReadPointer(CharBase,CharYOff))).ToString();

	itemVacX = Convert::ToInt32(ItemVacXText->Text);
	itemVacY = Convert::ToInt32(ItemVacYText->Text);
}
#pragma endregion

#pragma region Other Vac Options

void MainForm::LootNoMobsCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(LootNoMobsCB->Checked){
		lootWhenNoMobs = true;
	}else{
		lootWhenNoMobs = false;
	}
}
void MainForm::KamiWallcheckCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(KamiWallcheckCB->Checked){
		wallCheck = true;
	}else{

		if(MessageBox::Show("Wallcheck is recommended if you want to avoid an autoban. \nDisabling it increases the chances greatly. "+
			"\n\nAre you sure you want to disable Kami Wallcheck?","Notice!",
			MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == ::DialogResult::No)
		{
			this->KamiWallcheckCB->Checked = true;
			return;
		}

		wallCheck = false;
	}
}

#pragma endregion

#pragma region Misc Random Stuff

void MainForm::FTFDelayCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(FTFDelayCB->Checked){
		FTFDelayTimer->Interval = Convert::ToInt32(FTFDelayText->Text)*60000 + 5500;
		FTFDelayTimer->Enabled = true;
	}else{
		FTFDelayTimer->Enabled = false;
	}
}

void MainForm::FTFDelayTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	ccing = true;
	usingSkill = true;
	wallCheck = false;
	Sleep(500);
	Teleport(ReadPointer(CharBase,CharXOff),ReadPointer(WallBase,BottomWallOff)+50);
	Sleep(5000);
	ccing = false;
	wallCheck = KamiWallcheckCB->Checked;
	usingSkill = false;
}

void MainForm::DisableKamiLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(DisableKamiLootCB->Checked){
		DisableKamiLootTimer->Interval = Convert::ToInt32(DisableLootText->Text)*60000;
		DisableKamiLootTimer->Enabled = true;
	}else{
		DisableKamiLootTimer->Enabled = false;
	}
}

void MainForm::DisableKamiLootTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	KamiLootCB->Checked = false;
	AutoLootCB->Checked = false;
	DisableKamiLootCB->Checked = false;

	DisableKamiLootTimer->Enabled = false;
}

void MainForm::AutoGourdCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(AutoGourdCB->Checked){
		
		MessageBox::Show("Make sure that you are standing next to Cassandra before enabling this. \n"+ 
			"For this to work you must also have your 'NPC Chat' key on 'Y'.\nDO NOT try botting while "+
			"you have this enabled as it will not work.\nThis is for AFK use only.\n\n"+
			"What this does is accept and complete the Tempest Gourd Quest from Cassandra every 30 minutes. "+
			"You can recieve 2 tempest coins per completion (or 4 if you are a Luminous) ... Enjoy", "Information");
		
		AutoGourdTimer->Enabled = true;
		NewThread(AutoGourdQuest);
	}else{
		AutoGourdTimer->Enabled = false;
		AutoGourdTimer2->Enabled = false;
	}
}

void MainForm::AutoGourdTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	NewThread(AutoGourdQuest);
	AutoGourdTimer->Enabled = false;
	AutoGourdTimer2->Enabled = true;
}

void MainForm::AutoGourdTimer2_Tick(System::Object^  sender, System::EventArgs^  e){
	NewThread(AutoGourdQuest);
	AutoGourdTimer->Enabled = true;
	AutoGourdTimer2->Enabled = false;
}

void MainForm::TeleWalkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TeleWalkCB->Checked){
		teleWalkDist = (int)TeleWalkUpDown->Value;
		teleWalk = true;
		NewThread(TeleportWalk);
	}else{
		teleWalk = false;
	}
}
#pragma endregion

#pragma region Timed Exit

void MainForm::TimedExitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TimedExitCB->Checked){
		TimedExitTimer->Interval = (Convert::ToInt32(TimedExitHoursText->Text)*3600000)+(Convert::ToInt32(TimedExitMinText->Text)*60000);
		TimedExitTimer->Enabled = true;
	}else{
		TimedExitTimer->Enabled = false;
	}
}

void MainForm::TimedExitTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	TerminateProcess(GetCurrentProcess(), 0);
}

#pragma endregion

#pragma region 2 Point Tele

void MainForm::TwoPointTeleCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(TwoPointTeleCB->Checked){
		point1X = Convert::ToInt32(TwoPointX1Text->Text);
		point2X = Convert::ToInt32(TwoPointX2Text->Text);
		point1Y = Convert::ToInt32(TwoPointY1Text->Text);
		point2Y = Convert::ToInt32(TwoPointY2Text->Text);
		twoPointInterval = Convert::ToInt32(TwoPointDlyText->Text);
		twoPointTele = true;

		NewThread(TwoPointTele);
	}else{
		twoPointTele = false;
	}
}

void MainForm::TwoPointGetPosBtn1_Click(System::Object^  sender, System::EventArgs^  e){
	PressKey(0x28);

	Sleep(100);

	TwoPointX1Text->Text = ((short signed)(ReadPointer(CharBase, CharXOff))).ToString();
	TwoPointY1Text->Text = ((short signed)(ReadPointer(CharBase,CharYOff))).ToString();

	point1X = Convert::ToInt32(TwoPointX1Text->Text);
	point1Y = Convert::ToInt32(TwoPointY1Text->Text);
}

void MainForm::TwoPointGetPosBtn2_Click(System::Object^  sender, System::EventArgs^  e){
	PressKey(0x28);

	Sleep(100);

	TwoPointX2Text->Text = ((short signed)(ReadPointer(CharBase, CharXOff))).ToString();
	TwoPointY2Text->Text = ((short signed)(ReadPointer(CharBase,CharYOff))).ToString();

	point2X = Convert::ToInt32(TwoPointX2Text->Text);
	point2Y = Convert::ToInt32(TwoPointY2Text->Text);
}

#pragma endregion

#pragma region Bypass NDFA Checkbox

void MainForm::BPNDFACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(BPNDFACB->Checked){

		if(BPNDFAAFACB->Checked){
			if(BPNDFACombo->SelectedIndex == 0){
				BPNDFASkillID = 1120013;
			}
			else if(BPNDFACombo->SelectedIndex == 3){
				BPNDFASkillID = 21120012;
			}
			else if(BPNDFACombo->SelectedIndex == 4){
				BPNDFASkillID = 3120008;
			}
			else if(BPNDFACombo->SelectedIndex == 6){
				BPNDFASkillID = 51120002;
			}
			else if(BPNDFACombo->SelectedIndex == 8){
				BPNDFASkillID = 33120011;
			}
			else if(BPNDFACombo->SelectedIndex == 9){
				BPNDFASkillID = 23120012;
			}
			else{
				BPNDFASkillID = BPGetSkillID(BPNDFACombo->SelectedIndex);
			}
		}
		else{
			BPNDFASkillID = BPGetSkillID(BPNDFACombo->SelectedIndex);
		}

		fNDFA(true);
	}else{
		fNDFA(false);
	}
}

#pragma endregion

#pragma region Save + Load Settings

void MainForm::saveSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){

	System::IO::StreamWriter^ sw = gcnew StreamWriter("HBSettings.txt");
	
	// TextBoxes
	sw->WriteLine(AutoHPText->Text);
	sw->WriteLine(AutoMPText->Text);
	sw->WriteLine(AutoCCText->Text);
	sw->WriteLine(AutoCSText->Text);
	sw->WriteLine(PeopleCCText->Text);
	sw->WriteLine(AutoAtkText->Text);
	sw->WriteLine(AutoSkill1Text->Text);
	sw->WriteLine(AutoSkill2Text->Text);
	sw->WriteLine(AutoSkill3Text->Text);
	sw->WriteLine(AutoSkill4Text->Text);
	sw->WriteLine(NDFASpeedText->Text);
	sw->WriteLine(KamiXText->Text);
	sw->WriteLine(KamiYText->Text);
	sw->WriteLine(KamiDelayText->Text);
	sw->WriteLine(KamiItemsText->Text);
	sw->WriteLine(KamiLootDelText->Text);
	sw->WriteLine(AutoLootItemsText->Text);
	sw->WriteLine(AutoLootDelText->Text);
	sw->WriteLine(TeleXText->Text);
	sw->WriteLine(TeleYText->Text);
	sw->WriteLine(TeleDelayText->Text);
	sw->WriteLine(ItemVacXText->Text);
	sw->WriteLine(ItemVacYText->Text);
	sw->WriteLine(FTFDelayText->Text);
	sw->WriteLine(DisableLootText->Text);

	// Comboboxes
	sw->WriteLine(AutoHPCombo->SelectedIndex);
	sw->WriteLine(AutoMPCombo->SelectedIndex);
	sw->WriteLine(AutoAtkCombo->SelectedIndex);
	sw->WriteLine(AutoSkill1Combo->SelectedIndex);
	sw->WriteLine(AutoSkill2Combo->SelectedIndex);
	sw->WriteLine(AutoSkill3Combo->SelectedIndex);
	sw->WriteLine(AutoSkill4Combo->SelectedIndex);
	sw->WriteLine(NDFAClassCombo->SelectedIndex);

	// Hack Checkboxes
	sw->WriteLine(AutoHPCB->Checked);
	sw->WriteLine(AutoMPCB->Checked);
	sw->WriteLine(ClickFlyCB->Checked);
	sw->WriteLine(TubiCB->Checked);
	sw->WriteLine(MorphGMCB->Checked);
	sw->WriteLine(NoBreathCB->Checked);
	sw->WriteLine(BLUACB->Checked);
	sw->WriteLine(TeleUACB->Checked);
	sw->WriteLine(MobDisarmCB->Checked);
	sw->WriteLine(FMACB->Checked);
	sw->WriteLine(DisableSkillWaitCB->Checked);

	sw->Close();

	MessageBox::Show("Settings Saved");
}

void MainForm::loadSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){

	System::IO::StreamReader^ sr = gcnew StreamReader("HBSettings.txt");
	
	// TextBoxes
	AutoHPText->Text = sr->ReadLine();
	AutoMPText->Text = sr->ReadLine();
	AutoCCText->Text = sr->ReadLine();
	AutoCSText->Text = sr->ReadLine();
	PeopleCCText->Text = sr->ReadLine();
	AutoAtkText->Text = sr->ReadLine();
	AutoSkill1Text->Text = sr->ReadLine();
	AutoSkill2Text->Text = sr->ReadLine();
	AutoSkill3Text->Text = sr->ReadLine();
	AutoSkill4Text->Text = sr->ReadLine();
	NDFASpeedText->Text = sr->ReadLine();
	KamiXText->Text = sr->ReadLine();
	KamiYText->Text = sr->ReadLine();
	KamiDelayText->Text = sr->ReadLine();
	KamiItemsText->Text = sr->ReadLine();
	KamiLootDelText->Text = sr->ReadLine();
	AutoLootItemsText->Text = sr->ReadLine();
	AutoLootDelText->Text = sr->ReadLine();
	TeleXText->Text = sr->ReadLine();
	TeleYText->Text = sr->ReadLine();
	TeleDelayText->Text = sr->ReadLine();
	ItemVacXText->Text = sr->ReadLine();
	ItemVacYText->Text = sr->ReadLine();
	FTFDelayText->Text = sr->ReadLine();
	DisableLootText->Text = sr->ReadLine();

	// Comboboxes
	AutoHPCombo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoMPCombo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoAtkCombo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoSkill1Combo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoSkill2Combo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoSkill3Combo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	AutoSkill4Combo->SelectedIndex = Convert::ToInt32(sr->ReadLine());
	NDFAClassCombo->SelectedIndex = Convert::ToInt32(sr->ReadLine());

	// Hack Checkboxes
	AutoHPCB->Checked = Convert::ToBoolean(sr->ReadLine());
	AutoMPCB->Checked = Convert::ToBoolean(sr->ReadLine());
	ClickFlyCB->Checked = Convert::ToBoolean(sr->ReadLine());
	TubiCB->Checked = Convert::ToBoolean(sr->ReadLine());
	MorphGMCB->Checked = Convert::ToBoolean(sr->ReadLine());
	NoBreathCB->Checked = Convert::ToBoolean(sr->ReadLine());
	BLUACB->Checked = Convert::ToBoolean(sr->ReadLine());
	TeleUACB->Checked = Convert::ToBoolean(sr->ReadLine());
	MobDisarmCB->Checked = Convert::ToBoolean(sr->ReadLine());
	FMACB->Checked = Convert::ToBoolean(sr->ReadLine());
	DisableSkillWaitCB->Checked = Convert::ToBoolean(sr->ReadLine());

	sr->Close();

	MessageBox::Show("Settings Loaded");
}
#pragma endregion

#pragma region Exit & Hide/Show MS

void MainForm::exitMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	TerminateProcess(GetCurrentProcess(), 0);
}

void MainForm::hideMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	if(hideMSToolStripMenuItem->Text == "Hide MS"){
		ShowWindow(MShwnd,SW_HIDE);
		hideMSToolStripMenuItem->Text = "Show MS";
	}
	else if(hideMSToolStripMenuItem->Text == "Show MS"){
		ShowWindow(MShwnd,SW_SHOW);

		hideMSToolStripMenuItem->Text = "Hide MS";
	}
}

#pragma endregion

#pragma region Attach to MS

void MainForm::attachToMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	MShwnd = FindWindowA("MapleStoryClass", 0);
}

#pragma endregion

#pragma region Hotkey Info + Hack Info

void MainForm::hotKeyInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	MessageBox::Show(" F7 - AutoAtk\n F8 - Click Fly\n F9 - Mob Disarm\n F10 - FMA\n F11 - Kami\n\n "+
		"Enable the use of Hotkeys \n by going to \n\n \"Tools > Enable Hotkeys\"", "Hotkey Info", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

void MainForm::hackInfoiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	MessageBox::Show("##### BYPASSLESS HACKS (DO NOT REQUIRE A BYPASS) #####\n"+
		"Click Fly - While holding the left mouse button down you will fly wherever your mouse pointer is at.\n"+
		"Tubi - Pick up items much faster than the default speed.\n"+
		"No Breath - No breathing after you get hit by a mob. Lets you do things like CC even when you just took damage.\n"+
		"UA - Unlimited attacks. You can stand in one spot and attack forever instead of only 100 times.\n"+
		"Tele UA - Once you reach a certain amount of attacks it teleports to a different spot, attacks, then teleports back.\n"+
		"Mob Disarm - Physical/Magical Mob Disarm. Take no damage when walking through mobs and from some magic attacks. \n"+
		"Some magic attacks will still hit you.\n"+
		"FMA - Full Map Attack. Attack the whole map (monsters in range) while standing in one spot.\n"+
		"Morph GM - Morph into a Doll which will allow you to take no damage, however, you cant attack with it enabled.\n"+
		"Kami - Continues to teleport to mob location at a user set interval.\n"+
		"Kami Loot - Teleports to items and picks them up across the entire map.\n"+
		"Teleport - Used to teleport back to a set spot after looting (mainly used for FMA botting)\n"+
		"Timed Exit - Will exit MapleStory after the time you set it to\n"+
		"Pointer Info - Displays information about the game. ex. HP, MP, Map ID, Channel, World, etc\n"+
		"Show/Hide MS - Will show or hide the MapleStory window\n"+
		"NDFA (No-Delay Final Attack) - After triggering Final Attack once it will continue to attack nonstop.\n\n"+

		"###### HACKS THAT REQUIRE A FULL HSCRC + MSCRC BYPASS #####\n"+
		"Full GM - Full Godmode. You wont take damage from any mobs even if they are aggroed to another player.\n"+
		"Multi Damage - Take constant damage while on top of a mob.\n"+
		"Air Loot - Loot an item while its still falling\n"+
		"Instant Drop - Items drop instantly\n"+
		"No Attack Limit - Disables the attack limit and lets you attack over 100 times\n"+
		"No Loot Animation - Loot items without the pickup animation\n"+
		"No Mob Lag - ?\n"+
		"Slow Mobs - Mobs walk very slow\n"+
		"UA - Unlimited Attacks\n"+
		"FLACC - Face left after CC\n"+
		"No KB - No Knockback from mobs\n"+
		"Hide Login - Will hide your login info on the login page\n"+
		"CPU Hack 1 - Hides MapleStory background images\n"+
		"CPU Hack 2 - Hides MapleStory background images and platforms as well as most other objects\n"+
		 "(excluding portals, items, and mobs)\n"+
		"Hide Damage - Hides the damage that you do to mobs (Sometimes shows 0's)\n"+
		"Item Vac - Vacs items dropped by mobs to a spot set by the user.","Hack Info", MessageBoxButtons::OK, MessageBoxIcon::Question);
}

#pragma endregion

#pragma region Enable Hotkeys

void MainForm::HotkeyTimer_Tick(System::Object^  sender, System::EventArgs^  e){
	if(GetAsyncKeyState(0x76)){
		if(this->AutoAtkCB->Checked == false){   // AutoAtk
			this->AutoAtkCB->Checked = true;
		}else{
			this->AutoAtkCB->Checked = false;
		}
	}

	if(GetAsyncKeyState(0x77)){
		if(this->ClickFlyCB->Checked == false){   // Click Fly Hotkey
			this->ClickFlyCB->Checked = true;
		}else{
			this->ClickFlyCB->Checked = false;
		}
	}

	if(GetAsyncKeyState(0x78)){
		if(this->MobDisarmCB->Checked == false){  // FGM Hotkey
			this->MobDisarmCB->Checked = true;
		}else{
			this->MobDisarmCB->Checked = false;
		}
	}

	if(GetAsyncKeyState(0x79)){
		if(this->FMACB->Checked == false){  // FMA Hotkey
			this->FMACB->Checked = true;
		}else{
			this->FMACB->Checked = false;
		}
	}

	if(GetAsyncKeyState(0x7A)){
		if(this->KamiCB->Checked == false){  // Kami Hotkey
			this->KamiCB->Checked = true;
		}else{
			this->KamiCB->Checked = false;
		}
	}
}

void MainForm::enableHotkeysToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
	
	if(this->enableHotkeysToolStripMenuItem->Text == "Enable Hotkeys"){
		this->HotkeyTimer->Enabled = true;
		this->enableHotkeysToolStripMenuItem->Text = "Disable Hotkeys";
	}
	else if(this->enableHotkeysToolStripMenuItem->Text == "Disable Hotkeys"){
		this->HotkeyTimer->Enabled = false;
		this->enableHotkeysToolStripMenuItem->Text = "Enable Hotkeys";
	}
}

#pragma endregion

#pragma region HPMPAlert Fix + Maple Window Find

void MainForm::HPMPAlertFix_Tick(System::Object^  sender, System::EventArgs^  e){
	if(ReadPointer(MapInfoBase, MapIDOff) != 0)
	{
		MShwnd = FindWindowA("MapleStoryClass", 0);
		WritePointer(AlertBase, HPAlertOff, 20);
		WritePointer(AlertBase, MPAlertOff, 20);
		HPMPAlertFix->Enabled = false;
	}
}

#pragma endregion