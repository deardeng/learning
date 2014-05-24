import re
f=open('random.txt','r')
s=f.read()
s1 = re.split(' ',s)
for i in s1:
###  if i.isdigit():
###    a = int(i)
###  if a%7==0:
###    print a
  if i.isdigit() :
    if int(i)%7 == 0:
      print i
