import random

l = [i for i in range(10000)]
random.shuffle(l)
f = open("test_1.txt", "w")
f.writelines(["%s\n" % item for item in l])
