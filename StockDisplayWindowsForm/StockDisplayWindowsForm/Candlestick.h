namespace CppCLRWinFormsProject {
#pragma once
    ref class Candlestick
    {
    public:
        // Properties for a candlestick
        System::DateTime^ date;  // Date of the candlestick
        System::Decimal open;    // Opening price
        System::Decimal high;    // Highest price
        System::Decimal low;     // Lowest price
        System::Decimal close;   // Closing price
        System::Int64 volume;    // Volume of stock traded

        /**
        * Default constructor
        */
        Candlestick()
        {
            setCandlestickProperties(gcnew System::DateTime(), System::Decimal(0), System::Decimal(0), System::Decimal(0), System::Decimal(0), 0);
        }

        /**
        * Candlestick constructor
        * @param Line from a csv file formatted "date,open,high,low,close,adj close,volume"
        */
        Candlestick(System::String^ row)
        {
            // Split the row into an array
            array<System::String^>^ splitRow = row->Split(',');

			// Set the properties
            setCandlestickProperties(
                System::DateTime::Parse(splitRow[0]),
                System::Convert::ToDecimal(splitRow[1]),
                System::Convert::ToDecimal(splitRow[2]),
                System::Convert::ToDecimal(splitRow[3]),
                System::Convert::ToDecimal(splitRow[4]),
                System::Convert::ToInt64(splitRow[6])
            );
        }

        /**
        * Candlestick constructor
        * @param date Time of the candlestick
        * @param open Opening price
        * @param high Highest price
        * @param low Lowest price
        * @param close Closing price
        * @param volume Volume of stock traded
        */
        Candlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume)
        {
            setCandlestickProperties(date, open, high, low, close, volume);
        }

        /**
        * Copy constructor
        * @param candlestick The candlestick to copy
        */
        Candlestick(Candlestick^ candlestick) {
            setCandlestickProperties(candlestick->date, candlestick->open, candlestick->high, candlestick->low, candlestick->close, candlestick->volume);
        }

    private:
        /**
        * Set the candlestick properties
        * @param date Date of the candlestick
        * @param open Opening price
        * @param high Highest price
        * @param low Lowest price
        * @param close Closing price
        * @param volume Volume of stock traded
        * @returns void
        */
        System::Void setCandlestickProperties(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume) {
            // Set properties from parameters
		    this->date = date;
		    this->open = open;
		    this->high = high;
		    this->low = low;
		    this->close = close;
		    this->volume = volume;
        }
    };
}
