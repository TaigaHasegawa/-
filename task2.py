import numpy as np 

filename="task2-sample-input.txt"

sample=open(filename,"r")
matrix=sample.readlines()[1:]

for i,line in enumerate(matrix):
    if line=="\n":
        N=int(matrix[i+1])
        X=[0]*N
        Y=[0]*N
        for j in range(N-1):
            X[j],Y[j]=map(int,matrix[i+j+1].split(" "))
        X=np.array(X)
        Y=np.array(Y)
        connection={}
        for j in range(N):
            connection[j+1]=[]
            connection[j+1].append(Y[X==j])
            connection[j+1].append(X[Y==j])
        dis_lists=[]
        for j in range(N):
            dis_list=[]
            dis={}
            switch=True
            s_pre=j+1
            while switch:
                for s in connection[s_pre]:
                    if s!=j+1:
                        dis[s]=dis[s_pre]+1
                    else:
                        dis_list.append(dis[s])
                    for s_pre=s
                
                


        