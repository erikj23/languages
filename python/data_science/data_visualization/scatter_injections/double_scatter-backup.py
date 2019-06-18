
# type -> python (script path) (marked file path) (missed file path)

import matplotlib.pyplot as plot
from sys import argv

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

def load(file, x_col, y_col): # reads data from files
	# initialized to empty lists
	x = []
	y = []
	# column 3, 6 (marked) column 2, 4 (missed)
	with open(file, 'r') as data:
		# strip the unusable data and collect the usable data
		for line in data:
			words = line.split() # splits line into words
			x.append(float(words[x_col]))
			y.append(float(words[y_col]))
		
	return (x, y)
	
script, marked, missed = argv

start()
