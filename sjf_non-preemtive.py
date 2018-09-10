BT=[]
BT.append(int(input("Enter Burst Time of P1\n")))
BT.append(int(input("Enter Burst Time of P2\n")))
BT.append(int(input("Enter Burst Time of P3\n")))
BT.append(int(input("Enter Burst Time of P4\n")))
BT.sort()
x=len(BT)-1
AWT,TAT=0,0
j=0
for i in range (x,0,-1):
    AWT=AWT+(BT[j]*(x-j))
    j=j+1
AWT=AWT/(len(BT))
print("Average Waiting Time is: ",AWT)
j=0
for i in range (x+1,0,-1):
    TAT=TAT+(BT[j]*(x-j+1))
    j=j+1
print("Turn Around Time is: ",TAT/(len(BT)))
print("Average Response Time is: ",AWT) #As waiting time is zero WT=RT
