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
	// String to store selected file
	private: System::String^ selectedFilename;
	// List to store all candlesticks loaded from a file
	private: Generic::List<aSmartCandlestick^>^ listOfCandlesticks;
	// CandlestickLoader object to be used to load candlesticks from csv files
	private: aCandlestickLoader^ candlestickLoader;
	// Bool to identify parent form
	private: bool isParentForm;


	private: System::Windows::Forms::Label^ label_startDate;
	private: System::Windows::Forms::Label^ label_endDate;
	private: System::Windows::Forms::Button^ button_update;
	private: System::Windows::Forms::GroupBox^ groupBox_patterns;

	private: System::Windows::Forms::CheckBox^ checkBox_neutralPattern;
	private: System::Windows::Forms::CheckBox^ checkBox_marubozuPattern;

	private: System::Windows::Forms::CheckBox^ checkBox_bearishPattern;
	private: System::Windows::Forms::CheckBox^ checkBox_bullishPattern;
	private: System::Windows::Forms::CheckBox^ checkBox_gravestoneDojiPattern;

	private: System::Windows::Forms::CheckBox^ checkBox_dragonflyDojiPattern;
	private: System::Windows::Forms::CheckBox^ checkBox_dojiPattern;
	private: System::Windows::Forms::CheckBox^ checkBox_hammerPattern;
	private: System::Windows::Forms::GroupBox^ groupBox_dateFiltering;





		   // List of candlesticks to display
	private: BindingList<aSmartCandlestick^>^ filteredListOfCandlesticks;

