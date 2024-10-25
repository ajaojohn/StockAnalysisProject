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
	// List of candlesticks to display
	private: BindingList<aCandlestick^>^ bindingListOfCandlesticks = gcnew BindingList<aCandlestick^>();

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
			// Bind data grid to binding list
			dataGridView_stockData->DataSource = bindingListOfCandlesticks;
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
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->dataGridView_stockData = (gcnew System::Windows::Forms::DataGridView());
			this->button_load = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_load = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_stockData = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView_stockData
			// 
			this->dataGridView_stockData->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_stockData->Location = System::Drawing::Point(17, 59);
			this->dataGridView_stockData->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView_stockData->Name = L"dataGridView_stockData";
			this->dataGridView_stockData->RowHeadersWidth = 51;
			this->dataGridView_stockData->RowTemplate->Height = 24;
			this->dataGridView_stockData->Size = System::Drawing::Size(875, 775);
			this->dataGridView_stockData->TabIndex = 0;
			// 
			// button_load
			// 
			this->button_load->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button_load->Location = System::Drawing::Point(919, 981);
			this->button_load->Margin = System::Windows::Forms::Padding(4);
			this->button_load->Name = L"button_load";
			this->button_load->Size = System::Drawing::Size(368, 69);
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
			this->dateTimePicker_start->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->dateTimePicker_start->Location = System::Drawing::Point(454, 999);
			this->dateTimePicker_start->Name = L"dateTimePicker_start";
			this->dateTimePicker_start->Size = System::Drawing::Size(381, 31);
			this->dateTimePicker_start->TabIndex = 2;
			this->dateTimePicker_start->Value = System::DateTime(2020, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_end
			// 
			this->dateTimePicker_end->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->dateTimePicker_end->Location = System::Drawing::Point(1375, 999);
			this->dateTimePicker_end->Name = L"dateTimePicker_end";
			this->dateTimePicker_end->Size = System::Drawing::Size(355, 31);
			this->dateTimePicker_end->TabIndex = 3;
			// 
			// chart_stockData
			// 
			chartArea1->Name = L"ChartArea_OHLC";
			this->chart_stockData->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart_stockData->Legends->Add(legend1);
			this->chart_stockData->Location = System::Drawing::Point(919, 59);
			this->chart_stockData->Name = L"chart_stockData";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart_stockData->Series->Add(series1);
			this->chart_stockData->Size = System::Drawing::Size(1225, 775);
			this->chart_stockData->TabIndex = 4;
			this->chart_stockData->Text = L"Stock Data";
			// 
			// Form_Input
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2157, 1131);
			this->Controls->Add(this->chart_stockData);
			this->Controls->Add(this->dateTimePicker_end);
			this->Controls->Add(this->dateTimePicker_start);
			this->Controls->Add(this->button_load);
			this->Controls->Add(this->dataGridView_stockData);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form_Input";
			this->Text = L"Form_Input";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_stockData))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_stockData))->EndInit();
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

			// Get candlesticks in time frame
			Generic::List<aCandlestick^>^ filteredCandlesticks = this->getFilteredCandlesticks(this->dateTimePicker_start->Value, this->dateTimePicker_end->Value, this->listOfCandlesticks);
			// Clear binding list
			this->bindingListOfCandlesticks->Clear();
			// Add filtered candlesticks to binding list
			for (int i = 0; i < filteredCandlesticks->Count; i++) {
				this->bindingListOfCandlesticks->Add(filteredCandlesticks[i]);
			}
			// Fill chart with candlestick data
			this->populateChart(filteredCandlesticks);
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
	* Populate chart with data
	* @param listOfCandlesticks The list of candlesticks to display
	*/
	private: System::Void populateChart(Generic::List<aCandlestick^> ^ listOfCandlesticks) {
		// Clear prior chart data
		chart_stockData->Series["Series_OHLC"]->Points->Clear();

		// Add each candlestick to the chart
		for each (aCandlestick^ candlestick in listOfCandlesticks)
		{
			// Create a new data point
			System::Windows::Forms::DataVisualization::Charting::DataPoint^ point = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint();
			point->XValue = candlestick->date->ToOADate();
			point->YValues = gcnew cli::array<double>{
				static_cast<double>(candlestick->open),
				static_cast<double>(candlestick->high),
				static_cast<double>(candlestick->low),
				static_cast<double>(candlestick->close)
			};
			// Add the point to the series
			chart_stockData->Series[0]->Points->Add(point);
		}
	}
};
}