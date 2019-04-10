## This program shows the xy-coordinate plot animation for Water Jug problem.
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

def update_line(num, data, line):
    line.set_data(data[..., :num])
    return line,

fig1 = plt.figure()

# get data from file
# data from fill1
data1Bucket1 = []
data1Bucket2 = []
with open("branchFill1.txt", "r") as file:
    # get max stored on top
    line = file.readline()
    maxBucket1, maxBucket2 = line.split()
    # get buckets into data array
    for line in file:
        b1, b2 = line.split(" ")
        data1Bucket1.append(int(b1))
        data1Bucket2.append(int(b2))
data1Bucket1 = np.array(data1Bucket1)
data1Bucket2 = np.array(data1Bucket2)
data1Buckets = np.array([data1Bucket1, data1Bucket2])

# data from fill2
data2Bucket1 = []
data2Bucket2 = []
with open("branchFill2.txt", "r") as file:
    # get buckets into data array
    for line in file:
        b1, b2 = line.split(" ")
        data2Bucket1.append(int(b1))
        data2Bucket2.append(int(b2))
data2Bucket1 = np.array(data2Bucket1)
data2Bucket2 = np.array(data2Bucket2)
data2Buckets = np.array([data2Bucket1, data2Bucket2])

l1, = plt.plot([], [], 'r-', linewidth=3)
l2, = plt.plot([], [], 'g-', linewidth=3)
# format animation
plt.legend((l1, l2),('Fill Bucket 1 Branch','Fill Bucket 2 Branch'),loc='center left', bbox_to_anchor=(1, 0.5))
plt.xlim(0, int(maxBucket1))
plt.ylim(0, int(maxBucket2))
plt.xlabel('Smaller Bucket')
plt.ylabel('Larger Bucket')
plt.title('The Buckets Problem')
plt.axes().set_aspect('equal')
# animation
animationFill1 = animation.FuncAnimation(fig1, update_line, 40, fargs=(data1Buckets, l1), interval=1000)
animationFill2 = animation.FuncAnimation(fig1, update_line, 40, fargs=(data2Buckets, l2), interval=1000)

plt.show()
file.close()