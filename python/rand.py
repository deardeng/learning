f=open('random.txt','w')
i=0
import random
while i<100:
  a=random.randint(1,1000);
  f.write(str(a)+'\n')
  i=i+1
f.close()
