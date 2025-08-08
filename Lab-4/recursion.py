def tail_fact(n, a):
    if n == 1:
        return a
    else:
        return tail_fact(n - 1, a * n)

n = int(input("Enter the number: "))
print(f"The factorial of {n} is: {tail_fact(n, 1)}")
