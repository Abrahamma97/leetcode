strs = ["neet","code","love","you"]
res = ""
for s in strs:
    res = res+ str(len(s)) + s+ "#"


strs = []
a = []
strs = res.split('#')
for i,s in enumerate(strs):
    if(s == '' or (not(s[0].isnumeric())) or int(s[0]) != len(s)-1):
        strs.pop(i)
    else:
        a.append(s[1::])    
        

