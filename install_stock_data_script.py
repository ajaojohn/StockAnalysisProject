import yfinance as yf
import pandas as pd
import os

def main():
    print("Starting stock data download script...")
    # Define the stock tickers and the date range
    tickers = {'AAPL', 'MSFT', 'GOOG', 'IBM', 'TSLA'}
    start_date = '1900-01-01'
    end_date = '2024-12-31'
        
    # Define the path where files will be saved
    directory = './StockDisplayWindowsForm/Stock Data/'  # Replace with your desired path
    
    # Ensure the directory exists, if not, create it
    if not os.path.exists(directory):
        os.makedirs(directory)

    # Download stock data for each ticker
    for ticker in tickers:
        downloadStockData(ticker, start_date, end_date, directory)

def downloadStockData(ticker, start_date, end_date, directory):
    # Download daily stock data
    daily_data = yf.download(ticker, start=start_date, end=end_date, interval='1d')
    daily_data = drop_adj_close(daily_data)
    daily_file = os.path.join(directory, f"{ticker}-Day.csv")
    daily_data.to_csv(daily_file)

    # Download weekly stock data
    weekly_data = yf.download(ticker, start=start_date, end=end_date, interval='1wk')
    weekly_data = drop_adj_close(weekly_data)
    weekly_file = os.path.join(directory, f"{ticker}-Week.csv")
    weekly_data.to_csv(weekly_file)

    # Download monthly stock data
    monthly_data = yf.download(ticker, start=start_date, end=end_date, interval='1mo')
    monthly_data = drop_adj_close(monthly_data)
    monthly_file = os.path.join(directory, f"{ticker}-Month.csv")
    monthly_data.to_csv(monthly_file)

    print(f"Downloaded stock data for {ticker} from {start_date} to {end_date} to {directory}")

def drop_adj_close(df):
    """
    Drops the 'Adj Close' column from the DataFrame if it exists.
    """
    if 'Adj Close' in df.columns:
        df = df.drop(columns=['Adj Close'])
        print("Dropped 'Adj Close' column.")
    else:
        print("'Adj Close' column not found; no action taken.")
    return df

if __name__ == "__main__":
    main()
