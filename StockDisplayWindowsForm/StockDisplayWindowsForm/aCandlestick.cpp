#include "pch.h"
#include "aCandlestick.h"

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

aCandlestick::aCandlestick(System::String^ row)
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

aCandlestick::aCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume)
{
    setCandlestickProperties(date, open, high, low, close, volume);
}

aCandlestick::aCandlestick(aCandlestick^ candlestick) {
    setCandlestickProperties(candlestick->date, candlestick->open, candlestick->high, candlestick->low, candlestick->close, candlestick->volume);
}

System::Void aCandlestick::setCandlestickProperties(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume) {
    // Set properties from parameters
    this->_date = date;
    this->_open = open;
    this->_high = high;
    this->_low = low;
    this->_close = close;
    this->_volume = volume;
}
