
# type -> python double_scatter.py 'found_injections.txt' 'missed_injections.txt'

import matplotlib.pyplot as plot # scatter
from sys import argv # to collect input from terminal

def start(): # setup
	# this is the window showing the plot
	fig = plot.figure() 
	# to this figure add a subplot with dimentions (x, y, subplot_number) 
	axis = fig.add_subplot(1, 1, 1) 
	# load marked
	x_marked, y_marked = load(marked, 2, 5)
	# plot marked
	axis.scatter(x_marked, y_marked, c='b', marker='o', label='Found Injections')
	# load missed
	x_missed, y_missed =  load(missed, 1, 3) 
	# plot missed
	axis.scatter(x_missed, y_missed, c='r', marker='x', label='Missed Injections')
	# name the graph
	plot.title('BayesWave All: missed %d found %d' % (len(x_missed), len(x_marked)))
	# name the axis 
	plot.xlabel('Injected SNR')
	plot.ylabel('Injected Frequency (Hz)')
	# plot legend
	axis.legend(loc='lower right')
	# show the plot
	plot.show()

def load(file, x_col, y_col): # reads data from files with these columns
	# initialized to empty lists
	x = []
	y = []
	
	with open(file, 'r') as data:
		# split and collect the usable data
		for line in data:
			words = line.split() # splits line into word list
			x.append(float(words[x_col]))
			y.append(float(words[y_col]))
		
	return (x, y) # return tuple of lists
	
script, marked, missed = argv

start()
