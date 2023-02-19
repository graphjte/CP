n, t = map(int, input().split(" "))
tree = [0]

for i in range(1, n+1):
    tree.append(list(input().split(" ")))

print(tree)

has = {}
res = []

def travel(node):
    if (tree[node][0]=="L"):
        res.append(tree[node][2])
        return
        
    yesNode = int(tree[node][3])
    noNode = int(tree[node][4])
    if (tree[node][2] in has):
        travel(yesNode)
    
    else:
        travel(yesNode)
        travel(noNode)
        
    


        

for i in range(t):
    str = input()
    has = {}
    res = []
    for char in str:
        has[char] = True
    
    travel(1)
    res.sort()
    for item in res:
        print(item, end = ' ')
    # if (has[tree[curNode[2]]]):
        # -> yes
    print("")
    
