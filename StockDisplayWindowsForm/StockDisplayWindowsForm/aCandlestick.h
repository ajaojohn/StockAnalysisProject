#pragma once
ref class aCandlestick
{
private:
    /// Private fields
    System::DateTime^ _date;    // Date of the candlestick
    System::Decimal _open;      // Opening price
    System::Decimal _high;      // Highest price
    System::Decimal _low;       // Lowest price
    System::Decimal _close;     // Closing price
    System::Int64 _volume;      // Volume of stock traded

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
    System::Void setCandlestickProperties(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume);
public:
    // Property for date
    property System::DateTime^ date {
        // Date getter
        System::DateTime^ get() { return _date; }
        // Date setter
        void set(System::DateTime^ value) { _date = value; }
    }

    // Property for open
    property System::Decimal open {
		// Open price getter
        System::Decimal get() { return _open; }
		// Open price setter
        void set(System::Decimal value) { _open = value; }
    }

    // Property for high
    property System::Decimal high {
		// High price getter
        System::Decimal get() { return _high; }
		// High price setter
        void set(System::Decimal value) { _high = value; }
    }

    // Property for low
    property System::Decimal low {
		// Low price getter
        System::Decimal get() { return _low; }
		// Low price setter
        void set(System::Decimal value) { _low = value; }
    }

    // Property for close
    property System::Decimal close {
		// Close price getter
        System::Decimal get() { return _close; }
        // Close price setter
        void set(System::Decimal value) { _close = value; }
    }

    // Property for volume
    property System::Int64 volume {
		// Volume getter
        System::Int64 get() { return _volume; }
		// Volume setter
        void set(System::Int64 value) { _volume = value; }
    }

    /**
    * Default constructor
    */
    aCandlestick();

    /**
    * aCandlestick constructor
    * @param Line from a csv file formatted "date,open,high,low,close,adj close,volume"
    */
    aCandlestick(System::String^ row);

    /**
    * aCandlestick constructor
    * @param date Time of the candlestick
    * @param open Opening price
    * @param high Highest price
    * @param low Lowest price
    * @param close Closing price
    * @param volume Volume of stock traded
    */
    aCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume);

    /**
    * Copy constructor
    * @param candlestick The candlestick to copy
    */
    aCandlestick(aCandlestick^ candlestick);
};