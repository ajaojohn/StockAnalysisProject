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
	private: Generic::List<Candlestick^>^ listOfCandlesticks;

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
			this->listOfCandlesticks = gcnew Generic::List<Candlestick^>();
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
			// button_load
			// 
			this->button_load->Location = System::Drawing::Point(423, 625);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(141, 44);
			this->button_load->TabIndex = 1;
			this->button_load->Text = L"Select File";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Form_Input::button_load_Click);
			// 
			// openFileDialog_load
			// 
			this->openFileDialog_load->FileName = L"openFileDialog1";
			this->openFileDialog_load->Filter = L"CSV Files (*.csv)|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1043, 724);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->dataGridView_stockData);
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
			this->populateDataGridView(filename);
		}
	}

	/**
	* Reads candlestick data from a file
	* @param filename The name of the file to read
	*/
	private: Generic::List<Candlestick^>^ readCandlestickDataFromFile(System::String^ filename) {
		// Create empty list of candlesticks
		Generic::List<Candlestick^>^ listOfCandlesticks = gcnew Generic::List<Candlestick^>();

		try {
			// Create stream reader for new data file
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filename);

			// Confirm file is formatted as expected
			System::String^ firstLine = reader->ReadLine();
			if (firstLine == "Date,Open,High,Low,Close,Adj Close,Volume") {
				// Loop through each line in the file
				while (!reader->EndOfStream) {
					// Get next row
					System::String^ currRow = reader->ReadLine();

					// Create new candlestick from row
					Candlestick^ newCandlestick = gcnew Candlestick(currRow);
					// Add the candlestick to the list
					listOfCandlesticks->Add(newCandlestick);
				}
			}
			else {
				// If file is a different format, throw error
				throw gcnew System::IO::IOException("File is not formatted as expected");
			}
		} catch (System::IO::IOException^ e) {
			// If error reading file, show message box with what went wrong
			System::Windows::Forms::MessageBox::Show("Error reading file: " + e->Message);
		}

		// Return the list
		return listOfCandlesticks;
	}

	/**
	* Populates the dataGridView_stockData with candlestick data
	* @param filename The name of the file to read data from
	*/
	private: System::Void populateDataGridView(System::String^ filename) {
		// Read candlesticks from file into list
		this->listOfCandlesticks = readCandlestickDataFromFile(filename);
		
		// Create binding list
		BindingList<Candlestick^>^ bindingList = gcnew BindingList<Candlestick^>(this->listOfCandlesticks);
		// Set binding list
		this->dataGridView_stockData->DataSource = bindingList;
	}
	};
}