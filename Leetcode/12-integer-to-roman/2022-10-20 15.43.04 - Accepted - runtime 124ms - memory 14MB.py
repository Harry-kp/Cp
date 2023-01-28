class Solution:
    def __init__(self):
        self.dict1 = {1:'I',4:'IV',5:'V',9:'IX',10:'X',40:'XL',50:'L',90:'XC',100:'C',400:'CD',500:'D',900:'CM',1000:'M'}
    def nearest(self,n):
        x = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        if n>1000:
            return 1000
        for i in range(len(x)):
            if n == x[i]:
                return x[i]
            elif n<x[i]:
                return x[i-1]
                
    def solve(self,n):
        if n == 0:
            return ''
        
        near = self.nearest(n)
        return self.dict1[near]*(n//near)+self.solve(n%near)
    def intToRoman(self, num: int) -> str:
        return self.solve(num)
        
            