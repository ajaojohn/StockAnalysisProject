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
#pragma region Self-written Form properties
	// List to store all candlesticks loaded from a file
	private: Generic::List<aCandlestick^>^ listOfCandlesticks;

#pragma endregion

	public:
		Form_Input(void)
		{
			InitializeComponent();

			// Generate initial  directory for open file dialog
			System::String^ CombinedPath = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), "..\\Stock Data");
			// Set initial directory for open file dialog
			this->openFileDialog_load->InitialDirectory = System::IO::Path::GetFullPath(CombinedPath);

			// Initialize list as empty
			this->listOfCandlesticks = gcnew Generic::List<aCandlestick^>();
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
	private: System::Windows::Forms::Button^ button_load;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_load;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_start;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_end;

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
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_load = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_stockData
			// 
			this->dataGridView_stockData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_stockData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_stockData->Location = System::Drawing::Point(16, 57);
			this->dataGridView_stockData->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView_stockData->Name = L"dataGridView_stockData";
			this->dataGridView_stockData->RowHeadersWidth = 51;
			this->dataGridView_stockData->RowTemplate->Height = 24;
			this->dataGridView_stockData->Size = System::Drawing::Size(1401, 744);
			this->dataGridView_stockData->TabIndex = 0;
			// 
			// button_load
			// 
			this->button_load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_load->Location = System::Drawing::Point(582, 938);
			this->button_load->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(194, 66);
			this->button_load->TabIndex = 1;
			this->button_load->Text = L"Load";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Form_Input::button_load_Click);
			// 
			// openFileDialog_load
			// 
			this->openFileDialog_load->FileName = L"openFileDialog1";
			this->openFileDialog_load->Filter = L"CSV Files (*.csv)|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			// 
			// dateTimePicker_start
			// 
			this->dateTimePicker_start->Location = System::Drawing::Point(125, 959);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(350, 29);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Location = System::Drawing::Point(899, 955);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(326, 29);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1434, 1086);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->dataGridView_stockData);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e) {
		// On button click, trigger the open file dialog
		System::Windows::Forms::DialogResult result = this->openFileDialog_load->ShowDialog();

		// If the user selected a file
		if (result == System::Windows::Forms::DialogResult::OK) {
			// Get file selected
			System::String^ filename =this->openFileDialog_load->FileName;
			// Load the selected file
			aCandlestickLoader^ loader = gcnew aCandlestickLoader();
			this->listOfCandlesticks = loader->load(filename);
			this->populateDataGridView(this->listOfCandlesticks);
		}
	}

	/**
	* Get filtered list of candlesticks in a time frame
	* @param startDate The start date of the time frame
	* @param endDate The end date of the time frame
	* @return A list of candlesticks in the time frame
	*/
	private: Generic::List<aCandlestick^>^ getFilteredCandlesticks(System::DateTime^ startDate, System::DateTime^ endDate, Generic::List<aCandlestick^>^  listOfCandlesticks) {
		// Create a new list
		Generic::List<aCandlestick^>^ filteredCandlesticks = gcnew Generic::List<aCandlestick^>();
		// Loop through each candlestick
		for (int i = 0; i < listOfCandlesticks->Count; i++) {
			// If the candlestick is in the time frame
			if (listOfCandlesticks[i]->date->CompareTo(startDate) >= 0 && listOfCandlesticks[i]->date->CompareTo(endDate) <= 0) {
				// Add the candlestick to the list
				filteredCandlesticks->Add(listOfCandlesticks[i]);
			}
		}
		// Return the list
		return filteredCandlesticks;
	}

	

	/**
	* Populates the dataGridView_stockData with candlestick data
	* @param filename The name of the file to read data from
	*/
	private: System::Void populateDataGridView(Generic::List<aCandlestick^>^ listOfCandlesticks) {
		// Filter candlesticks to display
		Generic::List<aCandlestick^>^ filteredCandlesticks = getFilteredCandlesticks(this->dateTimePicker_start->Value, this->dateTimePicker_end->Value, listOfCandlesticks);
		// Create binding list
		BindingList<aCandlestick^>^ bindingList = gcnew BindingList<aCandlestick^>(filteredCandlesticks);
		// Set binding list
		this->dataGridView_stockData->DataSource = bindingList;
	}
	};
}