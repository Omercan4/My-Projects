# Energy Price Forecast

[![Energy Price Forecast](https://raw.githubusercontent.com/Omercan4/energy-price-forecast/main/docs/img/social-preview.png)](https://github.com/Omercan4/energy-price-forecast)

Day-ahead electricity prices for Germany. The model forecasts tomorrow's 24 hourly prices with LightGBM quantile models and an 80 % prediction interval.

- 12-month rolling backtest, every month forecast by a model trained on earlier data only: MAE 19.6 EUR/MWh, which is 22.3 % lower than the best classical baseline (Holt-Winters, 25.2) and 47.6 % lower than the seasonal naive forecast (37.4).
- The interval covers 79 % of the real prices.
- Anomaly detection, SHAP, FastAPI, and a daily GitHub Action that forecasts, scores finished days and checks input drift.
- A notebook walks through the whole process step by step.

**Tools:** Python, LightGBM, statsmodels, pandas, MLflow, SHAP, FastAPI, GitHub Actions and Pages

[Live page](https://omercan4.github.io/energy-price-forecast/) · **[Code and full README in its own repository](https://github.com/Omercan4/energy-price-forecast)**
