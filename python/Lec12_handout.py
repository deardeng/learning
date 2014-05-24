def fib(n):
    global numCalls
    numCalls +=1
    print 'call fib', n
    if n<=1:
        return n
    else:
        return fib(n-1)+fib(n-2)
numCalls = 0
##fib(5)

n = 100
print 'fib_', n, '=','\n', fib(n)
print 'call times', numCalls
    
            
