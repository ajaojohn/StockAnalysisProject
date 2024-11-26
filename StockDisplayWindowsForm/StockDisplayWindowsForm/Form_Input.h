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
	private: System::Windows::Forms::CheckBox^ checkBox_selectAllPatterns;
	private: System::Windows::Forms::CheckBox^ checkBox_showPeaksAndValleys;






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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_load = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_stockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label_startDate = (gcnew System::Windows::Forms::Label());
			this->label_endDate = (gcnew System::Windows::Forms::Label());
			this->button_update = (gcnew System::Windows::Forms::Button());
			this->groupBox_patterns = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox_showPeaksAndValleys = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_selectAllPatterns = (gcnew System::Windows::Forms::CheckBox());
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
			this->button_load->Location = System::Drawing::Point(1401, 842);
			this->button_load->Margin = System::Windows::Forms::Padding(4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(359, 69);
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
			this->dateTimePicker_start->Size = System::Drawing::Size(164, 29);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker_end->CustomFormat = L"d MMM yyyy";
			this->dateTimePicker_end->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_end->Location = System::Drawing::Point(187, 68);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(165, 29);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// chart_stockData
			// 
			this->chart_stockData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisY->LabelStyle->Format = L"F2";
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea1->AxisY->Title = L"Price";
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->AxisY->Title = L"Volume";
			chartArea2->Name = L"ChartArea_Volume";
			this->chart_stockData->ChartAreas->Add(chartArea1);
			this->chart_stockData->ChartAreas->Add(chartArea2);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart_stockData->Legends->Add(legend1);
			this->chart_stockData->Location = System::Drawing::Point(12, 14);
			this->chart_stockData->Margin = System::Windows::Forms::Padding(4);
			this->chart_stockData->Name = L"chart_stockData";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			series2->ChartArea = L"ChartArea_Volume";
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart_stockData->Series->Add(series1);
			this->chart_stockData->Series->Add(series2);
			this->chart_stockData->Size = System::Drawing::Size(1380, 896);
			this->chart_stockData->TabIndex = 4;
			this->chart_stockData->Text = L"Stock Data";
			this->chart_stockData->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form_Input::chart_stockData_Paint);
			this->chart_stockData->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_Input::chart_stockData_MouseDown);
			this->chart_stockData->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_Input::chart_stockData_MouseMove);
			this->chart_stockData->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_Input::chart_stockData_MouseUp);
			// 
			// label_startDate
			// 
			this->label_startDate->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(10, 39);
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
			this->label_endDate->Location = System::Drawing::Point(188, 39);
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
			this->button_update->Location = System::Drawing::Point(14, 110);
			this->button_update->Margin = System::Windows::Forms::Padding(4);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(340, 70);
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
			this->groupBox_patterns->Controls->Add(this->checkBox_showPeaksAndValleys);
			this->groupBox_patterns->Controls->Add(this->checkBox_selectAllPatterns);
			this->groupBox_patterns->Controls->Add(this->checkBox_gravestoneDojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_dragonflyDojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_dojiPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_hammerPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_marubozuPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_bearishPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_bullishPattern);
			this->groupBox_patterns->Controls->Add(this->checkBox_neutralPattern);
			this->groupBox_patterns->Location = System::Drawing::Point(1400, 14);
			this->groupBox_patterns->Name = L"groupBox_patterns";
			this->groupBox_patterns->Size = System::Drawing::Size(360, 579);
			this->groupBox_patterns->TabIndex = 12;
			this->groupBox_patterns->TabStop = false;
			this->groupBox_patterns->Text = L"Select Patterns";
			// 
			// checkBox_showPeaksAndValleys
			// 
			this->checkBox_showPeaksAndValleys->AutoSize = true;
			this->checkBox_showPeaksAndValleys->Location = System::Drawing::Point(15, 531);
			this->checkBox_showPeaksAndValleys->Name = L"checkBox_showPeaksAndValleys";
			this->checkBox_showPeaksAndValleys->Size = System::Drawing::Size(258, 29);
			this->checkBox_showPeaksAndValleys->TabIndex = 9;
			this->checkBox_showPeaksAndValleys->Text = L"Show Peaks And Valleys";
			this->checkBox_showPeaksAndValleys->UseVisualStyleBackColor = true;
			this->checkBox_showPeaksAndValleys->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::checkBox_showPeaksAndValleys_CheckedChanged);
			// 
			// checkBox_selectAllPatterns
			// 
			this->checkBox_selectAllPatterns->AutoSize = true;
			this->checkBox_selectAllPatterns->Location = System::Drawing::Point(14, 51);
			this->checkBox_selectAllPatterns->Name = L"checkBox_selectAllPatterns";
			this->checkBox_selectAllPatterns->Size = System::Drawing::Size(158, 29);
			this->checkBox_selectAllPatterns->TabIndex = 8;
			this->checkBox_selectAllPatterns->Text = L"SELECT ALL";
			this->checkBox_selectAllPatterns->UseVisualStyleBackColor = true;
			this->checkBox_selectAllPatterns->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::checkBox_selectAllPatterns_CheckedChanged);
			// 
			// checkBox_gravestoneDojiPattern
			// 
			this->checkBox_gravestoneDojiPattern->AutoSize = true;
			this->checkBox_gravestoneDojiPattern->Location = System::Drawing::Point(14, 332);
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
			this->checkBox_dragonflyDojiPattern->Location = System::Drawing::Point(14, 297);
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
			this->checkBox_dojiPattern->Location = System::Drawing::Point(14, 261);
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
			this->checkBox_hammerPattern->Location = System::Drawing::Point(14, 226);
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
			this->checkBox_marubozuPattern->Location = System::Drawing::Point(14, 192);
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
			this->checkBox_bearishPattern->Location = System::Drawing::Point(14, 87);
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
			this->checkBox_bullishPattern->Location = System::Drawing::Point(14, 122);
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
			this->checkBox_neutralPattern->Location = System::Drawing::Point(14, 156);
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
			this->groupBox_dateFiltering->Location = System::Drawing::Point(1400, 628);
			this->groupBox_dateFiltering->Name = L"groupBox_dateFiltering";
			this->groupBox_dateFiltering->Size = System::Drawing::Size(360, 206);
			this->groupBox_dateFiltering->TabIndex = 13;
			this->groupBox_dateFiltering->TabStop = false;
			this->groupBox_dateFiltering->Text = L"Filter Dates";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1772, 920);
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
	// Call loader to get the list of candlesticks from the file
	Generic::List<aCandlestick^>^ candlesticks = candlestickLoader->load(filename);
	// Create a list to hold smart candlesticks
	Generic::List<aSmartCandlestick^>^ smartCandlesticks = gcnew Generic::List<aSmartCandlestick^>();

	for each (aCandlestick ^ candlestick in candlesticks) {
		// Create a smart candlestick instance
		aSmartCandlestick^ smartCandlestick = gcnew aSmartCandlestick(candlestick);
		// Add the smart candlestick to the list
		smartCandlesticks->Add(smartCandlestick);
		// Increment the index for the next candlestick
	}

	// Return the list of smart candlesticks with updated properties
	return smartCandlesticks;
}
	/// <summary>
	/// Reads candlesticks from a file and saves it to private parameter
	/// </summary>
	/// <returns>void</returns>
	private: System::Void readCandlesticksFromFile() {
		// Use candlestick loader to read candlesticks
		this->listOfCandlesticks = this->readCandlesticksFromFile(this->selectedFilename);
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

		int index = 0;
		// Loop through each candlestick
		for (int i = 0; i < listOfCandlesticks->Count; i++) {
			// If the candlestick is in the time frame
			if (listOfCandlesticks[i]->Date->CompareTo(startDate) >= 0 && listOfCandlesticks[i]->Date->CompareTo(endDate) <= 0) {
				// 
				listOfCandlesticks[i]->Index = index++;
				// Add the candlestick to the list
				filteredCandlesticks->Add(listOfCandlesticks[i]);
			}
		}

	// Total number of candlesticks
	int count = filteredCandlesticks->Count;
	// Iterate through the smart candlesticks to determine peaks and valleys
	for (int i = 0; i < count; i++) {
		aSmartCandlestick^ current = filteredCandlesticks[i];
		if (i == 0 && count > 1) {
			// **First Candlestick: Compare with the next candlestick only**
			aSmartCandlestick^ next = filteredCandlesticks[i + 1];
			// Determine if it's a peak
			current->IsPeak = current->High > next->High;
			// Determine if it's a valley
			current->IsValley = current->Low < next->Low;

			MessageBox::Show("First cs isPeak: " + current->IsPeak + "\nFirst cs isValley: " + current->IsValley + "\n");
		}
		else if (i == count - 1 && count > 1) {
			// **Last Candlestick: Compare with the previous candlestick only**
			aSmartCandlestick^ prev = filteredCandlesticks[i - 1];
			// Determine if it's a peak
			current->IsPeak = current->High > prev->High;
			// Determine if it's a valley
			current->IsValley = current->Low < prev->Low;

			MessageBox::Show("Last cs isPeak: " + current->IsPeak + "\Last cs isValley: " + current->IsValley + "\n");
		}
		else if (i > 0 && i < count - 1) {
			// **Middle Candlesticks: Compare with both previous and next candlesticks**
			aSmartCandlestick^ prev = filteredCandlesticks[i - 1];
			aSmartCandlestick^ next = filteredCandlesticks[i + 1];
			// Determine if it's a peak
			current->IsPeak = (current->High > prev->High) && (current->High > next->High);
			// Determine if it's a valley
			current->IsValley = (current->Low < prev->Low) && (current->Low < next->Low);
		}
		else {
			// **Edge Case Handling:**
			// If there's only one candlestick, it cannot be a peak or valley
			current->IsPeak = false;
			current->IsValley = false;
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
	if (checkBox_showPeaksAndValleys->Checked) {
		outlinePeaksAndValleys();
	}

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
	for (int i = 0; i < filteredListOfCandlesticks->Count ; i++) {
		// Get current candlestick
		aSmartCandlestick^ current = filteredListOfCandlesticks[i];

		// Calculate if current candlestick is a peak
		bool isPeak = current->IsPeak;
		// Calculate if current candlestick is a valley
		bool isValley = current->IsValley;

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

private: System::Void checkBox_selectAllPatterns_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {\
	// Get list of all checkboxes
	Generic::List<CheckBox^>^ listOfCheckboxes = gcnew Generic::List<CheckBox^>();
	listOfCheckboxes->Add(checkBox_bearishPattern);
	listOfCheckboxes->Add(checkBox_bullishPattern);
	listOfCheckboxes->Add(checkBox_neutralPattern);
	listOfCheckboxes->Add(checkBox_marubozuPattern);
	listOfCheckboxes->Add(checkBox_hammerPattern);
	listOfCheckboxes->Add(checkBox_dojiPattern);
	listOfCheckboxes->Add(checkBox_dragonflyDojiPattern);
	listOfCheckboxes->Add(checkBox_gravestoneDojiPattern);

	// Set checked state of all checkboxes to match select all checkbox
	for each (CheckBox^ checkbox in listOfCheckboxes) {
		checkbox->Checked = checkBox_selectAllPatterns->Checked;
	}
}


private:
	const int SNAP_MARGIN = 5; // Number of candlesticks to search on either side
	System::Drawing::Rectangle selectionRectangle; // Rectangle to draw during selection
	DataVisualization::Charting::DataPoint^ currentDragDataPoint = nullptr;
	bool isDragging; // Indicates if a drag operation is in progress
	System::Drawing::Point dragStartPoint; // Starting point of the drag
	aSmartCandlestick^ selectedCandlestickStart; // Candlestick at drag start
	aSmartCandlestick^ selectedCandlestickEnd;   // Candlestick at drag end

	DataVisualization::Charting::DataPoint^ selectedDataPointStart; // Data point at drag start
	DataVisualization::Charting::DataPoint^ selectedDataPointEnd; // Data point at drag end
	DataVisualization::Charting::RectangleAnnotation^ currentWaveRectangle;

/// <summary>
/// Finds the nearest peak or valley to a candlestick
/// </summary>
/// <param name="cs">Candlestick to search from</param>
/// <param name="margin">Margin to search</param>
/// <returns></returns>
aSmartCandlestick^ Form_Input::findNearestPeakOrValley(aSmartCandlestick^ cs, int margin) {
    if (cs == nullptr) return nullptr;
    if (filteredListOfCandlesticks->Count == 0) return nullptr;

    // Find the index of the reference candlestick
    int index = filteredListOfCandlesticks->IndexOf(cs);
    if (index == -1) return nullptr;

    // Alternate search: for each distance d from 1 to margin
    for (int d = 0; d < margin; d++) {
        // Calculate backward and forward indices
        int backIndex = index - d;
        int forwardIndex = index + d;

        // Search backward first
        if (backIndex >= 0) {
            aSmartCandlestick^ backCandlestick = filteredListOfCandlesticks[backIndex];
            if (backCandlestick->IsPeak || backCandlestick->IsValley) {
                return backCandlestick;
            }
        }

        // Then search forward
        if (forwardIndex < filteredListOfCandlesticks->Count) {
            aSmartCandlestick^ forwardCandlestick = filteredListOfCandlesticks[forwardIndex];
            if (forwardCandlestick->IsPeak || forwardCandlestick->IsValley) {
                return forwardCandlestick;
            }
        }
    }

    // If no peak or valley is found within the margin
    return nullptr;
}

private: aSmartCandlestick^ findCandlestickByXValue(double xValue) {
	for each (aSmartCandlestick ^ cs in filteredListOfCandlesticks) {
		if (cs->Date->ToOADate() == xValue) {
			return cs;
		}
	}
	return nullptr;
}

private: System::Void resetWaveSelections() {
    if (selectedDataPointStart != nullptr) {
        highlightDataPoint(selectedDataPointStart, false);
    }
    if (selectedDataPointEnd != nullptr) {
        highlightDataPoint(selectedDataPointEnd, false);
    }

    // Remove the current rectangle annotation if it exists
    if (currentWaveRectangle != nullptr) {
        chart_stockData->Annotations->Remove(currentWaveRectangle);
        currentWaveRectangle = nullptr;
    }

    selectedCandlestickStart = nullptr;
    selectedCandlestickEnd = nullptr;
    selectedDataPointStart = nullptr;
    selectedDataPointEnd = nullptr;
}

private: System::Void highlightDataPoint(DataVisualization::Charting::DataPoint^ dp, bool isSelected) {
	if (isSelected) {
		dp->MarkerStyle = DataVisualization::Charting::MarkerStyle::Circle;
		dp->MarkerSize = 10;
		dp->MarkerColor = System::Drawing::Color::Yellow;
		dp->BorderWidth = 2;
		dp->BorderColor = System::Drawing::Color::Black;
	}
	else {
		dp->MarkerStyle = DataVisualization::Charting::MarkerStyle::None;
		dp->BorderWidth = 1;
		dp->BorderColor = System::Drawing::Color::Transparent;
	}
}

private: DataVisualization::Charting::DataPoint^ GetDataPointByXPosition(int mouseX)
{
	// Access the relevant ChartArea
	DataVisualization::Charting::ChartArea^ chartArea = chart_stockData->ChartAreas["ChartArea_OHLC"];

	// Convert the mouse's X pixel position to the axis X-value (which is the index)
	double xValue = chartArea->AxisX->PixelPositionToValue(static_cast<double>(mouseX));

	// Round to the nearest integer index
	int index = static_cast<int>(Math::Round(xValue));

	// Check if the index is within the valid range
	if (index > 0 && index <= chart_stockData->Series["Series_OHLC"]->Points->Count)
	{
		// Optional: Define a threshold to ensure the click is close enough to the DataPoint
		// For indexed charts, a threshold of 0.5 is reasonable
		double distance = Math::Abs(xValue - index);
		double threshold = 0.5; // Adjust if necessary

		if (distance <= threshold)
		{
			return chart_stockData->Series["Series_OHLC"]->Points[index-1];
		}
	}

	// Return nullptr if no DataPoint is within the threshold
	return nullptr;
}


private: System::Void chart_stockData_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		// Reset any previous selections
		resetWaveSelections();

		isDragging = true;
		dragStartPoint = System::Drawing::Point(e->X, e->Y);
		selectionRectangle = System::Drawing::Rectangle(e->X, e->Y, 0, 0);

		// Use the helper method to get the closest DataPoint
		DataVisualization::Charting::DataPoint^ startPoint = GetDataPointByXPosition(e->X);
		if (startPoint != nullptr) {
			selectedCandlestickStart = findCandlestickByXValue(startPoint->XValue);
			selectedDataPointStart = startPoint;
			highlightDataPoint(selectedDataPointStart, true);
		}

		// Unhighlight any existing drag DataPoint
		if (currentDragDataPoint != nullptr) {
			highlightDataPoint(currentDragDataPoint, false);
			currentDragDataPoint = nullptr;
		}
	}
}

private: System::Void chart_stockData_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (isDragging) {
		// Update the selection rectangle based on mouse movement
		int x = Math::Min(dragStartPoint.X, e->X);
		int y = Math::Min(dragStartPoint.Y, e->Y);
		int width = Math::Abs(e->X - dragStartPoint.X);
		int height = Math::Abs(e->Y - dragStartPoint.Y);
		selectionRectangle = System::Drawing::Rectangle(x, y, width, height);

		// Redraw the chart to display the selection rectangle
		chart_stockData->Invalidate();

		// Use the helper method to get the closest DataPoint
		DataVisualization::Charting::DataPoint^ currentPoint = GetDataPointByXPosition(e->X);

		if (currentPoint != currentDragDataPoint && currentPoint != nullptr) {
			// Unhighlight the previous DataPoint if it exists
			if (currentDragDataPoint != nullptr) {
				highlightDataPoint(currentDragDataPoint, false);
			}

			// Highlight the new DataPoint
			highlightDataPoint(currentPoint, true);
			currentDragDataPoint = currentPoint;
		}
		else if (currentPoint == nullptr && currentDragDataPoint != nullptr) {
			// If not hovering over a DataPoint, remove any existing highlight
			highlightDataPoint(currentDragDataPoint, false);
			currentDragDataPoint = nullptr;
		}
	}
}

private: System::Void chart_stockData_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (isDragging) {
		isDragging = false;

		// Redraw the chart to remove the selection rectangle
		chart_stockData->Invalidate();

		// Unhighlight the current drag DataPoint, if any
		if (currentDragDataPoint != nullptr) {
			highlightDataPoint(currentDragDataPoint, false);
			currentDragDataPoint = nullptr;
		}

		// Use the helper method to get the closest DataPoint
		DataVisualization::Charting::DataPoint^ endPoint = GetDataPointByXPosition(e->X);
		if (endPoint != nullptr) {
			selectedCandlestickEnd = findCandlestickByXValue(endPoint->XValue);
			selectedDataPointEnd = endPoint;
			highlightDataPoint(selectedDataPointEnd, true);

			// Perform actions with the selected candlesticks
			onTwoCandlesticksSelected(selectedCandlestickStart, selectedCandlestickEnd);
		}
	}
}

