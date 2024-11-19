#pragma once
#include "aCandlestick.h"
ref class aSmartCandlestick :
    public aCandlestick
{
private:
    /// Private fields
    System::Int64 _index; // Index
    System::Decimal _range;    // High minus low
    System::Decimal _bodyRange; // topPrice minus bottomPrice
    System::Decimal _topPrice; // max(open, close)
    System::Decimal _bottomPrice; // min(open, close)
    System::Decimal _upperTail; // height of upper tail
    System::Decimal _lowerTail; // height of lower tail

    // Range property
	property System::Decimal Range {
        System::Decimal get() { return _range; }
        System::Void set(System::Decimal value) { _range = value; }
    }
    // Body range property
	property System::Decimal BodyRange {
		System::Decimal get() { return _bodyRange; }
		System::Void set(System::Decimal value) { _bodyRange = value; }
	}
    // Top Price property
	property System::Decimal TopPrice {
		System::Decimal get() { return _topPrice; }
		System::Void set(System::Decimal value) { _topPrice = value; }
	}
    // Bottom Price property
	property System::Decimal BottomPrice {
		System::Decimal get() { return _bottomPrice; }
		System::Void set(System::Decimal value) { _bottomPrice = value; }
	}
    // Upper tail property
	property System::Decimal UpperTail {
		System::Decimal get() { return _upperTail; }
		System::Void set(System::Decimal value) { _upperTail = value; }
	}
    // Lower tail property
    property System::Decimal LowerTail {
		System::Decimal get() { return _lowerTail; }
		System::Void set(System::Decimal value) { _lowerTail = value; }
	}

    // Index property
    public: property System::Int64 Index {
        System::Int64 get() { return _index; }
        System::Void set(System::Int64 value) { _index = value; }
    }

    /// <summary>
    /// Calculates the smart candlestick properties
    /// </summary>
    /// <returns></returns>
    System::Void calculateSmartProperties();

public:
    /// <summary>
    /// Default constructor, sets all properties to 0 and date to today
    /// </summary>
    aSmartCandlestick();

    /// <summary>
    /// Constructor for aSmartCandlestick
    /// </summary>
    /// <param name="row">Line from a csv file formatted "date,open,high,low,close,adj close,volume"</param>
    aSmartCandlestick(System::String^ row);

    /// <summary>
    /// Constructs a aSmallCandlestick object representing a stock's performance for a specific time period.
    /// </summary>
    /// <param name="date">The time of the candlestick.</param>
    /// <param name="open">The opening price.</param>
    /// <param name="high">The highest price.</param>
    /// <param name="low">The lowest price.</param>
    /// <param name="close">The closing price.</param>
    /// <param name="volume">The volume of stock traded.</param>
    aSmartCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume);

    /// <summary>
    /// Constructor that creates a aSmartCandlestick from a aCandlestick
    /// </summary>
    /// <param name="candlestick">The candlestick to copy.</param>
    aSmartCandlestick(aCandlestick^ candlestick);

    /// <summary>
    /// Copy constructor for aSmartCandlestick
    /// </summary>
    /// <param name="smartCandlestick">aSmartCandlestick to copy</param>
    aSmartCandlestick(aSmartCandlestick^ smartCandlestick);

    /// <summary>
    /// Checks if the candlestick is bearish
    /// </summary>
    /// <returns>A boolean value indicating whether the candlestick is bearish</returns>
    bool isBearish();

	/// <summary>
	/// Checks if the candlestick is bullish
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is bullish</returns>
	bool isBullish();

	/// <summary>
	/// Checks if the candlestick is neutral
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is neutral</returns>
	bool isNeutral();

	/// <summary>
	/// Checks if the candlestick is a marubozu
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is a marubozu</returns>
	bool isMarubozu();

    /// <summary>
	/// Checks if the candlestick is a hammer
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is a hammer</returns>
	bool isHammer();

	/// <summary>
	/// Checks if the candlestick is a doji
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is a doji</returns>
	bool isDoji();

    /// <summary>
	/// Checks if the candlestick is a dragonfly doji
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is a dragonfly doji</returns>
	bool isDragonflyDoji();

    /// <summary>
	/// Checks if the candlestick is a gravestone doji
	/// </summary>
	/// <returns>A boolean value indicating whether the candlestick is a gravestone doji</returns>
	bool isGravestoneDoji();
};

