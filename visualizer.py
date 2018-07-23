import matplotlib.pyplot as plt

file_in = open("Debug/result.txt", 'r') 
lines = file_in.readlines()

lower_bound = lines[0].split()
upper_bound = lines[1].split()

opt_d = lines[2].split()
opt_d_prime = lines[3].split()
opt_d_pprime = lines[4].split()

delta_s = float(lines[5])
init_d = float(lines[6])
init_d_prime = float(lines[7])
init_d_pprime = float(lines[8])

print("size of bounds:\t" + str(len(lower_bound)))
s = []
for i in range(len(lower_bound)):
    s.append(delta_s * i) 
    
d_ref = [0.0] * len(lower_bound) 


for t in lower_bound:
    t = float(t)
for t in upper_bound:
    t = float(t)
for t in opt_d:
    t = float(t)
for t in opt_d_prime:
    t = float(t)
for t in opt_d_pprime:
    t = float(t)

upperlimits = 2.0
lower_limits = -2.0

plt.title("Optimization Result for Lateral Trajectory")
plt.axes().set_aspect('equal', 'datalim')
plt.ylim(lower_limits, upperlimits)
plt.plot(s, lower_bound, 'r-')
plt.plot(s, upper_bound, 'r-')
plt.plot(s, d_ref, 'y-')
plt.plot(s, opt_d, 'b-')
plt.xlabel("s")
plt.ylabel("d")
plt.show()  


plt.title("Optimization Result for Lateral Trajectory: d")
plt.axes().set_aspect('equal', 'datalim')
plt.plot(s, opt_d, 'r-')
plt.plot([0.0], [init_d], 'b*')
plt.xlabel("s")
plt.ylabel("d")
plt.show()    