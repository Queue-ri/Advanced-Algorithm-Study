def quadtree(location, idx):
    word = location[idx]
    if word == 'w' or word == 'b':
        return word
    idx = idx + 1
    a = quadtree(tree, idx)
    idx = idx + len(a)
    b = quadtree(tree, idx)
    idx = idx + len(b)
    c = quadtree(tree, idx)
    idx = idx + len(c)
    d = quadtree(tree, idx)
    return 'x'+c+d+a+b

case = int(input())
for _ in range(case):
    tree = input()
    print(quadtree(tree,0))