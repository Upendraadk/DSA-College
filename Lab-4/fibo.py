table = [0] * 100
def fibo(n):
    if n==1 or n==2 :
        return 1
    else:
        if table[n]==0:
            table[n]=fibo(n-1)+fibo(n-2)
        return table[n]
    
n = int(input("Enter n:"))
print(f"The {n}th term is {fibo(n)}")