#pragma endregion

	public:
		Form_Input(void)
		{
			InitializeComponent();
			initializeCustomProperties();
			isParentForm = true;
		}

		Form_Input(String^ filename, DateTime startDate, DateTime endDate)
		{
			// Initialize form components
			InitializeComponent();
			// Initialize self-written properties
			initializeCustomProperties();

			// Set isParentForm to false
			isParentForm = false;
			// Set selected filename
			this->selectedFilename = filename;
			// Set start date picker
			this->dateTimePicker_start->Value = startDate;
			// Set end date picker
			this->dateTimePicker_end->Value = endDate;

			// Set title of the form using the selected filename
			setTitleUsingFilename();
			// Retrieve and display stock data on current form
			getAndDisplayStockData();
		}
	
	/// <summary>
	/// Initialize custom properties not defined by form
	/// </summary>
	private: void initializeCustomProperties() {
		// Initialize loader
		candlestickLoader = gcnew aCandlestickLoader();
		// Generate initial  directory for open file dialog
		System::String^ CombinedPath = System::IO::Path::Combine(System::IO::Directory::GetCurrentDirectory(), "..\\Stock Data");
		// Set initial directory for open file dialog
		this->openFileDialog_load->InitialDirectory = System::IO::Path::GetFullPath(CombinedPath);

		// Initialize list as empty
		this->listOfCandlesticks = gcnew Generic::List<aSmartCandlestick^>();
		// Intialize filtered list as empty
		this->filteredListOfCandlesticks = gcnew BindingList<aSmartCandlestick^>();

		// Create an array of strings
		array<String^>^ patternArray = gcnew array<String^> {
			"All",
			"Bullish",
			"Bearish",
			"Neutral",
			"Marubozu",
			"Hammer",
			"Doji",
			"Dragonfly Doji",
			"Gravestone Doji"
		};
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

	private: System::Windows::Forms::Button^ button_load;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_load;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_start;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_end;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_stockData;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_load = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_stockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label_startDate = (gcnew System::Windows::Forms::Label());
			this->label_endDate = (gcnew System::Windows::Forms::Label());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->groupBox_patterns = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_gravestoneDojiPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_dragonflyDojiPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_dojiPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_hammerPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_marubozuPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_bearishPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_bullishPattern = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_neutralPattern = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox_dateFiltering = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->BeginInit();
			this->groupBox_patterns->SuspendLayout();
			this->groupBox_dateFiltering->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_load
			// 
			this->button_load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_load->Location = System::Drawing::Point(1431, 841);
			this->button_load->Margin = System::Windows::Forms::Padding(4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(329, 69);
			this->button_load->TabIndex = 0;
			this->button_load->Text = L"Load File";
			this->button_load->UseVisualStyleBackColor = true;
			this->button_load->Click += gcnew System::EventHandler(this, &Form_Input::button_load_Click);
			// 
			// openFileDialog_load
			// 
			this->openFileDialog_load->FileName = L"openFileDialog1";
			this->openFileDialog_load->Filter = L"CSV Files (*.csv)|*.csv|Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*-Day.csv";
			this->openFileDialog_load->Multiselect = true;
			this->openFileDialog_load->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_Input::openFileDialog_load_FileOk);
			// 
			// dateTimePicker_start
			// 
			this->dateTimePicker_start->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker_start->CustomFormat = L"d MMM yyyy";
			this->dateTimePicker_start->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_start->Location = System::Drawing::Point(14, 68);
			this->dateTimePicker_start->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(150, 29);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker_end->CustomFormat = L"d MMM yyyy";
			this->dateTimePicker_end->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_end->Location = System::Drawing::Point(176, 68);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(150, 29);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// chart_stockData
			// 
			this->chart_stockData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea3->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea3->AxisY->LabelStyle->Format = L"F2";
			chartArea3->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea3->AxisY->Title = L"Price";
			chartArea3->Name = L"ChartArea_OHLC";
			chartArea4->AxisY->Title = L"Volume";
			chartArea4->Name = L"ChartArea_Volume";
			this->chart_stockData->ChartAreas->Add(chartArea3);
			this->chart_stockData->ChartAreas->Add(chartArea4);
			legend2->Enabled = false;
			legend2->Name = L"Legend1";
			this->chart_stockData->Legends->Add(legend2);
			this->chart_stockData->Location = System::Drawing::Point(13, 13);
			this->chart_stockData->Margin = System::Windows::Forms::Padding(4);
			this->chart_stockData->Name = L"chart_stockData";
			series3->ChartArea = L"ChartArea_OHLC";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series3->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series3->IsXValueIndexed = true;
			series3->Legend = L"Legend1";
			series3->Name = L"Series_OHLC";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series3->YValuesPerPoint = 4;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series4->ChartArea = L"ChartArea_Volume";
			series4->IsXValueIndexed = true;
			series4->Legend = L"Legend1";
			series4->Name = L"Series_Volume";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series4->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart_stockData->Series->Add(series3);
			this->chart_stockData->Series->Add(series4);
			this->chart_stockData->Size = System::Drawing::Size(1410, 896);
			this->chart_stockData->TabIndex = 4;
			this->chart_stockData->Text = L"Stock Data";
			// 
			// label_startDate
			// 
			this->label_startDate->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(9, 39);
			this->label_startDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_startDate->Name = L"label_startDate";
			this->label_startDate->Size = System::Drawing::Size(99, 25);
			this->label_startDate->TabIndex = 7;
			this->label_startDate->Text = L"Start Date";
			// 
			// label_endDate
			// 
			this->label_endDate->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_endDate->AutoSize = true;
			this->label_endDate->Location = System::Drawing::Point(177, 39);
			this->label_endDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(93, 25);
			this->label_endDate->TabIndex = 8;
			this->label_endDate->Text = L"End Date";
			// 
			// button_update
			// 
			this->button_update->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button_update->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button_update->Location = System::Drawing::Point(14, 115);
			this->button_update->Margin = System::Windows::Forms::Padding(4);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(308, 70);
			this->button_update->TabIndex = 9;
			this->button_update->Text = L"Update";
			this->button_update->UseVisualStyleBackColor = false;
			this->button_update->Click += gcnew System::EventHandler(this, &Form_Input::button_update_Click);
			// 
			// groupBox_patterns
			// 
			this->groupBox_patterns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_patterns->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox_patterns->Controls->Add(this->checkBox_gravestoneDojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_dragonflyDojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_dojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_hammerPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_marubozuPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_bearishPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_bullishPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_neutralPattern);
			this->groupBox_patterns->Location = System::Drawing::Point(1431, 13);
			this->groupBox_patterns->Name = L"groupBox_patterns";
			this->groupBox_patterns->Size = System::Drawing::Size(329, 579);
			this->groupBox_patterns->TabIndex = 12;
			this->groupBox_patterns->TabStop = false;
			this->groupBox_patterns->Text = L"Select Patterns";
			// 
			// checkBox_gravestoneDojiPattern
			// 
			this->checkBox_gravestoneDojiPattern->AutoSize = true;
			this->checkBox_gravestoneDojiPattern->Location = System::Drawing::Point(24, 282);
			this->checkBox_gravestoneDojiPattern->Name = L"checkBox_gravestoneDojiPattern";
			this->checkBox_gravestoneDojiPattern->Size = System::Drawing::Size(225, 29);
			this->checkBox_gravestoneDojiPattern->TabIndex = 7;
			this->checkBox_gravestoneDojiPattern->Text = L"Gravestone Doji (GD)";
			this->checkBox_gravestoneDojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_gravestoneDojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_dragonflyDojiPattern
			// 
			this->checkBox_dragonflyDojiPattern->AutoSize = true;
			this->checkBox_dragonflyDojiPattern->Location = System::Drawing::Point(24, 247);
			this->checkBox_dragonflyDojiPattern->Name = L"checkBox_dragonflyDojiPattern";
			this->checkBox_dragonflyDojiPattern->Size = System::Drawing::Size(206, 29);
			this->checkBox_dragonflyDojiPattern->TabIndex = 6;
			this->checkBox_dragonflyDojiPattern->Text = L"Dragonfly Doji (DD)";
			this->checkBox_dragonflyDojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_dragonflyDojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_dojiPattern
			// 
			this->checkBox_dojiPattern->AutoSize = true;
			this->checkBox_dojiPattern->Location = System::Drawing::Point(24, 212);
			this->checkBox_dojiPattern->Name = L"checkBox_dojiPattern";
			this->checkBox_dojiPattern->Size = System::Drawing::Size(104, 29);
			this->checkBox_dojiPattern->TabIndex = 5;
			this->checkBox_dojiPattern->Text = L"Doji (D)";
			this->checkBox_dojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_dojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_hammerPattern
			// 
			this->checkBox_hammerPattern->AutoSize = true;
			this->checkBox_hammerPattern->Location = System::Drawing::Point(24, 177);
			this->checkBox_hammerPattern->Name = L"checkBox_hammerPattern";
			this->checkBox_hammerPattern->Size = System::Drawing::Size(145, 29);
			this->checkBox_hammerPattern->TabIndex = 4;
			this->checkBox_hammerPattern->Text = L"Hammer (H)";
			this->checkBox_hammerPattern->UseVisualStyleBackColor = true;
			this->checkBox_hammerPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_marubozuPattern
			// 
			this->checkBox_marubozuPattern->AutoSize = true;
			this->checkBox_marubozuPattern->Location = System::Drawing::Point(24, 142);
			this->checkBox_marubozuPattern->Name = L"checkBox_marubozuPattern";
			this->checkBox_marubozuPattern->Size = System::Drawing::Size(162, 29);
			this->checkBox_marubozuPattern->TabIndex = 3;
			this->checkBox_marubozuPattern->Text = L"Marubozu (M)";
			this->checkBox_marubozuPattern->UseVisualStyleBackColor = true;
			this->checkBox_marubozuPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_bearishPattern
			// 
			this->checkBox_bearishPattern->AutoSize = true;
			this->checkBox_bearishPattern->Location = System::Drawing::Point(24, 37);
			this->checkBox_bearishPattern->Name = L"checkBox_bearishPattern";
			this->checkBox_bearishPattern->Size = System::Drawing::Size(147, 29);
			this->checkBox_bearishPattern->TabIndex = 2;
			this->checkBox_bearishPattern->Text = L"Bearish (Be)";
			this->checkBox_bearishPattern->UseVisualStyleBackColor = true;
			this->checkBox_bearishPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_bullishPattern
			// 
			this->checkBox_bullishPattern->AutoSize = true;
			this->checkBox_bullishPattern->Location = System::Drawing::Point(24, 72);
			this->checkBox_bullishPattern->Name = L"checkBox_bullishPattern";
			this->checkBox_bullishPattern->Size = System::Drawing::Size(138, 29);
			this->checkBox_bullishPattern->TabIndex = 1;
			this->checkBox_bullishPattern->Text = L"Bullish (Bu)";
			this->checkBox_bullishPattern->UseVisualStyleBackColor = true;
			this->checkBox_bullishPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_neutralPattern
			// 
			this->checkBox_neutralPattern->AutoSize = true;
			this->checkBox_neutralPattern->Location = System::Drawing::Point(24, 107);
			this->checkBox_neutralPattern->Name = L"checkBox_neutralPattern";
			this->checkBox_neutralPattern->Size = System::Drawing::Size(133, 29);
			this->checkBox_neutralPattern->TabIndex = 0;
			this->checkBox_neutralPattern->Text = L"Neutral (N)";
			this->checkBox_neutralPattern->UseVisualStyleBackColor = true;
			this->checkBox_neutralPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// groupBox_dateFiltering
			// 
			this->groupBox_dateFiltering->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->groupBox_dateFiltering->BackColor = System::Drawing::SystemColors::Window;
			this->groupBox_dateFiltering->Controls->Add(this->button_update);
			this->groupBox_dateFiltering->Controls->Add(this->label_endDate);
			this->groupBox_dateFiltering->Controls->Add(this->label_startDate);
			this->groupBox_dateFiltering->Controls->Add(this->dateTimePicker_end);
			this->groupBox_dateFiltering->Controls->Add(this->dateTimePicker_start);
			this->groupBox_dateFiltering->Location = System::Drawing::Point(1431, 629);
			this->groupBox_dateFiltering->Name = L"groupBox_dateFiltering";
			this->groupBox_dateFiltering->Size = System::Drawing::Size(329, 205);
			this->groupBox_dateFiltering->TabIndex = 13;
			this->groupBox_dateFiltering->TabStop = false;
			this->groupBox_dateFiltering->Text = L"Filter Dates";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1772, 919);
			this->Controls->Add(this->groupBox_dateFiltering);
			this->Controls->Add(this->groupBox_patterns);
			this->Controls->Add(this->chart_stockData);
			this->Controls->Add(this->button_load);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->EndInit();
			this->groupBox_patterns->ResumeLayout(false);
			this->groupBox_patterns->PerformLayout();
			this->groupBox_dateFiltering->ResumeLayout(false);
			this->groupBox_dateFiltering->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e) {
		// On button click, trigger the open file dialog
		System::Windows::Forms::DialogResult result = this->openFileDialog_load->ShowDialog();
	}

	private: System::Void openFileDialog_load_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		// Get array of all selected files
		array<System::String^>^ selectedFilenames = this->openFileDialog_load->FileNames;

		// Get file selected
		this->selectedFilename = selectedFilenames[0];
		// Set title of the form using the selected filename
		setTitleUsingFilename();
		// Display stock data on current form
		getAndDisplayStockData();

		// Iterate through each selected file
		for (int i = 1; i < selectedFilenames->Length; i++) {
			// Construct child form using the selected file and time range
			Form_Input^ childForm = gcnew Form_Input(selectedFilenames[i], this->dateTimePicker_start->Value, this->dateTimePicker_end->Value);
			// Display/show child form
			childForm->Show();
		}
	}
	
	/// <summary>
	/// Displays stock data on the current form by reading candlesticks from the selected file stored in a member variable
	/// </summary>
	/// <returns>void</returns>
	private: System::Void getAndDisplayStockData() {
		// Load candlesticks from the selected file
		readCandlesticksFromFile();
		// Filter candlesticks
		filterCandlesticks();
		// Fill chart with filtered candlestick data
		displayDataOnChart();
		// Normalize the chart
		normalizeCandlestickChart();
		// Show annotations for selected pattern
		showAnnotationsForSelectedPattern(nullptr, nullptr);
	}

	/// <summary>
	/// Set title of the form using the selected filename
	/// </summary>
	/// <returns></returns>
	private: System::Void setTitleUsingFilename() {
		// Get filename without extension
		String^ filenameWithoutExtension = System::IO::Path::GetFileNameWithoutExtension(this->selectedFilename);
		// Create string for form title
		String^ formTitle = "";
		// Add text indicating if the form is a child form
		if (isParentForm) {
			formTitle += "(Parent Form) ";
		}
		// Append filename
		formTitle += filenameWithoutExtension;
		// Set form title
		this->Text = formTitle;
	}

	/// <summary>
	/// Reads candlesticks from a file and returns a list of candlestick objects.
	/// </summary>
	/// <param name="filename">The name of the file to read.</param>
	/// <returns>A list of candlesticks read from the file.</returns>
	private: Generic::List<aSmartCandlestick^>^ readCandlesticksFromFile(System::String^ filename) {
		// Call loader
		Generic::List<aCandlestick^>^ candlesticks = candlestickLoader->load(filename);
		// Create list of smart candlesticks
		Generic::List<aSmartCandlestick^>^ smartCandlesticks = gcnew Generic::List<aSmartCandlestick^>();
		// Iterate through each candlestick
		for each (aCandlestick^ candlestick in candlesticks) {
			// Add smart candlestick
			smartCandlesticks->Add(gcnew aSmartCandlestick(candlestick));
		}
		// Return smart candlesticks
		return smartCandlesticks;
	}
	/// <summary>
	/// Reads candlesticks from a file and saves it to private parameter
	/// </summary>
	/// <returns>void</returns>
	private: System::Void readCandlesticksFromFile() {
		// Use candlestick loader to read candlesticks
		this->listOfCandlesticks = this->readCandlesticksFromFile(this->selectedFilename);
		// If the first candlestick is after the last candlestick (chronological order), reverse the list
		if (this->listOfCandlesticks[0]->Date->CompareTo(this->listOfCandlesticks[this->listOfCandlesticks->Count - 1]->Date) > 0) {
			// Reverse the list
			this->listOfCandlesticks->Reverse();
		}
	}


	/// <summary>
	/// Gets a filtered list of candlesticks within a specified time frame.
	/// </summary>
	/// <param name="startDate">The start date of the time frame.</param>
	/// <param name="endDate">The end date of the time frame.</param>
	/// <returns>A list of candlesticks within the specified time frame.</returns>
	private: Generic::List<aSmartCandlestick^>^ filterCandlesticks(System::DateTime^ startDate, System::DateTime^ endDate, Generic::List<aSmartCandlestick^>^  listOfCandlesticks) {
		// Create a new list
		Generic::List<aSmartCandlestick^>^ filteredCandlesticks = gcnew Generic::List<aSmartCandlestick^>();
		// Loop through each candlestick
		for (int i = 0; i < listOfCandlesticks->Count; i++) {
			// If the candlestick is in the time frame
			if (listOfCandlesticks[i]->Date->CompareTo(startDate) >= 0 && listOfCandlesticks[i]->Date->CompareTo(endDate) <= 0) {
				// Add the candlestick to the list
				filteredCandlesticks->Add(listOfCandlesticks[i]);
			}
		}
		// Return the list
		return filteredCandlesticks;
	}
	/// <summary>
	/// Set filteredListOfCandlesticks to candlesticks in the time frame selected using the date time pickers
	/// </summary>
	/// <returns>void</returns>
	private: System::Void filterCandlesticks() {
		// Get candlesticks in time frame
		Generic::List<aSmartCandlestick^>^ filteredCandlesticks = this->filterCandlesticks(
			this->dateTimePicker_start->Value, this->dateTimePicker_end->Value, this->listOfCandlesticks
		);
		// Clear binding list
		this->filteredListOfCandlesticks->Clear();
		// Add filtered candlesticks to binding list
		for (int i = 0; i < filteredCandlesticks->Count; i++) {
			this->filteredListOfCandlesticks->Add(filteredCandlesticks[i]);
		}
	}


	/// <summary>
	/// Populates a chart series with candlestick data.
	/// </summary>
	/// <param name="chart">The chart to populate.</param>
	/// <param name="seriesName">The name of the candlestick series to populate.</param>
	/// <param name="listOfCandlesticks">The list of candlesticks to display in the chart.</param>
	private: System::Void displayDataOnChart(
		DataVisualization::Charting::Chart^ chart,
		System::String^ candlestickSeriesName,
		System::String^ volumeSeriesName,
		System::Collections::Generic::IList<aSmartCandlestick^>^ listOfCandlesticks)
	{
		// Clear prior candlestick series data
		chart->Series[candlestickSeriesName]->Points->Clear();
		// Clear prior volume series data
		chart->Series[volumeSeriesName]->Points->Clear();

		// Add each candlestick to the chart
		for  each (aSmartCandlestick ^ candlestick in listOfCandlesticks) {
			// Create a new data point for candlestick OHLC area
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ csPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();
			// Set point's y-value
			csPoint->XValue = candlestick->Date->ToOADate();
			// Set point's x value
			csPoint->YValues = gcnew cli::array<double>{
				static_cast<double>(candlestick->High),
				static_cast<double>(candlestick->Low),
				static_cast<double>(candlestick->Open),
				static_cast<double>(candlestick->Close)
			};

			// Check if point is bullish or bearish
			if (candlestick->Close > candlestick->Open) {
				// If point is bullish, set color to green
				csPoint->Color = System::Drawing::Color::Green;
			}
			else {
				// If point is bearish, set color to red
				csPoint->Color = System::Drawing::Color::Red;
			}
			// Set point's border width
			csPoint->BorderWidth = 1;

			// Create data point for volume area
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ volumePoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();
			// Set point's y-value
			volumePoint->XValue = candlestick->Date->ToOADate();
			// Set point's x value
			volumePoint->YValues = gcnew cli::array<double>{
				static_cast<double>(candlestick->Volume)
			};


			// Add volume point to the series
			chart->Series[volumeSeriesName]->Points->Add(volumePoint);
			// Add the candlestick point to chart
			chart->Series[candlestickSeriesName]->Points->Add(csPoint);
		}
	}
	
	/// <summary>
	/// Populates the chart_stockData with candlestick data.
	/// </summary>
	/// <param name="listOfCandlesticks">The list of candlesticks to display in chart_stockData.</param>
	private: System::Void displayDataOnChart() {
		// Populate chart with candlestick data
		this->displayDataOnChart(chart_stockData, "Series_OHLC", "Series_Volume", filteredListOfCandlesticks);
	}
	

	/// <summary>
	/// Normalizes a chart series according to specified minimum and maximum values.
	/// </summary>
	/// <param name="chart">The chart to normalize.</param>
	/// <param name="seriesName">The name of the chart series to normalize.</param>
	/// <param name="areaName">The name of the chart area to normalize.</param>
	private: System::Void normalizeCandlestickChart(Windows::Forms::DataVisualization::Charting::Chart^ chart, String^ seriesName, String^ areaName) {
		// Variable to store min
		double minY = 0;
		// Variable to store max
		double maxY = 0;
		
		// If the series is not empty
		if (chart->Series[seriesName]->Points->Count != 0) {
			// Set proper initial min
			minY = chart->Series[seriesName]->Points[0]->YValues[1];
			// Set proper initial max
			maxY = chart->Series[seriesName]->Points[0]->YValues[0];
		}

		
		// Iterate through each point in the series
		for each (Windows::Forms::DataVisualization::Charting::DataPoint^ point in chart->Series[seriesName]->Points) {
			// Check point and update min
			minY = Math::Min(minY, point->YValues[1]);
			// Check point and update max
			maxY = Math::Max(maxY, point->YValues[0]);
		}

		// Set chart area minimum
		chart->ChartAreas[areaName]->AxisY->Minimum = Math::Round(minY * 0.98, 2);
		// Set chart area maximum
		chart->ChartAreas[areaName]->AxisY->Maximum = Math::Round(maxY * 1.02, 2);
	}
	/// <summary>
	/// Normalize a chart series according to min and max values
	/// </summary>
	/// <returns>void</returns>
	private: System::Void normalizeCandlestickChart() {
		// Normalize chart
		normalizeCandlestickChart(chart_stockData, "Series_OHLC", "ChartArea_OHLC");
	}


	/// <summary>
	/// Updates the stocks being displayed by filtering according to the provided start and end dates.
	/// </summary>
	/// <param name="startDate">The start date for the filter.</param>
	/// <param name="endDate">The end date for the filter.</param>
	private: System::Void update(System::DateTime^ startDate, System::DateTime^ endDate) {
		// Filter candlesticks using the provided dates
		Generic::List<aSmartCandlestick^>^ filteredCandlesticks = this->filterCandlesticks(startDate, endDate, this->listOfCandlesticks);

		// Clear binding list
		this->filteredListOfCandlesticks->Clear();

		// Add filtered candlesticks to binding list
		for (int i = 0; i < filteredCandlesticks->Count; i++) {
			this->filteredListOfCandlesticks->Add(filteredCandlesticks[i]);
		}

		// Update chart
		this->displayDataOnChart();

		// Normalize chart
		this->normalizeCandlestickChart();

		// Show annotations for selected pattern
		showAnnotationsForSelectedPattern(nullptr, nullptr);
	}
	/// <summary>
	/// Update stocks being displayed according to filters from form controls
	/// </summary>
	/// <returns>void</returns>
	private: System::Void update() {
		// Get the start date from the date picker
		// Get the start date from the date picker
		System::DateTime^ startDate = this->dateTimePicker_start->Value;
		// Get the end date from the date picker
		System::DateTime^ endDate = this->dateTimePicker_end->Value;

		// Call the overloaded update method with the date range
		this->update(startDate, endDate);
	}


