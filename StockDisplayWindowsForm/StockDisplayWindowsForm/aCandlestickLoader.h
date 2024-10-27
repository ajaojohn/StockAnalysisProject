#pragma once

#include "aCandlestick.h"
using namespace System::Collections::Generic;

ref class aCandlestickLoader
{
public:
	/// <summary>
	/// Reads candlestick data from a file.
	/// </summary>
	/// <param name="filename">The name of the file to read.</param>
	List<aCandlestick^>^ load(System::String^ filename);
};

