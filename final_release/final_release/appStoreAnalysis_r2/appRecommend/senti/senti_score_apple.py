import subprocess
import shlex
import nltk
import string
from nltk.corpus import stopwords
stopword = stopwords.words('english')
from nltk.stem import WordNetLemmatizer 
lemmatizer = WordNetLemmatizer()

def RateSentiment(sentiString):
    #open a subprocess using shlex to get the command line string into the correct args list format
    #Modify the location of SentiStrength.jar and D:/SentiStrength_Data/ if necessary
    p = subprocess.Popen(shlex.split("java -jar SentiStrength.jar stdin sentidata SentiStrength_Data/"),stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    #communicate via stdin the string to be rated. Note that all spaces are replaced with +
    #Can't send string in Python 3, must send bytes
    b = bytes(sentiString.replace(" ","+"), 'utf-8')
    stdout_byte, stderr_text = p.communicate(b)
    #convert from byte
    stdout_text = stdout_byte.decode("utf-8") 
    #replace the tab with a space between the positive and negative ratings. e.g. 1    -5 -> 1 -5
    stdout_text = stdout_text.rstrip().replace("\t"," ")
    return stdout_text
#An example to illustrate calling the process.


f=open("output_apple_text_reviews.txt","r", encoding="utf8")

data = f.read()
l = data.split('\n')

p = []
for i in l:
    if(i!=''):
        p.append(i)

f.close()
# print(p)
# print()

f1 = open("stop_word_list.txt", "r")
stop_data = f1.read()
stop_list = stop_data.split('\n')
f1.close()

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
    print(RateSentiment(refined_review))
# print(RateSentiment("It is an amazing and interesting game , anybody , anywhere, anytime can play this game"))

#The above is OK for one text but inefficient to repeatedly call for many texts. Try instead: 
#  either modify the above to submit a file
#  or modify the above to send multiple lines through multiple calls of p.communicate(b)
