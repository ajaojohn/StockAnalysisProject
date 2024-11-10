#include "pch.h"
#include "aCandlestick.h"

/// <summary>
/// Default constructor for aCandlestick that sets all the properties to 0 and date to the current date
/// </summary>
aCandlestick::aCandlestick()
{
    setCandlestickProperties(
        gcnew System::DateTime(),
        System::Decimal(0),
        System::Decimal(0),
        System::Decimal(0),
        System::Decimal(0),
        0);
}

/// <summary>
/// Constructor for aCandlestick that takes in a row of data in the format "Date,Open,High,Low,Close,Volume"
/// </summary>
/// <param name="row">A row of data in the format "Date,Open,High,Low,Close,Volume"</param>
aCandlestick::aCandlestick(System::String^ row)
{
    // Split the row into an array
    array<System::String^>^ splitRow = row->Split(gcnew array<wchar_t>{',', '\"'}, System::StringSplitOptions::RemoveEmptyEntries);

    // Set the properties
    setCandlestickProperties(
        System::DateTime::Parse(splitRow[0]),
        System::Convert::ToDecimal(splitRow[1]),
        System::Convert::ToDecimal(splitRow[2]),
        System::Convert::ToDecimal(splitRow[3]),
        System::Convert::ToDecimal(splitRow[4]),
        System::Convert::ToInt64(splitRow[5])
    );
}

/// <summary>
/// Constructor for aCandlestick that individually sets the properties
/// </summary>
/// <param name="date">Date of the candlestick</param>
/// <param name="open">Open price of the candlestick</param>
/// <param name="high">Highest price of the candlestick</param>
/// <param name="low">Lowest price of the candlestick</param>
/// <param name="close">Close price of the candlestick</param>
/// <param name="volume">Volume of candlestick's stock traded</param>
aCandlestick::aCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume)
{
    setCandlestickProperties(date, open, high, low, close, volume);
}

/// <summary>
/// Copy constructor for aCandlestick
/// </summary>
/// <param name="candlestick">Candlestick to copy</param>
aCandlestick::aCandlestick(aCandlestick^ candlestick) {
    setCandlestickProperties(candlestick->date, candlestick->open, candlestick->high, candlestick->low, candlestick->close, candlestick->volume);
}

/// <summary>
/// Sets the individual properties of the candlestick
/// </summary>
/// <param name="date">Date of the candlestick</param>
/// <param name="open">Open price of the candlestick</param>
/// <param name="high">Highest price of the candlestick</param>
/// <param name="low">Lowest price of the candlestick</param>
/// <param name="close">Close price of the candlestick</param>
/// <param name="volume">Volume of candlestick's stock traded</param>
/// <returns>void</returns>
System::Void aCandlestick::setCandlestickProperties(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume) {
    // Set date variable
    this->_date = date;
    // Set open variable
    this->_open = open;
    // Set high variable
    this->_high = high;
    // Set low variable
    this->_low = low;
    // Set close variable
    this->_close = close;
    // Set volume variable
    this->_volume = volume;
}
