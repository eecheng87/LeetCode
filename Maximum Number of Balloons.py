import numpy as np
def containz(v):
    for s in v:
        if s<0:
            return True
    return False
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        v = np.zeros(5)
        o = np.array([1,1,2,2,1])
        ans = 0
        for c in text:
            if c=='a':
                v[0]+=1
            elif c=='b':
                v[1]+=1
            elif c=='l':
                v[2]+=1
            elif c=='o':
                v[3]+=1
            elif c=='n':
                v[4]+=1
 
        v=v-o
        while(not containz(v)):
            ans+=1
            v=v-o
        return ans