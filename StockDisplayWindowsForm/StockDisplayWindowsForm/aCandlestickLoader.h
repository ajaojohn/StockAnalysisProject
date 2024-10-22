#pragma once

#include "aCandlestick.h"
using namespace System::Collections::Generic;

ref class aCandlestickLoader
{
public:
	/**
	* Reads candlestick data from a file
	* @param filename The name of the file to read
	*/
	List<aCandlestick^>^ load(System::String^ filename);
};

