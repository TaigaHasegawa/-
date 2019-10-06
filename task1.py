import numpy as np 

filename="task1-test-input.txt"

sample=open(filename,"r")
matrix=sample.readlines()[1:]

best_prices=[]

for i,line in enumerate(matrix):
    if line=="\n":
        X=int(matrix[i+1])
        N=int(matrix[i+2])
        flavor_name=[0]*N
        flavor_price=[0]*N
        for j in range(N):
            flavor_name[j],flavor_price[j]=matrix[i+2+j+1].split(" ")
        M=int(matrix[i+N+3])
        option_name=[0]*M
        option_price=[0]*M
        for j in range(M):
            option_name[j],option_price[j]=matrix[i+N+3+j+1].split(" ")
        best_price=int(flavor_price[0])
        for flavor in flavor_price:
            price=0
            price+=int(flavor)
            if np.abs(X-price)==np.abs(X-best_price):
                best_price=min(price,best_price)
            if np.abs(X-price)<np.abs(X-best_price):
                best_price=price
            for j,option in enumerate(option_price):
                price+=int(option)
                if np.abs(X-price)==np.abs(X-best_price):
                    best_price=min(price,best_price)
                if np.abs(X-price)<np.abs(X-best_price):
                    best_price=price
                ind=[True]*M
                ind[j]=False
                for option_more in np.array(option_price)[ind]:
                    price+=int(option_more)                    
                    if np.abs(X-price)==np.abs(X-best_price):
                        best_price=min(price,best_price)
                    if np.abs(X-price)<np.abs(X-best_price):
                        best_price=price
                    price=int(flavor)
        best_prices.append(best_price)

output_file_name="output-file"

sentence=[]
for i,best_price in enumerate(best_prices):
    s="Case #{}: {}".format(i,best_price)
    sentence.append(s)
with open(output_file_name,"w") as f:
    f.write('\n'.join(sentence))

                