private: System::Void onTwoCandlesticksSelected(aSmartCandlestick^ csStart, aSmartCandlestick^ csEnd) {
	if (csStart != nullptr && csEnd != nullptr) {
		// Find the nearest peak or valley to the start candlestick
		aSmartCandlestick^ snappedStart = findNearestPeakOrValley(csStart, SNAP_MARGIN);
		// Find the nearest peak or valley to the end candlestick
		aSmartCandlestick^ snappedEnd = csEnd;

		// Check if both snapped candlesticks are found
		if (snappedStart != nullptr && snappedEnd != nullptr) {
			// Unhighlight the initially selected candlesticks
			if (selectedDataPointStart != nullptr) {
				highlightDataPoint(selectedDataPointStart, false);
			}
			if (selectedDataPointEnd != nullptr) {
				highlightDataPoint(selectedDataPointEnd, false);
			}

			// Find the DataPoints corresponding to the snapped candlesticks
			DataVisualization::Charting::DataPoint^ snappedStartPoint = nullptr;
			DataVisualization::Charting::DataPoint^ snappedEndPoint = nullptr;

			for each (DataVisualization::Charting::DataPoint ^ dp in chart_stockData->Series["Series_OHLC"]->Points) {
				if (dp->XValue == snappedStart->Date->ToOADate()) {
					snappedStartPoint = dp;
				}
				if (dp->XValue == snappedEnd->Date->ToOADate()) {
					snappedEndPoint = dp;
				}
			}

			// Highlight the snapped candlesticks
			if (snappedStartPoint != nullptr) {
				highlightDataPoint(snappedStartPoint, true);
			}
			if (snappedEndPoint != nullptr) {
				highlightDataPoint(snappedEndPoint, true);
			}

			// Update selected candlesticks and DataPoints
			selectedCandlestickStart = snappedStart;
			selectedCandlestickEnd = snappedEnd;
			selectedDataPointStart = snappedStartPoint;
			selectedDataPointEnd = snappedEndPoint;

			if (isValidWave(snappedStart, snappedEnd)) {
				// Draw rectangle between the snapped candlesticks
				drawRectangleBetweenCandlesticks(snappedStart, snappedEnd);
			}
			else {

				// Show the information in a message box
				MessageBox::Show("Selected Candlesticks do not form a valid wave.", "Selection Error");
				resetWaveSelections();
			}			
		}
		else {
			MessageBox::Show("No nearby peak or valley found within the margin of error.", "Selection Error");
		}
	}
}