private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e) {
	// Update displays
	this->update();
}

/// <summary>
/// Display annotations for patterns selected using checkboxes
/// </summary>
/// <returns>void</returns>
private: System::Void showAnnotationsForSelectedPattern(System::Object^ sender, System::EventArgs^ e) {
	// Clear previous annotations
	chart_stockData->Annotations->Clear();

	// Regenerate annotations for peaks and valleys
	outlinePeaksAndValleys();

	// Get selected patterns
	Generic::List<String^>^ selectedPatterns = gcnew Generic::List<String^>();
	// If bearish checkbox is checked add pattern to list
	if (checkBox_bearishPattern->Checked) selectedPatterns->Add("Bearish");
	// If bullish checkbox is checked add pattern to list
	if (checkBox_bullishPattern->Checked) selectedPatterns->Add("Bullish");
	// If neutral checkbox is checked add pattern to list
	if (checkBox_neutralPattern->Checked) selectedPatterns->Add("Neutral");
	// If marubozu checkbox is checked add pattern to list
	if (checkBox_marubozuPattern->Checked) selectedPatterns->Add("Marubozu");
	// If hammer checkbox is checked add pattern to list
	if (checkBox_hammerPattern->Checked) selectedPatterns->Add("Hammer");
	// If doji checkbox is checked add pattern to list
	if (checkBox_dojiPattern->Checked) selectedPatterns->Add("Doji");
	// If dragonfly doji checkbox is checked add pattern to list
	if (checkBox_dragonflyDojiPattern->Checked) selectedPatterns->Add("Dragonfly Doji");
	// If gravestone doji checkbox is checked add pattern to list
	if (checkBox_gravestoneDojiPattern->Checked) selectedPatterns->Add("Gravestone Doji");

	// Dictionary to store text annotations per index
	Generic::Dictionary<int, String^>^ textAnnotations = gcnew Generic::Dictionary<int, String^>();
	// Pattern to abbreviation dictionary
	Generic::Dictionary<String^, String^>^ patternToAbbr = gcnew Generic::Dictionary<String^, String^>();
	
	// Add patterns and respective abbreviations to dictionary
	patternToAbbr->Add("Bearish", "Be");
	patternToAbbr->Add("Bullish", "Bu");
	patternToAbbr->Add("Neutral", "N");
	patternToAbbr->Add("Marubozu", "M");
	patternToAbbr->Add("Hammer", "H");
	patternToAbbr->Add("Doji", "D");
	patternToAbbr->Add("Dragonfly Doji", "DD");
	patternToAbbr->Add("Gravestone Doji", "GD");

	for each (String ^ selectedPattern in selectedPatterns) {
		// Iterate through each displayed candlestick
		for (int i = 0; i < filteredListOfCandlesticks->Count; i++) {
			// Get current candlestick
			aSmartCandlestick^ candlestick = filteredListOfCandlesticks[i];
			// Initialize matchesPattern
			bool matchesPattern = false;

			// Check for if selected pattern matches candlestick pattern
			if (selectedPattern->Equals("Bearish")) {
				// If candlestick is bearish set matchesPattern
				matchesPattern = candlestick->isBearish();
			}
			else if (selectedPattern->Equals("Bullish")) {
				// If candlestick is bullish set matchesPattern
				matchesPattern = candlestick->isBullish();
			}
			else if (selectedPattern->Equals("Neutral")) {
				// If candlestick is neutral set matchesPattern
				matchesPattern = candlestick->isNeutral();
			}
			else if (selectedPattern->Equals("Marubozu")) {
				// If candlestick is marubozu set matchesPattern
				matchesPattern = candlestick->isMarubozu();
			}
			else if (selectedPattern->Equals("Hammer")) {
				// If candlestick is hammer set matchesPattern
				matchesPattern = candlestick->isHammer();
			}
			else if (selectedPattern->Equals("Doji")) {
				// If candlestick is doji set matchesPattern
				matchesPattern = candlestick->isDoji();
			}
			else if (selectedPattern->Equals("Dragonfly Doji")) {
				// If candlestick is dragonfly doji set matchesPattern
				matchesPattern = candlestick->isDragonflyDoji();
			}
			else if (selectedPattern->Equals("Gravestone Doji")) {
				// If candlestick is gravestone doji set matchesPattern
				matchesPattern = candlestick->isGravestoneDoji();
			}

			// If candlestick's pattern matches selected pattern
			if (matchesPattern) {
				// Create arrow annotation
				auto arrowAnnotation = gcnew DataVisualization::Charting::ArrowAnnotation();
				// Set annotation colors
				arrowAnnotation->BackColor = System::Drawing::Color::DarkBlue;
				arrowAnnotation->LineColor = System::Drawing::Color::Transparent;
				// Set annotation width
				arrowAnnotation->Width = 0;
				// Set annotation height
				arrowAnnotation->Height = -5;
				// Anchor annotation to corresponding data point
				arrowAnnotation->AnchorDataPoint = chart_stockData->Series["Series_OHLC"]->Points[i];

				if (!textAnnotations->ContainsKey(i)) {
				// If dictionary does not contain key, add key and value
					textAnnotations->Add(i, patternToAbbr[selectedPattern]);
				}
				else {
				// If dictionary contains key, add value to existing key
					textAnnotations[i] = textAnnotations[i] + "\n" + patternToAbbr[selectedPattern];
				}

				// Add arrow annotation to chart candlestick series
				chart_stockData->Annotations->Add(arrowAnnotation);
			}
		}
	}

	for each (KeyValuePair<int, String^> ^ kvp in textAnnotations) {
		// Get key
		int key = kvp->Key;
		// Get value
		String^ value = kvp->Value;

		// Create text annotation
		auto textAnnotation = gcnew DataVisualization::Charting::TextAnnotation();
		// Set anchor data point
		textAnnotation->AnchorDataPoint = chart_stockData->Series["Series_OHLC"]->Points[key];
		// Set annotation position to bottom of candlestick
		textAnnotation->Y = (double)filteredListOfCandlesticks[key]->Low;
		// Set annotation color
		textAnnotation->ForeColor = System::Drawing::Color::DarkBlue;
		// Set annotation text
		textAnnotation->Text = value;
		// Add text annotation to chart candlestick series
		chart_stockData->Annotations->Add(textAnnotation);
	}
}

