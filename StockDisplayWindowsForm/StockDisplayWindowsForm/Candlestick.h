#pragma once
ref class Candlestick
{
public:
    // Properties for a candlestick
    System::DateTime^ date;  // Time of the candlestick
    double open;          // Opening price
    double high;          // Highest price
    double low;           // Lowest price
    double close;         // Closing price
    double volume;        // Volume of stock traded

    /**
    * Default constructor
    */
    Candlestick()
    {
		this->date = gcnew System::DateTime();
		this->open = 0;
		this->high = 0;
		this->low = 0;
		this->close = 0;
		this->volume = 0;
    }

    /**
    * Candlestick default constructor
    * @param date Time of the candlestick
    * @param open Opening price
    * @param high Highest price
    * @param low Lowest price
    * @param close Closing price
    * @param volume Volume of stock traded
    */
    Candlestick(System::DateTime^ date, double open, double high, double low, double close, double volume)
    {
        this->date = date;
        this->open = open;
        this->high = high;
        this->low = low;
        this->close = close;
        this->volume = volume;
    }

    /**
    * Copy constructor
	* @param candlestick The candlestick to copy
    */
    Candlestick(Candlestick^ candlestick) {
		this->date = candlestick->date;
		this->open = candlestick->open;
		this->high = candlestick->high;
		this->low = candlestick->low;
		this->close = candlestick->close;
		this->volume = candlestick->volume;
    }
};

