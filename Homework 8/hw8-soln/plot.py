import csv
import matplotlib.pyplot as plt

# read data
N = []
V = []
S = []
US = []
with open('output.csv') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    for row in csv_reader:
        N.append(float(row[0]))
        V.append(float(row[1]))
        S.append(float(row[2]))
        US.append(float(row[3]))
    
plt.figure(dpi=300)
plt.plot(N, V, 'r', label='Array') # plot vector timings in red
plt.plot(N, S, 'g', label='Balanced BST') # plot set timings in green
plt.plot(N, US, 'b', label='Hash Table') # plot unordered_set timings in blue
plt.xlabel('Number of Stored Elements (N)')
plt.ylabel('Average Search Time (seconds)')
plt.legend()
#plt.show()
plt.savefig('output.png')
