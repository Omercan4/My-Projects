# Analysis of the World Happiness Report (2015-2023)

**Project Aim:** The primary objective of this project is to develop a robust Bayesian framework capable of capturing the complex variance, hierarchical nesting, and temporal dependencies inherent in global happiness trends from 2015 to 2023. By implementing a multilevel architecture, the study aims to move beyond traditional frequentist regressions—which often fail to account for regional dependency structures or non-Gaussian error distributions—toward a model that utilizes regional exchangeability and partial pooling. Through an incremental modeling strategy implemented via the `brms` package in R, the project seeks to balance global trends with local regional nuances while remaining resilient to the heavy-tailed noise and stochastic shocks characteristic of longitudinal happiness data.

**Definition:** To evaluate the effectiveness of the Bayesian framework and analyze the drivers of global life satisfaction, this report addresses three central research components within a unified investigative framework:

* **Model Progression and Comparison:** A sequence of five increasingly complex models is developed—ranging from a baseline complete pooling model to a hierarchical specification with varying intercepts, varying slopes, and ARMA(1,1) time series errors—to determine which structure best captures the hierarchical and temporal nature of the dataset.
* **Likelihood Robustness Analysis:** A comparative assessment is conducted between Gaussian and Student-t likelihoods to ascertain which distribution better accommodates the outliers and heavy-tailed volatility observed in national happiness scores.
* **Predictor Influence and Temporal Dynamics:** The study performs an analysis of six key input parameters (GDP per capita, social support, healthy life expectancy, freedom, generosity, and corruption) to identify the dominant drivers of happiness while specifically isolating the role of autoregressive components in explaining structural persistence over time.

**Other Contributors:** Tobias Rumpe, and Yordan Saputra
