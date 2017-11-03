#pragma once

namespace HypnoBot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PtrInfoForm
	/// </summary>
	public ref class PtrInfoForm : public System::Windows::Forms::Form
	{
	public:
		PtrInfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PtrInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  WorldLabel;
	protected: 
	private: System::Windows::Forms::GroupBox^  PointerGroup;
	private: System::Windows::Forms::CheckBox^  StayOnTopCB;
	private: System::Windows::Forms::Label^  TeleXYLabel;
	private: System::Windows::Forms::Label^  MobXYLabel;
	private: System::Windows::Forms::Label^  MouseXYLabel;
	private: System::Windows::Forms::Label^  MobsLabel;
	private: System::Windows::Forms::Label^  CharXYLabel;
	private: System::Windows::Forms::Label^  ItemIDLabel;
	private: System::Windows::Forms::Label^  BreathLabel;
	private: System::Windows::Forms::Label^  ItemsLabel;
	private: System::Windows::Forms::Label^  AttacksLabel;
	private: System::Windows::Forms::Label^  PeopleLabel;
	private: System::Windows::Forms::Label^  ExpLabel;
	private: System::Windows::Forms::Label^  MapIDLabel;
	private: System::Windows::Forms::Label^  ManaLabel;
	private: System::Windows::Forms::Label^  ChannelLabel;
	private: System::Windows::Forms::Label^  HealthLabel;
	private: System::Windows::Forms::Timer^  PtrUpdateTimer;
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
			this->WorldLabel = (gcnew System::Windows::Forms::Label());
			this->PointerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->StayOnTopCB = (gcnew System::Windows::Forms::CheckBox());
			this->TeleXYLabel = (gcnew System::Windows::Forms::Label());
			this->MobXYLabel = (gcnew System::Windows::Forms::Label());
			this->MouseXYLabel = (gcnew System::Windows::Forms::Label());
			this->MobsLabel = (gcnew System::Windows::Forms::Label());
			this->CharXYLabel = (gcnew System::Windows::Forms::Label());
			this->ItemIDLabel = (gcnew System::Windows::Forms::Label());
			this->BreathLabel = (gcnew System::Windows::Forms::Label());
			this->ItemsLabel = (gcnew System::Windows::Forms::Label());
			this->AttacksLabel = (gcnew System::Windows::Forms::Label());
			this->PeopleLabel = (gcnew System::Windows::Forms::Label());
			this->ExpLabel = (gcnew System::Windows::Forms::Label());
			this->MapIDLabel = (gcnew System::Windows::Forms::Label());
			this->ManaLabel = (gcnew System::Windows::Forms::Label());
			this->ChannelLabel = (gcnew System::Windows::Forms::Label());
			this->HealthLabel = (gcnew System::Windows::Forms::Label());
			this->PtrUpdateTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->PointerGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// WorldLabel
			// 
			this->WorldLabel->AutoSize = true;
			this->WorldLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->WorldLabel->Location = System::Drawing::Point(9, 16);
			this->WorldLabel->Name = L"WorldLabel";
			this->WorldLabel->Size = System::Drawing::Size(44, 15);
			this->WorldLabel->TabIndex = 0;
			this->WorldLabel->Text = L"World:";
			// 
			// PointerGroup
			// 
			this->PointerGroup->Controls->Add(this->StayOnTopCB);
			this->PointerGroup->Controls->Add(this->TeleXYLabel);
			this->PointerGroup->Controls->Add(this->MobXYLabel);
			this->PointerGroup->Controls->Add(this->MouseXYLabel);
			this->PointerGroup->Controls->Add(this->MobsLabel);
			this->PointerGroup->Controls->Add(this->CharXYLabel);
			this->PointerGroup->Controls->Add(this->ItemIDLabel);
			this->PointerGroup->Controls->Add(this->BreathLabel);
			this->PointerGroup->Controls->Add(this->ItemsLabel);
			this->PointerGroup->Controls->Add(this->AttacksLabel);
			this->PointerGroup->Controls->Add(this->PeopleLabel);
			this->PointerGroup->Controls->Add(this->ExpLabel);
			this->PointerGroup->Controls->Add(this->MapIDLabel);
			this->PointerGroup->Controls->Add(this->ManaLabel);
			this->PointerGroup->Controls->Add(this->ChannelLabel);
			this->PointerGroup->Controls->Add(this->HealthLabel);
			this->PointerGroup->Controls->Add(this->WorldLabel);
			this->PointerGroup->Location = System::Drawing::Point(3, -3);
			this->PointerGroup->Name = L"PointerGroup";
			this->PointerGroup->Size = System::Drawing::Size(302, 209);
			this->PointerGroup->TabIndex = 1;
			this->PointerGroup->TabStop = false;
			// 
			// StayOnTopCB
			// 
			this->StayOnTopCB->AutoSize = true;
			this->StayOnTopCB->Location = System::Drawing::Point(281, 15);
			this->StayOnTopCB->Name = L"StayOnTopCB";
			this->StayOnTopCB->Size = System::Drawing::Size(15, 14);
			this->StayOnTopCB->TabIndex = 1;
			this->StayOnTopCB->UseVisualStyleBackColor = true;
			this->StayOnTopCB->CheckedChanged += gcnew System::EventHandler(this, &PtrInfoForm::StayOnTopCB_CheckedChanged);
			// 
			// TeleXYLabel
			// 
			this->TeleXYLabel->AutoSize = true;
			this->TeleXYLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TeleXYLabel->Location = System::Drawing::Point(148, 184);
			this->TeleXYLabel->Name = L"TeleXYLabel";
			this->TeleXYLabel->Size = System::Drawing::Size(50, 15);
			this->TeleXYLabel->TabIndex = 0;
			this->TeleXYLabel->Text = L"Tele XY:";
			// 
			// MobXYLabel
			// 
			this->MobXYLabel->AutoSize = true;
			this->MobXYLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MobXYLabel->Location = System::Drawing::Point(9, 184);
			this->MobXYLabel->Name = L"MobXYLabel";
			this->MobXYLabel->Size = System::Drawing::Size(51, 15);
			this->MobXYLabel->TabIndex = 0;
			this->MobXYLabel->Text = L"Mob XY:";
			// 
			// MouseXYLabel
			// 
			this->MouseXYLabel->AutoSize = true;
			this->MouseXYLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MouseXYLabel->Location = System::Drawing::Point(148, 160);
			this->MouseXYLabel->Name = L"MouseXYLabel";
			this->MouseXYLabel->Size = System::Drawing::Size(65, 15);
			this->MouseXYLabel->TabIndex = 0;
			this->MouseXYLabel->Text = L"Mouse XY:";
			// 
			// MobsLabel
			// 
			this->MobsLabel->AutoSize = true;
			this->MobsLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MobsLabel->Location = System::Drawing::Point(9, 160);
			this->MobsLabel->Name = L"MobsLabel";
			this->MobsLabel->Size = System::Drawing::Size(41, 15);
			this->MobsLabel->TabIndex = 0;
			this->MobsLabel->Text = L"Mobs:";
			// 
			// CharXYLabel
			// 
			this->CharXYLabel->AutoSize = true;
			this->CharXYLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CharXYLabel->Location = System::Drawing::Point(148, 136);
			this->CharXYLabel->Name = L"CharXYLabel";
			this->CharXYLabel->Size = System::Drawing::Size(54, 15);
			this->CharXYLabel->TabIndex = 0;
			this->CharXYLabel->Text = L"Char XY:";
			// 
			// ItemIDLabel
			// 
			this->ItemIDLabel->AutoSize = true;
			this->ItemIDLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ItemIDLabel->Location = System::Drawing::Point(9, 136);
			this->ItemIDLabel->Name = L"ItemIDLabel";
			this->ItemIDLabel->Size = System::Drawing::Size(49, 15);
			this->ItemIDLabel->TabIndex = 0;
			this->ItemIDLabel->Text = L"Item ID:";
			// 
			// BreathLabel
			// 
			this->BreathLabel->AutoSize = true;
			this->BreathLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->BreathLabel->Location = System::Drawing::Point(148, 112);
			this->BreathLabel->Name = L"BreathLabel";
			this->BreathLabel->Size = System::Drawing::Size(48, 15);
			this->BreathLabel->TabIndex = 0;
			this->BreathLabel->Text = L"Breath:";
			// 
			// ItemsLabel
			// 
			this->ItemsLabel->AutoSize = true;
			this->ItemsLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ItemsLabel->Location = System::Drawing::Point(9, 112);
			this->ItemsLabel->Name = L"ItemsLabel";
			this->ItemsLabel->Size = System::Drawing::Size(42, 15);
			this->ItemsLabel->TabIndex = 0;
			this->ItemsLabel->Text = L"Items:";
			// 
			// AttacksLabel
			// 
			this->AttacksLabel->AutoSize = true;
			this->AttacksLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->AttacksLabel->Location = System::Drawing::Point(148, 88);
			this->AttacksLabel->Name = L"AttacksLabel";
			this->AttacksLabel->Size = System::Drawing::Size(54, 15);
			this->AttacksLabel->TabIndex = 0;
			this->AttacksLabel->Text = L"Attacks:";
			// 
			// PeopleLabel
			// 
			this->PeopleLabel->AutoSize = true;
			this->PeopleLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->PeopleLabel->Location = System::Drawing::Point(9, 88);
			this->PeopleLabel->Name = L"PeopleLabel";
			this->PeopleLabel->Size = System::Drawing::Size(49, 15);
			this->PeopleLabel->TabIndex = 0;
			this->PeopleLabel->Text = L"People:";
			// 
			// ExpLabel
			// 
			this->ExpLabel->AutoSize = true;
			this->ExpLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ExpLabel->Location = System::Drawing::Point(148, 64);
			this->ExpLabel->Name = L"ExpLabel";
			this->ExpLabel->Size = System::Drawing::Size(31, 15);
			this->ExpLabel->TabIndex = 0;
			this->ExpLabel->Text = L"Exp:";
			// 
			// MapIDLabel
			// 
			this->MapIDLabel->AutoSize = true;
			this->MapIDLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MapIDLabel->Location = System::Drawing::Point(9, 64);
			this->MapIDLabel->Name = L"MapIDLabel";
			this->MapIDLabel->Size = System::Drawing::Size(48, 15);
			this->MapIDLabel->TabIndex = 0;
			this->MapIDLabel->Text = L"Map ID:";
			// 
			// ManaLabel
			// 
			this->ManaLabel->AutoSize = true;
			this->ManaLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ManaLabel->Location = System::Drawing::Point(148, 40);
			this->ManaLabel->Name = L"ManaLabel";
			this->ManaLabel->Size = System::Drawing::Size(41, 15);
			this->ManaLabel->TabIndex = 0;
			this->ManaLabel->Text = L"Mana:";
			// 
			// ChannelLabel
			// 
			this->ChannelLabel->AutoSize = true;
			this->ChannelLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->ChannelLabel->Location = System::Drawing::Point(9, 40);
			this->ChannelLabel->Name = L"ChannelLabel";
			this->ChannelLabel->Size = System::Drawing::Size(56, 15);
			this->ChannelLabel->TabIndex = 0;
			this->ChannelLabel->Text = L"Channel:";
			// 
			// HealthLabel
			// 
			this->HealthLabel->AutoSize = true;
			this->HealthLabel->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->HealthLabel->Location = System::Drawing::Point(148, 16);
			this->HealthLabel->Name = L"HealthLabel";
			this->HealthLabel->Size = System::Drawing::Size(46, 15);
			this->HealthLabel->TabIndex = 0;
			this->HealthLabel->Text = L"Health:";
			// 
			// PtrUpdateTimer
			// 
			this->PtrUpdateTimer->Tick += gcnew System::EventHandler(this, &PtrInfoForm::PtrUpdateTimer_Tick);
			// 
			// PtrInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(308, 209);
			this->Controls->Add(this->PointerGroup);
			this->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"PtrInfoForm";
			this->Text = L" Pointer Info";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PtrInfoForm::PtrInfoForm_FormClosing);
			this->VisibleChanged += gcnew System::EventHandler(this, &PtrInfoForm::PtrInfoForm_VisibleChanged);
			this->PointerGroup->ResumeLayout(false);
			this->PointerGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PtrUpdateTimer_Tick(System::Object^  sender, System::EventArgs^  e);

	private: System::Void StayOnTopCB_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PtrInfoForm_VisibleChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void PtrInfoForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);

};
}
