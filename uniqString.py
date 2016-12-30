'''n = int(input().strip())'''
grid = []
'''grid_i = 0
for grid_i in range(n):
    grid_t = str(input().strip())
    grid.append(grid_t)'''
grid=['1112','1912','1892','1234']
for x in range(len(grid)):
    if(x==0 or x==len(grid)-1):
        continue
    else:
        for y in range(len(grid)):
            if(y==0 or y==(len(grid)-1)):
                continue
            else:
                if(grid[x][y]>grid[x][y-1] and grid[x][y]>grid[x][y+1] and grid[x][y]>grid[x-1][y] and grid[x][y]>grid[x+1][y]):
                    l=list(grid[x])
                    l[y]='X'
                    "".join(l)
                    grid[x]=l
print(grid) 
