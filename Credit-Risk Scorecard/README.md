# Credit-Risk Scorecard

[![Credit-Risk Scorecard](https://raw.githubusercontent.com/Omercan4/credit-risk-scorecard/main/docs/img/social-preview.png)](https://github.com/Omercan4/credit-risk-scorecard)

A loan scorecard built the way a bank builds it, on 2.26 million Lending Club loans.

- WoE binning and a logistic points scorecard that gives the top 3 reasons for every decision.
- Only information known at application time is allowed. Time cross-validation on 2007 to 2014, one out-of-time test on 2015: Gini 0.30, against 0.34 for a LightGBM challenger and 0.36 for the lender's own grade.
- Profit-based decision rule, reject-bias analysis and monitoring after go-live (PSI/CSI), which caught early defaults 1.49 times above expected while the inputs stayed stable.

**Tools:** Python, optbinning, scikit-learn, LightGBM, FastAPI, GitHub Actions and Pages

[Live page](https://omercan4.github.io/credit-risk-scorecard/) · **[Code and full README in its own repository](https://github.com/Omercan4/credit-risk-scorecard)**
