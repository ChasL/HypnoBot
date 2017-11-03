#include "PtrInfoForm.h"
#include "Functions.h"
#include "Pointers.h"
#include <Windows.h>
#include <cmath>
#include <math.h>

using namespace HypnoBot;

String^ GetWorld(int index){
	switch(index){
		case 0:	return	"Scania";		break; 
		case 1:	return	"Bera";			break; 
		case 2:	return	"Broa";			break; 
		case 3:	return	"Windia";		break; 
		case 4:	return	"Khani";		break; 
		case 5:	return	"Bellocan";		break; 
		case 6:	return	"Mardia";		break; 
		case 7:	return	"Kradia";		break; 
		case 8:	return	"Yellonde";		break; 
		case 9:	return	"Demethos";		break; 
		case 10: return	"Galicia";		break; 
		case 11: return	"El Nido";		break; 
		case 12: return	"Zenith";		break; 
		case 13: return	"Arcania";		break; 
		case 14: return	"Chaos";		break; 
		case 15: return	"Nova";			break; 
		case 16: return	"Renegades";	break;
		default: return "Joining...";	break;
	}
}

void PtrInfoForm::PtrInfoForm_VisibleChanged(System::Object^  sender, System::EventArgs^  e){
	PtrUpdateTimer->Enabled = this->Visible ? true : false;
	if(this->Visible == false){
		this->TopMost = false;
		StayOnTopCB->Checked = false;
	}
}

void PtrInfoForm::StayOnTopCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){
	if(StayOnTopCB->Checked == true){
		this->TopMost = true;
	}else{
		this->TopMost = false;
	}
}

void PtrInfoForm::PtrUpdateTimer_Tick(System::Object^  sender, System::EventArgs^  e){

#pragma region XY Strings
	String^ CharX = ((short signed)(ReadPointer(CharBase, CharXOff))).ToString();
	String^ CharY = ((short signed)(ReadPointer(CharBase, CharYOff))).ToString();
	String^ MouseX = ((short signed)(ReadIndefinitePointer(MouseBase, 2, MouseLocOff, MouseXOff))).ToString();
	String^ MouseY = ((short signed)(ReadIndefinitePointer(MouseBase, 2, MouseLocOff, MouseYOff))).ToString();
	//String^ TeleX = ((short signed)(ReadPointer(CharBase, TeleX))).ToString();
	//String^ TeleY = ((short signed)(ReadPointer(CharBase, TeleY))).ToString();
	String^ MobX = ((short signed)(ReadIndefinitePointer(MobBase, 5,  Mob1Off, Mob2Off, Mob3Off, Mob4Off, MobXOff))).ToString();
	String^ MobY = ((short signed)(ReadIndefinitePointer(MobBase, 5,  Mob1Off, Mob2Off, Mob3Off, Mob4Off, MobYOff))).ToString();
#pragma endregion

	double Exp = ReadPointerDouble(GUIBase, ExpOff);
	double ExpRnd = (Exp*100 - floor(Exp*100) > 0.49) ? ceil(Exp*100)/100 : floor(Exp*100)/100;

	this->HealthLabel->Text = "Health: "+(ReadPointer(GUIBase, HPOff)).ToString();
	this->ManaLabel->Text = "Mana: "+(ReadPointer(GUIBase, MPOff)).ToString();
	this->ExpLabel->Text = "Exp: "+ExpRnd.ToString()+"%";
	this->AttacksLabel->Text = "Attacks: "+(ReadPointer(CharBase, AtkCountOff)).ToString();
	this->BreathLabel->Text = "Breath: "+(ReadPointer(CharBase, BreathOff)).ToString();
	this->CharXYLabel->Text = "Char XY: ("+CharX+", "+CharY+")";
	this->MouseXYLabel->Text = "Mouse XY: ("+MouseX+", "+MouseY+")";
	this->TeleXYLabel->Text = "Tele XY: (0, 0)";

	if(ReadPointer(MapInfoBase, MapIDOff) != 0) this->WorldLabel->Text =  "World: "+GetWorld((int)ReadPointer(ServerBase,WorldOff));
	else this->WorldLabel->Text = "World: Joining...";

	this->ChannelLabel->Text =  "Channel: "+(ReadPointer(ServerBase,ChannelOff)+1).ToString();
	this->MapIDLabel->Text =  "Map ID: "+ReadPointer(MapInfoBase,MapIDOff).ToString();
	this->PeopleLabel->Text =  "People: "+ReadPointer(PeopleBase,PeopleCountOff).ToString();
	this->ItemsLabel->Text =  "Items: "+ReadPointer(ItemBase,ItemCountOff).ToString();
	this->ItemIDLabel->Text =  "Item ID: "+ReadPointer(CharBase, ItemIDOff).ToString();
	this->MobsLabel->Text =  "Mobs: "+ReadPointer(MobBase,MobCountOff).ToString();
	this->MobXYLabel->Text =  "Mob XY: ("+MobX+", "+MobY+")";
}

void PtrInfoForm::PtrInfoForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
{
	e->Cancel = true;
	this->Visible = false;
}


