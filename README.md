# Projects: Ömercan Misirlioglu

**Data Scientist** (M.Sc. Data Science, TU Dortmund) with an **industrial-engineering**
foundation (B.Sc., Boğaziçi) and hands-on **applied-AI / GenAI** experience. This repository
is a selection of academic and personal projects spanning statistical modeling, machine
learning, simulation-based inference, generative AI, and operations research.

📍 Dortmund, Germany · 🔗 [LinkedIn](https://linkedin.com/in/omercanmisirlioglu4) ·
✉️ omercanmisirlioglu@hotmail.com

> Several projects were completed in teams; individual contributors are credited in each
> project's own README.

---

## Featured projects

| Project | Area | Tools |
|---|---|---|
| [German Energy Q&A Agent: LLM Tool Calling + RAG over Bundestag Papers (LangGraph, MLflow, Docker, Azure)](https://github.com/Omercan4/energiewende-agent) *(work in progress, separate repo)* | Answers questions on German energy data: an LLM agent calls live data tools (SMARD prices and generation, Open-Meteo weather) and searches 99 Bundestag papers (RAG); evaluated with 30 questions in MLflow; Docker, CI and a working deployment on Azure | Python, LangGraph, LlamaIndex, Chroma, FastAPI, MLflow, Docker, GitHub Actions, Azure |
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

- **[Master Projects](Master%20Projects)** — M.Sc. Data Science: advanced statistical modeling,
  Bayesian methods, simulation-based inference, ML.
- **[Bachelor Projects](Bachelor%20Projects)** — B.Sc. Industrial Engineering: optimization,
  simulation, operations research, forecasting, data mining, and the graduation project.

- **[German Energy Q&A Agent: LLM Tool Calling + RAG over Bundestag Papers (LangGraph, MLflow, Docker, Azure)](https://github.com/Omercan4/energiewende-agent)**: personal project in its own repository,
  work in progress (a working version is already deployed).

Each project folder contains its own README and the report/code/data for that work.

---

## Skills reflected here

**Languages:** Python, R, SQL, C/C++ ·
**ML & Statistics:** regression, classification (random forest, gradient boosting), clustering, neural networks,
Bayesian inference (Stan/brms), simulation-based inference, time series & forecasting (ARIMA), experimental design ·
**Generative AI:** LLM APIs (OpenAI, Claude, Gemini), function/tool calling (since 2023), LLM agents (LangGraph),
RAG & GraphRAG, knowledge graphs, multimodal models, LlamaIndex, Chroma, LLM evaluation ·
**Operations Research:** optimization (Gurobi), discrete-event simulation (ARENA/Python), scheduling ·
**Engineering & deployment (first hands-on experience):** FastAPI, Docker, GitHub Actions (CI), MLflow, Azure ·
**Tools:** Git, Streamlit, LaTeX, Excel
