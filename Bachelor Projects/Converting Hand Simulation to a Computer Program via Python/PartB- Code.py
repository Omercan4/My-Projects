import numpy as np


#I CREATED A CLASS CALLED SIMULATION TO EASILY CREATE THE MODEL IN OBJECT ORIENTED MANNER

class SimQuestion2b:
    def __init__(self): #this constructor initializes the attributes of the simulation at the beginning, with the help of this, I can control the beginning states
        self.num_in_sv1 = 1 #number of customers in server 1
        self.num_in_sv2 = 0 #number of customers in server 2
        self.num_in_queue = 0 #number of customers in queue
        self.sv1_usagetime = 0 #totalusagetime of server 1
        self.sv2_usagetime = 0 #totalusagetime of server 2
        self.sv1_utilization = 0 #utilization of server 1
        self.sv2_utilization = 0 #utilization of server 2
        
        
        self.clock = 0.0 #system clock
        self.t_arrival = self.generate_interarrival() #the first arrival generated at time 0.0
        self.t_depart1 = self.generate_svtime1() #service time of the customer that is in server 1 when simulation begins 
        self.t_depart2 = float('inf') #since it is empty, service time is infinite for server 2
        
        self.num_arrivals = 0 #total number of arrivals
        self.num_departs = 0 #total number of departures
        self.total_wait = 0.0 #total waiting time in queue
        self.avg_queue_time = 0.0
        self.tot_usage_customer = 0 #total time that customers stayed in the system
        self.avg_num_cus = 0 #average number of customers in the system
        self.totalqueuecust = 0 #total number of customers waited in the queue
        self.total_num_cus = 1 #total number of customers that have used the system
        
    def advance_time(self):
        t_event= min(self.t_arrival, self.t_depart1, self.t_depart2) #choosing the closest event to jump
        self.total_wait += self.num_in_queue*(t_event- self.clock) #total queue waiting time update
        self.tot_usage_customer += (self.num_in_sv1+self.num_in_sv2+self.num_in_queue)*(t_event-self.clock) #calculating the total usage of system by customers 
        self.clock = t_event #jumping to the next event
        self.avg_num_cus = self.tot_usage_customer/self.clock #calculating average number of customers in the system
        self.avg_queue_time = self.total_wait/self.clock #calculating the average queue time
        self.sv1_utilization = self.sv1_usagetime/self.clock
        self.sv2_utilization = self.sv2_usagetime/self.clock
        if ((self.t_arrival <= self.t_depart1) and (self.t_arrival <= self.t_depart2)):  #there are 4 probable situations here and I use these statements 
            self.handle_arrival_event()                                                     #to give priority to the earliest one
            self.total_num_cus += 1 #updating total number of customers
        elif ((self.t_arrival > self.t_depart1) and (self.t_arrival <= self.t_depart2)):
            self.handle_depart1_event()
        elif (self.t_depart1 <= self.t_depart2): #here departure from sv 1 has a priority
            self.handle_depart1_event()
        elif (self.t_depart1 > self.t_depart2):
            self.handle_depart2_event()
        
            
    def handle_arrival_event(self):
        if(self.num_in_queue <= 0 and self.num_in_sv1 < 1): #here the first server has a priority, when a customer comes first
            self.num_in_sv1 += 1                                                   # the availability of the 1st server is checked, if available, it is used
            svtime1 = self.generate_svtime1() #
            self.t_depart1 = self.clock + svtime1 #these 3 lines store the total time the server 1 is used
            self.sv1_usagetime += svtime1 # 
            self.num_arrivals += 1
            self.t_arrival = self.clock + self.generate_interarrival()
        elif(self.num_in_queue <= 0 and self.num_in_sv2 < 1): #if there is no queue and the first server is busy, second server is chosen and begins working
            self.num_in_sv2 += 1
            svtime2 = self.generate_svtime2() #
            self.t_depart2 = self.clock + svtime2 #these 3 lines store the total time the server 2 is used
            self.sv2_usagetime += svtime2 #
            self.num_arrivals += 1
            self.t_arrival = self.clock + self.generate_interarrival()
        else: #if both of the servers are busy, person enters the queue
            self.num_in_queue += 1
            self.totalqueuecust += 1
            self.num_arrivals += 1
            self.t_arrival = self.clock + self.generate_interarrival()
            
        
    def handle_depart1_event(self): #function to handle the departures of server 1
        self.num_in_sv1 -= 1
        self.num_departs += 1
        if (self.num_in_queue > 0):
            svtime1 = self.generate_svtime1() #
            self.t_depart1 = self.clock + svtime1 #these 3 lines store the total time the server 2 is used
            self.sv1_usagetime += svtime1 #
            self.num_in_sv1 += 1
            self.num_in_queue -= 1
        else:
            self.t_depart1 = float('inf')
            
    def handle_depart2_event(self): #function to handle the departures of server 2
        self.num_in_sv2 -= 1
        self.num_departs += 1
        if (self.num_in_queue > 0 and self.num_in_sv1 > 0):
            svtime2 = self.generate_svtime2() #
            self.t_depart2 = self.clock + svtime2 #these 3 lines store the total time the server 2 is used
            self.sv2_usagetime += svtime2 #
            self.num_in_sv2 += 1
            self.num_in_queue -= 1
        else:
            self.t_depart2 = float('inf')       
            
    def generate_interarrival(self): 
        return np.random.uniform(6,16)
    
    def generate_svtime1(self):
        return np.random.uniform(14,21)
    
    def generate_svtime2(self):
        x = np.random.uniform(0,1)
        if x < 0.18:
            return (8)
        elif x < 0.48:
            return (12)
        elif x < 0.78:
            return (22)
        else:
            return (33)
      
        
      
