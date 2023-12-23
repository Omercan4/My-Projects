
0$            CREATE,        1:NORM(5,1):NEXT(11$);                             Creates Engineering Student with Normal(5,1)

11$           ASSIGN:        StudentType=1:
                             ServiceTime=ED(StudentType);                       Assigns the student type with respected service and payment times.
service       QUEUE,         ServiceQue:MARK(EnterServiceQue);
1$            SEIZE,         1,Other:
                             Server,1:NEXT(10$);

10$           TALLY:         Time Spent in Service Queue,INTERVAL(EnterServiceQue),1;
2$            DELAY:         ServiceTime,StudentType,Other:NEXT(3$);

3$            ASSIGN:        AllCount=AllCount+1;
resume        RELEASE:       Server,1;
12$           BRANCH,        1:
                             With,0.4,cashPayment,Yes:
                             With,0.6,CreditPayment,Yes;                        sends 60% of the customers to credit card payment independent of their student type, sends the rest to cash payment indep. of the student type
cashPayment   ASSIGN:        PaymentTime=4;                                     with 0.4 probability assigns a payment time with U(2,6)
payment       QUEUE,         PaymentQue:MARK(PaymentQueArr);
4$            SEIZE,         1,Other:
                             Cashier,1:NEXT(5$);

5$            DELAY:         PaymentTime,StudentType+2,Other:NEXT(6$);

6$            RELEASE:       Cashier,1;
7$            BRANCH,        1:
                             With,0.25,forget,Yes:
                             Else,dont_forget,Yes;                              with 0.25 probability customer forgets the drink
forget        ASSIGN:        PaymentTime=ED(5):NEXT(forgetbranch);

forgetbranch  BRANCH,        1:
                             If,StudentType==1,Engineering Student,Yes:
                             Else,Social Sciences Student,Yes;                  Checks if the student who forget the drink is Engineering or Social Sciences Student
Engineering Student COUNT:   Number Of Engineering Students Who Forget Their Drink,1; counts the Engineering Students who forget their drinks
selfservice   DELAY:         0.5,,Other:NEXT(payment);

Social Sciences Student COUNT: Number Of Social Sciences Students Who Forget Their Drink,1:NEXT(selfservice); counts the Social Sciences Students who forget their drinks

dont_forget   DISPOSE:       No;                                                disposes the successful entity

CreditPayment ASSIGN:        PaymentTime=3:NEXT(payment);                       with 0.6 probability assigns a payment time with U(1,2)


9$            CREATE,        1:EXPO(4):NEXT(8$);                                Creates Social Sciences student with Exponential(4)

8$            ASSIGN:        StudentType=2:
                             ServiceTime=ED(StudentType):NEXT(service);         Assigns the student type with respected service and payment times.





