# pandas is  a data anallysis toolkit
import pandas as pd 
# numpy is a high performance lib for calculations and allows us to use arrays
import numpy as np 
# quandl is for getting data samples
# math is for common math related functions
import quandl, math 
# sklearn is a machine learning lib 
# preprocessing is for scaling data(usually done on features) 
# cross_validation is for creation of training and testing data for stats 
# cross_validation is replaced by model_selection
# svm is for regression
from sklearn import preprocessing, model_selection, svm
# 
from sklearn.linear_model import LinearRegression
# df = data frame, quandle.get('quadl code for data')
df = quandl.get('WIKI/GOOGL')
# only include these columns(features)
df = df[ ['Adj. Open', 'Adj. High', 'Adj. Low', 'Adj. Close', 'Adj. Volume'] ]
# defining new column that is equal to (high - close) / close * 100
df['HL_PCT'] =(df['Adj. High'] - df['Adj. Close']) / df['Adj. Close'] * 100.0
# defining a new column that is equal (new - old) / old * 100
df['PCT_change'] =(df['Adj. Close'] - df['Adj. Open']) / df['Adj. Open'] * 100.0
# define a new data frame with only columns we actually care about
df = df[ ['Adj. Close', 'HL_PCT', 'PCT_change', 'Adj. Volume'] ]
# the variable to predict?
forcast_col = 'Adj. Close'
# just in case there is not missing data fill, you can only with with data
df.fillna('-99999', inplace=True)
# regression algorithm = an integer that is equal the length of df * 0. 01(%1) 
forcast_out = int(math.ceil(0.01 * len(df)))
# now that we have forcast out we need a label for its values, (-)=shift up
df['label'] = df[forcast_col].shift(-forcast_out)
# you cannot work with nan data
df.dropna(inplace=True)
# features
X = np.array(df.drop(['label'], 1))
#
X = preprocessing.scale(X)
# prediction
X_lately = X[-forecast_out:]
#
X = X[:-forcast_out]
# labels
Y = np.array(df['label'])
# shuffles data to return arrays that can be used to train or test
X_train, X_test, Y_train, Y_test = model_selection.train_test_split(X, Y, test_size=0.2)
# clasifier 
clf = LinearRegression(n_jobs=10)
# fitting or training
clf.fit(X_train, Y_train)
# testing clasifier
accuracy = clf.score(X_test, Y_test)

forcast_set

print(accuracy)


