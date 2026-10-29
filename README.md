# Projects: Ömercan Misirlioglu

**Data Scientist** (M.Sc. Data Science, TU Dortmund) with an **industrial-engineering**
foundation (B.Sc., Boğaziçi) and hands-on **applied-AI / GenAI** experience. This repository
is a selection of academic and personal projects spanning statistical modeling, machine
learning, simulation-based inference, generative AI, and operations research.

📍 Germany · 🔗 [LinkedIn](https://linkedin.com/in/omercanmisirlioglu4) ·
✉️ omercanmisirlioglu@hotmail.com

> Several projects were completed in teams; individual contributors are credited in each
> project's own README.

---

## Featured projects

| Project | Area | Tools |
|---|---|---|
| **AI-Based Patent Infringement Detection Using Knowledge Graphs and Multimodal Language Models** *(master's thesis with Wilhelm Böllhoff, in progress until Dec 2026; company project, code not public)* | An LLM builds knowledge graphs from patent claims and product descriptions; graph-based retrieval (compared with text embeddings) finds the documents that may infringe a claim, and an LLM judge decides element by element. Evaluated on a synthetic benchmark of 49 claims and 441 documents with recall-based metrics and statistical tests, comparing judge models from three LLM families | Python, knowledge graphs, GraphRAG, GPT, Claude, Gemini, BGE-M3, SciPy |
| [German Energy Q&A Agent: LLM Tool Calling + RAG over Bundestag Papers (LangGraph, MLflow, Docker, Azure)](https://github.com/Omercan4/energiewende-agent) *(v0.2, separate repo)* | Answers questions on German energy data: an LLM agent chooses between live data tools (SMARD, Open-Meteo), a price forecast tool and RAG over 99 Bundestag papers (filters by party and paper type); evaluated with 35 questions and an LLM judge in MLflow (numbers 100% correct, 94% of answers fully correct); Docker, CI and a deployment on Azure | Python, LangGraph, LlamaIndex, Chroma, FastAPI, MLflow, Docker, GitHub Actions, Azure |
| [Energy Price Forecast: day-ahead electricity prices for Germany (LightGBM, MLflow, GitHub Actions)](https://github.com/Omercan4/energy-price-forecast) *(personal project, separate repo, [live page](https://omercan4.github.io/energy-price-forecast/))* | Forecasts tomorrow's 24 hourly prices with a conformal 80% interval. 12-month rolling backtest: MAE 19.6 EUR/MWh, 22.3% lower than the best classical baseline (Holt-Winters ETS, 25.2) and 47.6% lower than the seasonal naive forecast, m=168 (37.4); interval coverage 79%. Anomaly detection, SHAP, daily monitoring (error and input drift) by a scheduled GitHub Action, FastAPI | Python, LightGBM, pandas, MLflow, SHAP, FastAPI, GitHub Actions and Pages |
| [Credit-Risk Scorecard: a loan scorecard built like a bank would (WoE, LightGBM challenger, monitoring)](https://github.com/Omercan4/credit-risk-scorecard) *(personal project, separate repo, [live page](https://omercan4.github.io/credit-risk-scorecard/))* | Points scorecard on 2.26 M Lending Club loans with the top 3 reasons for every decision. Only application-time information (leakage gate), time cross-validation on 2007–2014, one out-of-time test on 2015: Gini 0.30 vs 0.34 for a LightGBM challenger and 0.36 for the lender's own grade. Profit-based decision rule, reject-bias analysis, and monitoring 2015–2018 that caught early defaults 1.49× above expected while the inputs stayed stable | Python, optbinning, scikit-learn, LightGBM, FastAPI, GitHub Actions and Pages |
| [Conversational Shift-Scheduling Assistant: LLM Tool Calling + Optimization](Bachelor%20Projects/Graduation%20Project%20-%20Conversational%20Schedule%20Explainer%20using%20ChatGPT%20API) *(graduation project, 2023/24)* | LLM assistant with a Streamlit chat interface: OpenAI function calling routes natural-language questions to Python tools for schedule queries, shift swaps, feasibility checks and rescheduling, on top of Gurobi optimization models. Agent-style tool use in 2023/24, shortly after OpenAI introduced function calling (June 2023) | Python, OpenAI API (function calling, GPT-3.5), Gurobi, Streamlit |
| [Bayesian Analysis of the World Happiness Report](Master%20Projects/Bayesian%20Analysis%20of%20World%20Happiness%20Report) | Bayesian hierarchical modeling, time-series errors (ARMA) | R, `brms`, Stan |
| [Inferring Initial Conditions in the 3-Body Problem](Master%20Projects/Inferring_Initial_Conditions_in_the_3_body_Problem) | Simulation-based inference on a chaotic system | Python, BayesFlow, RK4, LSTM |
| [Spotify Recommendation Algorithm Analysis](Master%20Projects/Spotify%20Recommendation%20Algorithm%20Analysis) | Sensitivity study of a recommender: full factorial design with 90 simulated user profiles | Cosine similarity, ANOVA, t-tests |
| [Predicting Bank Term Deposits & Seoul Bike Rentals](Bachelor%20Projects/Predicting%20Bank%20Term%20Deposits%20and%20Seoul%20Bike%20Rentals%20using%20Machine%20Learning%20and%20Data%20Analysis) | Classification & regression, model comparison and tuning | R, random forest, gradient boosting |
| [AGV Requirements for a Flexible Manufacturing System](Bachelor%20Projects/Estimating%20the%20AGV%20Requirements%20for%20a%20Hypotethical%20Flexible%20Manufacturing%20System) | Operations research, analytical AGV sizing (Egbelu) | Excel, analytical OR |
| [Forecasting Gasoline Prices](Bachelor%20Projects/Forecasting%20Gasoline%20Prices%20using%20Time%20Series%20and%20Regression) | Time-series forecasting & regression, compared by RMSE and MAPE | R, ARIMA, regression |
| [Customer Segmentation for East-West Airlines](Bachelor%20Projects/Customer%20Segmentation%20Analysis%20for%20East-West%20Airlines) | Customer segmentation & marketing analytics | R, hierarchical clustering, k-means |

---

## Repository structure

**Recent projects** (each folder has a short description and a link to the code)
- **[Patent Scout](Patent%20Scout)**: AI tool for patent engineers at Wilhelm Böllhoff (company tool, code private).
- **[Energiewende Agent](Energiewende%20Agent)**: LLM agent with live data tools and RAG over Bundestag papers.
- **[Energy Price Forecast](Energy%20Price%20Forecast)**: day-ahead electricity price forecast with prediction intervals.
- **[Credit-Risk Scorecard](Credit-Risk%20Scorecard)**: loan scorecard built like a bank would, with monitoring.

**Studies**
- **[Master Projects](Master%20Projects)**: M.Sc. Data Science, advanced statistical modeling, Bayesian methods, simulation-based inference, ML.
- **[Bachelor Projects](Bachelor%20Projects)**: B.Sc. Industrial Engineering, optimization, simulation, operations research, forecasting, data mining, and the graduation project.

**Master's thesis** (in progress): confidential company project, so it is described above but its code and data are not in this repository.

Each project folder contains its own README and the report, code or data for that work.

---

## Skills reflected here

**Languages:** Python, R, SQL, C/C++ ·
**ML & Statistics:** regression, classification (random forest, gradient boosting), clustering, neural networks,
Bayesian inference (Stan/brms), simulation-based inference, time series & forecasting (ARIMA, LightGBM quantile models, prediction intervals, backtesting), anomaly detection, experimental design, credit risk scorecards (WoE/IV, out-of-time validation, PSI/CSI monitoring) ·
**Generative AI:** LLM APIs (OpenAI, Claude, Gemini), function/tool calling (since 2023), LLM agents (LangGraph),
RAG & GraphRAG, knowledge graphs (Neo4j, NetworkX), multimodal models, LlamaIndex, Chroma, LLM evaluation ·
**Operations Research:** optimization (Gurobi), discrete-event simulation (ARENA/Python), scheduling ·
**Engineering & deployment (first hands-on experience):** FastAPI, Docker, GitHub Actions (CI, scheduled jobs, secret scanning), GitHub Pages, MLflow, Azure ·
**Tools:** Git, Streamlit, LaTeX, Excel · Databricks (first experience) · Power BI (currently learning)
