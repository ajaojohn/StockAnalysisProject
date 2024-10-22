namespace CppCLRWinFormsProject {
	using namespace System::Collections::Generic;

#pragma once
	ref class aCandlestickLoader
	{
	public:
		/**
		* Reads candlestick data from a file
		* @param filename The name of the file to read
		*/
		List<aCandlestick^>^ load(System::String^ filename) {
			// Create empty list of candlesticks
			List<aCandlestick^>^ listOfCandlesticks = gcnew List<aCandlestick^>();

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
	};
}

