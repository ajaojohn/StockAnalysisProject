#include "pch.h"
#include "aSmartCandlestick.h"
#include "aCandlestick.h"

using namespace System;

System::Void aSmartCandlestick::calculateSmartProperties() {
	// Calculate range
	_range = Decimal::Subtract(_high, _low);
	// Calculate top price
	_topPrice = Math::Max(_open, _close);
	// Calculate bottom price
	_bottomPrice = Math::Min(_open, _close);
	// Calculate upper tail
	_upperTail = Decimal::Subtract(_high, _topPrice);
	// Calculate lower tail
	_lowerTail = Decimal::Subtract(_bottomPrice, _low);
}

aSmartCandlestick::aSmartCandlestick() : aCandlestick()
{
	// Calculate extra smart properties
	calculateSmartProperties();
}

aSmartCandlestick::aSmartCandlestick(System::String^ row) : aCandlestick(row)
{
	// Calculate extra smart properties
	calculateSmartProperties();
}

aSmartCandlestick::aSmartCandlestick(System::DateTime^ date, System::Decimal open, System::Decimal high, System::Decimal low, System::Decimal close, System::Int64 volume)
:
aCandlestick(date, open, high, low, close, volume)
{
	// Calculate extra smart properties
	calculateSmartProperties();
}

aSmartCandlestick::aSmartCandlestick(aCandlestick^ candlestick) : aCandlestick(candlestick)
{
	// Calculate extra smart properties
	calculateSmartProperties();
}

aSmartCandlestick::aSmartCandlestick(aSmartCandlestick^ smartCandlestick) {
	// Set andlestick-only properties
	setCandlestickProperties(smartCandlestick->date, smartCandlestick->open, smartCandlestick->high, smartCandlestick->low, smartCandlestick->close, smartCandlestick->volume);
	// Calculate extra smart properties
	calculateSmartProperties();
}

bool aSmartCandlestick::isBearish() {
	// Return true if the bottom price is equal to the close
	return _bottomPrice == _close;
}

bool aSmartCandlestick::isBullish() {
	// Return true if the top price is equal to the close
	return _topPrice == _close;
}

bool aSmartCandlestick::isNeutral() {
	// Return true if the body range is less than 10% of the range
	return _bodyRange < Decimal::Divide(_range, 10);
}

bool aSmartCandlestick::isMarubozu() {
	// Return true if the body range is more than 85% of the range
	return _bodyRange >= Decimal(static_cast<double>(_range) * 0.85);
}

bool aSmartCandlestick::isHammer() {
	// Return true if the lower tail is greater than 60% of the range and the upper tail is less than 10%
	return (_lowerTail >= Decimal(static_cast<double>(_range) * 0.6))
		&& (_upperTail < Decimal(static_cast<double>(_range) * 0.1));
}

bool aSmartCandlestick::isDoji() {
	// Return true if the body range is less than 25% of the range
	return _bodyRange < Decimal::Divide(_range, 4);
}

bool aSmartCandlestick::isDragonflyDoji() {
	// Return true if the upper tail is greater than the lower tail
	return isDoji() && (_lowerTail >= Decimal(static_cast<double>(_range) * 0.7));
}

bool aSmartCandlestick::isGravestoneDoji() {
	// Return true if the upper tail is greater than the lower tail
	return isDoji() && (_upperTail >= Decimal(static_cast<double>(_range) * 0.7));
}

