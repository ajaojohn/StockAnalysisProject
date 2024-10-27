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
	private: Generic::List<aCandlestick^>^ listOfCandlesticks;


	private: System::Windows::Forms::Label^ label_startDate;
	private: System::Windows::Forms::Label^ label_endDate;
	private: System::Windows::Forms::Button^ button_update;

		   // List of candlesticks to display
	private: BindingList<aCandlestick^>^ filteredListOfCandlesticks;

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
			// Intialize filtered list as empty
			this->filteredListOfCandlesticks = gcnew BindingList<aCandlestick^>();

			// Bind data grid to binding list
			dataGridView_stockData->DataSource = filteredListOfCandlesticks;
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
			this->dataGridView_stockData = (gcnew System::Windows::Forms::DataGridView());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_load = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_stockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label_startDate = (gcnew System::Windows::Forms::Label());
			this->label_endDate = (gcnew System::Windows::Forms::Label());
			this->button_update = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_stockData
			// 
			this->dataGridView_stockData->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->dataGridView_stockData->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView_stockData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_stockData->Location = System::Drawing::Point(15, 18);
			this->dataGridView_stockData->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dataGridView_stockData->Name = L"dataGridView_stockData";
			this->dataGridView_stockData->RowHeadersVisible = false;
			this->dataGridView_stockData->RowHeadersWidth = 51;
			this->dataGridView_stockData->RowTemplate->Height = 24;
			this->dataGridView_stockData->Size = System::Drawing::Size(920, 750);
			this->dataGridView_stockData->TabIndex = 0;
			// 
			// button_load
			// 
			this->button_load->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_load->Location = System::Drawing::Point(829, 812);
			this->button_load->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(167, 74);
			this->button_load->TabIndex = 1;
			this->button_load->Text = L"Load File";
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
			this->dateTimePicker_start->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->dateTimePicker_start->Location = System::Drawing::Point(449, 846);
			this->dateTimePicker_start->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(349, 29);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->dateTimePicker_end->Location = System::Drawing::Point(1188, 846);
			this->dateTimePicker_end->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(349, 29);
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
			this->chart_stockData->Location = System::Drawing::Point(942, 17);
			this->chart_stockData->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
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
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart_stockData->Series->Add(series1);
			this->chart_stockData->Series->Add(series2);
			this->chart_stockData->Size = System::Drawing::Size(970, 750);
			this->chart_stockData->TabIndex = 4;
			this->chart_stockData->Text = L"Stock Data";
			// 
			// label_startDate
			// 
			this->label_startDate->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label_startDate->AutoSize = true;
			this->label_startDate->Location = System::Drawing::Point(566, 807);
			this->label_startDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_startDate->Name = L"label_startDate";
			this->label_startDate->Size = System::Drawing::Size(99, 25);
			this->label_startDate->TabIndex = 7;
			this->label_startDate->Text = L"Start Date";
			// 
			// label_endDate
			// 
			this->label_endDate->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label_endDate->AutoSize = true;
			this->label_endDate->Location = System::Drawing::Point(1305, 807);
			this->label_endDate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_endDate->Name = L"label_endDate";
			this->label_endDate->Size = System::Drawing::Size(93, 25);
			this->label_endDate->TabIndex = 8;
			this->label_endDate->Text = L"End Date";
			// 
			// button_update
			// 
			this->button_update->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_update->Location = System::Drawing::Point(1003, 812);
			this->button_update->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->button_update->Name = L"button_update";
			this->button_update->Size = System::Drawing::Size(167, 74);
			this->button_update->TabIndex = 9;
			this->button_update->Text = L"Update";
			this->button_update->UseVisualStyleBackColor = true;
			this->button_update->Click += gcnew System::EventHandler(this, &Form_Input::button_update_Click);
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1927, 919);
			this->Controls->Add(this->button_update);
			this->Controls->Add(this->label_endDate);
			this->Controls->Add(this->label_startDate);
			this->Controls->Add(this->chart_stockData);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->dataGridView_stockData);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button_load_Click(System::Object^ sender, System::EventArgs^ e) {
		// On button click, trigger the open file dialog
		System::Windows::Forms::DialogResult result = this->openFileDialog_load->ShowDialog();

		// If the user selected a file
		if (result == System::Windows::Forms::DialogResult::OK) {
			// Get file selected
			this->selectedFilename = this->openFileDialog_load->FileName;
			// Load candlesticks from the selected file
			readCandlesticksFromFile();
			// Filter candlesticks
			filterCandlesticks();
			// Fill chart with filtered candlestick data
			displayChart();
			// Normalize the chart
			normalizeCandlestickChart();
		}
	}

	/**
	* Read candlesticks from file
	* @param filename The name of the file to read
	* @return A list of candlesticks read from the file
	*/
	private: Generic::List<aCandlestick^>^ readCandlesticksFromFile(System::String^ filename) {
		aCandlestickLoader^ loader = gcnew aCandlestickLoader();
		return loader->load(filename);
	}
	/**
	* Read candlesticks from file
	*/
	private: System::Void readCandlesticksFromFile() {
		this->listOfCandlesticks = this->readCandlesticksFromFile(this->selectedFilename);
	}


	/**
	* Get filtered list of candlesticks in a time frame
	* @param startDate The start date of the time frame
	* @param endDate The end date of the time frame
	* @return A list of candlesticks in the time frame
	*/
	private: Generic::List<aCandlestick^>^ filterCandlesticks(System::DateTime^ startDate, System::DateTime^ endDate, Generic::List<aCandlestick^>^  listOfCandlesticks) {
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
	* Set filteredListOfCandlesticks to candlesticks in the time frame selected using the date time pickers
	*/
	private: System::Void filterCandlesticks() {
		// Get candlesticks in time frame
		Generic::List<aCandlestick^>^ filteredCandlesticks = this->filterCandlesticks(
			this->dateTimePicker_start->Value, this->dateTimePicker_end->Value, this->listOfCandlesticks
		);
		// Clear binding list
		this->filteredListOfCandlesticks->Clear();
		// Add filtered candlesticks to binding list
		for (int i = 0; i < filteredCandlesticks->Count; i++) {
			this->filteredListOfCandlesticks->Add(filteredCandlesticks[i]);
		}
	}


	/**
	* Populate a chart series with candlestick data
	* @param chart The chart to populate
	* @param seriesName The name of the Candlestick series to populate
	* @param listOfCandlesticks The list of candlesticks to display
	*/
	private: System::Void displayChart(
		DataVisualization::Charting::Chart^ chart,
		System::String^ candlestickSeriesName,
		System::String^ volumeSeriesName,
		System::Collections::Generic::IList<aCandlestick^>^ listOfCandlesticks) 
	{
		// Clear prior candlestick series data
		chart->Series[candlestickSeriesName]->Points->Clear();
		// Clear prior volume series data
		chart->Series[volumeSeriesName]->Points->Clear();

		// Add each candlestick to the chart
		for (int i = listOfCandlesticks->Count - 1; i >= 0; i--)
		{
			// Get candlestick
			aCandlestick ^ candlestick = listOfCandlesticks[i];
			// Create a new data point
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ csPoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();
			// Set point's y-value
			csPoint->XValue = candlestick->date->ToOADate();
			// Set point's x value
			csPoint->YValues = gcnew cli::array<double>{
				static_cast<double>(candlestick->high),
				static_cast<double>(candlestick->low),
				static_cast<double>(candlestick->open),
				static_cast<double>(candlestick->close)
			};

			// Check if point is bullish or bearish
			if (candlestick->close > candlestick->open) {
				// If point is bullish, set color to green
				csPoint->Color = System::Drawing::Color::Green;
			}
			else {
				// If point is bearish, set color to red
				csPoint->Color = System::Drawing::Color::Red;
			}
			csPoint->BorderWidth = 1.5;

			// Create data point for volume
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ volumePoint = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();
			// Set point's y-value
			volumePoint->XValue = candlestick->date->ToOADate();
			// Set point's x value
			volumePoint->YValues = gcnew cli::array<double>{
				static_cast<double>(candlestick->volume)
			};


			// Add volume point to the series
			chart->Series[volumeSeriesName]->Points->Add(volumePoint);
			// Add the candlestick point to chart
			chart->Series[candlestickSeriesName]->Points->Add(csPoint);
		}
	}
	/**
	* Populate chart_stockData with data
	* @param listOfCandlesticks The list of candlesticks to display
	*/
	private: System::Void displayChart() {
		// Populate chart with candlestick data
		this->displayChart(chart_stockData, "Series_OHLC", "Series_Volume", filteredListOfCandlesticks);
	}
	

	/**
	* Normalize a chart series according to min and max values
	* @param chart The chart to normalize
	* @param seriesName The name of the chart series to normalize
	* @param areaName The name of the chart area to normalize
	*/
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
	/**
	* Normalize a chart series according to min and max values
	*/
	private: System::Void normalizeCandlestickChart() {
		// Normalize chart
		normalizeCandlestickChart(chart_stockData, "Series_OHLC", "ChartArea_OHLC");
	}


	/**
	* Update stocks being displayed according to the provided start and end dates
	* @param startDate The start date for the filter
	* @param endDate The end date for the filter
	*/
	private: System::Void update(System::DateTime^ startDate, System::DateTime^ endDate) {
		// Filter candlesticks using the provided dates
		Generic::List<aCandlestick^>^ filteredCandlesticks = this->filterCandlesticks(startDate, endDate, this->listOfCandlesticks);

		// Clear binding list
		this->filteredListOfCandlesticks->Clear();

		// Add filtered candlesticks to binding list
		for (int i = 0; i < filteredCandlesticks->Count; i++) {
			this->filteredListOfCandlesticks->Add(filteredCandlesticks[i]);
		}

		// Update chart
		this->displayChart();

		// Normalize chart
		this->normalizeCandlestickChart();
	}
	/**
	* Update stocks being displayed according to filters from form controls
	*/
	private: System::Void update() {
		// Get the start and end dates from the date pickers
		System::DateTime^ startDate = this->dateTimePicker_start->Value;
		System::DateTime^ endDate = this->dateTimePicker_end->Value;

		// Call the overloaded update method with the date range
		this->update(startDate, endDate);
	}


private: System::Void button_update_Click(System::Object^ sender, System::EventArgs^ e) {
	// Update displays
	this->update();
}
};
}