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
	private: System::Windows::Forms::ComboBox^ comboBox_patternSelection;
	private: System::Windows::Forms::Label^ label_selectPattern;


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
		// Add patterns to combobox
		this->comboBox_patternSelection->Items->AddRange(patternArray);
		// Set default pattern selection to All
		this->comboBox_patternSelection->SelectedIndex = 0;

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
			this->comboBox_patternSelection = (gcnew System::Windows::Forms::ComboBox());
			this->label_selectPattern = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->BeginInit();
			this->SuspendLayout();
			// 
			// button_load
			// 
			this->button_load->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button_load->Location = System::Drawing::Point(1424, 421);
			this->button_load->Margin = System::Windows::Forms::Padding(4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(162, 69);
			this->button_load->TabIndex = 1;
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
			this->dateTimePicker_start->Location = System::Drawing::Point(1424, 262);
			this->dateTimePicker_start->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(329, 29);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->dateTimePicker_end->Location = System::Drawing::Point(1424, 378);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(4);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(329, 29);
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
			this->chart_stockData->Location = System::Drawing::Point(13, 13);
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
			this->chart_stockData->Size = System::Drawing::Size(1374, 896);
			this->chart_stockData->TabIndex = 4;
			this->chart_stockData->Text = L"Stock Data";
			// 
			// label_startDate
			// 
			this->label_startDate->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(1419, 233);
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
			this->label_endDate->Location = System::Drawing::Point(1419, 349);
			this->label_endDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(93, 25);
			this->label_endDate->TabIndex = 8;
			this->label_endDate->Text = L"End Date";
			// 
			// button_update
			// 
			this->button_update->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button_update->Location = System::Drawing::Point(1594, 420);
			this->button_update->Margin = System::Windows::Forms::Padding(4);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(159, 70);
			this->button_update->TabIndex = 9;
			this->button_update->Text = L"Update";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &Form_Input::button_update_Click);
			// 
			// comboBox_patternSelection
			// 
			this->comboBox_patternSelection->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->comboBox_patternSelection->FormattingEnabled = true;
			this->comboBox_patternSelection->Location = System::Drawing::Point(1424, 642);
			this->comboBox_patternSelection->Name = L"comboBox_patternSelection";
			this->comboBox_patternSelection->Size = System::Drawing::Size(329, 32);
			this->comboBox_patternSelection->TabIndex = 10;
			this->comboBox_patternSelection->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_Input::comboBox_patternSelection_SelectedIndexChanged);
			// 
			// label_selectPattern
			// 
			this->label_selectPattern->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_selectPattern->AutoSize = true;
			this->label_selectPattern->Location = System::Drawing::Point(1419, 614);
			this->label_selectPattern->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_selectPattern->Name = L"label_selectPattern";
			this->label_selectPattern->Size = System::Drawing::Size(134, 25);
			this->label_selectPattern->TabIndex = 11;
			this->label_selectPattern->Text = L"Select Pattern";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1772, 919);
			this->Controls->Add(this->label_selectPattern);
			this->Controls->Add(this->comboBox_patternSelection);
			this->Controls->Add(this->button_update);
			this->Controls->Add(this->label_endDate);
			this->Controls->Add(this->label_startDate);
			this->Controls->Add(this->chart_stockData);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_load);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
		showAnnotationsForSelectedPattern();
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
		showAnnotationsForSelectedPattern();
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


private: System::Void comboBox_patternSelection_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Show annotations for selected pattern
	showAnnotationsForSelectedPattern();
}

/// <summary>
/// Display annotations for pattern selected using comboBox
/// </summary>
/// <returns>void</returns>
private: System::Void showAnnotationsForSelectedPattern() {
	// Get selected pattern
	String^ selectedPattern = comboBox_patternSelection->SelectedItem->ToString();
	// Clear prior annotations
	chart_stockData->Annotations->Clear();

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
			arrowAnnotation->BackColor = System::Drawing::Color::Purple;
			arrowAnnotation->LineColor = System::Drawing::Color::Purple;
			// Set annotation width
			arrowAnnotation->Width = 0;
			// Set annotation height
			arrowAnnotation->Height = -5;
			// Anchor annotation to corresponding data point
			arrowAnnotation->AnchorDataPoint = chart_stockData->Series["Series_OHLC"]->Points[i];

			// Add annotation to chart candlestick series
			chart_stockData->Annotations->Add(arrowAnnotation);
		}
	}
	// Regenerate annotations for peaks and valleys
	outlinePeaksAndValleys();
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
			peakAnnotation->Width = 0;
			peakAnnotation->Height = -5;
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
			valleyAnnotation->Width = 0;
			valleyAnnotation->Height = 5;
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