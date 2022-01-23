comp_quad = ""
idx = 0

def upside_down():
    global idx
    cell = comp_quad[idx]
    idx += 1
    if cell == 'b' or cell == 'w':
        return cell

    s1 = upside_down()
    s2 = upside_down()
    s3 = upside_down()
    s4 = upside_down()

    return "x" + s3 + s4 + s1 + s2


TC = int(input())
for _ in range(TC):
    comp_quad = input()
    idx = 0
    print(upside_down())
    
