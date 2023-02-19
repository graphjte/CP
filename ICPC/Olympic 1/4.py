L = int(input(),16)
R = int(input(),16)

Hex = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A' , 'B', 'C', 'D', 'E', 'F']

Map = {'0':0,'1':1,'2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,'a':10,'b':11,'c':12,'d':13,'e':14,'f':15}

def Calc(n):  
    sum = 0
    for i in range(2,len(n)): 
      sum += int(Map[n[i]])      
    return sum

res = 1;
for i in range(L,R+1):
	res*=i;

res = (res)

while (res>15):
	res = Calc(hex(res))

print(Hex[res])
