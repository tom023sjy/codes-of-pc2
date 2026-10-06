from os import system
system("g++ triangle.cpp -std=c++14 -O2 -lm -o run")
for i in range(1, 7):
    print("Test", i)
    system(f"copy samples\\{i}.in triangle.in")
    system(f"copy samples\\{i}.ans triangle.ans")
    system("run")
    if system("fc /w triangle.out triangle.ans"):
        system("pause")
    system("del triangle.in")
    system("del triangle.out")
    system("del triangle.ans")