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
			this->button_load->Location = System::Drawing::Point(1019, 561);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(261, 46);
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
			this->dateTimePicker_start->Location = System::Drawing::Point(10, 45);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(120, 22);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker_end->CustomFormat = L"d MMM yyyy";
			this->dateTimePicker_end->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker_end->Location = System::Drawing::Point(136, 45);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(121, 22);
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
			chartArea4->Name = L"ChartArea_Beauty";
			this->chart_stockData->ChartAreas->Add(chartArea3);
			this->chart_stockData->ChartAreas->Add(chartArea4);
			legend2->Enabled = false;
			legend2->Name = L"Legend1";
			this->chart_stockData->Legends->Add(legend2);
			this->chart_stockData->Location = System::Drawing::Point(9, 9);
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
			series4->ChartArea = L"ChartArea_Beauty";
			series4->IsValueShownAsLabel = true;
			series4->Legend = L"Legend1";
			series4->Name = L"Series_Beauty";
			this->chart_stockData->Series->Add(series3);
			this->chart_stockData->Series->Add(series4);
			this->chart_stockData->Size = System::Drawing::Size(1004, 597);
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
			this->label_startDate->Location = System::Drawing::Point(7, 26);
			this->label_startDate->Name = L"label_startDate";
			this->label_startDate->Size = System::Drawing::Size(66, 16);
			this->label_startDate->TabIndex = 7;
			this->label_startDate->Text = L"Start Date";
			// 
			// label_endDate
			// 
			this->label_endDate->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_endDate->AutoSize = true;
			this->label_endDate->Location = System::Drawing::Point(137, 26);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(63, 16);
			this->label_endDate->TabIndex = 8;
			this->label_endDate->Text = L"End Date";
			// 
			// button_update
			// 
			this->button_update->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button_update->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button_update->Location = System::Drawing::Point(10, 73);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(247, 47);
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
			this->groupBox_patterns->Location = System::Drawing::Point(1018, 9);
			this->groupBox_patterns->Margin = System::Windows::Forms::Padding(2);
			this->groupBox_patterns->Name = L"groupBox_patterns";
			this->groupBox_patterns->Padding = System::Windows::Forms::Padding(2);
			this->groupBox_patterns->Size = System::Drawing::Size(262, 386);
			this->groupBox_patterns->TabIndex = 12;
			this->groupBox_patterns->TabStop = false;
			this->groupBox_patterns->Text = L"Select Patterns";
			// 
			// checkBox_showPeaksAndValleys
			// 
			this->checkBox_showPeaksAndValleys->AutoSize = true;
			this->checkBox_showPeaksAndValleys->Location = System::Drawing::Point(11, 354);
			this->checkBox_showPeaksAndValleys->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_showPeaksAndValleys->Name = L"checkBox_showPeaksAndValleys";
			this->checkBox_showPeaksAndValleys->Size = System::Drawing::Size(179, 20);
			this->checkBox_showPeaksAndValleys->TabIndex = 9;
			this->checkBox_showPeaksAndValleys->Text = L"Show Peaks And Valleys";
			this->checkBox_showPeaksAndValleys->UseVisualStyleBackColor = true;
			this->checkBox_showPeaksAndValleys->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::checkBox_showPeaksAndValleys_CheckedChanged);
			// 
			// checkBox_selectAllPatterns
			// 
			this->checkBox_selectAllPatterns->AutoSize = true;
			this->checkBox_selectAllPatterns->Location = System::Drawing::Point(10, 34);
			this->checkBox_selectAllPatterns->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_selectAllPatterns->Name = L"checkBox_selectAllPatterns";
			this->checkBox_selectAllPatterns->Size = System::Drawing::Size(107, 20);
			this->checkBox_selectAllPatterns->TabIndex = 8;
			this->checkBox_selectAllPatterns->Text = L"SELECT ALL";
			this->checkBox_selectAllPatterns->UseVisualStyleBackColor = true;
			this->checkBox_selectAllPatterns->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::checkBox_selectAllPatterns_CheckedChanged);
			// 
			// checkBox_gravestoneDojiPattern
			// 
			this->checkBox_gravestoneDojiPattern->AutoSize = true;
			this->checkBox_gravestoneDojiPattern->Location = System::Drawing::Point(10, 221);
			this->checkBox_gravestoneDojiPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_gravestoneDojiPattern->Name = L"checkBox_gravestoneDojiPattern";
			this->checkBox_gravestoneDojiPattern->Size = System::Drawing::Size(157, 20);
			this->checkBox_gravestoneDojiPattern->TabIndex = 7;
			this->checkBox_gravestoneDojiPattern->Text = L"Gravestone Doji (GD)";
			this->checkBox_gravestoneDojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_gravestoneDojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_dragonflyDojiPattern
			// 
			this->checkBox_dragonflyDojiPattern->AutoSize = true;
			this->checkBox_dragonflyDojiPattern->Location = System::Drawing::Point(10, 198);
			this->checkBox_dragonflyDojiPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_dragonflyDojiPattern->Name = L"checkBox_dragonflyDojiPattern";
			this->checkBox_dragonflyDojiPattern->Size = System::Drawing::Size(145, 20);
			this->checkBox_dragonflyDojiPattern->TabIndex = 6;
			this->checkBox_dragonflyDojiPattern->Text = L"Dragonfly Doji (DD)";
			this->checkBox_dragonflyDojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_dragonflyDojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_dojiPattern
			// 
			this->checkBox_dojiPattern->AutoSize = true;
			this->checkBox_dojiPattern->Location = System::Drawing::Point(10, 174);
			this->checkBox_dojiPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_dojiPattern->Name = L"checkBox_dojiPattern";
			this->checkBox_dojiPattern->Size = System::Drawing::Size(74, 20);
			this->checkBox_dojiPattern->TabIndex = 5;
			this->checkBox_dojiPattern->Text = L"Doji (D)";
			this->checkBox_dojiPattern->UseVisualStyleBackColor = true;
			this->checkBox_dojiPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_hammerPattern
			// 
			this->checkBox_hammerPattern->AutoSize = true;
			this->checkBox_hammerPattern->Location = System::Drawing::Point(10, 151);
			this->checkBox_hammerPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_hammerPattern->Name = L"checkBox_hammerPattern";
			this->checkBox_hammerPattern->Size = System::Drawing::Size(102, 20);
			this->checkBox_hammerPattern->TabIndex = 4;
			this->checkBox_hammerPattern->Text = L"Hammer (H)";
			this->checkBox_hammerPattern->UseVisualStyleBackColor = true;
			this->checkBox_hammerPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_marubozuPattern
			// 
			this->checkBox_marubozuPattern->AutoSize = true;
			this->checkBox_marubozuPattern->Location = System::Drawing::Point(10, 128);
			this->checkBox_marubozuPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_marubozuPattern->Name = L"checkBox_marubozuPattern";
			this->checkBox_marubozuPattern->Size = System::Drawing::Size(110, 20);
			this->checkBox_marubozuPattern->TabIndex = 3;
			this->checkBox_marubozuPattern->Text = L"Marubozu (M)";
			this->checkBox_marubozuPattern->UseVisualStyleBackColor = true;
			this->checkBox_marubozuPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_bearishPattern
			// 
			this->checkBox_bearishPattern->AutoSize = true;
			this->checkBox_bearishPattern->Location = System::Drawing::Point(10, 58);
			this->checkBox_bearishPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_bearishPattern->Name = L"checkBox_bearishPattern";
			this->checkBox_bearishPattern->Size = System::Drawing::Size(103, 20);
			this->checkBox_bearishPattern->TabIndex = 2;
			this->checkBox_bearishPattern->Text = L"Bearish (Be)";
			this->checkBox_bearishPattern->UseVisualStyleBackColor = true;
			this->checkBox_bearishPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_bullishPattern
			// 
			this->checkBox_bullishPattern->AutoSize = true;
			this->checkBox_bullishPattern->Location = System::Drawing::Point(10, 81);
			this->checkBox_bullishPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_bullishPattern->Name = L"checkBox_bullishPattern";
			this->checkBox_bullishPattern->Size = System::Drawing::Size(95, 20);
			this->checkBox_bullishPattern->TabIndex = 1;
			this->checkBox_bullishPattern->Text = L"Bullish (Bu)";
			this->checkBox_bullishPattern->UseVisualStyleBackColor = true;
			this->checkBox_bullishPattern->CheckedChanged += gcnew System::EventHandler(this, &Form_Input::showAnnotationsForSelectedPattern);
			// 
			// checkBox_neutralPattern
			// 
			this->checkBox_neutralPattern->AutoSize = true;
			this->checkBox_neutralPattern->Location = System::Drawing::Point(10, 104);
			this->checkBox_neutralPattern->Margin = System::Windows::Forms::Padding(2);
			this->checkBox_neutralPattern->Name = L"checkBox_neutralPattern";
			this->checkBox_neutralPattern->Size = System::Drawing::Size(93, 20);
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
			this->groupBox_dateFiltering->Location = System::Drawing::Point(1018, 419);
			this->groupBox_dateFiltering->Margin = System::Windows::Forms::Padding(2);
			this->groupBox_dateFiltering->Name = L"groupBox_dateFiltering";
			this->groupBox_dateFiltering->Padding = System::Windows::Forms::Padding(2);
			this->groupBox_dateFiltering->Size = System::Drawing::Size(262, 137);
			this->groupBox_dateFiltering->TabIndex = 13;
			this->groupBox_dateFiltering->TabStop = false;
			this->groupBox_dateFiltering->Text = L"Filter Dates";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1289, 613);
			this->Controls->Add(this->groupBox_dateFiltering);
			this->Controls->Add(this->groupBox_patterns);
			this->Controls->Add(this->chart_stockData);
			this->Controls->Add(this->button_load);
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
		// Remove existing Fibonacci and MaxBeauty annotations before loading new data
		removeFibonacciAndMaxBeautyAnnotations();
		// Reset any previous selections
		resetWaveSelections();
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

		int index = 1;
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
		}
		else if (i == count - 1 && count > 1) {
			// **Last Candlestick: Compare with the previous candlestick only**
			aSmartCandlestick^ prev = filteredCandlesticks[i - 1];
			// Determine if it's a peak
			current->IsPeak = current->High > prev->High;
			// Determine if it's a valley
			current->IsValley = current->Low < prev->Low;
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
		// Remove existing Fibonacci and MaxBeauty annotations before loading new data
		removeFibonacciAndMaxBeautyAnnotations();
		// Reset any previous selections
		resetWaveSelections();
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
	// Create list to store prior pattern annotations
	List<DataVisualization::Charting::Annotation^>^ annotationsToRemove = gcnew List<DataVisualization::Charting::Annotation^>();

	// Find pattern annotations
	for each (DataVisualization::Charting::Annotation ^ annotation in chart_stockData->Annotations) {
		if (annotation->Name->StartsWith("Pattern_")) {
			annotationsToRemove->Add(annotation);
		}
	}
	// Remove prior pattern annotations
	for each (DataVisualization::Charting::Annotation ^ annotation in annotationsToRemove) {
		chart_stockData->Annotations->Remove(annotation);
	}
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
				// Set annotation name
				arrowAnnotation->Name = "Pattern_" + selectedPattern + "_" + i.ToString();
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
		// Set annotation name
		textAnnotation->Name = "Pattern_Text_" + key.ToString();
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
			peakAnnotation->Name = "Pattern_PeakArrow_" + i.ToString();
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
			peakLine->Name = "Pattern_PeakLine_" + i.ToString();
			peakLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
			peakLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
			peakLine->IsInfinitive = false;
			peakLine->IsSizeAlwaysRelative = false;
			peakLine->Width = 3;
			peakLine->ClipToChartArea = "ChartArea_OHLC";
			peakLine->X = current->Index - 1.5;
			peakLine->Y = Convert::ToDouble(current->High);
			peakLine->LineColor = System::Drawing::Color::Green;
			// Add peak line to chart
			chart_stockData->Annotations->Add(peakLine);
		}

		if (isValley) {
		// If current candlestick is a valley
			// Create and configure a red annotation for valley
			auto valleyAnnotation = gcnew DataVisualization::Charting::ArrowAnnotation();
			valleyAnnotation->Name = "Pattern_ValleyArrow_" + i.ToString();
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
			valleyLine->Name = "Pattern_ValleyLine_" + i.ToString();
			valleyLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
			valleyLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
			valleyLine->IsInfinitive = false;
			valleyLine->IsSizeAlwaysRelative = false;
			valleyLine->Width = 3;
			valleyLine->ClipToChartArea = "ChartArea_OHLC";
			valleyLine->X = current->Index - 1.5;
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
	DataVisualization::Charting::DataPoint^ currentDragDataPoint = nullptr; // Currently dragged DataPoint
	bool isDragging; // Indicates if a drag operation is in progress
	System::Drawing::Point dragStartPoint; // Starting point of the drag
	aSmartCandlestick^ selectedCandlestickStart; // Candlestick at drag start
	aSmartCandlestick^ selectedCandlestickEnd;   // Candlestick at drag end

	DataVisualization::Charting::DataPoint^ selectedDataPointStart; // Data point at drag start
	DataVisualization::Charting::DataPoint^ selectedDataPointEnd; // Data point at drag end
	DataVisualization::Charting::RectangleAnnotation^ currentWaveRectangle; // Current wave rectangle annotation

	/// <summary>
	/// Finds the nearest peak or valley to a given candlestick within a specified margin.
	/// </summary>
	/// <param name="cs">Candlestick to search from.</param>
	/// <param name="margin">Margin to search on either side.</param>
	/// <returns>The nearest peak or valley candlestick, or nullptr if none found.</returns>
	aSmartCandlestick^ findNearestPeakOrValley(aSmartCandlestick^ cs, int margin) {
		if (cs == nullptr) return nullptr;
		if (filteredListOfCandlesticks->Count == 0) return nullptr;

		// Find the index of the reference candlestick
		int index = filteredListOfCandlesticks->IndexOf(cs);
		if (index == -1) return nullptr;

		// Search outward from the reference candlestick within the margin
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

	/// <summary>
	/// Finds a candlestick by its X-axis value (date).
	/// </summary>
	/// <param name="xValue">The X-axis value (date) of the candlestick.</param>
	/// <returns>The corresponding candlestick, or nullptr if not found.</returns>
	aSmartCandlestick^ findCandlestickByXValue(double xValue) {
		for each (aSmartCandlestick ^ cs in filteredListOfCandlesticks) {
			if (cs->Date->ToOADate() == xValue) {
				return cs;
			}
		}
		return nullptr;
	}

	/// <summary>
	/// Resets any selected wave selections and clears related annotations.
	/// </summary>
	private: System::Void resetWaveSelections() {
		// Remove highlight from start and end DataPoints
		if (selectedDataPointStart != nullptr) {
			highlightDataPoint(selectedDataPointStart, false); // Remove arrow
		}
		if (selectedDataPointEnd != nullptr) {
			highlightDataPoint(selectedDataPointEnd, false); // Remove arrow
		}

		// Remove the current rectangle annotation if it exists
		if (currentWaveRectangle != nullptr) {
			chart_stockData->Annotations->Remove(currentWaveRectangle);
			currentWaveRectangle = nullptr;
		}

		// Clear selected candlesticks and DataPoints
		selectedCandlestickStart = nullptr;
		selectedCandlestickEnd = nullptr;
		selectedDataPointStart = nullptr;
		selectedDataPointEnd = nullptr;

		// Clear beauty chart
		chart_stockData->Series["Series_Beauty"]->Points->Clear();
	}

		   /// <summary>
		   /// Highlights or unhighlights a specific DataPoint with an arrow and label.
		   /// </summary>
		   /// <param name="dp">The DataPoint to highlight or unhighlight.</param>
		   /// <param name="isSelected">True to highlight, false to remove highlight.</param>
	private: System::Void highlightDataPoint(DataVisualization::Charting::DataPoint^ dp, bool isSelected) {
		if (dp == nullptr) return;

		// Generate a unique annotation name based on the data point index
		int pointIndex = static_cast<int>(dp->XValue);
		String^ annotationName = "SelectionArrow_" + pointIndex.ToString();

		if (isSelected) {
			// Check if the annotation already exists to avoid duplicates
			bool exists = false;
			for each (DataVisualization::Charting::Annotation ^ ann in chart_stockData->Annotations) {
				if (ann->Name == annotationName) {
					exists = true;
					break;
				}
			}

			if (!exists) {
				// Create and configure the arrow annotation
				auto arrowAnnotation = gcnew DataVisualization::Charting::ArrowAnnotation();
				arrowAnnotation->Name = annotationName;
				arrowAnnotation->BackColor = System::Drawing::Color::Yellow;
				arrowAnnotation->LineColor = System::Drawing::Color::Black;
				arrowAnnotation->Width = 0; // No width for a vertical arrow
				arrowAnnotation->Height = -5; // Adjust the height as needed
				arrowAnnotation->AnchorDataPoint = dp;
				arrowAnnotation->Y = dp->YValues[0] + (dp->YValues[1] - dp->YValues[0]) * 0.05; // Position above the data point

				// Create and configure the label annotation
				auto labelAnnotation = gcnew DataVisualization::Charting::TextAnnotation();
				labelAnnotation->Name = "SelectionLabel_" + pointIndex.ToString();
				labelAnnotation->Text = "Selected";
				labelAnnotation->ForeColor = System::Drawing::Color::Black;
				labelAnnotation->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);
				labelAnnotation->AnchorDataPoint = dp;
				labelAnnotation->Y = arrowAnnotation->Y + 0.02; // Slightly above the arrow
				labelAnnotation->X = dp->XValue;
				labelAnnotation->Alignment = Drawing::ContentAlignment::MiddleCenter;

				// Add the annotations to the chart
				chart_stockData->Annotations->Add(arrowAnnotation);
				chart_stockData->Annotations->Add(labelAnnotation);
			}
		}
		else {
			// Remove the arrow and label annotations if they exist
			DataVisualization::Charting::Annotation^ annotationToRemove = nullptr;
			DataVisualization::Charting::Annotation^ labelToRemove = nullptr;

			for each (DataVisualization::Charting::Annotation ^ ann in chart_stockData->Annotations) {
				if (ann->Name == annotationName) {
					annotationToRemove = ann;
				}
				else if (ann->Name == "SelectionLabel_" + pointIndex.ToString()) {
					labelToRemove = ann;
				}
			}

			if (annotationToRemove != nullptr) {
				chart_stockData->Annotations->Remove(annotationToRemove);
			}

			if (labelToRemove != nullptr) {
				chart_stockData->Annotations->Remove(labelToRemove);
			}
		}
	}

		/// <summary>
		/// Retrieves the DataPoint closest to the given mouse X position.
		/// </summary>
		/// <param name="mouseX">The mouse's X pixel position.</param>
		/// <returns>The nearest DataPoint, or nullptr if none is within the threshold.</returns>
	private: DataVisualization::Charting::DataPoint^ GetDataPointByXPosition(int mouseX) {
		// Access the relevant ChartArea
		DataVisualization::Charting::ChartArea^ chartArea = chart_stockData->ChartAreas["ChartArea_OHLC"];

		// Convert the mouse's X pixel position to the axis X-value (which is the index)
		double xValue = chartArea->AxisX->PixelPositionToValue(static_cast<double>(mouseX));

		// Round to the nearest integer index
		int index = static_cast<int>(Math::Round(xValue));

		// Check if the index is within the valid range
		if (index > 0 && index <= chart_stockData->Series["Series_OHLC"]->Points->Count) {
			// Define a threshold to ensure the click is close enough to the DataPoint
			double distance = Math::Abs(xValue - index);
			double threshold = 0.5; // Adjust if necessary

			if (distance <= threshold) {
				return chart_stockData->Series["Series_OHLC"]->Points[index - 1];
			}
		}

		// Return nullptr if no DataPoint is within the threshold
		return nullptr;
	}

		   /// <summary>
		   /// Handles the MouseDown event on the chart for initiating wave selection.
		   /// </summary>
		   /// <param name="sender">Event sender.</param>
		   /// <param name="e">Mouse event arguments.</param>
	private: System::Void chart_stockData_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			// Remove existing Fibonacci and MaxBeauty annotations
			removeFibonacciAndMaxBeautyAnnotations();

			// Reset any previous selections
			resetWaveSelections();

			// Initialize dragging state
			isDragging = true;
			dragStartPoint = System::Drawing::Point(e->X, e->Y);
			selectionRectangle = System::Drawing::Rectangle(e->X, e->Y, 0, 0);

			// Get the closest DataPoint to the mouse position
			DataVisualization::Charting::DataPoint^ startPoint = GetDataPointByXPosition(e->X);
			if (startPoint != nullptr) {
				selectedCandlestickStart = findCandlestickByXValue(startPoint->XValue);
				selectedDataPointStart = startPoint;
				highlightDataPoint(selectedDataPointStart, true); // Highlight the start DataPoint
			}

			// Unhighlight any existing drag DataPoint
			if (currentDragDataPoint != nullptr) {
				highlightDataPoint(currentDragDataPoint, false); // Remove highlight
				currentDragDataPoint = nullptr;
			}
		}
	}

		   /// <summary>
		   /// Handles the MouseMove event on the chart for updating the selection rectangle and highlighting.
		   /// </summary>
		   /// <param name="sender">Event sender.</param>
		   /// <param name="e">Mouse event arguments.</param>
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

			// Get the closest DataPoint to the current mouse position
			DataVisualization::Charting::DataPoint^ currentPoint = GetDataPointByXPosition(e->X);

			if (currentPoint != currentDragDataPoint && currentPoint != nullptr) {
				// Unhighlight the previous DataPoint
				if (currentDragDataPoint != nullptr) {
					highlightDataPoint(currentDragDataPoint, false); // Remove highlight
				}

				// Highlight the new DataPoint
				highlightDataPoint(currentPoint, true); // Add highlight
				currentDragDataPoint = currentPoint;
			}
			else if (currentPoint == nullptr && currentDragDataPoint != nullptr) {
				// If not hovering over a DataPoint, remove any existing highlight
				highlightDataPoint(currentDragDataPoint, false); // Remove highlight
				currentDragDataPoint = nullptr;
			}
		}
	}

		   /// <summary>
		   /// Handles the MouseUp event on the chart to finalize wave selection and perform calculations.
		   /// </summary>
		   /// <param name="sender">Event sender.</param>
		   /// <param name="e">Mouse event arguments.</param>
	private: System::Void chart_stockData_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (isDragging) {
			// End dragging state
			isDragging = false;

			// Redraw the chart to remove the selection rectangle
			chart_stockData->Invalidate();

			// Remove any existing drag DataPoint highlight
			if (currentDragDataPoint != nullptr) {
				highlightDataPoint(currentDragDataPoint, false); // Remove highlight
				currentDragDataPoint = nullptr;
			}

			// Get the closest DataPoint to the mouse position
			DataVisualization::Charting::DataPoint^ endPoint = GetDataPointByXPosition(e->X);
			if (endPoint != nullptr) {
				selectedCandlestickEnd = findCandlestickByXValue(endPoint->XValue);
				selectedDataPointEnd = endPoint;
				highlightDataPoint(selectedDataPointEnd, true); // Highlight the end DataPoint

				// Perform actions with the selected candlesticks
				onTwoCandlesticksSelected(selectedCandlestickStart, selectedCandlestickEnd);
			}
		}
	}

		   /// <summary>
