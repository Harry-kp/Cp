class Solution:
    def intToRoman(self, num: int) -> str:
        if num == 0:
            return ''
        if num == 4:
            return 'IV'
        elif num == 9:
            return 'IX'
        elif num == 40:
            return 'XL'
        elif num == 90:
            return 'XC'
        elif num == 400:
            return 'CD'
        elif num == 900:
            return 'CM'
        elif 1<=num<4:
            return 'I'*(num)
        elif 5<=num<9:
            return 'V'+ self.intToRoman(num%5) 
        elif 10<=num<39:
            return 'X'*(num//10) + self.intToRoman(num%10)
        elif 41<=num<50:
            return 'XL' + self.intToRoman(num%40)
        elif 51<=num<90:
            return 'L' + self.intToRoman(num%50)
        elif 91<=num<100:
            return 'XC' + self.intToRoman(num%90)
        elif 101<=num<400:
            return 'C'*(num//100) + self.intToRoman(num%100)
        elif 401<=num<500:
            return 'CD' + self.intToRoman(nums%400)
        elif 501<=num<900:
            return 'D' + self.intToRoman(num%500)
        elif 901<=num<1000:
            return 'CM' + self.intToRoman(nums%900)
        return 'M'*(num//1000) + self.intToRoman(num%1000)
            