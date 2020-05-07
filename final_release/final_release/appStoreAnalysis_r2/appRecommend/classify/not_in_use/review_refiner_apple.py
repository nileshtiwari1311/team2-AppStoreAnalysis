import subprocess
import shlex

f=open("apple.txt","r", encoding="utf8")

data = f.read()
l = data.split('\n')
p = []
for i in l:
    if(i!=''):
        p.append(i)
f.close()

import nltk
import string
from nltk.corpus import stopwords
stopword = stopwords.words('english')
from nltk.stem import WordNetLemmatizer 
lemmatizer = WordNetLemmatizer() 

f1 = open("stop_word_list.txt", "r")
stop_data = f1.read()
stop_list = stop_data.split('\n')
f1.close()

f2 = open("apple_refine.txt", "w", encoding="utf8")

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
    f2.write(refined_review)
    f2.write("\n")

f2.close()