#BELOW I CREATED 4 DIFFERENT RANDOM SEEDS FOR 4 SimQuestion2bS AS DESCRIBED
np.random.seed(1)  
s1 = SimQuestion2b()
np.random.seed(2)
s2 = SimQuestion2b()
np.random.seed(3)
s3 = SimQuestion2b()
np.random.seed(4)
s4 = SimQuestion2b()


# REPORTING AND PRINTING PART IS BELOW

while 1:
    if s1.clock<=7000:
        s1.advance_time()
    else:
        print("Results for seed 1")
        print("Average queue time is: " , s1.avg_queue_time)
        print("Average number of customers in the system is: " , s1.avg_num_cus)
        print("The average utilization of server 1: " , s1.sv1_utilization)
        print("The average utilization of server 2: " , s1.sv2_utilization)
        print("Probability of Customer not waiting in the queue: ", 1-s1.totalqueuecust/s1.total_num_cus)
        print("------------------------------------------------------------")
        break
    
while 1:
    if s2.clock<=7000:
        s2.advance_time()
    else:
        print("Results for seed 2")
        print("Average queue time is: " , s2.avg_queue_time)
        print("Average number of customers in the system is: " , s2.avg_num_cus)
        print("The average utilization of server 1: " , s2.sv1_utilization)
        print("The average utilization of server 2: " , s2.sv2_utilization)
        print("Probability of Customer not waiting in the queue: ", 1-s2.totalqueuecust/s2.total_num_cus)
        print("------------------------------------------------------------")
        break

while 1:
    if s3.clock<=7000:
        s3.advance_time()
    else:
        print("Results for seed 3")
        print("Average queue time is: " , s3.avg_queue_time)
        print("Average number of customers in the system is: " , s3.avg_num_cus)
        print("The average utilization of server 1: " , s3.sv1_utilization)
        print("The average utilization of server 2: " , s3.sv2_utilization)
        print("Probability of Customer not waiting in the queue: ",1-s3.totalqueuecust/s3.total_num_cus)
        print("------------------------------------------------------------")
        break
    
while 1:
    if s4.clock<=7000:
        s4.advance_time()
    else:
        print("Results for seed 4")
        print("Average queue time is: " , s4.avg_queue_time)
        print("Average number of customers in the system is: " , s4.avg_num_cus)
        print("The average utilization of server 1: " , s4.sv1_utilization)
        print("The average utilization of server 2: " , s4.sv2_utilization)
        print("Probability of Customer not waiting in the queue: ", 1-s4.totalqueuecust/s4.total_num_cus)
        print("------------------------------------------------------------")
        print("------------------------------------------------------------")
        print("------------------------------------------------------------")
        break    

print("AVERAGES OF 4 DIFFERENT SEEDS AND ESTIMATE FOR THE SYSTEM")
print("Queue time estimate: " , (s4.avg_queue_time+s3.avg_queue_time+s2.avg_queue_time+s1.avg_queue_time)/4)
print("Average number of customers in the system estimate: " , (s4.avg_num_cus+s3.avg_num_cus+s2.avg_num_cus+s1.avg_num_cus)/4)
print("The average utilization of server 1 estimate: " , (s4.sv1_utilization+s3.sv1_utilization+s2.sv1_utilization+s1.sv1_utilization)/4)
print("The average utilization of server 2 estimate: " , (s4.sv2_utilization+s3.sv2_utilization+s2.sv2_utilization+s1.sv2_utilization)/4)
print("Probability of Customer not waiting in the queue estimate: ", ((1-s4.totalqueuecust/s4.total_num_cus)+(1-s3.totalqueuecust/s3.total_num_cus)+(1-s2.totalqueuecust/s2.total_num_cus)+(1-s1.totalqueuecust/s1.total_num_cus))/4)