private: System::Void chart_stockData_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	if (isDragging) {
		// Define the pen for drawing the rectangle (e.g., Blue dashed line)
		System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Blue, 2);
		pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;

		// Draw the selection rectangle
		e->Graphics->DrawRectangle(pen, selectionRectangle);

		// Clean up
		delete pen;
	}
}

	   bool Form_Input::isValidWave(aSmartCandlestick^ candlestick1, aSmartCandlestick^ candlestick2) {
		   // Validate inputs
		   if (candlestick1 == nullptr || candlestick2 == nullptr)
			   return false;

		   // Determine if the first candlestick is a peak or a valley
		   bool c1Peak = candlestick1->IsPeak;
		   bool c1Valley = candlestick1->IsValley;

		   // Ensure the first candlestick is either a peak or a valley
		   if (!(c1Peak || c1Valley))
			   return false;

		   // Find indices of the selected candlesticks in the filtered list
		   int index1 = filteredListOfCandlesticks->IndexOf(candlestick1);
		   int index2 = filteredListOfCandlesticks->IndexOf(candlestick2);

		   // Ensure both candlesticks are present in the list
		   if (index1 == -1 || index2 == -1)
			   return false;

		   // Determine the order based on index
		   int startIndex = Math::Min(index1, index2);
		   int endIndex = Math::Max(index1, index2);

		   if (startIndex == endIndex) {
			   MessageBox::Show("Selected candlesticks are the same.", "Selection Error");
			   return false;
		   }

		   // Get the first candlestick in the selection
		   aSmartCandlestick^ firstCandlestick = filteredListOfCandlesticks[startIndex];
		   // Get the second candlestick in the selection
		   aSmartCandlestick^ secondCandlestick = filteredListOfCandlesticks[endIndex];

		   auto maxY = Math::Max((double)firstCandlestick->High, (double)secondCandlestick->High);
		   auto minY = Math::Min((double)firstCandlestick->Low, (double)secondCandlestick->Low);
		   

		   // Iterate through candlesticks between startIndex and endIndex (exclusive)
		   for (int i = startIndex + 1; i < endIndex; i++) {
			   aSmartCandlestick^ curr = filteredListOfCandlesticks[i];

			   // If first is a peak, ensure no intermediate high exceeds first's high
			   if ((double)curr->High > maxY)
				   return false;

			   // If first is a valley, ensure no intermediate low falls below first's low
			   if ((double)curr->Low < minY)
				   return false;
		   }

		   // All conditions met; valid wave within selection
		   return true;
	   }
