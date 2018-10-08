import collections
n = int(input('Enter no of processes: '))
bt,p =[],[]
d={}
for i in range(n):
    pr = int(input('Enter the priority for process ' +str(i+1)+ ': ' ))
    btime = int(input('Enter the burst time for process ' +str(i+1)+ ': ' ))
    d[pr]=btime
#print(d)

od = collections.OrderedDict(sorted(d.items()))

for k,v in od.items():
    p.append(k)
    bt.append(v)


#print(p)
#print('Burst Time:',bt)
ct=[]
t=0
for v in range(n):
    #print(d[i+1])
    t=int(t)+int(d[v+1])
    ct.append(t)
#print('Completion Time:', ct)
wt=[]
wt.append(0)
for i in range(n-1):
    wt.append(ct[i])
#print('Waiting Time:',wt)
tat=[]
for i in range(n):
    tat.append(wt[i]+bt[i])
#print('Turnaround Time:',tat)

print('BT\tCT\tTAT\tWT')
for i in range(len(ct)):
	print("{}\t{}\t{}\t{}\n".format(bt[i],  ct[i], tat[i], wt[i]))
print('Average Waiting Time = ', sum(wt)/len(wt))
print('Average Turnaround Time = ', sum(tat)/len(tat))
