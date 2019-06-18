
istr1="abcabcbb"
istr2="bbbbbakldsjapoiepgfbaasd"
istr3="pwwkew"
istr4="abcdefgh"

def lsub(istr):
    slen=0
    chars=[]
    for e in istr:
        if e in chars:
            if chars[-1]==e:
                del chars[:]
            elif chars[0]==e:
                chars.remove(e)
                chars.append(e)
            else:
                for i in range(len(chars)):
                    if chars[0]==e:
                        chars.pop(0)
                        chars.append(e)
                        break
                    else:
                        chars.pop(0)
        else:
            chars.append(e)
        slen=len(chars) if len(chars)>slen else slen
    return slen

print(lsub(istr1))
print(lsub(istr2))
print(lsub(istr3))
print(lsub(istr4))

