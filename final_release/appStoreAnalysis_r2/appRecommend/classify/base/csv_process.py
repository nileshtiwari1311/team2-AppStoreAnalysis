import csv
import numpy as np
import pandas as pd
import seaborn as sns

def process_data(serial_no):
    with open('test'+str(serial_no)+'.csv','r', encoding='utf-8') as dest_f:
        data_iter = csv.reader(dest_f, delimiter = ",")
        data = [data for data in data_iter]
    data_array = np.asarray(data)

    data_array.reshape(5,-1)

    ds = []
    columns = ['Name','Review','UpVotes','Rating','Date']
    if serial_no == 1 :
        ds.append(columns)

    for j in range(len(data_array[0])):
        temp = []
        for i in range(data_array.shape[0]):
            try:
                temp.append(data_array[i][j])
            except:
                continue
        if len(temp) == 5:
            ds.append(temp)

    with open("processed.csv", "a", encoding='utf-8') as f:
        writer = csv.writer(f)
        writer.writerows(ds)

for i in range(1,29):
    process_data(i)