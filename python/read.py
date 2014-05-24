import re
f=open('random.txt','r')
s=f.read()
s1 = re.split(' ',s)
for i in s1:
  if not i.isalnum() and int(i)%7==0:
    print i
