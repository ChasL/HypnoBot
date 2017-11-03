#pragma once
#include <Windows.h>
#include "PtrInfoForm.h"
#include "AdvToolsForm.h"

namespace HypnoBot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	private: PtrInfoForm^ PntrInfoFrm;
	private: System::Windows::Forms::ToolStripMenuItem^  attachToMSToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  BPNDFAGroup;
	private: System::Windows::Forms::CheckBox^  BPNDFAAFACB;
	private: System::Windows::Forms::Label^  BPNDFAClassLabel;
	private: System::Windows::Forms::ComboBox^  BPNDFACombo;
	private: System::Windows::Forms::CheckBox^  BPNDFACB;
	private: System::Windows::Forms::CheckBox^  AutoGourdCB;
	private: System::Windows::Forms::Timer^  AutoGourdTimer;
	private: System::Windows::Forms::Timer^  AutoGourdTimer2;
	private: System::Windows::Forms::CheckBox^  TeleWalkCB;
	private: System::Windows::Forms::NumericUpDown^  TeleWalkUpDown;
	private: System::Windows::Forms::Label^  TeleWalkDistLabel;
	private: System::Windows::Forms::CheckBox^  UnlimKaiserCB;
	private: AdvToolsForm^ AdvToolsFrm;

	public:
		MainForm(void)
		{
			InitializeComponent();
			PntrInfoFrm = gcnew PtrInfoForm;
			AdvToolsFrm = gcnew AdvToolsForm;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected: 
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::RichTextBox^  InfoText;
	private: System::Windows::Forms::PictureBox^  Banner;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::GroupBox^  AutoCCGroup;
	private: System::Windows::Forms::TextBox^  PeopleCCText;
	private: System::Windows::Forms::TextBox^  AutoCSText;
	private: System::Windows::Forms::TextBox^  AutoCCText;
	private: System::Windows::Forms::CheckBox^  PeopleCCCB;
	private: System::Windows::Forms::CheckBox^  AutoCSCB;
	private: System::Windows::Forms::CheckBox^  AutoCCCB;
	private: System::Windows::Forms::GroupBox^  AutoKeyGroup;
	private: System::Windows::Forms::ComboBox^  AutoSkill4Combo;
	private: System::Windows::Forms::ComboBox^  AutoSkill3Combo;
	private: System::Windows::Forms::ComboBox^  AutoSkill2Combo;
	private: System::Windows::Forms::ComboBox^  AutoSkill1Combo;
	private: System::Windows::Forms::ComboBox^  AutoAtkCombo;
	private: System::Windows::Forms::TextBox^  AutoAtkText;
	private: System::Windows::Forms::TextBox^  AutoSkill1Text;
	private: System::Windows::Forms::TextBox^  AutoSkill2Text;
	private: System::Windows::Forms::TextBox^  AutoSkill3Text;
	private: System::Windows::Forms::TextBox^  AutoSkill4Text;
	private: System::Windows::Forms::CheckBox^  AutoAtkCB;
	private: System::Windows::Forms::CheckBox^  AutoSkill1CB;
	private: System::Windows::Forms::CheckBox^  AutoSkill2CB;
	private: System::Windows::Forms::CheckBox^  AutoSkill3CB;
	private: System::Windows::Forms::CheckBox^  AutoSkill4CB;
	private: System::Windows::Forms::GroupBox^  AutoPotGroup;
	private: System::Windows::Forms::ComboBox^  AutoHPCombo;
	private: System::Windows::Forms::ComboBox^  AutoMPCombo;
	private: System::Windows::Forms::TextBox^  AutoMPText;
	private: System::Windows::Forms::TextBox^  AutoHPText;
	private: System::Windows::Forms::CheckBox^  AutoMPCB;
	private: System::Windows::Forms::CheckBox^  AutoHPCB;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadSettingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitMSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pointerInfoToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  enableHotkeysToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  advancedToolsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hideMSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gKThreadToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  hotKeyInfoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hackInfoiToolStripMenuItem;
	private: System::Windows::Forms::Label^  PeopleCCLabel;
	private: System::Windows::Forms::Label^  AutoCSLabel;
	private: System::Windows::Forms::Label^  AutoCCLabel;
	private: System::Windows::Forms::Label^  AutoSkill4Label;
	private: System::Windows::Forms::Label^  AutoSkill3Label;
	private: System::Windows::Forms::Label^  AutoSkill2Label;
	private: System::Windows::Forms::Label^  AutoSkill1Label;
	private: System::Windows::Forms::Label^  AutoAtkLabel;
	private: System::Windows::Forms::Label^  AutoMPLabel;
	private: System::Windows::Forms::Label^  AutoHPLabel;
	private: System::Windows::Forms::GroupBox^  BypassHacksGB;
	private: System::Windows::Forms::GroupBox^  NDFAGroup;
	private: System::Windows::Forms::Label^  NDFASpeedLabel;
	private: System::Windows::Forms::Label^  NDFAClassLabel;
	private: System::Windows::Forms::ComboBox^  NDFAClassCombo;
	private: System::Windows::Forms::TextBox^  NDFASpeedText;
	private: System::Windows::Forms::CheckBox^  NDFAAFACB;
	private: System::Windows::Forms::CheckBox^  NDFACB;
	private: System::Windows::Forms::GroupBox^  BypasslessHacksGB;
	private: System::Windows::Forms::Label^  AutoBanLabel;
	private: System::Windows::Forms::CheckBox^  FMACB;
	private: System::Windows::Forms::CheckBox^  MobDisarmCB;
	private: System::Windows::Forms::CheckBox^  TeleUACB;
	private: System::Windows::Forms::CheckBox^  BLUACB;
	private: System::Windows::Forms::CheckBox^  NoBreathCB;
	private: System::Windows::Forms::CheckBox^  MorphGMCB;
	private: System::Windows::Forms::CheckBox^  TubiCB;
	private: System::Windows::Forms::CheckBox^  ClickFlyCB;
private: System::Windows::Forms::Label^  MadeByLabel;
private: System::Windows::Forms::LinkLabel^  GKLinkLabel;
private: System::Windows::Forms::CheckBox^  HideDamageCB;
private: System::Windows::Forms::CheckBox^  CPUHack2CB;
private: System::Windows::Forms::CheckBox^  CPUHack1CB;


private: System::Windows::Forms::CheckBox^  SlowMobsCB;

private: System::Windows::Forms::CheckBox^  InstantDropCB;
private: System::Windows::Forms::CheckBox^  NoKBCB;
private: System::Windows::Forms::CheckBox^  NoMobLagCB;
private: System::Windows::Forms::CheckBox^  AirLootCB;
private: System::Windows::Forms::CheckBox^  FLACCCB;
private: System::Windows::Forms::CheckBox^  NoLootAnimCB;
private: System::Windows::Forms::CheckBox^  MultiDmgCB;
private: System::Windows::Forms::CheckBox^  UnlimAtkCB;
private: System::Windows::Forms::CheckBox^  NoAtkLimitCB;
private: System::Windows::Forms::CheckBox^  FullGMCB;
private: System::Windows::Forms::GroupBox^  OtherVacGroup;
private: System::Windows::Forms::GroupBox^  ItemVacGroup;
private: System::Windows::Forms::GroupBox^  TeleportGroup;
private: System::Windows::Forms::GroupBox^  AutoLootVacGB;
private: System::Windows::Forms::GroupBox^  KamiGroup;
private: System::Windows::Forms::CheckBox^  LootNoMobsCB;
private: System::Windows::Forms::CheckBox^  KamiWallcheckCB;


private: System::Windows::Forms::CheckBox^  LootBfrCCCB;

private: System::Windows::Forms::Label^  ItemVacDescLabel;
private: System::Windows::Forms::CheckBox^  ItemVacCB;
private: System::Windows::Forms::Label^  ItemVacYLabel;
private: System::Windows::Forms::Label^  ItemVacXLabel;
private: System::Windows::Forms::TextBox^  ItemVacYText;
private: System::Windows::Forms::TextBox^  ItemVacXText;
private: System::Windows::Forms::Button^  ItemVacGetPosBtn;
private: System::Windows::Forms::Button^  TeleportInfoBtn;

private: System::Windows::Forms::Label^  TeleMSLabel;
private: System::Windows::Forms::TextBox^  TeleDelayText;
private: System::Windows::Forms::CheckBox^  TeleDelayCB;
private: System::Windows::Forms::Button^  TeleTeleBtn;
private: System::Windows::Forms::Button^  TeleGetPosBtn;
private: System::Windows::Forms::CheckBox^  TeleportCB;
private: System::Windows::Forms::TextBox^  TeleXText;
private: System::Windows::Forms::TextBox^  TeleYText;
private: System::Windows::Forms::Label^  TeleXLabel;
private: System::Windows::Forms::Label^  TeleYLabel;
private: System::Windows::Forms::Label^  AutoLootItemLabel;
private: System::Windows::Forms::CheckBox^  AutoLootCB;
private: System::Windows::Forms::Label^  AutoLootDelLabel;
private: System::Windows::Forms::TextBox^  AutoLootDelText;
private: System::Windows::Forms::TextBox^  AutoLootItemsText;

private: System::Windows::Forms::Label^  KamiItemLabel;
private: System::Windows::Forms::Label^  KamiLootDelLabel;
private: System::Windows::Forms::Label^  KamiDelayLabel;
private: System::Windows::Forms::TextBox^  KamiItemsText;

private: System::Windows::Forms::Label^  KamiYLabel;
private: System::Windows::Forms::Label^  KamiXLabel;
private: System::Windows::Forms::TextBox^  KamiLootDelText;
private: System::Windows::Forms::TextBox^  KamiYText;
private: System::Windows::Forms::TextBox^  KamiDelayText;
private: System::Windows::Forms::TextBox^  KamiXText;
private: System::Windows::Forms::CheckBox^  KamiCB;
private: System::Windows::Forms::CheckBox^  KamiLootCB;
private: System::Windows::Forms::GroupBox^  TwoPointTeleGB;
private: System::Windows::Forms::GroupBox^  MiscRandomGroup;
private: System::Windows::Forms::CheckBox^  DisableSkillWaitCB;

private: System::Windows::Forms::CheckBox^  DisableKamiLootCB;

private: System::Windows::Forms::CheckBox^  FTFDelayCB;
private: System::Windows::Forms::TextBox^  DisableLootText;
private: System::Windows::Forms::CheckBox^  TwoPointTeleCB;


private: System::Windows::Forms::TextBox^  FTFDelayText;
private: System::Windows::Forms::Label^  TwoPointDlyLabel2;

private: System::Windows::Forms::TextBox^  TwoPointDlyText;

private: System::Windows::Forms::Label^  TwoPointDlyLabel;
private: System::Windows::Forms::Button^  TwoPointGetPosBtn2;


private: System::Windows::Forms::Button^  TwoPointGetPosBtn1;

private: System::Windows::Forms::Label^  TwoPointYLabel;

private: System::Windows::Forms::Label^  TwoPointXLabel;
private: System::Windows::Forms::TextBox^  TwoPointX1Text;
private: System::Windows::Forms::TextBox^  TwoPointY2Text;



private: System::Windows::Forms::TextBox^  TwoPointY1Text;

private: System::Windows::Forms::TextBox^  TwoPointX2Text;
private: System::Windows::Forms::ToolStripMenuItem^  hypnoBotBlogToolStripMenuItem;
private: System::Windows::Forms::Timer^  HPMPAlertFix;
private: System::Windows::Forms::Timer^  AutoSkill1Timer;
private: System::Windows::Forms::Timer^  AutoSkill2Timer;
private: System::Windows::Forms::Timer^  AutoSkill3Timer;
private: System::Windows::Forms::Timer^  AutoSkill4Timer;
private: System::Windows::Forms::Timer^  TeleIntervalTimer;
private: System::Windows::Forms::Timer^  FTFDelayTimer;
private: System::Windows::Forms::Timer^  DisableKamiLootTimer;

private: System::Windows::Forms::Timer^  HotkeyTimer;
private: System::Windows::Forms::GroupBox^  TimedExitGroup;
private: System::Windows::Forms::Label^  TimedExitMinLabel;
private: System::Windows::Forms::Label^  TimedExitHoursLabel;
private: System::Windows::Forms::TextBox^  TimedExitMinText;
private: System::Windows::Forms::TextBox^  TimedExitHoursText;
private: System::Windows::Forms::CheckBox^  TimedExitCB;
private: System::Windows::Forms::Timer^  TimedExitTimer;
private: System::ComponentModel::IContainer^  components;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->InfoText = (gcnew System::Windows::Forms::RichTextBox());
			this->Banner = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->AutoCCGroup = (gcnew System::Windows::Forms::GroupBox());
			this->PeopleCCLabel = (gcnew System::Windows::Forms::Label());
			this->AutoCSLabel = (gcnew System::Windows::Forms::Label());
			this->AutoCCLabel = (gcnew System::Windows::Forms::Label());
			this->PeopleCCText = (gcnew System::Windows::Forms::TextBox());
			this->AutoCSText = (gcnew System::Windows::Forms::TextBox());
			this->AutoCCText = (gcnew System::Windows::Forms::TextBox());
			this->PeopleCCCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoCSCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoCCCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoKeyGroup = (gcnew System::Windows::Forms::GroupBox());
			this->AutoSkill4Label = (gcnew System::Windows::Forms::Label());
			this->AutoSkill3Label = (gcnew System::Windows::Forms::Label());
			this->AutoSkill2Label = (gcnew System::Windows::Forms::Label());
			this->AutoSkill1Label = (gcnew System::Windows::Forms::Label());
			this->AutoAtkLabel = (gcnew System::Windows::Forms::Label());
			this->AutoSkill4Combo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoSkill3Combo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoSkill2Combo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoSkill1Combo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoAtkCombo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoAtkText = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill1Text = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill2Text = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill3Text = (gcnew System::Windows::Forms::TextBox());
			this->AutoSkill4Text = (gcnew System::Windows::Forms::TextBox());
			this->AutoAtkCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill1CB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill2CB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill3CB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoSkill4CB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoPotGroup = (gcnew System::Windows::Forms::GroupBox());
			this->AutoMPLabel = (gcnew System::Windows::Forms::Label());
			this->AutoHPLabel = (gcnew System::Windows::Forms::Label());
			this->AutoHPCombo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoMPCombo = (gcnew System::Windows::Forms::ComboBox());
			this->AutoMPText = (gcnew System::Windows::Forms::TextBox());
			this->AutoHPText = (gcnew System::Windows::Forms::TextBox());
			this->AutoMPCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoHPCB = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->BypassHacksGB = (gcnew System::Windows::Forms::GroupBox());
			this->HideDamageCB = (gcnew System::Windows::Forms::CheckBox());
			this->CPUHack2CB = (gcnew System::Windows::Forms::CheckBox());
			this->CPUHack1CB = (gcnew System::Windows::Forms::CheckBox());
			this->UnlimKaiserCB = (gcnew System::Windows::Forms::CheckBox());
			this->SlowMobsCB = (gcnew System::Windows::Forms::CheckBox());
			this->InstantDropCB = (gcnew System::Windows::Forms::CheckBox());
			this->NoKBCB = (gcnew System::Windows::Forms::CheckBox());
			this->NoMobLagCB = (gcnew System::Windows::Forms::CheckBox());
			this->AirLootCB = (gcnew System::Windows::Forms::CheckBox());
			this->FLACCCB = (gcnew System::Windows::Forms::CheckBox());
			this->NoLootAnimCB = (gcnew System::Windows::Forms::CheckBox());
			this->MultiDmgCB = (gcnew System::Windows::Forms::CheckBox());
			this->UnlimAtkCB = (gcnew System::Windows::Forms::CheckBox());
			this->NoAtkLimitCB = (gcnew System::Windows::Forms::CheckBox());
			this->FullGMCB = (gcnew System::Windows::Forms::CheckBox());
			this->NDFAGroup = (gcnew System::Windows::Forms::GroupBox());
			this->NDFASpeedLabel = (gcnew System::Windows::Forms::Label());
			this->NDFAClassLabel = (gcnew System::Windows::Forms::Label());
			this->NDFAClassCombo = (gcnew System::Windows::Forms::ComboBox());
			this->NDFASpeedText = (gcnew System::Windows::Forms::TextBox());
			this->NDFAAFACB = (gcnew System::Windows::Forms::CheckBox());
			this->NDFACB = (gcnew System::Windows::Forms::CheckBox());
			this->BypasslessHacksGB = (gcnew System::Windows::Forms::GroupBox());
			this->AutoBanLabel = (gcnew System::Windows::Forms::Label());
			this->FMACB = (gcnew System::Windows::Forms::CheckBox());
			this->MobDisarmCB = (gcnew System::Windows::Forms::CheckBox());
			this->TeleUACB = (gcnew System::Windows::Forms::CheckBox());
			this->BLUACB = (gcnew System::Windows::Forms::CheckBox());
			this->NoBreathCB = (gcnew System::Windows::Forms::CheckBox());
			this->MorphGMCB = (gcnew System::Windows::Forms::CheckBox());
			this->TubiCB = (gcnew System::Windows::Forms::CheckBox());
			this->ClickFlyCB = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->OtherVacGroup = (gcnew System::Windows::Forms::GroupBox());
			this->LootNoMobsCB = (gcnew System::Windows::Forms::CheckBox());
			this->KamiWallcheckCB = (gcnew System::Windows::Forms::CheckBox());
			this->LootBfrCCCB = (gcnew System::Windows::Forms::CheckBox());
			this->ItemVacGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ItemVacDescLabel = (gcnew System::Windows::Forms::Label());
			this->ItemVacCB = (gcnew System::Windows::Forms::CheckBox());
			this->ItemVacYLabel = (gcnew System::Windows::Forms::Label());
			this->ItemVacXLabel = (gcnew System::Windows::Forms::Label());
			this->ItemVacYText = (gcnew System::Windows::Forms::TextBox());
			this->ItemVacXText = (gcnew System::Windows::Forms::TextBox());
			this->ItemVacGetPosBtn = (gcnew System::Windows::Forms::Button());
			this->TeleportGroup = (gcnew System::Windows::Forms::GroupBox());
			this->TeleportInfoBtn = (gcnew System::Windows::Forms::Button());
			this->TeleMSLabel = (gcnew System::Windows::Forms::Label());
			this->TeleDelayText = (gcnew System::Windows::Forms::TextBox());
			this->TeleDelayCB = (gcnew System::Windows::Forms::CheckBox());
			this->TeleTeleBtn = (gcnew System::Windows::Forms::Button());
			this->TeleGetPosBtn = (gcnew System::Windows::Forms::Button());
			this->TeleportCB = (gcnew System::Windows::Forms::CheckBox());
			this->TeleXText = (gcnew System::Windows::Forms::TextBox());
			this->TeleYText = (gcnew System::Windows::Forms::TextBox());
			this->TeleXLabel = (gcnew System::Windows::Forms::Label());
			this->TeleYLabel = (gcnew System::Windows::Forms::Label());
			this->AutoLootVacGB = (gcnew System::Windows::Forms::GroupBox());
			this->AutoLootItemLabel = (gcnew System::Windows::Forms::Label());
			this->AutoLootCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoLootDelLabel = (gcnew System::Windows::Forms::Label());
			this->AutoLootDelText = (gcnew System::Windows::Forms::TextBox());
			this->AutoLootItemsText = (gcnew System::Windows::Forms::TextBox());
			this->KamiGroup = (gcnew System::Windows::Forms::GroupBox());
			this->KamiItemLabel = (gcnew System::Windows::Forms::Label());
			this->KamiLootDelLabel = (gcnew System::Windows::Forms::Label());
			this->KamiDelayLabel = (gcnew System::Windows::Forms::Label());
			this->KamiItemsText = (gcnew System::Windows::Forms::TextBox());
			this->KamiYLabel = (gcnew System::Windows::Forms::Label());
			this->KamiXLabel = (gcnew System::Windows::Forms::Label());
			this->KamiLootDelText = (gcnew System::Windows::Forms::TextBox());
			this->KamiYText = (gcnew System::Windows::Forms::TextBox());
			this->KamiDelayText = (gcnew System::Windows::Forms::TextBox());
			this->KamiXText = (gcnew System::Windows::Forms::TextBox());
			this->KamiCB = (gcnew System::Windows::Forms::CheckBox());
			this->KamiLootCB = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->BPNDFAGroup = (gcnew System::Windows::Forms::GroupBox());
			this->BPNDFAAFACB = (gcnew System::Windows::Forms::CheckBox());
			this->BPNDFAClassLabel = (gcnew System::Windows::Forms::Label());
			this->BPNDFACombo = (gcnew System::Windows::Forms::ComboBox());
			this->BPNDFACB = (gcnew System::Windows::Forms::CheckBox());
			this->TimedExitGroup = (gcnew System::Windows::Forms::GroupBox());
			this->TimedExitMinLabel = (gcnew System::Windows::Forms::Label());
			this->TimedExitHoursLabel = (gcnew System::Windows::Forms::Label());
			this->TimedExitMinText = (gcnew System::Windows::Forms::TextBox());
			this->TimedExitHoursText = (gcnew System::Windows::Forms::TextBox());
			this->TimedExitCB = (gcnew System::Windows::Forms::CheckBox());
			this->DisableLootText = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointTeleGB = (gcnew System::Windows::Forms::GroupBox());
			this->TwoPointDlyLabel2 = (gcnew System::Windows::Forms::Label());
			this->TwoPointDlyText = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointDlyLabel = (gcnew System::Windows::Forms::Label());
			this->TwoPointGetPosBtn2 = (gcnew System::Windows::Forms::Button());
			this->TwoPointGetPosBtn1 = (gcnew System::Windows::Forms::Button());
			this->TwoPointYLabel = (gcnew System::Windows::Forms::Label());
			this->TwoPointXLabel = (gcnew System::Windows::Forms::Label());
			this->TwoPointX1Text = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointY2Text = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointY1Text = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointX2Text = (gcnew System::Windows::Forms::TextBox());
			this->TwoPointTeleCB = (gcnew System::Windows::Forms::CheckBox());
			this->MiscRandomGroup = (gcnew System::Windows::Forms::GroupBox());
			this->TeleWalkUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->TeleWalkDistLabel = (gcnew System::Windows::Forms::Label());
			this->TeleWalkCB = (gcnew System::Windows::Forms::CheckBox());
			this->AutoGourdCB = (gcnew System::Windows::Forms::CheckBox());
			this->FTFDelayText = (gcnew System::Windows::Forms::TextBox());
			this->DisableSkillWaitCB = (gcnew System::Windows::Forms::CheckBox());
			this->DisableKamiLootCB = (gcnew System::Windows::Forms::CheckBox());
			this->FTFDelayCB = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitMSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pointerInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->advancedToolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->enableHotkeysToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->attachToMSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hideMSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hypnoBotBlogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gKThreadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hotKeyInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hackInfoiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MadeByLabel = (gcnew System::Windows::Forms::Label());
			this->GKLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->HPMPAlertFix = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoSkill1Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoSkill2Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoSkill3Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoSkill4Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->TeleIntervalTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->FTFDelayTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->DisableKamiLootTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->HotkeyTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimedExitTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoGourdTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->AutoGourdTimer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Banner))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->AutoCCGroup->SuspendLayout();
			this->AutoKeyGroup->SuspendLayout();
			this->AutoPotGroup->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->BypassHacksGB->SuspendLayout();
			this->NDFAGroup->SuspendLayout();
			this->BypasslessHacksGB->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->OtherVacGroup->SuspendLayout();
			this->ItemVacGroup->SuspendLayout();
			this->TeleportGroup->SuspendLayout();
			this->AutoLootVacGB->SuspendLayout();
			this->KamiGroup->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->BPNDFAGroup->SuspendLayout();
			this->TimedExitGroup->SuspendLayout();
			this->TwoPointTeleGB->SuspendLayout();
			this->MiscRandomGroup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TeleWalkUpDown))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(329, 322);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tabPage1->Controls->Add(this->InfoText);
			this->tabPage1->Controls->Add(this->Banner);
			this->tabPage1->Location = System::Drawing::Point(4, 23);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(321, 295);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Info";
			// 
			// InfoText
			// 
			this->InfoText->BackColor = System::Drawing::SystemColors::MenuBar;
			this->InfoText->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InfoText->Location = System::Drawing::Point(6, 69);
			this->InfoText->Name = L"InfoText";
			this->InfoText->ReadOnly = true;
			this->InfoText->Size = System::Drawing::Size(307, 220);
			this->InfoText->TabIndex = 3;
			this->InfoText->Text = L"- Updated for GMS v.148.2\n\n- I GOT BORED AND WANTED TO DO SOMETHING.\nTHAT SOMETHI" 
				L"NG ENDED UP BEING ME UPDATING\nYEAR OLD BOT WITH BASICALLY NO FEATURES.\n\n... I mi" 
				L"ght add all the other public stuff.";
			// 
			// Banner
			// 
			this->Banner->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"Banner.Image")));
			this->Banner->Location = System::Drawing::Point(0, 0);
			this->Banner->Name = L"Banner";
			this->Banner->Size = System::Drawing::Size(320, 63);
			this->Banner->TabIndex = 2;
			this->Banner->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tabPage2->Controls->Add(this->AutoCCGroup);
			this->tabPage2->Controls->Add(this->AutoKeyGroup);
			this->tabPage2->Controls->Add(this->AutoPotGroup);
			this->tabPage2->Location = System::Drawing::Point(4, 23);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(321, 295);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Autos";
			// 
			// AutoCCGroup
			// 
			this->AutoCCGroup->Controls->Add(this->PeopleCCLabel);
			this->AutoCCGroup->Controls->Add(this->AutoCSLabel);
			this->AutoCCGroup->Controls->Add(this->AutoCCLabel);
			this->AutoCCGroup->Controls->Add(this->PeopleCCText);
			this->AutoCCGroup->Controls->Add(this->AutoCSText);
			this->AutoCCGroup->Controls->Add(this->AutoCCText);
			this->AutoCCGroup->Controls->Add(this->PeopleCCCB);
			this->AutoCCGroup->Controls->Add(this->AutoCSCB);
			this->AutoCCGroup->Controls->Add(this->AutoCCCB);
			this->AutoCCGroup->Enabled = false;
			this->AutoCCGroup->Location = System::Drawing::Point(6, 68);
			this->AutoCCGroup->Name = L"AutoCCGroup";
			this->AutoCCGroup->Size = System::Drawing::Size(309, 89);
			this->AutoCCGroup->TabIndex = 0;
			this->AutoCCGroup->TabStop = false;
			// 
			// PeopleCCLabel
			// 
			this->PeopleCCLabel->AutoSize = true;
			this->PeopleCCLabel->Location = System::Drawing::Point(166, 64);
			this->PeopleCCLabel->Name = L"PeopleCCLabel";
			this->PeopleCCLabel->Size = System::Drawing::Size(81, 14);
			this->PeopleCCLabel->TabIndex = 8;
			this->PeopleCCLabel->Text = L"People Amount:";
			// 
			// AutoCSLabel
			// 
			this->AutoCSLabel->AutoSize = true;
			this->AutoCSLabel->Location = System::Drawing::Point(157, 40);
			this->AutoCSLabel->Name = L"AutoCSLabel";
			this->AutoCSLabel->Size = System::Drawing::Size(90, 14);
			this->AutoCSLabel->TabIndex = 7;
			this->AutoCSLabel->Text = L"Delay (seconds):";
			// 
			// AutoCCLabel
			// 
			this->AutoCCLabel->AutoSize = true;
			this->AutoCCLabel->Location = System::Drawing::Point(157, 16);
			this->AutoCCLabel->Name = L"AutoCCLabel";
			this->AutoCCLabel->Size = System::Drawing::Size(90, 14);
			this->AutoCCLabel->TabIndex = 6;
			this->AutoCCLabel->Text = L"Delay (seconds):";
			// 
			// PeopleCCText
			// 
			this->PeopleCCText->Location = System::Drawing::Point(250, 61);
			this->PeopleCCText->Name = L"PeopleCCText";
			this->PeopleCCText->Size = System::Drawing::Size(52, 20);
			this->PeopleCCText->TabIndex = 5;
			this->PeopleCCText->Text = L"1";
			this->PeopleCCText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoCSText
			// 
			this->AutoCSText->Location = System::Drawing::Point(250, 37);
			this->AutoCSText->Name = L"AutoCSText";
			this->AutoCSText->Size = System::Drawing::Size(52, 20);
			this->AutoCSText->TabIndex = 4;
			this->AutoCSText->Text = L"0";
			this->AutoCSText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoCCText
			// 
			this->AutoCCText->Location = System::Drawing::Point(250, 13);
			this->AutoCCText->Name = L"AutoCCText";
			this->AutoCCText->Size = System::Drawing::Size(52, 20);
			this->AutoCCText->TabIndex = 3;
			this->AutoCCText->Text = L"0";
			this->AutoCCText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// PeopleCCCB
			// 
			this->PeopleCCCB->AutoSize = true;
			this->PeopleCCCB->Location = System::Drawing::Point(9, 63);
			this->PeopleCCCB->Name = L"PeopleCCCB";
			this->PeopleCCCB->Size = System::Drawing::Size(75, 18);
			this->PeopleCCCB->TabIndex = 2;
			this->PeopleCCCB->Text = L"People CC";
			this->PeopleCCCB->UseVisualStyleBackColor = true;
			this->PeopleCCCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PeopleCCCB_CheckedChanged);
			// 
			// AutoCSCB
			// 
			this->AutoCSCB->AutoSize = true;
			this->AutoCSCB->Location = System::Drawing::Point(9, 39);
			this->AutoCSCB->Name = L"AutoCSCB";
			this->AutoCSCB->Size = System::Drawing::Size(66, 18);
			this->AutoCSCB->TabIndex = 1;
			this->AutoCSCB->Text = L"Auto CS";
			this->AutoCSCB->UseVisualStyleBackColor = true;
			this->AutoCSCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoCSCB_CheckedChanged);
			// 
			// AutoCCCB
			// 
			this->AutoCCCB->AutoSize = true;
			this->AutoCCCB->Location = System::Drawing::Point(9, 15);
			this->AutoCCCB->Name = L"AutoCCCB";
			this->AutoCCCB->Size = System::Drawing::Size(66, 18);
			this->AutoCCCB->TabIndex = 0;
			this->AutoCCCB->Text = L"Auto CC";
			this->AutoCCCB->UseVisualStyleBackColor = true;
			this->AutoCCCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoCCCB_CheckedChanged);
			// 
			// AutoKeyGroup
			// 
			this->AutoKeyGroup->Controls->Add(this->AutoSkill4Label);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill3Label);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill2Label);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill1Label);
			this->AutoKeyGroup->Controls->Add(this->AutoAtkLabel);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill4Combo);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill3Combo);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill2Combo);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill1Combo);
			this->AutoKeyGroup->Controls->Add(this->AutoAtkCombo);
			this->AutoKeyGroup->Controls->Add(this->AutoAtkText);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill1Text);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill2Text);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill3Text);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill4Text);
			this->AutoKeyGroup->Controls->Add(this->AutoAtkCB);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill1CB);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill2CB);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill3CB);
			this->AutoKeyGroup->Controls->Add(this->AutoSkill4CB);
			this->AutoKeyGroup->Location = System::Drawing::Point(6, 156);
			this->AutoKeyGroup->Name = L"AutoKeyGroup";
			this->AutoKeyGroup->Size = System::Drawing::Size(309, 135);
			this->AutoKeyGroup->TabIndex = 0;
			this->AutoKeyGroup->TabStop = false;
			// 
			// AutoSkill4Label
			// 
			this->AutoSkill4Label->AutoSize = true;
			this->AutoSkill4Label->Location = System::Drawing::Point(95, 112);
			this->AutoSkill4Label->Name = L"AutoSkill4Label";
			this->AutoSkill4Label->Size = System::Drawing::Size(62, 14);
			this->AutoSkill4Label->TabIndex = 18;
			this->AutoSkill4Label->Text = L"Delay (ms):";
			// 
			// AutoSkill3Label
			// 
			this->AutoSkill3Label->AutoSize = true;
			this->AutoSkill3Label->Location = System::Drawing::Point(95, 87);
			this->AutoSkill3Label->Name = L"AutoSkill3Label";
			this->AutoSkill3Label->Size = System::Drawing::Size(62, 14);
			this->AutoSkill3Label->TabIndex = 17;
			this->AutoSkill3Label->Text = L"Delay (ms):";
			// 
			// AutoSkill2Label
			// 
			this->AutoSkill2Label->AutoSize = true;
			this->AutoSkill2Label->Location = System::Drawing::Point(95, 64);
			this->AutoSkill2Label->Name = L"AutoSkill2Label";
			this->AutoSkill2Label->Size = System::Drawing::Size(62, 14);
			this->AutoSkill2Label->TabIndex = 16;
			this->AutoSkill2Label->Text = L"Delay (ms):";
			// 
			// AutoSkill1Label
			// 
			this->AutoSkill1Label->AutoSize = true;
			this->AutoSkill1Label->Location = System::Drawing::Point(95, 40);
			this->AutoSkill1Label->Name = L"AutoSkill1Label";
			this->AutoSkill1Label->Size = System::Drawing::Size(62, 14);
			this->AutoSkill1Label->TabIndex = 15;
			this->AutoSkill1Label->Text = L"Delay (ms):";
			// 
			// AutoAtkLabel
			// 
			this->AutoAtkLabel->AutoSize = true;
			this->AutoAtkLabel->Location = System::Drawing::Point(95, 16);
			this->AutoAtkLabel->Name = L"AutoAtkLabel";
			this->AutoAtkLabel->Size = System::Drawing::Size(62, 14);
			this->AutoAtkLabel->TabIndex = 14;
			this->AutoAtkLabel->Text = L"Delay (ms):";
			// 
			// AutoSkill4Combo
			// 
			this->AutoSkill4Combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill4Combo->FormattingEnabled = true;
			this->AutoSkill4Combo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoSkill4Combo->Location = System::Drawing::Point(223, 108);
			this->AutoSkill4Combo->Name = L"AutoSkill4Combo";
			this->AutoSkill4Combo->Size = System::Drawing::Size(79, 22);
			this->AutoSkill4Combo->TabIndex = 13;
			// 
			// AutoSkill3Combo
			// 
			this->AutoSkill3Combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill3Combo->FormattingEnabled = true;
			this->AutoSkill3Combo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoSkill3Combo->Location = System::Drawing::Point(223, 84);
			this->AutoSkill3Combo->Name = L"AutoSkill3Combo";
			this->AutoSkill3Combo->Size = System::Drawing::Size(79, 22);
			this->AutoSkill3Combo->TabIndex = 12;
			// 
			// AutoSkill2Combo
			// 
			this->AutoSkill2Combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill2Combo->FormattingEnabled = true;
			this->AutoSkill2Combo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoSkill2Combo->Location = System::Drawing::Point(223, 60);
			this->AutoSkill2Combo->Name = L"AutoSkill2Combo";
			this->AutoSkill2Combo->Size = System::Drawing::Size(79, 22);
			this->AutoSkill2Combo->TabIndex = 11;
			// 
			// AutoSkill1Combo
			// 
			this->AutoSkill1Combo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoSkill1Combo->FormattingEnabled = true;
			this->AutoSkill1Combo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoSkill1Combo->Location = System::Drawing::Point(223, 36);
			this->AutoSkill1Combo->Name = L"AutoSkill1Combo";
			this->AutoSkill1Combo->Size = System::Drawing::Size(79, 22);
			this->AutoSkill1Combo->TabIndex = 10;
			// 
			// AutoAtkCombo
			// 
			this->AutoAtkCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoAtkCombo->FormattingEnabled = true;
			this->AutoAtkCombo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoAtkCombo->Location = System::Drawing::Point(223, 12);
			this->AutoAtkCombo->Name = L"AutoAtkCombo";
			this->AutoAtkCombo->Size = System::Drawing::Size(79, 22);
			this->AutoAtkCombo->TabIndex = 9;
			// 
			// AutoAtkText
			// 
			this->AutoAtkText->Location = System::Drawing::Point(159, 13);
			this->AutoAtkText->Name = L"AutoAtkText";
			this->AutoAtkText->Size = System::Drawing::Size(58, 20);
			this->AutoAtkText->TabIndex = 2;
			this->AutoAtkText->Text = L"200";
			this->AutoAtkText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoSkill1Text
			// 
			this->AutoSkill1Text->Location = System::Drawing::Point(159, 37);
			this->AutoSkill1Text->Name = L"AutoSkill1Text";
			this->AutoSkill1Text->Size = System::Drawing::Size(58, 20);
			this->AutoSkill1Text->TabIndex = 3;
			this->AutoSkill1Text->Text = L"0";
			this->AutoSkill1Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoSkill2Text
			// 
			this->AutoSkill2Text->Location = System::Drawing::Point(159, 61);
			this->AutoSkill2Text->Name = L"AutoSkill2Text";
			this->AutoSkill2Text->Size = System::Drawing::Size(58, 20);
			this->AutoSkill2Text->TabIndex = 4;
			this->AutoSkill2Text->Text = L"0";
			this->AutoSkill2Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoSkill3Text
			// 
			this->AutoSkill3Text->Location = System::Drawing::Point(159, 85);
			this->AutoSkill3Text->Name = L"AutoSkill3Text";
			this->AutoSkill3Text->Size = System::Drawing::Size(58, 20);
			this->AutoSkill3Text->TabIndex = 5;
			this->AutoSkill3Text->Text = L"0";
			this->AutoSkill3Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoSkill4Text
			// 
			this->AutoSkill4Text->Location = System::Drawing::Point(159, 109);
			this->AutoSkill4Text->Name = L"AutoSkill4Text";
			this->AutoSkill4Text->Size = System::Drawing::Size(58, 20);
			this->AutoSkill4Text->TabIndex = 6;
			this->AutoSkill4Text->Text = L"0";
			this->AutoSkill4Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoAtkCB
			// 
			this->AutoAtkCB->AutoSize = true;
			this->AutoAtkCB->Location = System::Drawing::Point(9, 15);
			this->AutoAtkCB->Name = L"AutoAtkCB";
			this->AutoAtkCB->Size = System::Drawing::Size(82, 18);
			this->AutoAtkCB->TabIndex = 4;
			this->AutoAtkCB->Text = L"Auto Attack";
			this->AutoAtkCB->UseVisualStyleBackColor = true;
			this->AutoAtkCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoAtkCB_CheckedChanged);
			// 
			// AutoSkill1CB
			// 
			this->AutoSkill1CB->AutoSize = true;
			this->AutoSkill1CB->Location = System::Drawing::Point(9, 39);
			this->AutoSkill1CB->Name = L"AutoSkill1CB";
			this->AutoSkill1CB->Size = System::Drawing::Size(76, 18);
			this->AutoSkill1CB->TabIndex = 5;
			this->AutoSkill1CB->Text = L"AutoSkill 1";
			this->AutoSkill1CB->UseVisualStyleBackColor = true;
			this->AutoSkill1CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill1CB_CheckedChanged);
			// 
			// AutoSkill2CB
			// 
			this->AutoSkill2CB->AutoSize = true;
			this->AutoSkill2CB->Location = System::Drawing::Point(9, 63);
			this->AutoSkill2CB->Name = L"AutoSkill2CB";
			this->AutoSkill2CB->Size = System::Drawing::Size(76, 18);
			this->AutoSkill2CB->TabIndex = 6;
			this->AutoSkill2CB->Text = L"AutoSkill 2";
			this->AutoSkill2CB->UseVisualStyleBackColor = true;
			this->AutoSkill2CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill2CB_CheckedChanged);
			// 
			// AutoSkill3CB
			// 
			this->AutoSkill3CB->AutoSize = true;
			this->AutoSkill3CB->Location = System::Drawing::Point(9, 87);
			this->AutoSkill3CB->Name = L"AutoSkill3CB";
			this->AutoSkill3CB->Size = System::Drawing::Size(76, 18);
			this->AutoSkill3CB->TabIndex = 7;
			this->AutoSkill3CB->Text = L"AutoSkill 3";
			this->AutoSkill3CB->UseVisualStyleBackColor = true;
			this->AutoSkill3CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill3CB_CheckedChanged);
			// 
			// AutoSkill4CB
			// 
			this->AutoSkill4CB->AutoSize = true;
			this->AutoSkill4CB->Location = System::Drawing::Point(9, 111);
			this->AutoSkill4CB->Name = L"AutoSkill4CB";
			this->AutoSkill4CB->Size = System::Drawing::Size(76, 18);
			this->AutoSkill4CB->TabIndex = 8;
			this->AutoSkill4CB->Text = L"AutoSkill 4";
			this->AutoSkill4CB->UseVisualStyleBackColor = true;
			this->AutoSkill4CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoSkill4CB_CheckedChanged);
			// 
			// AutoPotGroup
			// 
			this->AutoPotGroup->Controls->Add(this->AutoMPLabel);
			this->AutoPotGroup->Controls->Add(this->AutoHPLabel);
			this->AutoPotGroup->Controls->Add(this->AutoHPCombo);
			this->AutoPotGroup->Controls->Add(this->AutoMPCombo);
			this->AutoPotGroup->Controls->Add(this->AutoMPText);
			this->AutoPotGroup->Controls->Add(this->AutoHPText);
			this->AutoPotGroup->Controls->Add(this->AutoMPCB);
			this->AutoPotGroup->Controls->Add(this->AutoHPCB);
			this->AutoPotGroup->Location = System::Drawing::Point(6, 6);
			this->AutoPotGroup->Name = L"AutoPotGroup";
			this->AutoPotGroup->Size = System::Drawing::Size(309, 63);
			this->AutoPotGroup->TabIndex = 0;
			this->AutoPotGroup->TabStop = false;
			// 
			// AutoMPLabel
			// 
			this->AutoMPLabel->AutoSize = true;
			this->AutoMPLabel->Location = System::Drawing::Point(93, 39);
			this->AutoMPLabel->Name = L"AutoMPLabel";
			this->AutoMPLabel->Size = System::Drawing::Size(64, 14);
			this->AutoMPLabel->TabIndex = 5;
			this->AutoMPLabel->Text = L"When MP < ";
			// 
			// AutoHPLabel
			// 
			this->AutoHPLabel->AutoSize = true;
			this->AutoHPLabel->Location = System::Drawing::Point(93, 14);
			this->AutoHPLabel->Name = L"AutoHPLabel";
			this->AutoHPLabel->Size = System::Drawing::Size(63, 14);
			this->AutoHPLabel->TabIndex = 4;
			this->AutoHPLabel->Text = L"When HP < ";
			// 
			// AutoHPCombo
			// 
			this->AutoHPCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoHPCombo->FormattingEnabled = true;
			this->AutoHPCombo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoHPCombo->Location = System::Drawing::Point(223, 11);
			this->AutoHPCombo->Name = L"AutoHPCombo";
			this->AutoHPCombo->Size = System::Drawing::Size(79, 22);
			this->AutoHPCombo->TabIndex = 1;
			// 
			// AutoMPCombo
			// 
			this->AutoMPCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->AutoMPCombo->FormattingEnabled = true;
			this->AutoMPCombo->Items->AddRange(gcnew cli::array< System::Object^  >(43) {L"Shift", L"Ctrl", L"PgUp", L"PgDown", L"End", 
				L"Home", L"Del", L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9", L"A", L"B", L"C", L"D", L"E", L"F", L"G", L"H", 
				L"I", L"J", L"K", L"L", L"M", L"N", L"O", L"P", L"Q", L"R", L"S", L"T", L"U", L"V", L"W", L"X", L"Y", L"Z"});
			this->AutoMPCombo->Location = System::Drawing::Point(223, 35);
			this->AutoMPCombo->Name = L"AutoMPCombo";
			this->AutoMPCombo->Size = System::Drawing::Size(79, 22);
			this->AutoMPCombo->TabIndex = 2;
			// 
			// AutoMPText
			// 
			this->AutoMPText->ForeColor = System::Drawing::Color::Blue;
			this->AutoMPText->Location = System::Drawing::Point(159, 36);
			this->AutoMPText->Name = L"AutoMPText";
			this->AutoMPText->Size = System::Drawing::Size(58, 20);
			this->AutoMPText->TabIndex = 3;
			this->AutoMPText->Text = L"250";
			this->AutoMPText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoHPText
			// 
			this->AutoHPText->ForeColor = System::Drawing::Color::Red;
			this->AutoHPText->Location = System::Drawing::Point(159, 12);
			this->AutoHPText->Name = L"AutoHPText";
			this->AutoHPText->Size = System::Drawing::Size(58, 20);
			this->AutoHPText->TabIndex = 2;
			this->AutoHPText->Text = L"1000";
			this->AutoHPText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoMPCB
			// 
			this->AutoMPCB->AutoSize = true;
			this->AutoMPCB->Location = System::Drawing::Point(9, 38);
			this->AutoMPCB->Name = L"AutoMPCB";
			this->AutoMPCB->Size = System::Drawing::Size(66, 18);
			this->AutoMPCB->TabIndex = 1;
			this->AutoMPCB->Text = L"Auto MP";
			this->AutoMPCB->UseVisualStyleBackColor = true;
			this->AutoMPCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoMPCB_CheckedChanged);
			// 
			// AutoHPCB
			// 
			this->AutoHPCB->AutoSize = true;
			this->AutoHPCB->Location = System::Drawing::Point(9, 14);
			this->AutoHPCB->Name = L"AutoHPCB";
			this->AutoHPCB->Size = System::Drawing::Size(65, 18);
			this->AutoHPCB->TabIndex = 0;
			this->AutoHPCB->Text = L"Auto HP";
			this->AutoHPCB->UseVisualStyleBackColor = true;
			this->AutoHPCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoHPCB_CheckedChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tabPage3->Controls->Add(this->BypassHacksGB);
			this->tabPage3->Controls->Add(this->NDFAGroup);
			this->tabPage3->Controls->Add(this->BypasslessHacksGB);
			this->tabPage3->Location = System::Drawing::Point(4, 23);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(321, 295);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Hacks";
			// 
			// BypassHacksGB
			// 
			this->BypassHacksGB->Controls->Add(this->HideDamageCB);
			this->BypassHacksGB->Controls->Add(this->CPUHack2CB);
			this->BypassHacksGB->Controls->Add(this->CPUHack1CB);
			this->BypassHacksGB->Controls->Add(this->UnlimKaiserCB);
			this->BypassHacksGB->Controls->Add(this->SlowMobsCB);
			this->BypassHacksGB->Controls->Add(this->InstantDropCB);
			this->BypassHacksGB->Controls->Add(this->NoKBCB);
			this->BypassHacksGB->Controls->Add(this->NoMobLagCB);
			this->BypassHacksGB->Controls->Add(this->AirLootCB);
			this->BypassHacksGB->Controls->Add(this->FLACCCB);
			this->BypassHacksGB->Controls->Add(this->NoLootAnimCB);
			this->BypassHacksGB->Controls->Add(this->MultiDmgCB);
			this->BypassHacksGB->Controls->Add(this->UnlimAtkCB);
			this->BypassHacksGB->Controls->Add(this->NoAtkLimitCB);
			this->BypassHacksGB->Controls->Add(this->FullGMCB);
			this->BypassHacksGB->Location = System::Drawing::Point(6, 156);
			this->BypassHacksGB->Name = L"BypassHacksGB";
			this->BypassHacksGB->Size = System::Drawing::Size(306, 135);
			this->BypassHacksGB->TabIndex = 2;
			this->BypassHacksGB->TabStop = false;
			this->BypassHacksGB->Text = L"Full Bypass Required";
			// 
			// HideDamageCB
			// 
			this->HideDamageCB->AutoSize = true;
			this->HideDamageCB->Enabled = false;
			this->HideDamageCB->Location = System::Drawing::Point(202, 113);
			this->HideDamageCB->Name = L"HideDamageCB";
			this->HideDamageCB->Size = System::Drawing::Size(89, 18);
			this->HideDamageCB->TabIndex = 4;
			this->HideDamageCB->Text = L"Hide Damage";
			this->HideDamageCB->UseVisualStyleBackColor = true;
			this->HideDamageCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::HideDamageCB_CheckedChanged);
			// 
			// CPUHack2CB
			// 
			this->CPUHack2CB->AutoSize = true;
			this->CPUHack2CB->Enabled = false;
			this->CPUHack2CB->Location = System::Drawing::Point(102, 113);
			this->CPUHack2CB->Name = L"CPUHack2CB";
			this->CPUHack2CB->Size = System::Drawing::Size(82, 18);
			this->CPUHack2CB->TabIndex = 4;
			this->CPUHack2CB->Text = L"CPU Hack 2";
			this->CPUHack2CB->UseVisualStyleBackColor = true;
			this->CPUHack2CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CPUHack2CB_CheckedChanged);
			// 
			// CPUHack1CB
			// 
			this->CPUHack1CB->AutoSize = true;
			this->CPUHack1CB->Enabled = false;
			this->CPUHack1CB->Location = System::Drawing::Point(9, 113);
			this->CPUHack1CB->Name = L"CPUHack1CB";
			this->CPUHack1CB->Size = System::Drawing::Size(82, 18);
			this->CPUHack1CB->TabIndex = 4;
			this->CPUHack1CB->Text = L"CPU Hack 1";
			this->CPUHack1CB->UseVisualStyleBackColor = true;
			this->CPUHack1CB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CPUHack1CB_CheckedChanged);
			// 
			// UnlimKaiserCB
			// 
			this->UnlimKaiserCB->AutoSize = true;
			this->UnlimKaiserCB->Enabled = false;
			this->UnlimKaiserCB->Location = System::Drawing::Point(202, 89);
			this->UnlimKaiserCB->Name = L"UnlimKaiserCB";
			this->UnlimKaiserCB->Size = System::Drawing::Size(76, 18);
			this->UnlimKaiserCB->TabIndex = 3;
			this->UnlimKaiserCB->Text = L"Hide Login";
			this->UnlimKaiserCB->UseVisualStyleBackColor = true;
			this->UnlimKaiserCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UnlimKaiserCB_CheckedChanged);
			// 
			// SlowMobsCB
			// 
			this->SlowMobsCB->AutoSize = true;
			this->SlowMobsCB->Enabled = false;
			this->SlowMobsCB->Location = System::Drawing::Point(102, 89);
			this->SlowMobsCB->Name = L"SlowMobsCB";
			this->SlowMobsCB->Size = System::Drawing::Size(80, 18);
			this->SlowMobsCB->TabIndex = 3;
			this->SlowMobsCB->Text = L"Slow Mobs";
			this->SlowMobsCB->UseVisualStyleBackColor = true;
			this->SlowMobsCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::SlowMobsCB_CheckedChanged);
			// 
			// InstantDropCB
			// 
			this->InstantDropCB->AutoSize = true;
			this->InstantDropCB->Enabled = false;
			this->InstantDropCB->Location = System::Drawing::Point(9, 89);
			this->InstantDropCB->Name = L"InstantDropCB";
			this->InstantDropCB->Size = System::Drawing::Size(84, 18);
			this->InstantDropCB->TabIndex = 3;
			this->InstantDropCB->Text = L"Instant Drop";
			this->InstantDropCB->UseVisualStyleBackColor = true;
			this->InstantDropCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::InstantDropCB_CheckedChanged);
			// 
			// NoKBCB
			// 
			this->NoKBCB->AutoSize = true;
			this->NoKBCB->Enabled = false;
			this->NoKBCB->Location = System::Drawing::Point(202, 65);
			this->NoKBCB->Name = L"NoKBCB";
			this->NoKBCB->Size = System::Drawing::Size(95, 18);
			this->NoKBCB->TabIndex = 2;
			this->NoKBCB->Text = L"No Knockback";
			this->NoKBCB->UseVisualStyleBackColor = true;
			this->NoKBCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoKBCB_CheckedChanged);
			// 
			// NoMobLagCB
			// 
			this->NoMobLagCB->AutoSize = true;
			this->NoMobLagCB->Enabled = false;
			this->NoMobLagCB->Location = System::Drawing::Point(102, 65);
			this->NoMobLagCB->Name = L"NoMobLagCB";
			this->NoMobLagCB->Size = System::Drawing::Size(83, 18);
			this->NoMobLagCB->TabIndex = 2;
			this->NoMobLagCB->Text = L"No Mob Lag";
			this->NoMobLagCB->UseVisualStyleBackColor = true;
			this->NoMobLagCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoMobLagCB_CheckedChanged);
			// 
			// AirLootCB
			// 
			this->AirLootCB->AutoSize = true;
			this->AirLootCB->Enabled = false;
			this->AirLootCB->Location = System::Drawing::Point(9, 65);
			this->AirLootCB->Name = L"AirLootCB";
			this->AirLootCB->Size = System::Drawing::Size(64, 18);
			this->AirLootCB->TabIndex = 2;
			this->AirLootCB->Text = L"Air Loot";
			this->AirLootCB->UseVisualStyleBackColor = true;
			this->AirLootCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AirLootCB_CheckedChanged);
			// 
			// FLACCCB
			// 
			this->FLACCCB->AutoSize = true;
			this->FLACCCB->Enabled = false;
			this->FLACCCB->Location = System::Drawing::Point(202, 43);
			this->FLACCCB->Name = L"FLACCCB";
			this->FLACCCB->Size = System::Drawing::Size(60, 18);
			this->FLACCCB->TabIndex = 1;
			this->FLACCCB->Text = L"FLACC";
			this->FLACCCB->UseVisualStyleBackColor = true;
			this->FLACCCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FLACCCB_CheckedChanged);
			// 
			// NoLootAnimCB
			// 
			this->NoLootAnimCB->AutoSize = true;
			this->NoLootAnimCB->Enabled = false;
			this->NoLootAnimCB->Location = System::Drawing::Point(102, 43);
			this->NoLootAnimCB->Name = L"NoLootAnimCB";
			this->NoLootAnimCB->Size = System::Drawing::Size(89, 18);
			this->NoLootAnimCB->TabIndex = 1;
			this->NoLootAnimCB->Text = L"No Loot Anim";
			this->NoLootAnimCB->UseVisualStyleBackColor = true;
			this->NoLootAnimCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoLootAnimCB_CheckedChanged);
			// 
			// MultiDmgCB
			// 
			this->MultiDmgCB->AutoSize = true;
			this->MultiDmgCB->Enabled = false;
			this->MultiDmgCB->Location = System::Drawing::Point(9, 43);
			this->MultiDmgCB->Name = L"MultiDmgCB";
			this->MultiDmgCB->Size = System::Drawing::Size(89, 18);
			this->MultiDmgCB->TabIndex = 1;
			this->MultiDmgCB->Text = L"Multi Damage";
			this->MultiDmgCB->UseVisualStyleBackColor = true;
			this->MultiDmgCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MultiDmgCB_CheckedChanged);
			// 
			// UnlimAtkCB
			// 
			this->UnlimAtkCB->AutoSize = true;
			this->UnlimAtkCB->Enabled = false;
			this->UnlimAtkCB->Location = System::Drawing::Point(202, 19);
			this->UnlimAtkCB->Name = L"UnlimAtkCB";
			this->UnlimAtkCB->Size = System::Drawing::Size(41, 18);
			this->UnlimAtkCB->TabIndex = 0;
			this->UnlimAtkCB->Text = L"UA";
			this->UnlimAtkCB->UseVisualStyleBackColor = true;
			this->UnlimAtkCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::UnlimAtkCB_CheckedChanged);
			// 
			// NoAtkLimitCB
			// 
			this->NoAtkLimitCB->AutoSize = true;
			this->NoAtkLimitCB->Enabled = false;
			this->NoAtkLimitCB->Location = System::Drawing::Point(102, 19);
			this->NoAtkLimitCB->Name = L"NoAtkLimitCB";
			this->NoAtkLimitCB->Size = System::Drawing::Size(96, 18);
			this->NoAtkLimitCB->TabIndex = 0;
			this->NoAtkLimitCB->Text = L"No Attack Limit";
			this->NoAtkLimitCB->UseVisualStyleBackColor = true;
			this->NoAtkLimitCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoAtkLimitCB_CheckedChanged);
			// 
			// FullGMCB
			// 
			this->FullGMCB->AutoSize = true;
			this->FullGMCB->Enabled = false;
			this->FullGMCB->Location = System::Drawing::Point(9, 19);
			this->FullGMCB->Name = L"FullGMCB";
			this->FullGMCB->Size = System::Drawing::Size(61, 18);
			this->FullGMCB->TabIndex = 0;
			this->FullGMCB->Text = L"Full GM";
			this->FullGMCB->UseVisualStyleBackColor = true;
			this->FullGMCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FullGMCB_CheckedChanged);
			// 
			// NDFAGroup
			// 
			this->NDFAGroup->Controls->Add(this->NDFASpeedLabel);
			this->NDFAGroup->Controls->Add(this->NDFAClassLabel);
			this->NDFAGroup->Controls->Add(this->NDFAClassCombo);
			this->NDFAGroup->Controls->Add(this->NDFASpeedText);
			this->NDFAGroup->Controls->Add(this->NDFAAFACB);
			this->NDFAGroup->Controls->Add(this->NDFACB);
			this->NDFAGroup->Enabled = false;
			this->NDFAGroup->Location = System::Drawing::Point(6, 94);
			this->NDFAGroup->Name = L"NDFAGroup";
			this->NDFAGroup->Size = System::Drawing::Size(306, 63);
			this->NDFAGroup->TabIndex = 1;
			this->NDFAGroup->TabStop = false;
			this->NDFAGroup->Text = L"Bypassless NDFA";
			// 
			// NDFASpeedLabel
			// 
			this->NDFASpeedLabel->AutoSize = true;
			this->NDFASpeedLabel->Location = System::Drawing::Point(163, 41);
			this->NDFASpeedLabel->Name = L"NDFASpeedLabel";
			this->NDFASpeedLabel->Size = System::Drawing::Size(95, 14);
			this->NDFASpeedLabel->TabIndex = 4;
			this->NDFASpeedLabel->Text = L"NDFA Speed (ms):";
			// 
			// NDFAClassLabel
			// 
			this->NDFAClassLabel->AutoSize = true;
			this->NDFAClassLabel->Location = System::Drawing::Point(175, 16);
			this->NDFAClassLabel->Name = L"NDFAClassLabel";
			this->NDFAClassLabel->Size = System::Drawing::Size(37, 14);
			this->NDFAClassLabel->TabIndex = 3;
			this->NDFAClassLabel->Text = L"Class:";
			// 
			// NDFAClassCombo
			// 
			this->NDFAClassCombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->NDFAClassCombo->FormattingEnabled = true;
			this->NDFAClassCombo->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"Fighter", L"Page", L"Spearman", L"Aran", 
				L"Hunter", L"Crossbowman", L"Wind Archer", L"Wild Hunter", L"Mercedes", L"Evan"});
			this->NDFAClassCombo->Location = System::Drawing::Point(214, 13);
			this->NDFAClassCombo->Name = L"NDFAClassCombo";
			this->NDFAClassCombo->Size = System::Drawing::Size(84, 22);
			this->NDFAClassCombo->TabIndex = 2;
			// 
			// NDFASpeedText
			// 
			this->NDFASpeedText->Location = System::Drawing::Point(259, 38);
			this->NDFASpeedText->Name = L"NDFASpeedText";
			this->NDFASpeedText->Size = System::Drawing::Size(39, 20);
			this->NDFASpeedText->TabIndex = 0;
			this->NDFASpeedText->Text = L"10";
			this->NDFASpeedText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// NDFAAFACB
			// 
			this->NDFAAFACB->AutoSize = true;
			this->NDFAAFACB->Location = System::Drawing::Point(9, 40);
			this->NDFAAFACB->Name = L"NDFAAFACB";
			this->NDFAAFACB->Size = System::Drawing::Size(98, 18);
			this->NDFAAFACB->TabIndex = 1;
			this->NDFAAFACB->Text = L"Advanced FA\?";
			this->NDFAAFACB->UseVisualStyleBackColor = true;
			this->NDFAAFACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDFAAFACB_CheckedChanged);
			// 
			// NDFACB
			// 
			this->NDFACB->AutoSize = true;
			this->NDFACB->Location = System::Drawing::Point(9, 16);
			this->NDFACB->Name = L"NDFACB";
			this->NDFACB->Size = System::Drawing::Size(88, 18);
			this->NDFACB->TabIndex = 0;
			this->NDFACB->Text = L"Enable NDFA";
			this->NDFACB->UseVisualStyleBackColor = true;
			this->NDFACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NDFACB_CheckedChanged);
			// 
			// BypasslessHacksGB
			// 
			this->BypasslessHacksGB->Controls->Add(this->AutoBanLabel);
			this->BypasslessHacksGB->Controls->Add(this->FMACB);
			this->BypasslessHacksGB->Controls->Add(this->MobDisarmCB);
			this->BypasslessHacksGB->Controls->Add(this->TeleUACB);
			this->BypasslessHacksGB->Controls->Add(this->BLUACB);
			this->BypasslessHacksGB->Controls->Add(this->NoBreathCB);
			this->BypasslessHacksGB->Controls->Add(this->MorphGMCB);
			this->BypasslessHacksGB->Controls->Add(this->TubiCB);
			this->BypasslessHacksGB->Controls->Add(this->ClickFlyCB);
			this->BypasslessHacksGB->Location = System::Drawing::Point(6, 6);
			this->BypasslessHacksGB->Name = L"BypasslessHacksGB";
			this->BypasslessHacksGB->Size = System::Drawing::Size(309, 89);
			this->BypasslessHacksGB->TabIndex = 0;
			this->BypasslessHacksGB->TabStop = false;
			this->BypasslessHacksGB->Text = L"Bypassless";
			// 
			// AutoBanLabel
			// 
			this->AutoBanLabel->AutoSize = true;
			this->AutoBanLabel->Location = System::Drawing::Point(186, 71);
			this->AutoBanLabel->Name = L"AutoBanLabel";
			this->AutoBanLabel->Size = System::Drawing::Size(117, 14);
			this->AutoBanLabel->TabIndex = 0;
			this->AutoBanLabel->Text = L"*Will AB without CC/CS";
			// 
			// FMACB
			// 
			this->FMACB->AutoSize = true;
			this->FMACB->Enabled = false;
			this->FMACB->Location = System::Drawing::Point(197, 40);
			this->FMACB->Name = L"FMACB";
			this->FMACB->Size = System::Drawing::Size(99, 18);
			this->FMACB->TabIndex = 7;
			this->FMACB->Text = L"Full-Map Attack";
			this->FMACB->UseVisualStyleBackColor = true;
			this->FMACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FMACB_CheckedChanged);
			// 
			// MobDisarmCB
			// 
			this->MobDisarmCB->AutoSize = true;
			this->MobDisarmCB->Location = System::Drawing::Point(197, 16);
			this->MobDisarmCB->Name = L"MobDisarmCB";
			this->MobDisarmCB->Size = System::Drawing::Size(42, 18);
			this->MobDisarmCB->TabIndex = 6;
			this->MobDisarmCB->Text = L"GM";
			this->MobDisarmCB->UseVisualStyleBackColor = true;
			this->MobDisarmCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MobDisarmCB_CheckedChanged);
			// 
			// TeleUACB
			// 
			this->TeleUACB->AutoSize = true;
			this->TeleUACB->Enabled = false;
			this->TeleUACB->Location = System::Drawing::Point(107, 64);
			this->TeleUACB->Name = L"TeleUACB";
			this->TeleUACB->Size = System::Drawing::Size(63, 18);
			this->TeleUACB->TabIndex = 5;
			this->TeleUACB->Text = L"Tele UA";
			this->TeleUACB->UseVisualStyleBackColor = true;
			this->TeleUACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TeleUACB_CheckedChanged);
			// 
			// BLUACB
			// 
			this->BLUACB->AutoSize = true;
			this->BLUACB->Location = System::Drawing::Point(107, 40);
			this->BLUACB->Name = L"BLUACB";
			this->BLUACB->Size = System::Drawing::Size(45, 18);
			this->BLUACB->TabIndex = 4;
			this->BLUACB->Text = L"UA*";
			this->BLUACB->UseVisualStyleBackColor = true;
			this->BLUACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::BLUACB_CheckedChanged);
			// 
			// NoBreathCB
			// 
			this->NoBreathCB->AutoSize = true;
			this->NoBreathCB->Location = System::Drawing::Point(107, 16);
			this->NoBreathCB->Name = L"NoBreathCB";
			this->NoBreathCB->Size = System::Drawing::Size(74, 18);
			this->NoBreathCB->TabIndex = 3;
			this->NoBreathCB->Text = L"No Breath";
			this->NoBreathCB->UseVisualStyleBackColor = true;
			this->NoBreathCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::NoBreathCB_CheckedChanged);
			// 
			// MorphGMCB
			// 
			this->MorphGMCB->AutoSize = true;
			this->MorphGMCB->Enabled = false;
			this->MorphGMCB->Location = System::Drawing::Point(9, 64);
			this->MorphGMCB->Name = L"MorphGMCB";
			this->MorphGMCB->Size = System::Drawing::Size(75, 18);
			this->MorphGMCB->TabIndex = 2;
			this->MorphGMCB->Text = L"Morph GM";
			this->MorphGMCB->UseVisualStyleBackColor = true;
			this->MorphGMCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::MorphGMCB_CheckedChanged);
			// 
			// TubiCB
			// 
			this->TubiCB->AutoSize = true;
			this->TubiCB->Location = System::Drawing::Point(9, 40);
			this->TubiCB->Name = L"TubiCB";
			this->TubiCB->Size = System::Drawing::Size(46, 18);
			this->TubiCB->TabIndex = 1;
			this->TubiCB->Text = L"Tubi";
			this->TubiCB->UseVisualStyleBackColor = true;
			this->TubiCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TubiCB_CheckedChanged);
			// 
			// ClickFlyCB
			// 
			this->ClickFlyCB->AutoSize = true;
			this->ClickFlyCB->Enabled = false;
			this->ClickFlyCB->Location = System::Drawing::Point(9, 16);
			this->ClickFlyCB->Name = L"ClickFlyCB";
			this->ClickFlyCB->Size = System::Drawing::Size(65, 18);
			this->ClickFlyCB->TabIndex = 0;
			this->ClickFlyCB->Text = L"Click Fly";
			this->ClickFlyCB->UseVisualStyleBackColor = true;
			this->ClickFlyCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ClickFlyCB_CheckedChanged);
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tabPage4->Controls->Add(this->OtherVacGroup);
			this->tabPage4->Controls->Add(this->ItemVacGroup);
			this->tabPage4->Controls->Add(this->TeleportGroup);
			this->tabPage4->Controls->Add(this->AutoLootVacGB);
			this->tabPage4->Controls->Add(this->KamiGroup);
			this->tabPage4->Location = System::Drawing::Point(4, 23);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(321, 295);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Vacs";
			// 
			// OtherVacGroup
			// 
			this->OtherVacGroup->Controls->Add(this->LootNoMobsCB);
			this->OtherVacGroup->Controls->Add(this->KamiWallcheckCB);
			this->OtherVacGroup->Controls->Add(this->LootBfrCCCB);
			this->OtherVacGroup->Location = System::Drawing::Point(6, 233);
			this->OtherVacGroup->Name = L"OtherVacGroup";
			this->OtherVacGroup->Size = System::Drawing::Size(309, 58);
			this->OtherVacGroup->TabIndex = 0;
			this->OtherVacGroup->TabStop = false;
			this->OtherVacGroup->Text = L"Other";
			// 
			// LootNoMobsCB
			// 
			this->LootNoMobsCB->AutoSize = true;
			this->LootNoMobsCB->Enabled = false;
			this->LootNoMobsCB->Location = System::Drawing::Point(9, 35);
			this->LootNoMobsCB->Name = L"LootNoMobsCB";
			this->LootNoMobsCB->Size = System::Drawing::Size(123, 18);
			this->LootNoMobsCB->TabIndex = 16;
			this->LootNoMobsCB->Text = L"Loot When No Mobs";
			this->LootNoMobsCB->UseVisualStyleBackColor = true;
			this->LootNoMobsCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::LootNoMobsCB_CheckedChanged);
			// 
			// KamiWallcheckCB
			// 
			this->KamiWallcheckCB->AutoSize = true;
			this->KamiWallcheckCB->Checked = true;
			this->KamiWallcheckCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->KamiWallcheckCB->Location = System::Drawing::Point(134, 15);
			this->KamiWallcheckCB->Name = L"KamiWallcheckCB";
			this->KamiWallcheckCB->Size = System::Drawing::Size(101, 18);
			this->KamiWallcheckCB->TabIndex = 17;
			this->KamiWallcheckCB->Text = L"Kami Wallcheck";
			this->KamiWallcheckCB->UseVisualStyleBackColor = true;
			this->KamiWallcheckCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::KamiWallcheckCB_CheckedChanged);
			// 
			// LootBfrCCCB
			// 
			this->LootBfrCCCB->AutoSize = true;
			this->LootBfrCCCB->Enabled = false;
			this->LootBfrCCCB->Location = System::Drawing::Point(9, 15);
			this->LootBfrCCCB->Name = L"LootBfrCCCB";
			this->LootBfrCCCB->Size = System::Drawing::Size(100, 18);
			this->LootBfrCCCB->TabIndex = 15;
			this->LootBfrCCCB->Text = L"Loot Before CC";
			this->LootBfrCCCB->UseVisualStyleBackColor = true;
			this->LootBfrCCCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::LootBfrCCCB_CheckedChanged);
			// 
			// ItemVacGroup
			// 
			this->ItemVacGroup->Controls->Add(this->ItemVacDescLabel);
			this->ItemVacGroup->Controls->Add(this->ItemVacCB);
			this->ItemVacGroup->Controls->Add(this->ItemVacYLabel);
			this->ItemVacGroup->Controls->Add(this->ItemVacXLabel);
			this->ItemVacGroup->Controls->Add(this->ItemVacYText);
			this->ItemVacGroup->Controls->Add(this->ItemVacXText);
			this->ItemVacGroup->Controls->Add(this->ItemVacGetPosBtn);
			this->ItemVacGroup->Enabled = false;
			this->ItemVacGroup->Location = System::Drawing::Point(164, 118);
			this->ItemVacGroup->Name = L"ItemVacGroup";
			this->ItemVacGroup->Size = System::Drawing::Size(151, 116);
			this->ItemVacGroup->TabIndex = 2;
			this->ItemVacGroup->TabStop = false;
			this->ItemVacGroup->Text = L"Fixed Item Vac";
			// 
			// ItemVacDescLabel
			// 
			this->ItemVacDescLabel->AutoSize = true;
			this->ItemVacDescLabel->Font = (gcnew System::Drawing::Font(L"Arial", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ItemVacDescLabel->Location = System::Drawing::Point(14, 88);
			this->ItemVacDescLabel->Name = L"ItemVacDescLabel";
			this->ItemVacDescLabel->Size = System::Drawing::Size(125, 24);
			this->ItemVacDescLabel->TabIndex = 5;
			this->ItemVacDescLabel->Text = L"This vacs items dropped by \r\nmobs, not players.";
			// 
			// ItemVacCB
			// 
			this->ItemVacCB->AutoSize = true;
			this->ItemVacCB->Location = System::Drawing::Point(9, 17);
			this->ItemVacCB->Name = L"ItemVacCB";
			this->ItemVacCB->Size = System::Drawing::Size(58, 18);
			this->ItemVacCB->TabIndex = 5;
			this->ItemVacCB->Text = L"Enable";
			this->ItemVacCB->UseVisualStyleBackColor = true;
			this->ItemVacCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::ItemVacCB_CheckedChanged);
			// 
			// ItemVacYLabel
			// 
			this->ItemVacYLabel->AutoSize = true;
			this->ItemVacYLabel->Location = System::Drawing::Point(76, 41);
			this->ItemVacYLabel->Name = L"ItemVacYLabel";
			this->ItemVacYLabel->Size = System::Drawing::Size(17, 14);
			this->ItemVacYLabel->TabIndex = 13;
			this->ItemVacYLabel->Text = L"Y:";
			// 
			// ItemVacXLabel
			// 
			this->ItemVacXLabel->AutoSize = true;
			this->ItemVacXLabel->Location = System::Drawing::Point(15, 41);
			this->ItemVacXLabel->Name = L"ItemVacXLabel";
			this->ItemVacXLabel->Size = System::Drawing::Size(17, 14);
			this->ItemVacXLabel->TabIndex = 12;
			this->ItemVacXLabel->Text = L"X:";
			// 
			// ItemVacYText
			// 
			this->ItemVacYText->Location = System::Drawing::Point(95, 38);
			this->ItemVacYText->Name = L"ItemVacYText";
			this->ItemVacYText->Size = System::Drawing::Size(38, 20);
			this->ItemVacYText->TabIndex = 8;
			this->ItemVacYText->Text = L"0";
			this->ItemVacYText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ItemVacXText
			// 
			this->ItemVacXText->Location = System::Drawing::Point(34, 38);
			this->ItemVacXText->Name = L"ItemVacXText";
			this->ItemVacXText->Size = System::Drawing::Size(38, 20);
			this->ItemVacXText->TabIndex = 7;
			this->ItemVacXText->Text = L"0";
			this->ItemVacXText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ItemVacGetPosBtn
			// 
			this->ItemVacGetPosBtn->Location = System::Drawing::Point(9, 64);
			this->ItemVacGetPosBtn->Name = L"ItemVacGetPosBtn";
			this->ItemVacGetPosBtn->Size = System::Drawing::Size(136, 23);
			this->ItemVacGetPosBtn->TabIndex = 14;
			this->ItemVacGetPosBtn->Text = L"Get Position";
			this->ItemVacGetPosBtn->UseVisualStyleBackColor = true;
			this->ItemVacGetPosBtn->Click += gcnew System::EventHandler(this, &MainForm::ItemVacGetPosBtn_Click);
			// 
			// TeleportGroup
			// 
			this->TeleportGroup->Controls->Add(this->TeleportInfoBtn);
			this->TeleportGroup->Controls->Add(this->TeleMSLabel);
			this->TeleportGroup->Controls->Add(this->TeleDelayText);
			this->TeleportGroup->Controls->Add(this->TeleDelayCB);
			this->TeleportGroup->Controls->Add(this->TeleTeleBtn);
			this->TeleportGroup->Controls->Add(this->TeleGetPosBtn);
			this->TeleportGroup->Controls->Add(this->TeleportCB);
			this->TeleportGroup->Controls->Add(this->TeleXText);
			this->TeleportGroup->Controls->Add(this->TeleYText);
			this->TeleportGroup->Controls->Add(this->TeleXLabel);
			this->TeleportGroup->Controls->Add(this->TeleYLabel);
			this->TeleportGroup->Enabled = false;
			this->TeleportGroup->Location = System::Drawing::Point(6, 118);
			this->TeleportGroup->Name = L"TeleportGroup";
			this->TeleportGroup->Size = System::Drawing::Size(151, 116);
			this->TeleportGroup->TabIndex = 2;
			this->TeleportGroup->TabStop = false;
			this->TeleportGroup->Text = L"Teleport";
			// 
			// TeleportInfoBtn
			// 
			this->TeleportInfoBtn->Location = System::Drawing::Point(136, 8);
			this->TeleportInfoBtn->Name = L"TeleportInfoBtn";
			this->TeleportInfoBtn->Size = System::Drawing::Size(13, 21);
			this->TeleportInfoBtn->TabIndex = 0;
			this->TeleportInfoBtn->Text = L"\?";
			this->TeleportInfoBtn->UseVisualStyleBackColor = true;
			this->TeleportInfoBtn->Click += gcnew System::EventHandler(this, &MainForm::TeleportInfoBtn_Click);
			// 
			// TeleMSLabel
			// 
			this->TeleMSLabel->AutoSize = true;
			this->TeleMSLabel->Location = System::Drawing::Point(129, 94);
			this->TeleMSLabel->Name = L"TeleMSLabel";
			this->TeleMSLabel->Size = System::Drawing::Size(21, 14);
			this->TeleMSLabel->TabIndex = 0;
			this->TeleMSLabel->Text = L"ms";
			// 
			// TeleDelayText
			// 
			this->TeleDelayText->Location = System::Drawing::Point(83, 91);
			this->TeleDelayText->Name = L"TeleDelayText";
			this->TeleDelayText->Size = System::Drawing::Size(46, 20);
			this->TeleDelayText->TabIndex = 17;
			this->TeleDelayText->Text = L"0";
			this->TeleDelayText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TeleDelayCB
			// 
			this->TeleDelayCB->AutoSize = true;
			this->TeleDelayCB->Location = System::Drawing::Point(9, 93);
			this->TeleDelayCB->Name = L"TeleDelayCB";
			this->TeleDelayCB->Size = System::Drawing::Size(76, 18);
			this->TeleDelayCB->TabIndex = 16;
			this->TeleDelayCB->Text = L"Tele Every";
			this->TeleDelayCB->UseVisualStyleBackColor = true;
			this->TeleDelayCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TeleDelayCB_CheckedChanged);
			// 
			// TeleTeleBtn
			// 
			this->TeleTeleBtn->Location = System::Drawing::Point(78, 64);
			this->TeleTeleBtn->Name = L"TeleTeleBtn";
			this->TeleTeleBtn->Size = System::Drawing::Size(65, 23);
			this->TeleTeleBtn->TabIndex = 15;
			this->TeleTeleBtn->Text = L"Teleport";
			this->TeleTeleBtn->UseVisualStyleBackColor = true;
			this->TeleTeleBtn->Click += gcnew System::EventHandler(this, &MainForm::TeleTeleBtn_Click);
			// 
			// TeleGetPosBtn
			// 
			this->TeleGetPosBtn->Location = System::Drawing::Point(8, 64);
			this->TeleGetPosBtn->Name = L"TeleGetPosBtn";
			this->TeleGetPosBtn->Size = System::Drawing::Size(65, 23);
			this->TeleGetPosBtn->TabIndex = 14;
			this->TeleGetPosBtn->Text = L"Get Pos";
			this->TeleGetPosBtn->UseVisualStyleBackColor = true;
			this->TeleGetPosBtn->Click += gcnew System::EventHandler(this, &MainForm::TeleGetPosBtn_Click);
			// 
			// TeleportCB
			// 
			this->TeleportCB->AutoSize = true;
			this->TeleportCB->Location = System::Drawing::Point(9, 17);
			this->TeleportCB->Name = L"TeleportCB";
			this->TeleportCB->Size = System::Drawing::Size(58, 18);
			this->TeleportCB->TabIndex = 5;
			this->TeleportCB->Text = L"Enable";
			this->TeleportCB->UseVisualStyleBackColor = true;
			this->TeleportCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TeleportCB_CheckedChanged);
			// 
			// TeleXText
			// 
			this->TeleXText->Location = System::Drawing::Point(33, 38);
			this->TeleXText->Name = L"TeleXText";
			this->TeleXText->Size = System::Drawing::Size(38, 20);
			this->TeleXText->TabIndex = 7;
			this->TeleXText->Text = L"0";
			this->TeleXText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TeleYText
			// 
			this->TeleYText->Location = System::Drawing::Point(94, 38);
			this->TeleYText->Name = L"TeleYText";
			this->TeleYText->Size = System::Drawing::Size(38, 20);
			this->TeleYText->TabIndex = 8;
			this->TeleYText->Text = L"0";
			this->TeleYText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TeleXLabel
			// 
			this->TeleXLabel->AutoSize = true;
			this->TeleXLabel->Location = System::Drawing::Point(14, 41);
			this->TeleXLabel->Name = L"TeleXLabel";
			this->TeleXLabel->Size = System::Drawing::Size(17, 14);
			this->TeleXLabel->TabIndex = 12;
			this->TeleXLabel->Text = L"X:";
			// 
			// TeleYLabel
			// 
			this->TeleYLabel->AutoSize = true;
			this->TeleYLabel->Location = System::Drawing::Point(75, 41);
			this->TeleYLabel->Name = L"TeleYLabel";
			this->TeleYLabel->Size = System::Drawing::Size(17, 14);
			this->TeleYLabel->TabIndex = 13;
			this->TeleYLabel->Text = L"Y:";
			// 
			// AutoLootVacGB
			// 
			this->AutoLootVacGB->Controls->Add(this->AutoLootItemLabel);
			this->AutoLootVacGB->Controls->Add(this->AutoLootCB);
			this->AutoLootVacGB->Controls->Add(this->AutoLootDelLabel);
			this->AutoLootVacGB->Controls->Add(this->AutoLootDelText);
			this->AutoLootVacGB->Controls->Add(this->AutoLootItemsText);
			this->AutoLootVacGB->Enabled = false;
			this->AutoLootVacGB->Location = System::Drawing::Point(6, 72);
			this->AutoLootVacGB->Name = L"AutoLootVacGB";
			this->AutoLootVacGB->Size = System::Drawing::Size(309, 47);
			this->AutoLootVacGB->TabIndex = 1;
			this->AutoLootVacGB->TabStop = false;
			this->AutoLootVacGB->Text = L"Auto Loot Vac";
			// 
			// AutoLootItemLabel
			// 
			this->AutoLootItemLabel->AutoSize = true;
			this->AutoLootItemLabel->Location = System::Drawing::Point(90, 20);
			this->AutoLootItemLabel->Name = L"AutoLootItemLabel";
			this->AutoLootItemLabel->Size = System::Drawing::Size(68, 14);
			this->AutoLootItemLabel->TabIndex = 16;
			this->AutoLootItemLabel->Text = L"Item Amount:";
			// 
			// AutoLootCB
			// 
			this->AutoLootCB->AutoSize = true;
			this->AutoLootCB->Location = System::Drawing::Point(9, 19);
			this->AutoLootCB->Name = L"AutoLootCB";
			this->AutoLootCB->Size = System::Drawing::Size(73, 18);
			this->AutoLootCB->TabIndex = 6;
			this->AutoLootCB->Text = L"Auto Loot";
			this->AutoLootCB->UseVisualStyleBackColor = true;
			this->AutoLootCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoLootCB_CheckedChanged);
			// 
			// AutoLootDelLabel
			// 
			this->AutoLootDelLabel->AutoSize = true;
			this->AutoLootDelLabel->Location = System::Drawing::Point(199, 20);
			this->AutoLootDelLabel->Name = L"AutoLootDelLabel";
			this->AutoLootDelLabel->Size = System::Drawing::Size(61, 14);
			this->AutoLootDelLabel->TabIndex = 15;
			this->AutoLootDelLabel->Text = L"Loot Delay:";
			// 
			// AutoLootDelText
			// 
			this->AutoLootDelText->Location = System::Drawing::Point(261, 17);
			this->AutoLootDelText->Name = L"AutoLootDelText";
			this->AutoLootDelText->Size = System::Drawing::Size(42, 20);
			this->AutoLootDelText->TabIndex = 11;
			this->AutoLootDelText->Text = L"200";
			this->AutoLootDelText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AutoLootItemsText
			// 
			this->AutoLootItemsText->Location = System::Drawing::Point(160, 17);
			this->AutoLootItemsText->Name = L"AutoLootItemsText";
			this->AutoLootItemsText->Size = System::Drawing::Size(35, 20);
			this->AutoLootItemsText->TabIndex = 9;
			this->AutoLootItemsText->Text = L"30";
			this->AutoLootItemsText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiGroup
			// 
			this->KamiGroup->Controls->Add(this->KamiItemLabel);
			this->KamiGroup->Controls->Add(this->KamiLootDelLabel);
			this->KamiGroup->Controls->Add(this->KamiDelayLabel);
			this->KamiGroup->Controls->Add(this->KamiItemsText);
			this->KamiGroup->Controls->Add(this->KamiYLabel);
			this->KamiGroup->Controls->Add(this->KamiXLabel);
			this->KamiGroup->Controls->Add(this->KamiLootDelText);
			this->KamiGroup->Controls->Add(this->KamiYText);
			this->KamiGroup->Controls->Add(this->KamiDelayText);
			this->KamiGroup->Controls->Add(this->KamiXText);
			this->KamiGroup->Controls->Add(this->KamiCB);
			this->KamiGroup->Controls->Add(this->KamiLootCB);
			this->KamiGroup->Enabled = false;
			this->KamiGroup->Location = System::Drawing::Point(6, 6);
			this->KamiGroup->Name = L"KamiGroup";
			this->KamiGroup->Size = System::Drawing::Size(309, 67);
			this->KamiGroup->TabIndex = 0;
			this->KamiGroup->TabStop = false;
			this->KamiGroup->Text = L"Kami + Kami Loot";
			// 
			// KamiItemLabel
			// 
			this->KamiItemLabel->AutoSize = true;
			this->KamiItemLabel->Location = System::Drawing::Point(90, 42);
			this->KamiItemLabel->Name = L"KamiItemLabel";
			this->KamiItemLabel->Size = System::Drawing::Size(68, 14);
			this->KamiItemLabel->TabIndex = 16;
			this->KamiItemLabel->Text = L"Item Amount:";
			// 
			// KamiLootDelLabel
			// 
			this->KamiLootDelLabel->AutoSize = true;
			this->KamiLootDelLabel->Location = System::Drawing::Point(199, 42);
			this->KamiLootDelLabel->Name = L"KamiLootDelLabel";
			this->KamiLootDelLabel->Size = System::Drawing::Size(61, 14);
			this->KamiLootDelLabel->TabIndex = 15;
			this->KamiLootDelLabel->Text = L"Loot Delay:";
			// 
			// KamiDelayLabel
			// 
			this->KamiDelayLabel->AutoSize = true;
			this->KamiDelayLabel->Location = System::Drawing::Point(201, 18);
			this->KamiDelayLabel->Name = L"KamiDelayLabel";
			this->KamiDelayLabel->Size = System::Drawing::Size(59, 14);
			this->KamiDelayLabel->TabIndex = 14;
			this->KamiDelayLabel->Text = L"Tele Delay:";
			// 
			// KamiItemsText
			// 
			this->KamiItemsText->Location = System::Drawing::Point(160, 39);
			this->KamiItemsText->Name = L"KamiItemsText";
			this->KamiItemsText->Size = System::Drawing::Size(35, 20);
			this->KamiItemsText->TabIndex = 9;
			this->KamiItemsText->Text = L"30";
			this->KamiItemsText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiYLabel
			// 
			this->KamiYLabel->AutoSize = true;
			this->KamiYLabel->Location = System::Drawing::Point(141, 18);
			this->KamiYLabel->Name = L"KamiYLabel";
			this->KamiYLabel->Size = System::Drawing::Size(17, 14);
			this->KamiYLabel->TabIndex = 13;
			this->KamiYLabel->Text = L"Y:";
			// 
			// KamiXLabel
			// 
			this->KamiXLabel->AutoSize = true;
			this->KamiXLabel->Location = System::Drawing::Point(83, 18);
			this->KamiXLabel->Name = L"KamiXLabel";
			this->KamiXLabel->Size = System::Drawing::Size(17, 14);
			this->KamiXLabel->TabIndex = 12;
			this->KamiXLabel->Text = L"X:";
			// 
			// KamiLootDelText
			// 
			this->KamiLootDelText->Location = System::Drawing::Point(261, 39);
			this->KamiLootDelText->Name = L"KamiLootDelText";
			this->KamiLootDelText->Size = System::Drawing::Size(42, 20);
			this->KamiLootDelText->TabIndex = 11;
			this->KamiLootDelText->Text = L"200";
			this->KamiLootDelText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiYText
			// 
			this->KamiYText->Location = System::Drawing::Point(160, 15);
			this->KamiYText->Name = L"KamiYText";
			this->KamiYText->Size = System::Drawing::Size(35, 20);
			this->KamiYText->TabIndex = 8;
			this->KamiYText->Text = L"0";
			this->KamiYText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiDelayText
			// 
			this->KamiDelayText->Location = System::Drawing::Point(261, 15);
			this->KamiDelayText->Name = L"KamiDelayText";
			this->KamiDelayText->Size = System::Drawing::Size(42, 20);
			this->KamiDelayText->TabIndex = 10;
			this->KamiDelayText->Text = L"150";
			this->KamiDelayText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiXText
			// 
			this->KamiXText->Location = System::Drawing::Point(102, 15);
			this->KamiXText->Name = L"KamiXText";
			this->KamiXText->Size = System::Drawing::Size(35, 20);
			this->KamiXText->TabIndex = 7;
			this->KamiXText->Text = L"0";
			this->KamiXText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// KamiCB
			// 
			this->KamiCB->AutoSize = true;
			this->KamiCB->Location = System::Drawing::Point(9, 17);
			this->KamiCB->Name = L"KamiCB";
			this->KamiCB->Size = System::Drawing::Size(49, 18);
			this->KamiCB->TabIndex = 5;
			this->KamiCB->Text = L"Kami";
			this->KamiCB->UseVisualStyleBackColor = true;
			this->KamiCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::KamiCB_CheckedChanged);
			// 
			// KamiLootCB
			// 
			this->KamiLootCB->AutoSize = true;
			this->KamiLootCB->Location = System::Drawing::Point(9, 41);
			this->KamiLootCB->Name = L"KamiLootCB";
			this->KamiLootCB->Size = System::Drawing::Size(73, 18);
			this->KamiLootCB->TabIndex = 6;
			this->KamiLootCB->Text = L"Kami Loot";
			this->KamiLootCB->UseVisualStyleBackColor = true;
			this->KamiLootCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::KamiLootCB_CheckedChanged);
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::SystemColors::MenuBar;
			this->tabPage5->Controls->Add(this->BPNDFAGroup);
			this->tabPage5->Controls->Add(this->TimedExitGroup);
			this->tabPage5->Controls->Add(this->DisableLootText);
			this->tabPage5->Controls->Add(this->TwoPointTeleGB);
			this->tabPage5->Controls->Add(this->MiscRandomGroup);
			this->tabPage5->Location = System::Drawing::Point(4, 23);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(321, 295);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Misc";
			// 
			// BPNDFAGroup
			// 
			this->BPNDFAGroup->Controls->Add(this->BPNDFAAFACB);
			this->BPNDFAGroup->Controls->Add(this->BPNDFAClassLabel);
			this->BPNDFAGroup->Controls->Add(this->BPNDFACombo);
			this->BPNDFAGroup->Controls->Add(this->BPNDFACB);
			this->BPNDFAGroup->Location = System::Drawing::Point(318, 242);
			this->BPNDFAGroup->Name = L"BPNDFAGroup";
			this->BPNDFAGroup->Size = System::Drawing::Size(309, 50);
			this->BPNDFAGroup->TabIndex = 6;
			this->BPNDFAGroup->TabStop = false;
			this->BPNDFAGroup->Text = L"NDFA (Bypass Required)";
			this->BPNDFAGroup->Visible = false;
			// 
			// BPNDFAAFACB
			// 
			this->BPNDFAAFACB->AutoSize = true;
			this->BPNDFAAFACB->Location = System::Drawing::Point(85, 20);
			this->BPNDFAAFACB->Name = L"BPNDFAAFACB";
			this->BPNDFAAFACB->Size = System::Drawing::Size(53, 18);
			this->BPNDFAAFACB->TabIndex = 7;
			this->BPNDFAAFACB->Text = L"AFA\?";
			this->BPNDFAAFACB->UseVisualStyleBackColor = true;
			// 
			// BPNDFAClassLabel
			// 
			this->BPNDFAClassLabel->AutoSize = true;
			this->BPNDFAClassLabel->Location = System::Drawing::Point(171, 21);
			this->BPNDFAClassLabel->Name = L"BPNDFAClassLabel";
			this->BPNDFAClassLabel->Size = System::Drawing::Size(37, 14);
			this->BPNDFAClassLabel->TabIndex = 6;
			this->BPNDFAClassLabel->Text = L"Class:";
			// 
			// BPNDFACombo
			// 
			this->BPNDFACombo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->BPNDFACombo->FormattingEnabled = true;
			this->BPNDFACombo->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"Fighter", L"Page", L"Spearman", L"Aran", L"Hunter", 
				L"Crossbowman", L"Mihile", L"Wind Archer", L"Wild Hunter", L"Mercedes", L"Evan"});
			this->BPNDFACombo->Location = System::Drawing::Point(211, 18);
			this->BPNDFACombo->Name = L"BPNDFACombo";
			this->BPNDFACombo->Size = System::Drawing::Size(85, 22);
			this->BPNDFACombo->TabIndex = 5;
			// 
			// BPNDFACB
			// 
			this->BPNDFACB->AutoSize = true;
			this->BPNDFACB->Location = System::Drawing::Point(10, 20);
			this->BPNDFACB->Name = L"BPNDFACB";
			this->BPNDFACB->Size = System::Drawing::Size(58, 18);
			this->BPNDFACB->TabIndex = 0;
			this->BPNDFACB->Text = L"Enable";
			this->BPNDFACB->UseVisualStyleBackColor = true;
			this->BPNDFACB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::BPNDFACB_CheckedChanged);
			// 
			// TimedExitGroup
			// 
			this->TimedExitGroup->Controls->Add(this->TimedExitMinLabel);
			this->TimedExitGroup->Controls->Add(this->TimedExitHoursLabel);
			this->TimedExitGroup->Controls->Add(this->TimedExitMinText);
			this->TimedExitGroup->Controls->Add(this->TimedExitHoursText);
			this->TimedExitGroup->Controls->Add(this->TimedExitCB);
			this->TimedExitGroup->Location = System::Drawing::Point(6, 148);
			this->TimedExitGroup->Name = L"TimedExitGroup";
			this->TimedExitGroup->Size = System::Drawing::Size(309, 48);
			this->TimedExitGroup->TabIndex = 5;
			this->TimedExitGroup->TabStop = false;
			this->TimedExitGroup->Text = L"Timed Exit";
			// 
			// TimedExitMinLabel
			// 
			this->TimedExitMinLabel->AutoSize = true;
			this->TimedExitMinLabel->Location = System::Drawing::Point(245, 20);
			this->TimedExitMinLabel->Name = L"TimedExitMinLabel";
			this->TimedExitMinLabel->Size = System::Drawing::Size(55, 14);
			this->TimedExitMinLabel->TabIndex = 4;
			this->TimedExitMinLabel->Text = L"minute(s).";
			// 
			// TimedExitHoursLabel
			// 
			this->TimedExitHoursLabel->AutoSize = true;
			this->TimedExitHoursLabel->Location = System::Drawing::Point(142, 20);
			this->TimedExitHoursLabel->Name = L"TimedExitHoursLabel";
			this->TimedExitHoursLabel->Size = System::Drawing::Size(64, 14);
			this->TimedExitHoursLabel->TabIndex = 3;
			this->TimedExitHoursLabel->Text = L"hour(s) and";
			// 
			// TimedExitMinText
			// 
			this->TimedExitMinText->Location = System::Drawing::Point(209, 17);
			this->TimedExitMinText->Name = L"TimedExitMinText";
			this->TimedExitMinText->Size = System::Drawing::Size(34, 20);
			this->TimedExitMinText->TabIndex = 2;
			this->TimedExitMinText->Text = L"0";
			this->TimedExitMinText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TimedExitHoursText
			// 
			this->TimedExitHoursText->Location = System::Drawing::Point(106, 17);
			this->TimedExitHoursText->Name = L"TimedExitHoursText";
			this->TimedExitHoursText->Size = System::Drawing::Size(34, 20);
			this->TimedExitHoursText->TabIndex = 1;
			this->TimedExitHoursText->Text = L"0";
			this->TimedExitHoursText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TimedExitCB
			// 
			this->TimedExitCB->AutoSize = true;
			this->TimedExitCB->Location = System::Drawing::Point(10, 19);
			this->TimedExitCB->Name = L"TimedExitCB";
			this->TimedExitCB->Size = System::Drawing::Size(87, 18);
			this->TimedExitCB->TabIndex = 0;
			this->TimedExitCB->Text = L"Exit MS after";
			this->TimedExitCB->UseVisualStyleBackColor = true;
			this->TimedExitCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TimedExitCB_CheckedChanged);
			// 
			// DisableLootText
			// 
			this->DisableLootText->Location = System::Drawing::Point(238, 47);
			this->DisableLootText->Name = L"DisableLootText";
			this->DisableLootText->Size = System::Drawing::Size(54, 20);
			this->DisableLootText->TabIndex = 4;
			this->DisableLootText->Text = L"0";
			this->DisableLootText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointTeleGB
			// 
			this->TwoPointTeleGB->Controls->Add(this->TwoPointDlyLabel2);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointDlyText);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointDlyLabel);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointGetPosBtn2);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointGetPosBtn1);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointYLabel);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointXLabel);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointX1Text);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointY2Text);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointY1Text);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointX2Text);
			this->TwoPointTeleGB->Controls->Add(this->TwoPointTeleCB);
			this->TwoPointTeleGB->Enabled = false;
			this->TwoPointTeleGB->Location = System::Drawing::Point(6, 195);
			this->TwoPointTeleGB->Name = L"TwoPointTeleGB";
			this->TwoPointTeleGB->Size = System::Drawing::Size(309, 90);
			this->TwoPointTeleGB->TabIndex = 0;
			this->TwoPointTeleGB->TabStop = false;
			this->TwoPointTeleGB->Text = L"2 Point Teleport";
			// 
			// TwoPointDlyLabel2
			// 
			this->TwoPointDlyLabel2->AutoSize = true;
			this->TwoPointDlyLabel2->Location = System::Drawing::Point(65, 63);
			this->TwoPointDlyLabel2->Name = L"TwoPointDlyLabel2";
			this->TwoPointDlyLabel2->Size = System::Drawing::Size(21, 14);
			this->TwoPointDlyLabel2->TabIndex = 11;
			this->TwoPointDlyLabel2->Text = L"ms";
			// 
			// TwoPointDlyText
			// 
			this->TwoPointDlyText->Location = System::Drawing::Point(10, 60);
			this->TwoPointDlyText->Name = L"TwoPointDlyText";
			this->TwoPointDlyText->Size = System::Drawing::Size(53, 20);
			this->TwoPointDlyText->TabIndex = 10;
			this->TwoPointDlyText->Text = L"10000";
			this->TwoPointDlyText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointDlyLabel
			// 
			this->TwoPointDlyLabel->AutoSize = true;
			this->TwoPointDlyLabel->Location = System::Drawing::Point(7, 43);
			this->TwoPointDlyLabel->Name = L"TwoPointDlyLabel";
			this->TwoPointDlyLabel->Size = System::Drawing::Size(78, 14);
			this->TwoPointDlyLabel->TabIndex = 9;
			this->TwoPointDlyLabel->Text = L"Teleport Delay:";
			// 
			// TwoPointGetPosBtn2
			// 
			this->TwoPointGetPosBtn2->Location = System::Drawing::Point(211, 55);
			this->TwoPointGetPosBtn2->Name = L"TwoPointGetPosBtn2";
			this->TwoPointGetPosBtn2->Size = System::Drawing::Size(85, 23);
			this->TwoPointGetPosBtn2->TabIndex = 8;
			this->TwoPointGetPosBtn2->Text = L"Get Position";
			this->TwoPointGetPosBtn2->UseVisualStyleBackColor = true;
			this->TwoPointGetPosBtn2->Click += gcnew System::EventHandler(this, &MainForm::TwoPointGetPosBtn2_Click);
			// 
			// TwoPointGetPosBtn1
			// 
			this->TwoPointGetPosBtn1->Location = System::Drawing::Point(211, 29);
			this->TwoPointGetPosBtn1->Name = L"TwoPointGetPosBtn1";
			this->TwoPointGetPosBtn1->Size = System::Drawing::Size(85, 23);
			this->TwoPointGetPosBtn1->TabIndex = 7;
			this->TwoPointGetPosBtn1->Text = L"Get Position";
			this->TwoPointGetPosBtn1->UseVisualStyleBackColor = true;
			this->TwoPointGetPosBtn1->Click += gcnew System::EventHandler(this, &MainForm::TwoPointGetPosBtn1_Click);
			// 
			// TwoPointYLabel
			// 
			this->TwoPointYLabel->AutoSize = true;
			this->TwoPointYLabel->Location = System::Drawing::Point(171, 16);
			this->TwoPointYLabel->Name = L"TwoPointYLabel";
			this->TwoPointYLabel->Size = System::Drawing::Size(15, 14);
			this->TwoPointYLabel->TabIndex = 6;
			this->TwoPointYLabel->Text = L"Y";
			// 
			// TwoPointXLabel
			// 
			this->TwoPointXLabel->AutoSize = true;
			this->TwoPointXLabel->Location = System::Drawing::Point(121, 16);
			this->TwoPointXLabel->Name = L"TwoPointXLabel";
			this->TwoPointXLabel->Size = System::Drawing::Size(14, 14);
			this->TwoPointXLabel->TabIndex = 5;
			this->TwoPointXLabel->Text = L"X";
			// 
			// TwoPointX1Text
			// 
			this->TwoPointX1Text->Location = System::Drawing::Point(106, 30);
			this->TwoPointX1Text->Name = L"TwoPointX1Text";
			this->TwoPointX1Text->Size = System::Drawing::Size(45, 20);
			this->TwoPointX1Text->TabIndex = 4;
			this->TwoPointX1Text->Text = L"0";
			this->TwoPointX1Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointY2Text
			// 
			this->TwoPointY2Text->Location = System::Drawing::Point(156, 56);
			this->TwoPointY2Text->Name = L"TwoPointY2Text";
			this->TwoPointY2Text->Size = System::Drawing::Size(45, 20);
			this->TwoPointY2Text->TabIndex = 3;
			this->TwoPointY2Text->Text = L"0";
			this->TwoPointY2Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointY1Text
			// 
			this->TwoPointY1Text->Location = System::Drawing::Point(156, 30);
			this->TwoPointY1Text->Name = L"TwoPointY1Text";
			this->TwoPointY1Text->Size = System::Drawing::Size(45, 20);
			this->TwoPointY1Text->TabIndex = 2;
			this->TwoPointY1Text->Text = L"0";
			this->TwoPointY1Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointX2Text
			// 
			this->TwoPointX2Text->Location = System::Drawing::Point(106, 56);
			this->TwoPointX2Text->Name = L"TwoPointX2Text";
			this->TwoPointX2Text->Size = System::Drawing::Size(45, 20);
			this->TwoPointX2Text->TabIndex = 1;
			this->TwoPointX2Text->Text = L"0";
			this->TwoPointX2Text->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// TwoPointTeleCB
			// 
			this->TwoPointTeleCB->AutoSize = true;
			this->TwoPointTeleCB->Location = System::Drawing::Point(10, 19);
			this->TwoPointTeleCB->Name = L"TwoPointTeleCB";
			this->TwoPointTeleCB->Size = System::Drawing::Size(58, 18);
			this->TwoPointTeleCB->TabIndex = 0;
			this->TwoPointTeleCB->Text = L"Enable";
			this->TwoPointTeleCB->UseVisualStyleBackColor = true;
			this->TwoPointTeleCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TwoPointTeleCB_CheckedChanged);
			// 
			// MiscRandomGroup
			// 
			this->MiscRandomGroup->Controls->Add(this->TeleWalkUpDown);
			this->MiscRandomGroup->Controls->Add(this->TeleWalkDistLabel);
			this->MiscRandomGroup->Controls->Add(this->TeleWalkCB);
			this->MiscRandomGroup->Controls->Add(this->AutoGourdCB);
			this->MiscRandomGroup->Controls->Add(this->FTFDelayText);
			this->MiscRandomGroup->Controls->Add(this->DisableSkillWaitCB);
			this->MiscRandomGroup->Controls->Add(this->DisableKamiLootCB);
			this->MiscRandomGroup->Controls->Add(this->FTFDelayCB);
			this->MiscRandomGroup->Location = System::Drawing::Point(6, 6);
			this->MiscRandomGroup->Name = L"MiscRandomGroup";
			this->MiscRandomGroup->Size = System::Drawing::Size(309, 141);
			this->MiscRandomGroup->TabIndex = 0;
			this->MiscRandomGroup->TabStop = false;
			this->MiscRandomGroup->Text = L"Random";
			// 
			// TeleWalkUpDown
			// 
			this->TeleWalkUpDown->Location = System::Drawing::Point(169, 114);
			this->TeleWalkUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {5000, 0, 0, 0});
			this->TeleWalkUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->TeleWalkUpDown->Name = L"TeleWalkUpDown";
			this->TeleWalkUpDown->Size = System::Drawing::Size(47, 20);
			this->TeleWalkUpDown->TabIndex = 8;
			this->TeleWalkUpDown->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->TeleWalkUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			// 
			// TeleWalkDistLabel
			// 
			this->TeleWalkDistLabel->AutoSize = true;
			this->TeleWalkDistLabel->Location = System::Drawing::Point(116, 116);
			this->TeleWalkDistLabel->Name = L"TeleWalkDistLabel";
			this->TeleWalkDistLabel->Size = System::Drawing::Size(52, 14);
			this->TeleWalkDistLabel->TabIndex = 7;
			this->TeleWalkDistLabel->Text = L"Distance:";
			// 
			// TeleWalkCB
			// 
			this->TeleWalkCB->AutoSize = true;
			this->TeleWalkCB->Enabled = false;
			this->TeleWalkCB->Location = System::Drawing::Point(10, 115);
			this->TeleWalkCB->Name = L"TeleWalkCB";
			this->TeleWalkCB->Size = System::Drawing::Size(90, 18);
			this->TeleWalkCB->TabIndex = 6;
			this->TeleWalkCB->Text = L"Teleport Walk";
			this->TeleWalkCB->UseVisualStyleBackColor = true;
			this->TeleWalkCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::TeleWalkCB_CheckedChanged);
			// 
			// AutoGourdCB
			// 
			this->AutoGourdCB->AutoSize = true;
			this->AutoGourdCB->Enabled = false;
			this->AutoGourdCB->Location = System::Drawing::Point(10, 91);
			this->AutoGourdCB->Name = L"AutoGourdCB";
			this->AutoGourdCB->Size = System::Drawing::Size(137, 18);
			this->AutoGourdCB->TabIndex = 5;
			this->AutoGourdCB->Text = L"Auto AFK Gourd Quest";
			this->AutoGourdCB->UseVisualStyleBackColor = true;
			this->AutoGourdCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::AutoGourdCB_CheckedChanged);
			// 
			// FTFDelayText
			// 
			this->FTFDelayText->Location = System::Drawing::Point(232, 17);
			this->FTFDelayText->Name = L"FTFDelayText";
			this->FTFDelayText->Size = System::Drawing::Size(54, 20);
			this->FTFDelayText->TabIndex = 3;
			this->FTFDelayText->Text = L"60";
			this->FTFDelayText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// DisableSkillWaitCB
			// 
			this->DisableSkillWaitCB->AutoSize = true;
			this->DisableSkillWaitCB->Checked = true;
			this->DisableSkillWaitCB->CheckState = System::Windows::Forms::CheckState::Checked;
			this->DisableSkillWaitCB->Location = System::Drawing::Point(10, 67);
			this->DisableSkillWaitCB->Name = L"DisableSkillWaitCB";
			this->DisableSkillWaitCB->Size = System::Drawing::Size(184, 18);
			this->DisableSkillWaitCB->TabIndex = 2;
			this->DisableSkillWaitCB->Text = L"Disable 3 second Auto Skill delay";
			this->DisableSkillWaitCB->UseVisualStyleBackColor = true;
			this->DisableSkillWaitCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::DisableSkillWaitCB_CheckedChanged);
			// 
			// DisableKamiLootCB
			// 
			this->DisableKamiLootCB->AutoSize = true;
			this->DisableKamiLootCB->Enabled = false;
			this->DisableKamiLootCB->Location = System::Drawing::Point(10, 43);
			this->DisableKamiLootCB->Name = L"DisableKamiLootCB";
			this->DisableKamiLootCB->Size = System::Drawing::Size(219, 18);
			this->DisableKamiLootCB->TabIndex = 1;
			this->DisableKamiLootCB->Text = L"Disable Kami Loot after ______ minutes:";
			this->DisableKamiLootCB->UseVisualStyleBackColor = true;
			this->DisableKamiLootCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::DisableKamiLootCB_CheckedChanged);
			// 
			// FTFDelayCB
			// 
			this->FTFDelayCB->AutoSize = true;
			this->FTFDelayCB->Enabled = false;
			this->FTFDelayCB->Location = System::Drawing::Point(10, 19);
			this->FTFDelayCB->Name = L"FTFDelayCB";
			this->FTFDelayCB->Size = System::Drawing::Size(220, 18);
			this->FTFDelayCB->TabIndex = 0;
			this->FTFDelayCB->Text = L"Fall through Floor after ______ minutes: ";
			this->FTFDelayCB->UseVisualStyleBackColor = true;
			this->FTFDelayCB->CheckedChanged += gcnew System::EventHandler(this, &MainForm::FTFDelayCB_CheckedChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuStrip1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"menuStrip1.BackgroundImage")));
			this->menuStrip1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileToolStripMenuItem, 
				this->toolsToolStripMenuItem, this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(329, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->TabStop = true;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->saveSettingsToolStripMenuItem, 
				this->loadSettingsToolStripMenuItem, this->exitMSToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveSettingsToolStripMenuItem
			// 
			this->saveSettingsToolStripMenuItem->Name = L"saveSettingsToolStripMenuItem";
			this->saveSettingsToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->saveSettingsToolStripMenuItem->Text = L"Save Settings";
			this->saveSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveSettingsToolStripMenuItem_Click);
			// 
			// loadSettingsToolStripMenuItem
			// 
			this->loadSettingsToolStripMenuItem->Name = L"loadSettingsToolStripMenuItem";
			this->loadSettingsToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->loadSettingsToolStripMenuItem->Text = L"Load Settings";
			this->loadSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::loadSettingsToolStripMenuItem_Click);
			// 
			// exitMSToolStripMenuItem
			// 
			this->exitMSToolStripMenuItem->Name = L"exitMSToolStripMenuItem";
			this->exitMSToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->exitMSToolStripMenuItem->Text = L"Exit MS";
			this->exitMSToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitMSToolStripMenuItem_Click);
			// 
			// toolsToolStripMenuItem
			// 
			this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->pointerInfoToolStripMenuItem, 
				this->advancedToolsToolStripMenuItem, this->toolStripSeparator1, this->enableHotkeysToolStripMenuItem, this->attachToMSToolStripMenuItem, 
				this->hideMSToolStripMenuItem});
			this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
			this->toolsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->toolsToolStripMenuItem->Text = L"Tools";
			// 
			// pointerInfoToolStripMenuItem
			// 
			this->pointerInfoToolStripMenuItem->Name = L"pointerInfoToolStripMenuItem";
			this->pointerInfoToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->pointerInfoToolStripMenuItem->Text = L"Pointer Info";
			this->pointerInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pointerInfoToolStripMenuItem_Click);
			// 
			// advancedToolsToolStripMenuItem
			// 
			this->advancedToolsToolStripMenuItem->Name = L"advancedToolsToolStripMenuItem";
			this->advancedToolsToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->advancedToolsToolStripMenuItem->Text = L"Advanced Tools";
			this->advancedToolsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::advancedToolsToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(156, 6);
			// 
			// enableHotkeysToolStripMenuItem
			// 
			this->enableHotkeysToolStripMenuItem->Name = L"enableHotkeysToolStripMenuItem";
			this->enableHotkeysToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->enableHotkeysToolStripMenuItem->Text = L"Enable Hotkeys";
			this->enableHotkeysToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::enableHotkeysToolStripMenuItem_Click);
			// 
			// attachToMSToolStripMenuItem
			// 
			this->attachToMSToolStripMenuItem->Name = L"attachToMSToolStripMenuItem";
			this->attachToMSToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->attachToMSToolStripMenuItem->Text = L"Attach to MS";
			this->attachToMSToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::attachToMSToolStripMenuItem_Click);
			// 
			// hideMSToolStripMenuItem
			// 
			this->hideMSToolStripMenuItem->Name = L"hideMSToolStripMenuItem";
			this->hideMSToolStripMenuItem->Size = System::Drawing::Size(159, 22);
			this->hideMSToolStripMenuItem->Text = L"Hide MS";
			this->hideMSToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hideMSToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->hypnoBotBlogToolStripMenuItem, 
				this->gKThreadToolStripMenuItem, this->hotKeyInfoToolStripMenuItem, this->hackInfoiToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// hypnoBotBlogToolStripMenuItem
			// 
			this->hypnoBotBlogToolStripMenuItem->Name = L"hypnoBotBlogToolStripMenuItem";
			this->hypnoBotBlogToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->hypnoBotBlogToolStripMenuItem->Text = L"HypnoBot Blog";
			this->hypnoBotBlogToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hypnoBotBlogToolStripMenuItem_Click);
			// 
			// gKThreadToolStripMenuItem
			// 
			this->gKThreadToolStripMenuItem->Name = L"gKThreadToolStripMenuItem";
			this->gKThreadToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->gKThreadToolStripMenuItem->Text = L"GK Thread";
			this->gKThreadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::gKThreadToolStripMenuItem_Click);
			// 
			// hotKeyInfoToolStripMenuItem
			// 
			this->hotKeyInfoToolStripMenuItem->Name = L"hotKeyInfoToolStripMenuItem";
			this->hotKeyInfoToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->hotKeyInfoToolStripMenuItem->Text = L"HotKey Info";
			this->hotKeyInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hotKeyInfoToolStripMenuItem_Click);
			// 
			// hackInfoiToolStripMenuItem
			// 
			this->hackInfoiToolStripMenuItem->Name = L"hackInfoiToolStripMenuItem";
			this->hackInfoiToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->hackInfoiToolStripMenuItem->Text = L"Hack Info";
			this->hackInfoiToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hackInfoiToolStripMenuItem_Click);
			// 
			// MadeByLabel
			// 
			this->MadeByLabel->AutoSize = true;
			this->MadeByLabel->Location = System::Drawing::Point(1, 348);
			this->MadeByLabel->Name = L"MadeByLabel";
			this->MadeByLabel->Size = System::Drawing::Size(117, 14);
			this->MadeByLabel->TabIndex = 3;
			this->MadeByLabel->Text = L"Made By: HypnoSmiley";
			// 
			// GKLinkLabel
			// 
			this->GKLinkLabel->AutoSize = true;
			this->GKLinkLabel->LinkBehavior = System::Windows::Forms::LinkBehavior::HoverUnderline;
			this->GKLinkLabel->Location = System::Drawing::Point(222, 348);
			this->GKLinkLabel->Name = L"GKLinkLabel";
			this->GKLinkLabel->Size = System::Drawing::Size(103, 14);
			this->GKLinkLabel->TabIndex = 4;
			this->GKLinkLabel->TabStop = true;
			this->GKLinkLabel->Text = L"www.gamekiller.net";
			this->GKLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::GKLinkLabel_LinkClicked);
			// 
			// HPMPAlertFix
			// 
			this->HPMPAlertFix->Enabled = true;
			this->HPMPAlertFix->Interval = 1000;
			this->HPMPAlertFix->Tick += gcnew System::EventHandler(this, &MainForm::HPMPAlertFix_Tick);
			// 
			// AutoSkill1Timer
			// 
			this->AutoSkill1Timer->Tick += gcnew System::EventHandler(this, &MainForm::AutoSkill1Timer_Tick);
			// 
			// AutoSkill2Timer
			// 
			this->AutoSkill2Timer->Tick += gcnew System::EventHandler(this, &MainForm::AutoSkill2Timer_Tick);
			// 
			// AutoSkill3Timer
			// 
			this->AutoSkill3Timer->Tick += gcnew System::EventHandler(this, &MainForm::AutoSkill3Timer_Tick);
			// 
			// AutoSkill4Timer
			// 
			this->AutoSkill4Timer->Tick += gcnew System::EventHandler(this, &MainForm::AutoSkill4Timer_Tick);
			// 
			// TeleIntervalTimer
			// 
			this->TeleIntervalTimer->Tick += gcnew System::EventHandler(this, &MainForm::TeleIntervalTimer_Tick);
			// 
			// FTFDelayTimer
			// 
			this->FTFDelayTimer->Tick += gcnew System::EventHandler(this, &MainForm::FTFDelayTimer_Tick);
			// 
			// DisableKamiLootTimer
			// 
			this->DisableKamiLootTimer->Tick += gcnew System::EventHandler(this, &MainForm::DisableKamiLootTimer_Tick);
			// 
			// HotkeyTimer
			// 
			this->HotkeyTimer->Tick += gcnew System::EventHandler(this, &MainForm::HotkeyTimer_Tick);
			// 
			// TimedExitTimer
			// 
			this->TimedExitTimer->Tick += gcnew System::EventHandler(this, &MainForm::TimedExitTimer_Tick);
			// 
			// AutoGourdTimer
			// 
			this->AutoGourdTimer->Interval = 1900000;
			this->AutoGourdTimer->Tick += gcnew System::EventHandler(this, &MainForm::AutoGourdTimer_Tick);
			// 
			// AutoGourdTimer2
			// 
			this->AutoGourdTimer2->Interval = 20000;
			this->AutoGourdTimer2->Tick += gcnew System::EventHandler(this, &MainForm::AutoGourdTimer2_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::SystemColors::MenuBar;
			this->ClientSize = System::Drawing::Size(329, 363);
			this->Controls->Add(this->GKLinkLabel);
			this->Controls->Add(this->MadeByLabel);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"HypnoBot";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Banner))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->AutoCCGroup->ResumeLayout(false);
			this->AutoCCGroup->PerformLayout();
			this->AutoKeyGroup->ResumeLayout(false);
			this->AutoKeyGroup->PerformLayout();
			this->AutoPotGroup->ResumeLayout(false);
			this->AutoPotGroup->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->BypassHacksGB->ResumeLayout(false);
			this->BypassHacksGB->PerformLayout();
			this->NDFAGroup->ResumeLayout(false);
			this->NDFAGroup->PerformLayout();
			this->BypasslessHacksGB->ResumeLayout(false);
			this->BypasslessHacksGB->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->OtherVacGroup->ResumeLayout(false);
			this->OtherVacGroup->PerformLayout();
			this->ItemVacGroup->ResumeLayout(false);
			this->ItemVacGroup->PerformLayout();
			this->TeleportGroup->ResumeLayout(false);
			this->TeleportGroup->PerformLayout();
			this->AutoLootVacGB->ResumeLayout(false);
			this->AutoLootVacGB->PerformLayout();
			this->KamiGroup->ResumeLayout(false);
			this->KamiGroup->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			this->BPNDFAGroup->ResumeLayout(false);
			this->BPNDFAGroup->PerformLayout();
			this->TimedExitGroup->ResumeLayout(false);
			this->TimedExitGroup->PerformLayout();
			this->TwoPointTeleGB->ResumeLayout(false);
			this->TwoPointTeleGB->PerformLayout();
			this->MiscRandomGroup->ResumeLayout(false);
			this->MiscRandomGroup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->TeleWalkUpDown))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Form Load
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e);

	//Auto Pot
	private: System::Void AutoHPCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoMPCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	
	//Auto CC, CS, and People CC
	private: System::Void AutoCCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoCSCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PeopleCCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//Auto Keys
	private: System::Void AutoAtkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill1CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill2CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill3CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill4CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// Bypassless Hacks
	private: System::Void ClickFlyCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TubiCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MorphGMCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoBreathCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void BLUACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleUACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MobDisarmCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FMACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	// Bypass Hacks
	private: System::Void FullGMCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void MultiDmgCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AirLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void InstantDropCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoAtkLimitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoLootAnimCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoMobLagCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void SlowMobsCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void UnlimAtkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FLACCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NoKBCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void UnlimKaiserCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CPUHack1CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void CPUHack2CB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HideDamageCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//NDFA
	private: System::Void NDFACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void NDFAAFACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){}

	//Kami + Kami Loot
	private: System::Void KamiCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void KamiLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//Auto Loot Vac
	private: System::Void AutoLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	
	//Teleport
	private: System::Void TeleportCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleGetPosBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleTeleBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleportInfoBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleDelayCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	
	//Fixed Item Vac
	private: System::Void ItemVacCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void ItemVacGetPosBtn_Click(System::Object^  sender, System::EventArgs^  e);
	
	//Other (Vacs Tab)
	private: System::Void LootBfrCCCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e){}
	private: System::Void LootNoMobsCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void KamiWallcheckCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//Misc Random
	private: System::Void FTFDelayCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DisableKamiLootCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DisableSkillWaitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TimedExitCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoGourdCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TeleWalkCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//2 Point Tele
	private: System::Void TwoPointTeleCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TwoPointGetPosBtn1_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void TwoPointGetPosBtn2_Click(System::Object^  sender, System::EventArgs^  e);

	//Bypass NDFA
	private: System::Void BPNDFACB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);

	//Menu Items
	private: System::Void saveSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void loadSettingsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void exitMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void pointerInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 { this->PntrInfoFrm->Visible = PntrInfoFrm->Visible ? false : true; }
	private: System::Void advancedToolsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 { this->AdvToolsFrm->Visible = AdvToolsFrm->Visible ? false : true; }

	private: System::Void enableHotkeysToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hideMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hotKeyInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void hackInfoiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void hypnoBotBlogToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 { Process::Start("http://www.hypnobot.blogspot.com"); }
	private: System::Void gKThreadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
			 { Process::Start("http://www.gamekiller.net/global-maplestory-hacks-bots/3162940-hypnobot-gms-v-124-2c-bypassless-botting.html"); }
	private: System::Void attachToMSToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);

	//GK Link
	private: System::Void GKLinkLabel_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
			 { Process::Start("http://www.gamekiller.net"); }

	// Timers
	private: System::Void HPMPAlertFix_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void AutoSkill1Timer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill2Timer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill3Timer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoSkill4Timer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void TeleIntervalTimer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void FTFDelayTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void DisableKamiLootTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void HotkeyTimer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void TimedExitTimer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void AutoGourdTimer_Tick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AutoGourdTimer2_Tick(System::Object^  sender, System::EventArgs^  e);

};
}