/// <summary>
/// Outline peaks and valleys of candlestick displayed on the chart_stockData OHLC series
/// </summary>
/// <returns>void</returns>
private: System::Void outlinePeaksAndValleys() {
	// Iterate through each displayed candlestick, checking for peaks and valleys
	for (int i = 1; i < filteredListOfCandlesticks->Count - 1; i++) {
		// Get previous candlestick
		aSmartCandlestick^ previous = filteredListOfCandlesticks[i - 1];
		// Get current candlestick
		aSmartCandlestick^ current = filteredListOfCandlesticks[i];
		// Get next candlestick
		aSmartCandlestick^ next = filteredListOfCandlesticks[i + 1];

		// Calculate if current candlestick is a peak
		bool isPeak = (current->High > previous->High) && (current->High > next->High);
		// Calculate if current candlestick is a valley
		bool isValley = (current->Low < previous->Low) && (current->Low < next->Low);

		if (isPeak) {
		// If current candlestick is a peak
			// Create and configure a green annotation for peak
			auto peakAnnotation = gcnew DataVisualization::Charting::ArrowAnnotation();
			peakAnnotation->BackColor = System::Drawing::Color::Green;
			peakAnnotation->LineColor = System::Drawing::Color::Green;
			peakAnnotation->Width = 2;
			peakAnnotation->Height = -4;
			peakAnnotation->ArrowStyle = DataVisualization::Charting::ArrowStyle::Tailed;
			peakAnnotation->ArrowSize = 2;
			peakAnnotation->AnchorDataPoint = chart_stockData->Series["Series_OHLC"]->Points[i];
			peakAnnotation->Y = Convert::ToDouble(current->High);
			// Add peak annotation to chart
			chart_stockData->Annotations->Add(peakAnnotation);

			// Add a green horizontal line across the chart at the peak's high price
			auto peakLine = gcnew DataVisualization::Charting::HorizontalLineAnnotation();
			peakLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
			peakLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
			peakLine->IsInfinitive = true;
			peakLine->ClipToChartArea = "ChartArea_OHLC";
			peakLine->Y = Convert::ToDouble(current->High);
			peakLine->LineColor = System::Drawing::Color::Green;
			// Add peak line to chart
			chart_stockData->Annotations->Add(peakLine);
		}

		if (isValley) {
		// If current candlestick is a valley
			// Create and configure a red annotation for valley
			auto valleyAnnotation = gcnew DataVisualization::Charting::ArrowAnnotation();
			valleyAnnotation->BackColor = System::Drawing::Color::Red;
			valleyAnnotation->LineColor = System::Drawing::Color::Red;
			valleyAnnotation->Width = 2;
			valleyAnnotation->Height = 4;
			valleyAnnotation->ArrowStyle = DataVisualization::Charting::ArrowStyle::Tailed;
			valleyAnnotation->ArrowSize = 2;
			valleyAnnotation->AnchorDataPoint = chart_stockData->Series["Series_OHLC"]->Points[i];
			valleyAnnotation->Y = Convert::ToDouble(current->Low);
			// Add valley annotation to chart
			chart_stockData->Annotations->Add(valleyAnnotation);

			// Add a red horizontal line across the chart at the valley's low price
			auto valleyLine = gcnew DataVisualization::Charting::HorizontalLineAnnotation();
			valleyLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
			valleyLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
			valleyLine->IsInfinitive = true;
			valleyLine->ClipToChartArea = "ChartArea_OHLC";
			valleyLine->Y = Convert::ToDouble(current->Low);
			valleyLine->LineColor = System::Drawing::Color::Red;
			// Add valley line to chart
			chart_stockData->Annotations->Add(valleyLine);
		}
	}
}








};
}