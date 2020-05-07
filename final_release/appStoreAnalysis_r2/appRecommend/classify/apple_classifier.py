import subprocess
import shlex
import pandas as pd
import numpy as np
import pickle
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LogisticRegression
from sklearn.multiclass import OneVsRestClassifier
import nltk
import string
from nltk.corpus import stopwords
stopword = stopwords.words('english')
from nltk.stem import WordNetLemmatizer 
lemmatizer = WordNetLemmatizer()

f=open("apple.txt","r", encoding="utf8")

data = f.read()
l = data.split('\n')
p = []
for i in l:
    if(i!=''):
        p.append(i)
f.close() 

f1 = open("stop_word_list.txt", "r")
stop_data = f1.read()
stop_list = stop_data.split('\n')
f1.close()

refined_p = []

for contents in p:
    # remove numeric digits
    output = ''.join(c for c in contents if not c.isdigit())
    # remove punctuation and make lower case
    output = ''.join(c for c in output if c not in string.punctuation)
    norm_contents = output.lower()
    words = nltk.word_tokenize(norm_contents)
    removed_stopwords = [word for word in words if word not in stopword]
    removed_stopwords = [word for word in removed_stopwords if word not in stop_list]
    lemmatized = [lemmatizer.lemmatize(word) for word in removed_stopwords]
    refined_review = ' '.join([str(elem) for elem in lemmatized])
    refined_p.append(refined_review)

size = len(refined_p)
test_text = np.asarray(refined_p)

vectorizer = pickle.load(open("vectorizer.pickle", "rb"))

x_test = vectorizer.transform(test_text)

classifier_b = pickle.load(open("classifier_b.pickle", "rb"))
classifier_f = pickle.load(open("classifier_f.pickle", "rb"))
classifier_r = pickle.load(open("classifier_r.pickle", "rb"))
classifier_u = pickle.load(open("classifier_u.pickle", "rb"))

prediction_b = classifier_b.predict(x_test)
prediction_f = classifier_f.predict(x_test)
prediction_r = classifier_r.predict(x_test)
prediction_u = classifier_u.predict(x_test)

f2 = open("apple_output.txt", "w", encoding="utf8")

for i in range(prediction_b.shape[0]):
	label = p[i]
	label += "\n Tags: "
	count = 0
	if prediction_b[i] == 1:
		count += 1
		label += "bug_report "
	if prediction_f[i] == 1:
		count += 1
		label += "feature_request "
	if prediction_u[i] == 1:
		count += 1
		label += "user_experience "
	if prediction_r[i] == 1:
		count += 1
		label += "rating"
	if count == 0:
		label += "rating"

	label += "\n\n"
	f2.write(label)

f2.close()