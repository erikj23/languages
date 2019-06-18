
# type -> python scatterplot.py 'data.txt' 'x_col' 'y_col'

import matplotlib.pyplot as plot # scatter
from sys import argv # to collect input from terminal

def start(): #setup
	# this is the window showing the plot
	fig = plot.figure() 
	# to this figure add a subplot with dimentions (x, y, subplot_number) 
	axis = fig.add_subplot(1, 1, 1) 
	# collect all the values to be plotted and store in lists
	x, y =  load(datafile)
	# x and y
	axis.scatter(x, y, c='r', marker='x', label='Injections')
	# name the graph
	plot.title('BayesWave All: missed %d found %d' % (len(x), len(x)))
	# name the axis 
	plot.xlabel('Injected SNR')
	plot.ylabel('Injected Frequency (Hz)')
	# plot legend
	axis.legend(loc='lower right')
	# show the plot
	plot.show()
	
def load(datafile): # reads data from files
	# initialized to empty lists
	x = []
	y = []
	# read a file safely 
	with open(datafile, 'r') as data:
		# split and collect the usable data
		for line in data:
			words = line.split() # splits line into word list
			x.append(float(words[int(x_col)]))
			y.append(float(words[int(y_col)]))
		
		
	return (x, y)
	
script, datafile, x_col, y_col = argv

start()