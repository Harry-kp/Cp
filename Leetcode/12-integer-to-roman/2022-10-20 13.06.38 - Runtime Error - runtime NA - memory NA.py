class Solution:
    def __init__(self):
        self.dict1 = {1:'I',4:'IV',5:'V',9:'IX',10:'X',40:'XL',50:'L',90:'XC',100:'C',400:'CD',500:'D',900:'CM',1000:'M'}
    def nearest(self,n):
        x = [1,4,5,9,10,40,50,90,100,400,500,900,1000]
        if n>1000:
            return 1000
        for i in range(len(x)):
            if n<x[i]:
                return x[i-1]
                
    def solve(self,n):
        if n == 0:
            return ''
        # print(n)
        near = self.nearest(n)
        return self.dict1[near]*(n//near)+self.solve(n%near)
    def intToRoman(self, num: int) -> str:
        return self.solve(num)
        # if num == 0:
        #     return ''
        # if num == 4:
        #     return 'IV'
        # elif num == 9:
        #     return 'IX'
        # elif num == 40:
        #     return 'XL'
        # elif num == 90:
        #     return 'XC'
        # elif num == 400:
        #     return 'CD'
        # elif num == 900:
        #     return 'CM'
        # elif 1<=num<=3:
        #     return 'I'*(num)
        # elif 5<=num<=8:
        #     return 'V'+ self.intToRoman(num%5) 
        # elif 10<=num<=39:
        #     return 'X'*(num//10) + self.intToRoman(num%10)
        # elif 41<=num<=49:
        #     return 'XL' + self.intToRoman(num%40)
        # elif 50<=num<90:
        #     return 'L' + self.intToRoman(num%50)
        # elif 91<=num<100:
        #     return 'XC' + self.intToRoman(num%90)
        # elif 101<=num<400:
        #     return 'C'*(num//100) + self.intToRoman(num%100)
        # elif 401<=num<500:
        #     return 'CD' + self.intToRoman(num%400)
        # elif 501<=num<900:
        #     return 'D' + self.intToRoman(num%500)
        # elif 901<=num<1000:
        #     return 'CM' + self.intToRoman(num%900)
        # return 'M'*(num//1000) + self.intToRoman(num%1000)
        
            