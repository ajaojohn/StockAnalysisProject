#include "pch.h"
#include "aSmartCandlestick.h"
#include "aCandlestick.h"

using namespace System;

System::Void aSmartCandlestick::calculateSmartProperties() {
	// Calculate range
	Range = Decimal::Subtract(High, Low);
	// Calculate top price
	TopPrice = Math::Max(Open, Close);
	// Calculate bottom price
	BottomPrice = Math::Min(Open, Close);
	// Calculate body range
	BodyRange = Decimal::Subtract(TopPrice, BottomPrice);
	// Calculate upper tail
	UpperTail = Decimal::Subtract(High, TopPrice);
	// Calculate lower tail
	LowerTail = Decimal::Subtract(BottomPrice, Low);
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
	setCandlestickProperties(smartCandlestick->Date, smartCandlestick->Open, smartCandlestick->High, smartCandlestick->Low, smartCandlestick->Close, smartCandlestick->Volume);
	// Calculate extra smart properties
	calculateSmartProperties();
}

bool aSmartCandlestick::isBearish() {
	// Return true if the bottom price is equal to the close
	return BottomPrice == Close;
}

bool aSmartCandlestick::isBullish() {
	// Return true if the top price is equal to the close
	return TopPrice == Close;
}

bool aSmartCandlestick::isNeutral() {
	// Return true if the body range is less than 10% of the range
	return BodyRange < Decimal::Divide(Range, 10);
}

bool aSmartCandlestick::isMarubozu() {
	// Return true if the body range is more than 85% of the range
	return BodyRange >= Decimal(static_cast<double>(Range) * 0.85);
}

bool aSmartCandlestick::isHammer() {
	// Return true if the lower tail is greater than 60% of the range and the upper tail is less than 10%
	return (LowerTail >= Decimal(static_cast<double>(Range) * 0.6))
		&& (UpperTail < Decimal(static_cast<double>(Range) * 0.1));
}

bool aSmartCandlestick::isDoji() {
	// Return true if the body range is less than or equal to 20% of the range
	return BodyRange <= Decimal::Divide(Range, 5);
}

bool aSmartCandlestick::isDragonflyDoji() {
	// Return true if the upper tail is greater than or equal to the lower tail
	return isDoji() && (LowerTail >= Decimal(static_cast<double>(Range) * 0.75));
}

bool aSmartCandlestick::isGravestoneDoji() {
	// Return true if the upper tail is greater than or equal to the lower tail
	return isDoji() && (UpperTail >= Decimal(static_cast<double>(Range) * 0.75));
}

