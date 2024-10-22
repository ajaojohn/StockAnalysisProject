#pragma once
ref class aCandlestick
{
private:
    // Private fields
    System::DateTime^ _date;
    System::Decimal _open;
    System::Decimal _high;
    System::Decimal _low;
    System::Decimal _close;
    System::Int64 _volume;

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
        System::DateTime^ get() { return _date; }
        void set(System::DateTime^ value) { _date = value; }
    }

    // Property for open
    property System::Decimal open {
        System::Decimal get() { return _open; }
        void set(System::Decimal value) { _open = value; }
    }

    // Property for high
    property System::Decimal high {
        System::Decimal get() { return _high; }
        void set(System::Decimal value) { _high = value; }
    }

    // Property for low
    property System::Decimal low {
        System::Decimal get() { return _low; }
        void set(System::Decimal value) { _low = value; }
    }

    // Property for close
    property System::Decimal close {
        System::Decimal get() { return _close; }
        void set(System::Decimal value) { _close = value; }
    }

    // Property for volume
    property System::Int64 volume {
        System::Int64 get() { return _volume; }
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