private: DataVisualization::Charting::RectangleAnnotation^ drawRectangleBetweenCandlesticks(aSmartCandlestick^ cs1, aSmartCandlestick^ cs2) {
	// Remove existing rectangle annotation if any
	if (currentWaveRectangle != nullptr) {
		chart_stockData->Annotations->Remove(currentWaveRectangle);
		currentWaveRectangle = nullptr;
	}

	// Create new rectangle annotation
	auto rectangleAnnotation = gcnew DataVisualization::Charting::RectangleAnnotation();
	rectangleAnnotation->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
	rectangleAnnotation->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
	rectangleAnnotation->LineColor = Color::Blue;
	rectangleAnnotation->BackColor = Color::Transparent;
	rectangleAnnotation->LineWidth = 2;
	rectangleAnnotation->LineDashStyle = DataVisualization::Charting::ChartDashStyle::Dash;
	rectangleAnnotation->IsSizeAlwaysRelative = false;

	// Determine the highest and lowest Y values
	double maxY = Math::Max((double)cs1->High, (double)cs2->High);
	double minY = Math::Min((double)cs1->Low, (double)cs2->Low);

	// Determine the order based on the X values (dates)
	aSmartCandlestick^ firstCS;
	aSmartCandlestick^ secondCS;

	if (cs1->Date->ToOADate() < cs2->Date->ToOADate()) {
		firstCS = cs1;
		secondCS = cs2;
	}
	else {
		firstCS = cs2;
		secondCS = cs1;
	}

	// Set the position and size of the rectangle
	rectangleAnnotation->Y = minY;
	rectangleAnnotation->Height = maxY - minY;
	rectangleAnnotation->X = firstCS->Index + 1;
	rectangleAnnotation->Width = secondCS->Index - firstCS->Index;

	// Add the rectangle to the chart
	chart_stockData->Annotations->Add(rectangleAnnotation);

	// Assign the newly created rectangle to the member variable
	currentWaveRectangle = rectangleAnnotation;

	return rectangleAnnotation;
}

private: System::Void checkBox_showPeaksAndValleys_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	showAnnotationsForSelectedPattern(nullptr, nullptr);
}
};
}