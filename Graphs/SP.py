import math
from queue import PriorityQueue
G={
    's':{'t':10, 'y':5},
    't':{'x':1, 'y':2},
    'x':{'z':4},
    'y':{'t':3, 'x':9, 'z':2},
    'z':{'s':7, 'x':6},

}
def DJ(G,s):
     cost = {}         #initialize a dictionary to store cost
     prev = {}         #initialize a dictionary to store cost
     for vertex in G.keys():
        cost[vertex] = math.inf
        prev[vertex] = " "
     cost[s] = 0
     visited =list()
     PQ = PriorityQueue()
     for vertex in G.keys():
         PQ.put((cost[vertex],vertex))
    #Repeat until all the vertices are visited
     while(len(visited)) != len(G.keys()):
       _, currentVertex = PQ.get()
       visited.append(currentVertex)
       for chimeki in G[currentVertex].keys():
           if chimeki not in visited:
                if cost[chimeki]>cost[currentVertex] + G[currentVertex][chimeki]:
                   cost[chimeki] = cost[currentVertex] + G[currentVertex][chimeki]
                   prev[chimeki] = currentVertex
                   PQ.put((cost[chimeki],chimeki))
     return cost,prev     

source = 's'
cost,prev=DJ(G, source)
print(cost)
print(prev)