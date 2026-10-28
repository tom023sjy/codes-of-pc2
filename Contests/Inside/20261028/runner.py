prob = ""





from os import system
if system(f"g++ {prob}.cpp -std=c++14 -O2 -Wall -o {prob}"):
    print("CE!")
    exit(1)
if system(f"time ./{prob}"):
    print("RE!")
    exit(2)
if system(f"diff -BZ {prob}.out {prob}.ans"):
    print("WA!")
    exit(3)
print("AC!")
exit(0)