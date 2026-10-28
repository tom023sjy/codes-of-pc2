prob = ""
case = 
TTL = 2



from os import system
if not system(f"ls | grep {prob}.in 1>/dev/null"):
    print("File Exist!")
    exit(-1)
if system(f"ls | grep {prob}.cpp 1>/dev/null"):
    print("Can't Complete!")
    exit(-2)
if system(f"g++ {prob}.cpp -std=c++14 -O2 -Wall -o {prob}"):
    print("CE!")
    exit(1)
for i in range(1, case + 1):
    print("Test case", i, ":", end=" ")
    if system(f"ls | grep {prob}{i}.in 1>/dev/null"):
        print("Not found")
        exit(-3)
    if system(f"ls | grep {prob}{i}.ans 1>/dev/null"):
        print("Not found")
        exit(-3)
    system(f"mv {prob}{i}.in {prob}.in")
    cod = system(f"timeout {TTL} time ./{prob}")
    system(f"mv {prob}.in {prob}{i}.in")
    if cod == 124:
        print("TLE!")
        exit(2)
    if cod:
        print("RE!")
        exit(3)
    if system(f"diff -BZ {prob}.out {prob}{i}.ans 1>/dev/null 2>&1"):
        print("WA!")
        exit(4)
    print("AC!")