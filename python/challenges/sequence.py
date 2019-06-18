
seq1="ataatata"
seq2="attatac"
seq3="pwwwkew"

def dna(seq):
    slen=len(seq)
    temp=""
    seti={}
    for x in range(slen-9):
        temp=seq[x:x+10]
        if temp in seti:
            seti[temp]+=1
        else:
            seti[temp]=0
            result=[]
            for e in seti.keys():
                if seti[key] > 0:
                    result.append((key, seti[e]))
                return result
             
print(dna(seq1))
print(dna(seq2))
print(dna(seq3))

