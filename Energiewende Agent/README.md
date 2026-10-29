# Energiewende Agent

[![Energiewende Agent](https://raw.githubusercontent.com/Omercan4/energiewende-agent/main/docs/img/social-preview.png)](https://github.com/Omercan4/energiewende-agent)

An LLM agent (LangGraph) that answers questions about German energy. Python calculates the numbers and the LLM explains them. The agent chooses between live data tools (SMARD, Open-Meteo), a price forecast tool and RAG over 99 Bundestag papers with filters by party and paper type, and it names its sources.

- Tested with 35 questions and an LLM judge in MLflow: numbers 100 % correct, 94 % of the answers fully correct.
- FastAPI service, Docker, CI with secret scanning and a deployment on Azure Container Apps.
- The README also documents what went wrong along the way.

**Tools:** Python, LangGraph, LlamaIndex, Chroma, FastAPI, MLflow, Docker, GitHub Actions, Azure

**[Code and full README in its own repository](https://github.com/Omercan4/energiewende-agent)**
