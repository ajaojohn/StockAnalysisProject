#include "pch.h"
#include "aCandlestickLoader.h"

/// <summary>
/// Loads a csv data file and returns a list of candlesticks
/// </summary>
/// <param name="filename">File path to the csv file</param>
/// <returns>A List of aCandlestick objects created from rows in the file</returns>
List<aCandlestick^>^ aCandlestickLoader::load(System::String^ filename) {
	// Create empty list of candlesticks
	List<aCandlestick^>^ listOfCandlesticks = gcnew List<aCandlestick^>();

	// Try reading candlesticks from the file
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

	// If the first candlestick is after the last candlestick (chronological order), reverse the list
	if (listOfCandlesticks[0]->Date->CompareTo(listOfCandlesticks[listOfCandlesticks->Count - 1]->Date) > 0) {
		// Reverse the list
		listOfCandlesticks->Reverse();
	}

	// Return the list
	return listOfCandlesticks;
}