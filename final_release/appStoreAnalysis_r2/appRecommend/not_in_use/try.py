f=open("output_google_text_reviews.txt","r", encoding="utf8")
review=""
i=0
l=[]
for temp in f:
    if temp=="\n" :
        l.append(review)
        i+=1
        review=""

    else:
        review+=temp          
f.close()