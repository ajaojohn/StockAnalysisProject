# Stock Analysis Project
## Overview

This project is a C++/CLI WinForms application designed for analyzing and visualizing stock market candlestick data. Leveraging Windows Forms and the .NET Charting control, it provides an interactive user interface where users can load CSV-based candlestick data, filter it by date, detect common candlestick patterns, identify peaks and valleys, and perform advanced technical analysis such as drawing Fibonacci retracement levels and calculating “beauty scores” for theoretical price levels.

## Key Features

1. **Candlestick Charting**:  
   - Displays OHLC (Open-High-Low-Close) candlesticks loaded from CSV files.
   - Visually normalizes the chart to fit the selected date range.

2. **Pattern Detection & Annotation**:  
   - Detects and marks various candlestick patterns:
     - Bullish
     - Bearish
     - Neutral
     - Marubozu
     - Hammer
     - Doji (including Dragonfly and Gravestone Doji)
   - Option to display peaks and valleys to quickly identify market turning points.
   - Patterns are highlighted via chart annotations (arrows and labels).

3. **Date Filtering & Multiple Data Files**:  
   - Load and display stock data from CSV files.
   - Choose custom start and end dates to filter displayed data.
   - Supports opening multiple data files, each in its own form window for comparison.

4. **Wave Selection & Validation**:  
   - Interactively select two candlesticks with mouse drag to form a "wave".
   - The application attempts to snap your selection to the nearest peak or valley, ensuring more meaningful technical analysis.
   - Validates if the selected wave meets certain criteria (e.g., properly formed wave, no invalid intrawave highs or lows).

5. **Fibonacci Levels**:  
   - Automatically draws Fibonacci retracement levels between two selected candlesticks to help identify potential support/resistance levels.

6. **Theoretical Beauty Scores**:  
   - Calculates a "beauty score" by theoretically adjusting the wave’s ending price level up and down.
   - Helps to visualize how well candlestick attributes align with Fibonacci levels as the ending price changes.
   - Highlights points on the chart corresponding to best theoretical alignment (maximum "beauty").

## Pictures
Pattern selection
![image](https://github.com/user-attachments/assets/ffe8e5fd-1993-4f80-9ca1-88ecbee755e3)

Peak and Valleys Display
![image](https://github.com/user-attachments/assets/348a246b-3386-44ac-8430-e76285e993ae)

Fibonacci Levels & Beauty Scores
![image](https://github.com/user-attachments/assets/165569f7-447d-49a1-96fc-0bb0edb8044b)

---
## Getting Started

### Prerequisites

- **Windows**: This project targets the .NET Framework via C++/CLI and Windows Forms, so it is primarily suited for Windows environments.
- **Visual Studio**: A recent version of Visual Studio with C++/CLI support is recommended.
- **.NET Framework**: This project requires the .NET Framework.

### Installation

#### Prerequisites
- Windows: This project targets the .NET Framework via C++/CLI and Windows Forms, so it is primarily suited for Windows environments.
- Visual Studio: A recent version of Visual Studio with C++/CLI support is recommended.
- .NET Framework: This project requires the .NET Framework, typically version 4.7.2 or newer (check the .vcxproj for the exact target).

#### Installation
- Clone the repository
- Open the .sln (solution) file in Visual Studio.
- Ensure that you have the required workloads (Desktop development with C++) and C++/CLI components installed.
- Build the Project:

#### Running the Application
- After a successful build, run the application by pressing F5 (Debug) or Ctrl+F5 (Run without Debugging).
- The main window (Form_Input) will appear.
- Click the Load File button to select a CSV file containing stock candlestick data.
- Adjust the date range using the start and end date pickers and click Update to refresh the displayed data.
- Check various pattern checkboxes to display pattern annotations.
- **Optional**: Enable “Show Peaks and Valleys” for additional insights.
- Select a “wave” by clicking and dragging on the chart; the application will help snap to meaningful peaks/valleys and then display Fibonacci and beauty score analyses.

#### Data Format
- CSV Input: The CSV file should contain candlestick data columns typically: Date,Open,High,Low,Close (and possibly Volume).
- File Selection: You can open multiple files. Each subsequent file opens in a separate Form_Input window, allowing side-by-side comparison.
