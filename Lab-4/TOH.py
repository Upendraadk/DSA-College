import time

def TOH(n, src, dst, temp):
    if n==1:
        print(f"Move disk {n} from {src} to {dst}")
    else:
        TOH(n-1, src, temp, dst)
        print(f"Move disk {n} from {src} to {dst}")
        TOH(n-1, temp, dst, src)

n = int(input("Enter number of disks:"))

start_time = time.time()
TOH(n, 'A', 'C','B')
end_time = time.time()

print(f"Time taken: {end_time - start_time:.6f} seconds")