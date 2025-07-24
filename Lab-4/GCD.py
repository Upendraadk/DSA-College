def gcd(a , b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))
print(f"The GCD of two numbers is: {gcd(a, b)}")
