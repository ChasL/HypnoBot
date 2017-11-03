#pragma once

namespace HypnoBot {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdvToolsForm
	/// </summary>
	public ref class AdvToolsForm : public System::Windows::Forms::Form
	{
	public:
		AdvToolsForm(void)
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
		~AdvToolsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  ReadPointerGroup;
	protected: 
	private: System::Windows::Forms::Label^  ReadPtrBaseLabel;
	private: System::Windows::Forms::Label^  ReadPtrOffsetLabel;
	private: System::Windows::Forms::Label^  ReadPtrValueLabel;
	private: System::Windows::Forms::TextBox^  ReadPtrValueText;
	private: System::Windows::Forms::Button^  ReadPointerBtn;
	private: System::Windows::Forms::TextBox^  ReadPtrOffsetText;
	private: System::Windows::Forms::TextBox^  ReadPtrBaseText;
	private: System::Windows::Forms::GroupBox^  WritePointerGroup;
	private: System::Windows::Forms::Label^  WritePtrBaseLabel;
	private: System::Windows::Forms::TextBox^  WritePtrValueText;
	private: System::Windows::Forms::Label^  WritePtrOffsetLabel;
	private: System::Windows::Forms::Button^  WritePointerBtn;
	private: System::Windows::Forms::Label^  WritePtrValueLabel;
	private: System::Windows::Forms::TextBox^  WritePtrBaseText;
	private: System::Windows::Forms::TextBox^  WritePtrOffsetText;
	private: System::Windows::Forms::GroupBox^  AoBScanGroup;
	private: System::Windows::Forms::Label^  AoBToLabel;
	private: System::Windows::Forms::Label^  AoBFromLabel;
	private: System::Windows::Forms::TextBox^  AoBToRangeText;
	private: System::Windows::Forms::TextBox^  AoBResultsText;

	private: System::Windows::Forms::TextBox^  AoBFromRangeText;
	private: System::Windows::Forms::TextBox^  AoBSearchText;
	private: System::Windows::Forms::Button^  AoBScanBtn;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ReadPointerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->WritePointerGroup = (gcnew System::Windows::Forms::GroupBox());
			this->AoBScanGroup = (gcnew System::Windows::Forms::GroupBox());
			this->ReadPointerBtn = (gcnew System::Windows::Forms::Button());
			this->WritePointerBtn = (gcnew System::Windows::Forms::Button());
			this->AoBScanBtn = (gcnew System::Windows::Forms::Button());
			this->ReadPtrBaseText = (gcnew System::Windows::Forms::TextBox());
			this->ReadPtrOffsetText = (gcnew System::Windows::Forms::TextBox());
			this->ReadPtrValueText = (gcnew System::Windows::Forms::TextBox());
			this->WritePtrBaseText = (gcnew System::Windows::Forms::TextBox());
			this->WritePtrOffsetText = (gcnew System::Windows::Forms::TextBox());
			this->WritePtrValueText = (gcnew System::Windows::Forms::TextBox());
			this->AoBSearchText = (gcnew System::Windows::Forms::TextBox());
			this->ReadPtrBaseLabel = (gcnew System::Windows::Forms::Label());
			this->ReadPtrOffsetLabel = (gcnew System::Windows::Forms::Label());
			this->ReadPtrValueLabel = (gcnew System::Windows::Forms::Label());
			this->WritePtrValueLabel = (gcnew System::Windows::Forms::Label());
			this->WritePtrOffsetLabel = (gcnew System::Windows::Forms::Label());
			this->WritePtrBaseLabel = (gcnew System::Windows::Forms::Label());
			this->AoBFromRangeText = (gcnew System::Windows::Forms::TextBox());
			this->AoBResultsText = (gcnew System::Windows::Forms::TextBox());
			this->AoBToRangeText = (gcnew System::Windows::Forms::TextBox());
			this->AoBFromLabel = (gcnew System::Windows::Forms::Label());
			this->AoBToLabel = (gcnew System::Windows::Forms::Label());
			this->ReadPointerGroup->SuspendLayout();
			this->WritePointerGroup->SuspendLayout();
			this->AoBScanGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// ReadPointerGroup
			// 
			this->ReadPointerGroup->Controls->Add(this->ReadPtrBaseLabel);
			this->ReadPointerGroup->Controls->Add(this->ReadPtrOffsetLabel);
			this->ReadPointerGroup->Controls->Add(this->ReadPtrValueLabel);
			this->ReadPointerGroup->Controls->Add(this->ReadPtrValueText);
			this->ReadPointerGroup->Controls->Add(this->ReadPointerBtn);
			this->ReadPointerGroup->Controls->Add(this->ReadPtrOffsetText);
			this->ReadPointerGroup->Controls->Add(this->ReadPtrBaseText);
			this->ReadPointerGroup->Location = System::Drawing::Point(1, 2);
			this->ReadPointerGroup->Name = L"ReadPointerGroup";
			this->ReadPointerGroup->Size = System::Drawing::Size(285, 58);
			this->ReadPointerGroup->TabIndex = 0;
			this->ReadPointerGroup->TabStop = false;
			this->ReadPointerGroup->Text = L"Read Pointer";
			// 
			// WritePointerGroup
			// 
			this->WritePointerGroup->Controls->Add(this->WritePtrBaseLabel);
			this->WritePointerGroup->Controls->Add(this->WritePtrValueText);
			this->WritePointerGroup->Controls->Add(this->WritePtrOffsetLabel);
			this->WritePointerGroup->Controls->Add(this->WritePointerBtn);
			this->WritePointerGroup->Controls->Add(this->WritePtrValueLabel);
			this->WritePointerGroup->Controls->Add(this->WritePtrBaseText);
			this->WritePointerGroup->Controls->Add(this->WritePtrOffsetText);
			this->WritePointerGroup->Location = System::Drawing::Point(1, 59);
			this->WritePointerGroup->Name = L"WritePointerGroup";
			this->WritePointerGroup->Size = System::Drawing::Size(285, 58);
			this->WritePointerGroup->TabIndex = 0;
			this->WritePointerGroup->TabStop = false;
			this->WritePointerGroup->Text = L"Write Pointer";
			// 
			// AoBScanGroup
			// 
			this->AoBScanGroup->Controls->Add(this->AoBToLabel);
			this->AoBScanGroup->Controls->Add(this->AoBFromLabel);
			this->AoBScanGroup->Controls->Add(this->AoBToRangeText);
			this->AoBScanGroup->Controls->Add(this->AoBResultsText);
			this->AoBScanGroup->Controls->Add(this->AoBFromRangeText);
			this->AoBScanGroup->Controls->Add(this->AoBSearchText);
			this->AoBScanGroup->Controls->Add(this->AoBScanBtn);
			this->AoBScanGroup->Location = System::Drawing::Point(1, 116);
			this->AoBScanGroup->Name = L"AoBScanGroup";
			this->AoBScanGroup->Size = System::Drawing::Size(285, 137);
			this->AoBScanGroup->TabIndex = 0;
			this->AoBScanGroup->TabStop = false;
			this->AoBScanGroup->Text = L"AoB Scan";
			// 
			// ReadPointerBtn
			// 
			this->ReadPointerBtn->Location = System::Drawing::Point(9, 24);
			this->ReadPointerBtn->Name = L"ReadPointerBtn";
			this->ReadPointerBtn->Size = System::Drawing::Size(59, 23);
			this->ReadPointerBtn->TabIndex = 1;
			this->ReadPointerBtn->Text = L"Read";
			this->ReadPointerBtn->UseVisualStyleBackColor = true;
			this->ReadPointerBtn->Click += gcnew System::EventHandler(this, &AdvToolsForm::ReadPointerBtn_Click);
			// 
			// WritePointerBtn
			// 
			this->WritePointerBtn->Location = System::Drawing::Point(9, 24);
			this->WritePointerBtn->Name = L"WritePointerBtn";
			this->WritePointerBtn->Size = System::Drawing::Size(59, 23);
			this->WritePointerBtn->TabIndex = 2;
			this->WritePointerBtn->Text = L"Write";
			this->WritePointerBtn->UseVisualStyleBackColor = true;
			this->WritePointerBtn->Click += gcnew System::EventHandler(this, &AdvToolsForm::WritePointerBtn_Click);
			// 
			// AoBScanBtn
			// 
			this->AoBScanBtn->Location = System::Drawing::Point(9, 22);
			this->AoBScanBtn->Name = L"AoBScanBtn";
			this->AoBScanBtn->Size = System::Drawing::Size(59, 23);
			this->AoBScanBtn->TabIndex = 3;
			this->AoBScanBtn->Text = L"Scan";
			this->AoBScanBtn->UseVisualStyleBackColor = true;
			this->AoBScanBtn->Click += gcnew System::EventHandler(this, &AdvToolsForm::AoBScanBtn_Click);
			// 
			// ReadPtrBaseText
			// 
			this->ReadPtrBaseText->Location = System::Drawing::Point(74, 26);
			this->ReadPtrBaseText->Name = L"ReadPtrBaseText";
			this->ReadPtrBaseText->Size = System::Drawing::Size(76, 20);
			this->ReadPtrBaseText->TabIndex = 4;
			this->ReadPtrBaseText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ReadPtrOffsetText
			// 
			this->ReadPtrOffsetText->Location = System::Drawing::Point(156, 26);
			this->ReadPtrOffsetText->Name = L"ReadPtrOffsetText";
			this->ReadPtrOffsetText->Size = System::Drawing::Size(38, 20);
			this->ReadPtrOffsetText->TabIndex = 5;
			this->ReadPtrOffsetText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// ReadPtrValueText
			// 
			this->ReadPtrValueText->Location = System::Drawing::Point(200, 26);
			this->ReadPtrValueText->Name = L"ReadPtrValueText";
			this->ReadPtrValueText->Size = System::Drawing::Size(76, 20);
			this->ReadPtrValueText->TabIndex = 6;
			this->ReadPtrValueText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// WritePtrBaseText
			// 
			this->WritePtrBaseText->Location = System::Drawing::Point(74, 26);
			this->WritePtrBaseText->Name = L"WritePtrBaseText";
			this->WritePtrBaseText->Size = System::Drawing::Size(76, 20);
			this->WritePtrBaseText->TabIndex = 4;
			this->WritePtrBaseText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// WritePtrOffsetText
			// 
			this->WritePtrOffsetText->Location = System::Drawing::Point(156, 26);
			this->WritePtrOffsetText->Name = L"WritePtrOffsetText";
			this->WritePtrOffsetText->Size = System::Drawing::Size(38, 20);
			this->WritePtrOffsetText->TabIndex = 5;
			this->WritePtrOffsetText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// WritePtrValueText
			// 
			this->WritePtrValueText->Location = System::Drawing::Point(200, 26);
			this->WritePtrValueText->Name = L"WritePtrValueText";
			this->WritePtrValueText->Size = System::Drawing::Size(76, 20);
			this->WritePtrValueText->TabIndex = 6;
			this->WritePtrValueText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AoBSearchText
			// 
			this->AoBSearchText->Location = System::Drawing::Point(74, 24);
			this->AoBSearchText->Name = L"AoBSearchText";
			this->AoBSearchText->Size = System::Drawing::Size(202, 20);
			this->AoBSearchText->TabIndex = 7;
			// 
			// ReadPtrBaseLabel
			// 
			this->ReadPtrBaseLabel->AutoSize = true;
			this->ReadPtrBaseLabel->Location = System::Drawing::Point(96, 12);
			this->ReadPtrBaseLabel->Name = L"ReadPtrBaseLabel";
			this->ReadPtrBaseLabel->Size = System::Drawing::Size(31, 13);
			this->ReadPtrBaseLabel->TabIndex = 1;
			this->ReadPtrBaseLabel->Text = L"Base";
			// 
			// ReadPtrOffsetLabel
			// 
			this->ReadPtrOffsetLabel->AutoSize = true;
			this->ReadPtrOffsetLabel->Location = System::Drawing::Point(158, 12);
			this->ReadPtrOffsetLabel->Name = L"ReadPtrOffsetLabel";
			this->ReadPtrOffsetLabel->Size = System::Drawing::Size(35, 13);
			this->ReadPtrOffsetLabel->TabIndex = 2;
			this->ReadPtrOffsetLabel->Text = L"Offset";
			// 
			// ReadPtrValueLabel
			// 
			this->ReadPtrValueLabel->AutoSize = true;
			this->ReadPtrValueLabel->Location = System::Drawing::Point(221, 12);
			this->ReadPtrValueLabel->Name = L"ReadPtrValueLabel";
			this->ReadPtrValueLabel->Size = System::Drawing::Size(34, 13);
			this->ReadPtrValueLabel->TabIndex = 3;
			this->ReadPtrValueLabel->Text = L"Value";
			// 
			// WritePtrValueLabel
			// 
			this->WritePtrValueLabel->AutoSize = true;
			this->WritePtrValueLabel->Location = System::Drawing::Point(221, 12);
			this->WritePtrValueLabel->Name = L"WritePtrValueLabel";
			this->WritePtrValueLabel->Size = System::Drawing::Size(34, 13);
			this->WritePtrValueLabel->TabIndex = 3;
			this->WritePtrValueLabel->Text = L"Value";
			// 
			// WritePtrOffsetLabel
			// 
			this->WritePtrOffsetLabel->AutoSize = true;
			this->WritePtrOffsetLabel->Location = System::Drawing::Point(158, 12);
			this->WritePtrOffsetLabel->Name = L"WritePtrOffsetLabel";
			this->WritePtrOffsetLabel->Size = System::Drawing::Size(35, 13);
			this->WritePtrOffsetLabel->TabIndex = 2;
			this->WritePtrOffsetLabel->Text = L"Offset";
			// 
			// WritePtrBaseLabel
			// 
			this->WritePtrBaseLabel->AutoSize = true;
			this->WritePtrBaseLabel->Location = System::Drawing::Point(96, 12);
			this->WritePtrBaseLabel->Name = L"WritePtrBaseLabel";
			this->WritePtrBaseLabel->Size = System::Drawing::Size(31, 13);
			this->WritePtrBaseLabel->TabIndex = 1;
			this->WritePtrBaseLabel->Text = L"Base";
			// 
			// AoBFromRangeText
			// 
			this->AoBFromRangeText->Location = System::Drawing::Point(9, 72);
			this->AoBFromRangeText->Name = L"AoBFromRangeText";
			this->AoBFromRangeText->Size = System::Drawing::Size(59, 20);
			this->AoBFromRangeText->TabIndex = 8;
			this->AoBFromRangeText->Text = L"00400000";
			this->AoBFromRangeText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AoBResultsText
			// 
			this->AoBResultsText->Location = System::Drawing::Point(74, 50);
			this->AoBResultsText->Multiline = true;
			this->AoBResultsText->Name = L"AoBResultsText";
			this->AoBResultsText->Size = System::Drawing::Size(202, 78);
			this->AoBResultsText->TabIndex = 9;
			// 
			// AoBToRangeText
			// 
			this->AoBToRangeText->Location = System::Drawing::Point(9, 108);
			this->AoBToRangeText->Name = L"AoBToRangeText";
			this->AoBToRangeText->Size = System::Drawing::Size(59, 20);
			this->AoBToRangeText->TabIndex = 10;
			this->AoBToRangeText->Text = L"01FFFFFF";
			this->AoBToRangeText->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// AoBFromLabel
			// 
			this->AoBFromLabel->AutoSize = true;
			this->AoBFromLabel->Location = System::Drawing::Point(22, 58);
			this->AoBFromLabel->Name = L"AoBFromLabel";
			this->AoBFromLabel->Size = System::Drawing::Size(30, 13);
			this->AoBFromLabel->TabIndex = 11;
			this->AoBFromLabel->Text = L"From";
			// 
			// AoBToLabel
			// 
			this->AoBToLabel->AutoSize = true;
			this->AoBToLabel->Location = System::Drawing::Point(27, 95);
			this->AoBToLabel->Name = L"AoBToLabel";
			this->AoBToLabel->Size = System::Drawing::Size(20, 13);
			this->AoBToLabel->TabIndex = 12;
			this->AoBToLabel->Text = L"To";
			// 
			// AdvToolsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 256);
			this->Controls->Add(this->AoBScanGroup);
			this->Controls->Add(this->WritePointerGroup);
			this->Controls->Add(this->ReadPointerGroup);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AdvToolsForm";
			this->Text = L" Advanced Tools";
			this->ReadPointerGroup->ResumeLayout(false);
			this->ReadPointerGroup->PerformLayout();
			this->WritePointerGroup->ResumeLayout(false);
			this->WritePointerGroup->PerformLayout();
			this->AoBScanGroup->ResumeLayout(false);
			this->AoBScanGroup->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ReadPointerBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void WritePointerBtn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void AoBScanBtn_Click(System::Object^  sender, System::EventArgs^  e);
};
}
