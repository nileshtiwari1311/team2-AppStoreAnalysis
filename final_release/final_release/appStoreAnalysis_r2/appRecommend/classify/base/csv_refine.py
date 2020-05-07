import csv
import numpy as np
import pandas as pd
import seaborn as sns

def refine_data():
    with open('processed.csv','r', encoding='utf-8') as dest_f:
        data_iter = csv.reader(dest_f, delimiter = ",")
        data = [data for data in data_iter]
    data_array = np.asarray(data)

    for i in range(data_array.shape[0]):
        if len(data_array[i]) == 5 :
            data_array[i][1] = data_array[i][1].replace('"','')
            data_array[i][1] = data_array[i][1].replace('...\nFull Review','')
            data_array[i][1] = data_array[i][1].replace('\n','')
            data_array[i][1] = data_array[i][1].replace('/','')
            data_array[i][1] = data_array[i][1].replace('\n','')
            data_array[i][1] = data_array[i][1].replace('be...','')
            data_array[i][3] = data_array[i][3].replace('Rated','')
            data_array[i][3] = data_array[i][3].replace('stars out of five stars','')
            data_array[i][3] = data_array[i][3].replace(' ','')

    ds = []
    for i in range(data_array.shape[0]):
        temp = []
        for j in range(len(data_array[0])):
            try:
                temp.append(data_array[i][j])
            except:
                continue
        if len(temp) != 5:
            continue
        if temp[2] == "":
            temp[2] = "0"
        if temp[0] != "" and temp[4] != "":
            ds.append(temp)

    with open("refined.csv", "w", encoding='utf-8') as f:
        writer = csv.writer(f)
        writer.writerows(ds)

refine_data()