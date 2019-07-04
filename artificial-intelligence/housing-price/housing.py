import pandas as pd

dataset = pd.read_csv("kc_house_data.csv")

X = dataset.iloc[:,[3,4,7,14]].values
y = dataset.iloc[:, 2].values


# Splitting the dataset into the Training set and Test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.25, random_state = 0)

# Feature Scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Training the dataset
from sklearn.linear_model import LinearRegression
lin = LinearRegression()
lin.fit(X_train,y_train)

# Testing the dataset on trained model
y_pred = lin.predict(X_test)
score = lin.score(X_test,y_test)*100
print("Accuracy on test set: ")
print("R square value:" , score)

# Testing with a custom input
# Features: [beds, baths, floors, yearbuilt]
# Label: [total]
import numpy as np
test_x = [3,2,3,2011]
print("New Prediction input: ", test_x)
new_prediction = lin.predict(sc.transform(np.array([test_x])))
print("Prediction score:" , new_prediction)
