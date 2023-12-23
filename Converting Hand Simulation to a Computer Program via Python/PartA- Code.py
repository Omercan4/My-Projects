import numpy as np


#I CREATED A CLASS CALLED SIMULATION TO EASILY CREATE THE MODEL IN OBJECT ORIENTED MANNER

random = [0.380, 0.496, 0.832, 0.391, 0.020, 0.480, 0.975, 0.759, 0.905, 0.593, 0.560] #these are the random values
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
        self.reporter()
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
            self.num_in_sv1 += 1   
            self.t_arrival = self.clock + self.generate_interarrival()                                                # the availability of the 1st server is checked, if available, it is used
            svtime1 = self.generate_svtime1() #
            self.t_depart1 = self.clock + svtime1 #these 3 lines store the total time the server 1 is used
            
            self.sv1_usagetime += svtime1 # 
            self.num_arrivals += 1
            
            
        elif(self.num_in_queue <= 0 and self.num_in_sv2 < 1): #if there is no queue and the first server is busy, second server is chosen and begins working
            self.num_in_sv2 += 1
            self.t_arrival = self.clock + self.generate_interarrival()
            svtime2 = self.generate_svtime2() #
            self.t_depart2 = self.clock + svtime2 #these 3 lines store the total time the server 2 is used
            
            self.sv2_usagetime += svtime2 #
            self.num_arrivals += 1
            
            
        else: #if both of the servers are busy, person enters the queue
            self.num_in_queue += 1
            self.t_arrival = self.clock + self.generate_interarrival()
            self.totalqueuecust += 1
            self.num_arrivals += 1
            
            
        
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
        x = random[0]
        random.remove(random[0])
        print("Arrival at: ", self.clock+(6+x*10))
        return (6+x*10)
        
        
    
    
    def generate_svtime1(self):
        x = random[0]
        random.remove(random[0])
        print("Departure form sv 1 at: ", self.clock+(14+x*7))
        return (14+x*7)
        
   
          
    def generate_svtime2(self):
        x = random[0]
        if x < 0.18:
            random.remove(random[0])
            print("Departure form sv 2 at: ", self.clock+8)
            return (8)
            
        elif x < 0.48:
            random.remove(random[0])
            print("Departure form sv 2 at: ", self.clock+12)
            return (12)
            
        elif x < 0.78:
            random.remove(random[0])
            print("Departure form sv 2 at: ", self.clock+22)
            return (22)
            
        else:
            random.remove(random[0])
            print("Departure form sv 2 at: ", self.clock+33)
            return (33)
            
    def reporter(self):
          print("-----------------------------------")
          print("LS1 at", self.clock, "= ", self.num_in_sv1)
          print("LS2 at", self.clock, "= ", self.num_in_sv2)
          print("LSQ at", self.clock, "= ", self.num_in_queue)   
          print("-----------------------------------")
      
#BELOW I CREATED 4 DIFFERENT RANDOM SEEDS FOR 4 SimQuestion2bS AS DESCRIBED
np.random.seed(1)  
s1 = SimQuestion2b()



# REPORTING AND PRINTING PART IS BELOW

while 1:
    if s1.clock<=35:
        s1.advance_time()
    else:
        break
    


