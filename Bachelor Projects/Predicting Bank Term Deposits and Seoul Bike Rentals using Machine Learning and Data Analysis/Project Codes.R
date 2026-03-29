library(caret)
library(caTools)
library(randomForest)

bank <- read.csv2("bank.csv", quote="\"")

bank$marital = as.factor(bank$marital)
bank$education = as.factor(bank$education)
bank$default = as.factor(bank$default)
bank$housing = as.factor(bank$housing)
bank$loan = as.factor(bank$loan)
bank$contact = as.factor(bank$contact)
bank$poutcome = as.factor(bank$poutcome)
bank$y = as.factor(bank$y)

#Question 1
#a

set.seed(425)
split=sample.split(bank$y,SplitRatio=0.8)
banktr=subset(bank,split==TRUE)
bankte=subset(bank,split==FALSE)

#b
t = read.csv("ToyotaCorolla.csv")
set.seed(425)

models <- list() # An empty list for different models to be put into
ntrees = c(100) # A list for ntree values
for (i in 1:length(ntrees)){
  ntree <- ntrees[i]
  ctrl <- trainControl(method = "repeatedcv", number = 10, repeats = 1)
  rf_model <- train(y ~ ., data = banktr, metric = "Accuracy", method = "rf", trControl = ctrl, ntree=ntree,tuneGrid = expand.grid(.mtry = (3:6)), importance = TRUE)
  models[[i]] = rf_model
}
rf = models[[1]]
rf$finalModel
