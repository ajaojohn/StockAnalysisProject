#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_Input
	/// </summary>
	public ref class Form_Input : public System::Windows::Forms::Form
	{
	public:
		Form_Input(void)
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
		~Form_Input()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView_stockData;
	private: System::Windows::Forms::Button^ button_selectFile;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_selectStock;
	protected:


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
			this->dataGridView_stockData = (gcnew System::Windows::Forms::DataGridView());
			this->button_selectFile = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_selectStock = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_stockData
			// 
			this->dataGridView_stockData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_stockData->Location = System::Drawing::Point(12, 38);
			this->dataGridView_stockData->Name = L"dataGridView_stockData";
			this->dataGridView_stockData->RowHeadersWidth = 51;
			this->dataGridView_stockData->RowTemplate->Height = 24;
			this->dataGridView_stockData->Size = System::Drawing::Size(1019, 496);
			this->dataGridView_stockData->TabIndex = 0;
			// 
			// button_selectFile
			// 
			this->button_selectFile->Location = System::Drawing::Point(423, 625);
			this->button_selectFile->Name = L"button_selectFile";
			this->button_selectFile->Size = System::Drawing::Size(142, 44);
			this->button_selectFile->TabIndex = 1;
			this->button_selectFile->Text = L"Select File";
			this->button_selectFile->UseVisualStyleBackColor = true;
			this->button_selectFile->Click += gcnew System::EventHandler(this, &Form_Input::button_selectFile_Click);
			// 
			// openFileDialog_selectStock
			// 
			this->openFileDialog_selectStock->FileName = L"openFileDialog1";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1043, 724);
			this->Controls->Add(this->button_selectFile);
			this->Controls->Add(this->dataGridView_stockData);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_selectFile_Click(System::Object^ sender, System::EventArgs^ e) {
		// On button click, trigger the open file dialog
		openFileDialog_selectStock->ShowDialog();
	}
	};
}