/// Handles the selection of two candlesticks and performs validation and calculations.
/// </summary>
/// <param name="csStart">Start candlestick.</param>
/// <param name="csEnd">End candlestick.</param>
private: System::Void onTwoCandlesticksSelected(aSmartCandlestick^ csStart, aSmartCandlestick^ csEnd) {
	if (csStart != nullptr && csEnd != nullptr) {
		// Find the nearest peak or valley to the start candlestick
		aSmartCandlestick^ snappedStart = findNearestPeakOrValley(csStart, SNAP_MARGIN);
		// Use the end candlestick as is (could also snap if needed)
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
			DataVisualization::Charting::DataPoint^ snappedStartPoint = findCandlestickDataPoint(snappedStart);
			DataVisualization::Charting::DataPoint^ snappedEndPoint = findCandlestickDataPoint(snappedEnd);

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

			// Validate the selected wave
			if (isValidWave(snappedStart, snappedEnd)) {
				// Perform calculations and annotations for a valid wave
				onValidSelection(snappedStart, snappedEnd);
			}
			else {
				// Draw a rectangle between the selected candlesticks
				drawRectangleBetweenCandlesticks(snappedStart, snappedEnd);

				// Show error message indicating invalid wave selection
				MessageBox::Show(
					"Invalid wave selected. Please ensure that the wave meets the required criteria.",
					"Invalid Wave Selection",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);

				// Reset wave selections to allow the user to make a new selection
				resetWaveSelections();
			}
		}
		else {
			// Notify the user that no nearby peak or valley was found
			MessageBox::Show(
				"No nearby peak or valley was found within the snapping margin. Please try selecting another wave.",
				"Selection Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
		}
	}
}


		   /// <summary>
		   /// Finds the DataPoint associated with a given candlestick.
		   /// </summary>
		   /// <param name="cs">The candlestick to find.</param>
		   /// <returns>The corresponding DataPoint, or nullptr if not found.</returns>
	private: DataVisualization::Charting::DataPoint^ findCandlestickDataPoint(aSmartCandlestick^ cs) {
		if (cs == nullptr) return nullptr;
		for each (DataVisualization::Charting::DataPoint ^ dp in chart_stockData->Series["Series_OHLC"]->Points) {
			if (dp->XValue == cs->Date->ToOADate()) {
				return dp;
			}
		}
		return nullptr;
	}

		   /// <summary>
		   /// Handles the Paint event of the chart to draw the selection rectangle.
		   /// </summary>
		   /// <param name="sender">Event sender.</param>
		   /// <param name="e">Paint event arguments.</param>
	private: System::Void chart_stockData_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		if (isDragging) {
			// Define the pen for drawing the rectangle (e.g., Blue dashed line)
			System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(System::Drawing::Color::Blue, 2);
			pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;

			// Draw the selection rectangle
			e->Graphics->DrawRectangle(pen, selectionRectangle);

			// Clean up the pen
			delete pen;
		}
	}

		   /// <summary>
		   /// Validates whether the selected candlesticks form a valid wave.
		   /// </summary>
		   /// <param name="candlestick1">First candlestick.</param>
		   /// <param name="candlestick2">Second candlestick.</param>
		   /// <returns>True if valid wave, false otherwise.</returns>
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
				   // Selected candlesticks are the same
				   // Removed MessageBox for logging purposes
				   return false;
			   }

			   // Get the first and second candlesticks in the selection
			   aSmartCandlestick^ firstCandlestick = filteredListOfCandlesticks[startIndex];
			   aSmartCandlestick^ secondCandlestick = filteredListOfCandlesticks[endIndex];

			   // Determine the maximum and minimum Y values within the wave
			   double maxY = Math::Max((double)firstCandlestick->High, (double)secondCandlestick->High);
			   double minY = Math::Min((double)firstCandlestick->Low, (double)secondCandlestick->Low);

			   // Special case
			   // If the max high and min low belong to the same candlestick, the wave is not valid
			   if (maxY == (double)firstCandlestick->High && minY == (double)firstCandlestick->Low) {
				   return false;
			   }
			   if (maxY == (double)secondCandlestick->High && minY == (double)secondCandlestick->Low) {
				   return false;
			   }

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

		   /// <summary>
		   /// Draws a rectangle annotation between two candlesticks on the chart.
		   /// </summary>
		   /// <param name="cs1">First candlestick.</param>
		   /// <param name="cs2">Second candlestick.</param>
		   /// <returns>The created RectangleAnnotation.</returns>
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
		rectangleAnnotation->X = firstCS->Index;
		rectangleAnnotation->Width = secondCS->Index - firstCS->Index;

		// Add the rectangle to the chart
		chart_stockData->Annotations->Add(rectangleAnnotation);

		// Assign the newly created rectangle to the member variable
		currentWaveRectangle = rectangleAnnotation;

		return rectangleAnnotation;
	}

		   /// <summary>
		   /// Handles the CheckedChanged event for the "Show Peaks And Valleys" checkbox.
		   /// </summary>
		   /// <param name="sender">Event sender.</param>
		   /// <param name="e">Event arguments.</param>
	private: System::Void checkBox_showPeaksAndValleys_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		showAnnotationsForSelectedPattern(nullptr, nullptr);
	}

		   /// <summary>
		   /// Draws Fibonacci level annotations between two candlesticks on the chart.
		   /// </summary>
		   /// <param name="cs1">First candlestick.</param>
		   /// <param name="cs2">Second candlestick.</param>
		   /// <returns>void</returns>
	private: System::Void drawFibonacciLevels(aSmartCandlestick^ cs1, aSmartCandlestick^ cs2) {
		// Validate input
		if (cs1 == nullptr || cs2 == nullptr) {
			// Removed MessageBox for logging purposes
			return;
		}

		// Determine which candlestick has the higher high and which has the lower low
		double high = Math::Max((double)cs1->High, (double)cs2->High);
		double low = Math::Min((double)cs1->Low, (double)cs2->Low);

		// Define Fibonacci levels percentages
		array<double>^ fibonacciPercentages = gcnew array<double> { 100.0, 76.4, 62.8, 50.0, 38.2, 23.6, 0.0 };

		// Define colors for each level for better distinction
		array<System::Drawing::Color>^ levelColors = gcnew array<System::Drawing::Color> {
			System::Drawing::Color::Blue,        // 100%
				System::Drawing::Color::Blue,        // 76.4%
				System::Drawing::Color::Blue,        // 62.8%
				System::Drawing::Color::Blue,        // 50.0%
				System::Drawing::Color::Blue,        // 38.2%
				System::Drawing::Color::Blue,        // 23.6%
				System::Drawing::Color::Blue         // 0.0%
		};

		// Remove existing Fibonacci annotations to prevent duplication
		removeFibonacciAndMaxBeautyAnnotations();

		// Determine the x-axis range based on the selected wave
		int startIndex = Math::Min(cs1->Index, cs2->Index);
		int endIndex = Math::Max(cs1->Index, cs2->Index);

		// Calculate the y-values for each Fibonacci level
		array<double>^ fibonacciLevels = gcnew array<double>(fibonacciPercentages->Length);
		for (int i = 0; i < fibonacciPercentages->Length; i++) {
			fibonacciLevels[i] = low + (high - low) * (fibonacciPercentages[i] / 100.0);
		}

		// Draw each Fibonacci level
		for (int i = 0; i < fibonacciLevels->Length; i++) {
			double levelValue = fibonacciLevels[i];
			double percentage = fibonacciPercentages[i];
			System::String^ levelName = "FibLevel_" + percentage.ToString() + "%";
			System::String^ labelName = "FibLabel_" + percentage.ToString() + "%";

			// Create HorizontalLineAnnotation for the Fibonacci level
			DataVisualization::Charting::HorizontalLineAnnotation^ fibLine = gcnew DataVisualization::Charting::HorizontalLineAnnotation();
			fibLine->Name = "FibLevel_" + percentage.ToString() + "%";
			fibLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
			fibLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
			fibLine->Y = levelValue;
			fibLine->LineColor = levelColors[i];
			fibLine->LineDashStyle = DataVisualization::Charting::ChartDashStyle::Dash;
			fibLine->LineWidth = 2;
			fibLine->ClipToChartArea = "ChartArea_OHLC";
			fibLine->IsInfinitive = false;
			fibLine->IsSizeAlwaysRelative = false;
			fibLine->X = startIndex; // Slight offset for better visibility
			fibLine->Width = endIndex - startIndex; // Span the wave

			// Add the Fibonacci line to the chart
			chart_stockData->Annotations->Add(fibLine);
		}
	}

		   /// <summary>
		   /// Removes existing Fibonacci and Max Beauty annotations from the chart.
		   /// </summary>
	private: void removeFibonacciAndMaxBeautyAnnotations() {
		// Create a list to hold annotations to remove
		System::Collections::Generic::List<DataVisualization::Charting::Annotation^>^ annotationsToRemove =
			gcnew System::Collections::Generic::List<DataVisualization::Charting::Annotation^>();

		// Identify annotations related to Fibonacci levels and Max Beauty lines
		for each (DataVisualization::Charting::Annotation ^ ann in chart_stockData->Annotations) {
			if (ann->Name->StartsWith("FibLevel_") ||
				ann->Name->StartsWith("FibLabel_") ||
				ann->Name->StartsWith("MaxBeautyLine") ||
				ann->Name->StartsWith("MaxBeautyLabel") ||
				ann->Name->StartsWith("Circle_")) // Remove circle annotations as well
			{
				annotationsToRemove->Add(ann);
			}
		}

		// Remove the identified annotations from the chart
		for each (DataVisualization::Charting::Annotation ^ ann in annotationsToRemove) {
			chart_stockData->Annotations->Remove(ann);
		}
	}

		   /// <summary>
		   /// Adds a circle annotation to the chart at the specified X and Y coordinates.
		   /// </summary>
		   /// <param name="name">Unique name for the annotation.</param>
		   /// <param name="xValue">The X-axis value (date) where the annotation will be placed.</param>
		   /// <param name="yValue">The Y-axis value (price) where the annotation will be placed.</param>
		   /// <param name="color">Color of the circle.</param>
	private: void addCircleAnnotation(String^ name, double xValue, double yValue, System::Drawing::Color color) {
		// Create a RectangleAnnotation to represent the circle (since EllipseAnnotation is not available)
		auto circle = gcnew DataVisualization::Charting::EllipseAnnotation();
		circle->Name = name;
		circle->X = xValue - 0.05; // Slight offset for centering
		circle->Y = yValue * 0.997; // Adjust Y position for better alignment
		circle->Width = 0.1; // Adjust size as needed
		circle->Height = 1; // Adjust size as needed
		circle->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
		circle->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
		circle->LineColor = System::Drawing::Color::Black;
		circle->LineWidth = 1;
		circle->BackColor = color;
		circle->ClipToChartArea = "ChartArea_OHLC";
		circle->IsSizeAlwaysRelative = false;
		circle->Alignment = Drawing::ContentAlignment::BottomCenter;

		// Add the circle annotation to the chart
		chart_stockData->Annotations->Add(circle);
	}

		   /// <summary>
		   /// Calculates the beauty score for a single candlestick based on Fibonacci levels and allowance.
		   /// </summary>
		   /// <param name="firstCs">First candlestick in the wave.</param>
		   /// <param name="secondCs">Second candlestick in the wave.</param>
		   /// <param name="targetCandlestick">The candlestick to evaluate.</param>
		   /// <param name="theoreticalPrice">The theoretical price level.</param>
		   /// <param name="detailedInfo">StringBuilder for logging detailed information.</param>
		   /// <returns>The beauty score for the candlestick.</returns>
	private: double CalculateBeautyForACandlestick(
		aSmartCandlestick^ firstCs,
		aSmartCandlestick^ secondCs,
		aSmartCandlestick^ targetCandlestick,
		double theoreticalPrice,
		System::Text::StringBuilder^ detailedInfo)
	{
		double beautyScore = 0.0;

		// Determine wave direction based on chronological order
		bool isRising = secondCs->High > firstCs->High;

		// Identify the first candlestick level based on wave direction
		double firstCandlestickLevel = isRising ? static_cast<double>(firstCs->Low) : static_cast<double>(firstCs->High);

		// Calculate wave range
		double waveRange = isRising ? (theoreticalPrice - firstCandlestickLevel)
			: (firstCandlestickLevel - theoreticalPrice);

		// Define allowance as 1.5% of the wave range
		double allowance = waveRange * 0.015;

		// Define Fibonacci percentages
		cli::array<double>^ fibonacciPercentages = gcnew cli::array<double> { 0.0, 23.6, 38.2, 50.0, 61.8, 76.4, 100.0 };

		// Calculate Fibonacci levels based on wave direction
		cli::array<double>^ fibonacciLevels = gcnew cli::array<double>(fibonacciPercentages->Length);
		for (int i = 0; i < fibonacciPercentages->Length; i++) {
			if (isRising) {
				// For rising waves: 0% at firstCandlestickLow, 100% at theoreticalPrice
				fibonacciLevels[i] = firstCandlestickLevel + (theoreticalPrice - firstCandlestickLevel) * (fibonacciPercentages[i] / 100.0);
			}
			else {
				// For falling waves: 100% at firstCandlestickHigh, 0% at theoreticalPrice
				fibonacciLevels[i] = firstCandlestickLevel - (firstCandlestickLevel - theoreticalPrice) * (fibonacciPercentages[i] / 100.0);
			}
		}

		// Array of candlestick attributes
		cli::array<double>^ attributes = gcnew cli::array<double>{
			static_cast<double>(targetCandlestick->Open),
				static_cast<double>(targetCandlestick->High),
				static_cast<double>(targetCandlestick->Low),
				static_cast<double>(targetCandlestick->Close)
		};

		// Check each attribute against all Fibonacci levels
		for each (double attr in attributes) {
			for (int i = 0; i < fibonacciLevels->Length; i++) {
				double levelValue = fibonacciLevels[i];
				double difference = Math::Abs(attr - levelValue);
				if (difference <= allowance) {
					beautyScore += 1.0;

					// Log detailed information
					detailedInfo->AppendFormat("    Candlestick Date: {0}, Attribute: {1:F2}, Fibonacci Level: {2:F2}, Difference: {3:F2}\n",
						targetCandlestick->Date->ToShortDateString(),
						attr,
						levelValue,
						difference);

					// Once matched with a Fibonacci level, no need to check other levels for this attribute
					break;
				}
			}
		}

		return beautyScore;
	}

		   /// <summary>
		   /// Calculates the theoretical beauty scores by varying the wave height and displays them in a chart.
		   /// </summary>
		   /// <param name="cs1">First selected candlestick.</param>
		   /// <param name="cs2">Second selected candlestick.</param>
		   /// <param name="maxPercentage">Maximum percentage to increment/decrement the wave height.</param>
		   /// <param name="incrementStep">Step size for each increment/decrement.</param>
	private: System::Void calculateTheoreticalBeauties(
		aSmartCandlestick^ cs1,
		aSmartCandlestick^ cs2,
		double maxPercentage,
		double incrementStep)
	{
		System::Text::StringBuilder^ detailedInfo = gcnew System::Text::StringBuilder("Theoretical Beauty Scores:\n\n");

		// Validate input
		if (cs1 == nullptr || cs2 == nullptr) {
			// Removed MessageBox for logging purposes
			return;
		}

		// Find indices of cs1 and cs2 in filteredListOfCandlesticks
		int index1 = filteredListOfCandlesticks->IndexOf(cs1);
		int index2 = filteredListOfCandlesticks->IndexOf(cs2);

		// Validate that both candlesticks are in the list
		if (index1 == -1 || index2 == -1) {
			// Removed MessageBox for logging purposes
			return;
		}

		// Determine the start and end indices
		int startIndex = Math::Min(index1, index2);
		int endIndex = Math::Max(index1, index2);

		// Extract the subset of candlesticks between cs1 and cs2 (inclusive)
		Generic::List<aSmartCandlestick^>^ subsetCandlesticks = gcnew Generic::List<aSmartCandlestick^>();
		for (int i = startIndex; i <= endIndex; i++) {
			subsetCandlesticks->Add(filteredListOfCandlesticks[i]);
		}

		// Assign firstCs and secondCs based on chronological order
		aSmartCandlestick^ firstCs = subsetCandlesticks[0];
		aSmartCandlestick^ secondCs = subsetCandlesticks[subsetCandlesticks->Count - 1];

		// Determine if the wave is rising or falling based on the first and last candlesticks in the subset
		bool isRising = secondCs->High > firstCs->High;

		// Determine the reference level based on wave direction
		double firstCandlestickLevel = isRising ? static_cast<double>(firstCs->Low) : static_cast<double>(firstCs->High);

		// Determine the theoretical price based on wave direction
		double theoreticalPrice = isRising ? static_cast<double>(secondCs->High) : static_cast<double>(secondCs->Low);

		// Calculate the wave range
		double waveRange = isRising ? (theoreticalPrice - firstCandlestickLevel)
			: (firstCandlestickLevel - theoreticalPrice);
		detailedInfo->AppendFormat("Wave Direction: {0}\n", isRising ? "Rising" : "Falling");
		detailedInfo->AppendFormat("firstCandlestickLevel: {0:F2}\n", firstCandlestickLevel);
		detailedInfo->AppendFormat("Theoretical Price: {0:F2}\n", theoreticalPrice);
		detailedInfo->AppendFormat("Wave Range: {0:F2}\n\n", waveRange);

		if (waveRange == 0) {
			// Removed MessageBox for logging purposes
			return;
		}

		// Calculate allowance based on waveRange
		double allowance = waveRange * 0.015;
		detailedInfo->AppendFormat("Allowance: {0:F4}\n\n", allowance); // Increased precision for logging

		// Define increments for both directions (-maxPercentage to +maxPercentage)
		int totalIncrements = static_cast<int>(maxPercentage / incrementStep) * 2 + 1; // Including zero
		array<double>^ incrementPercentages = gcnew array<double>(totalIncrements);
		array<double>^ adjustedLevels = gcnew array<double>(totalIncrements);
		array<double>^ beautyScores = gcnew array<double>(totalIncrements);

		// Populate the incrementPercentages and adjustedLevels arrays
		int idx = 0;
		for (int i = -static_cast<int>(maxPercentage); i <= static_cast<int>(maxPercentage); i += static_cast<int>(incrementStep)) {
			double deltaPercentage = static_cast<double>(i);
			incrementPercentages[idx] = deltaPercentage;
			if (deltaPercentage < 0) {
				// For negative percentages, adjust theoreticalPrice downwards
				adjustedLevels[idx] = theoreticalPrice - (waveRange * (Math::Abs(deltaPercentage) / 100.0));
			}
			else {
				// For positive percentages, adjust theoreticalPrice upwards
				adjustedLevels[idx] = theoreticalPrice + (waveRange * (deltaPercentage / 100.0));
			}
			idx++;
		}

		// Initialize beautyScores array
		for (int i = 0; i < beautyScores->Length; i++) {
			beautyScores[i] = 0.0;
		}

		// Initialize a list to store detailed info for both directions
		System::Text::StringBuilder^ allDetailedInfo = gcnew System::Text::StringBuilder("Theoretical Beauty Scores:\n\n");

		// Iterate through each increment to calculate beauty scores
		for (int i = 0; i < incrementPercentages->Length; i++) {
			double currentDeltaPercentage = incrementPercentages[i];
			double currentTheoreticalPrice = adjustedLevels[i];
			beautyScores[i] = 0.0;

			// Log the current theoretical price and direction
			String^ direction = (currentDeltaPercentage < 0) ? "Downwards" :
				(currentDeltaPercentage > 0) ? "Upwards" : "No Change";
			allDetailedInfo->AppendFormat("Increment {0}% ({1}) - Theoretical Price: {2:F2}\n",
				currentDeltaPercentage, direction, currentTheoreticalPrice);

			// Calculate beauty score for each candlestick in the subset
			for each (aSmartCandlestick ^ candlestick in subsetCandlesticks) {
				double beauty = CalculateBeautyForACandlestick(
					firstCs,
					secondCs,
					candlestick,
					currentTheoreticalPrice,
					detailedInfo // Logging detailed information
				);
				beautyScores[i] += beauty;
			}

			allDetailedInfo->AppendFormat("Total Beauty Score at {0:F2}: {1}\n\n",
				currentTheoreticalPrice, beautyScores[i]);

			// **Add Circle Annotations at Increment 0%**
			if (currentDeltaPercentage == 0) {
				// Define Fibonacci levels based on the wave direction
				array<double>^ fibonacciPercentages = gcnew array<double> { 0.0, 23.6, 38.2, 50.0, 61.8, 76.4, 100.0 };
				array<double>^ fibonacciLevels = gcnew array<double>(fibonacciPercentages->Length);
				for (int j = 0; j < fibonacciPercentages->Length; j++) {
					fibonacciLevels[j] = firstCandlestickLevel + (theoreticalPrice - firstCandlestickLevel) * (fibonacciPercentages[j] / 100.0);
				}

				// Iterate through each candlestick to check for matches
				for (int k = 0; k < subsetCandlesticks->Count; k++) {
					aSmartCandlestick^ candlestick = subsetCandlesticks[k];
					// Check each attribute: Open, High, Low, Close
					array<double>^ attributes = gcnew array<double> {
						static_cast<double>(candlestick->Open),
							static_cast<double>(candlestick->High),
							static_cast<double>(candlestick->Low),
							static_cast<double>(candlestick->Close)
					};
					array<String^>^ attributeNames = gcnew array<String^> { "Open", "High", "Low", "Close" };

					for (int attrIdx = 0; attrIdx < attributes->Length; attrIdx++) {
						double attrValue = attributes[attrIdx];
						String^ attrName = attributeNames[attrIdx];

						for (int fibIdx = 0; fibIdx < fibonacciLevels->Length; fibIdx++) {
							double fibLevel = fibonacciLevels[fibIdx];
							// Matching condition using allowance
							if (Math::Abs(attrValue - fibLevel) <= allowance) {
								// Create a unique name for the circle annotation
								String^ circleName = "Circle_" + attrName + "_" + k.ToString() + "_" + fibIdx.ToString();
								// Add the circle annotation
								addCircleAnnotation(circleName, candlestick->Index, attrValue, System::Drawing::Color::Magenta);
								// Log this event
								allDetailedInfo->AppendFormat("    {0}:{1} of Candlestick {2} matches Fibonacci Level {3}% ({4:F2})\n",
									attrName,
									attrValue,
									k,
									fibonacciPercentages[fibIdx],
									fibLevel);
							}
						}
					}
				}
			}
		}

		// Plot the beauty scores on the existing Series_Beauty
		// First, clear existing points
		chart_stockData->Series["Series_Beauty"]->Points->Clear();

		for (int i = 0; i < beautyScores->Length; i++) {
			double deltaPercentage = incrementPercentages[i];
			double beauty = beautyScores[i];
			double price = adjustedLevels[i];

			// Create a new data point
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ dp = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();

			// Set X value as the adjusted price
			dp->SetValueXY(price, beauty);

			// Assign different colors based on direction
			if (deltaPercentage > 0) {
				// Upwards increments - Green
				dp->Color = System::Drawing::Color::Green;
			}
			else if (deltaPercentage < 0) {
				// Downwards increments - Red
				dp->Color = System::Drawing::Color::Red;
			}
			else {
				// No change - Blue
				dp->Color = System::Drawing::Color::Blue;
			}

			// Optionally, set a tooltip or label for better UX
			dp->ToolTip = String::Format("Price: {0:F2}\nBeauty Score: {1}", price, beauty);

			// Add the data point to the series
			chart_stockData->Series["Series_Beauty"]->Points->Add(dp);
		}

		// Customize the beauty scores chart
		chart_stockData->ChartAreas["ChartArea_Beauty"]->Visible = true;
		double maximumBeautyScore = (secondCs->Index - firstCs->Index + 1) * 4;
		chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisX->Title = "Price";
		chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisX->LabelStyle->Format = "F0";
		chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisY->Title = "Beauty Score (Maximum: " + maximumBeautyScore.ToString() + ")";
		chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisY->Minimum = 0; // Adjust based on your data
		chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisY->Interval = incrementStep; // Optional

		// Find the maximum beauty score and its corresponding price level
		double maxBeauty = 0.0;
		int maxIndex = 0;
		for (int i = 0; i < beautyScores->Length; i++) {
			if (beautyScores[i] > maxBeauty) {
				maxBeauty = beautyScores[i];
				maxIndex = i;
			}
		}
		double maxBeautyLevel = adjustedLevels[maxIndex];

		// Remove any existing annotations related to the maximum beauty line
		System::Collections::Generic::List<DataVisualization::Charting::Annotation^>^ existingMaxBeautyAnnotations =
			gcnew System::Collections::Generic::List<DataVisualization::Charting::Annotation^>();

		for each (DataVisualization::Charting::Annotation ^ annotation in chart_stockData->Annotations) {
			if (annotation->Name->StartsWith("MaxBeautyLine") || annotation->Name->StartsWith("MaxBeautyLabel")) {
				existingMaxBeautyAnnotations->Add(annotation);
			}
		}

		for each (DataVisualization::Charting::Annotation ^ annotation in existingMaxBeautyAnnotations) {
			chart_stockData->Annotations->Remove(annotation);
		}

		// Create and configure the HorizontalLineAnnotation for Max Beauty Level
		auto maxBeautyLine = gcnew DataVisualization::Charting::HorizontalLineAnnotation();
		maxBeautyLine->Name = "MaxBeautyLine";
		maxBeautyLine->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
		maxBeautyLine->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
		maxBeautyLine->Y = maxBeautyLevel; // Set Y to the price level with max beauty
		maxBeautyLine->LineColor = System::Drawing::Color::Purple; // Distinct color
		maxBeautyLine->LineWidth = 2;
		maxBeautyLine->LineDashStyle = DataVisualization::Charting::ChartDashStyle::Dash;
		maxBeautyLine->IsInfinitive = true; // Extend across the entire X-axis
		maxBeautyLine->ToolTip = "Max Beauty Level: " + maxBeautyLevel.ToString("F2");
		maxBeautyLine->ClipToChartArea = "ChartArea_OHLC";

		// Optionally, add a label to the line
		auto maxBeautyLabel = gcnew DataVisualization::Charting::TextAnnotation();
		maxBeautyLabel->Name = "MaxBeautyLabel";
		maxBeautyLabel->Text = "Max Beauty Level: " + maxBeautyLevel.ToString("F2");
		maxBeautyLabel->ForeColor = System::Drawing::Color::Black;
		maxBeautyLabel->Font = gcnew System::Drawing::Font("Arial", 8, System::Drawing::FontStyle::Bold);
		maxBeautyLabel->AxisX = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisX;
		maxBeautyLabel->AxisY = chart_stockData->ChartAreas["ChartArea_OHLC"]->AxisY;
		maxBeautyLabel->Y = maxBeautyLevel;
		maxBeautyLabel->X = chart_stockData->ChartAreas["ChartArea_Beauty"]->AxisX->Maximum; // Position at the end of the X-axis
		maxBeautyLabel->Alignment = Drawing::ContentAlignment::MiddleRight;

		// Add the annotations to the chart
		chart_stockData->Annotations->Add(maxBeautyLine);
		chart_stockData->Annotations->Add(maxBeautyLabel);

		// Refresh the chart to display the new data
		chart_stockData->Invalidate();

		// MessageBox::Show(detailedInfo->ToString(), "Analysis Complete");
	}

		   /// <summary>
		   /// Handles the validation and processing of a valid wave selection.
		   /// </summary>
		   /// <param name="cs1">First candlestick of the wave.</param>
		   /// <param name="cs2">Second candlestick of the wave.</param>
	private: System::Void onValidSelection(aSmartCandlestick^ cs1, aSmartCandlestick^ cs2) {
		// Draw a rectangle between the snapped candlesticks
		drawRectangleBetweenCandlesticks(cs1, cs2);

		// Draw Fibonacci levels between the snapped candlesticks
		drawFibonacciLevels(cs1, cs2);

		// Calculate and display the beauty scores from -23.6% to +23.6% of wave end
		calculateTheoreticalBeauties(cs1, cs2, 23.6, 1);
	}

};
}