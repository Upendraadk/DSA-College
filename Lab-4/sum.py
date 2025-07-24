def sum(n,a):
    if n==0:
        return a
    else:
        return sum(n-1,a+n)
n = int(input("Enter the number: "))
print(f"The sum upto {n} is: {sum(n, 0)}")
