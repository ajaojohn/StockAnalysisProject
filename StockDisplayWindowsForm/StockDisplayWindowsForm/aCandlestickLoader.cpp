#include "pch.h"
#include "aCandlestickLoader.h"

List<aCandlestick^>^ aCandlestickLoader::load(System::String^ filename) {
	// Create empty list of candlesticks
	List<aCandlestick^>^ listOfCandlesticks = gcnew List<aCandlestick^>();

	try {
		// Create stream reader for new data file
		System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filename);

		// Store expected file headers
		System::Collections::Generic::SortedSet<System::String^>^ expectedHeaders = gcnew System::Collections::Generic::SortedSet<System::String^>();
		expectedHeaders->Add("Date,Open,High,Low,Close,Volume");
		expectedHeaders->Add("\"Date\",\"Open\",\"High\",\"Low\",\"Close\",\"Volume\"");

		// Get first line
		System::String^ firstLine = reader->ReadLine();
		// Confirm first line is formatted as expected
		if (expectedHeaders->Contains(firstLine)) {
			// Loop through each line in the file
			while (!reader->EndOfStream) {
				// Get next row
				System::String^ currRow = reader->ReadLine();

				// Create new candlestick from row
				aCandlestick^ newCandlestick = gcnew aCandlestick(currRow);
				// Add the candlestick to the list
				listOfCandlesticks->Add(newCandlestick);
			}
		}
		else {
			// If file is a different format, throw error
			throw gcnew System::IO::IOException("File is not formatted as expected");
		}
	}
	catch (System::IO::IOException^ e) {
		// If error reading file, show message box with what went wrong
		System::Windows::Forms::MessageBox::Show("Error reading file: " + e->Message);
	}

	// Return the list
	return listOfCandlesticks;
}