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

    /// <summary>
    /// Set the candlestick properties
    /// </summary>
    /// <param name="date">Date of the candlestick</param>
    /// <param name="open">Opening price</param>
    /// <param name="high">Highest price</param>
	/// <param name="low">Lowest price</param>
    /// <param name="close">Closing price</param>
    /// <param name="volume">Volume of stock traded</param>
    /// <returns>void</returns>
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

    /// <summary>
    /// Default constructor, sets all properties to 0 and date to today
    /// </summary>
    aCandlestick();

    /// <summary>
    /// Constructor for aCandlestick
    /// </summary>
    /// <param name="row">Line from a csv file formatted "date,open,high,low,close,adj close,volume"</param>
    aCandlestick(System::String^ row);

    /// <summary>
    /// Constructs a candlestick object representing a stock's performance for a specific time period.
    /// </summary>
    /// <param name="date">The time of the candlestick.</param>
    /// <param name="open">The opening price.</param>
    /// <param name="high">The highest price.</param>
    /// <param name="low">The lowest price.</param>
    /// <param name="close">The closing price.</param>
    /// <param name="volume">The volume of stock traded.</param>
    aCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume);

    /// <summary>
    /// Copy constructor that creates a new candlestick object by copying the data from an existing candlestick.
    /// </summary>
    /// <param name="candlestick">The candlestick to copy.</param>
    aCandlestick(aCandlestick^ candlestick);
};