
import random
import numpy as np
import matplotlib.pyplot as plot

i = 1
n = 10000
x = random.uniform(-1.0, 1.0)
c = p(3)
print c

while i < n:
	y = 1
	
def p(xi,theta=1, mu=1):
	a = 1.0 / (np.sqrt(2 * np.pi) * theta)
	exponent = -1 * (np.pow(x - theta, 2) / (2 * np.pow(theta, 2))) # x?
	draw = a * np.pow(np.e, exponent)
	return draw
