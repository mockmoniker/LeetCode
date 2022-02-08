class Solution:
    def addDigits(self, num: int) -> int:
        temp = 0
        while True:
            while(num > 0):
                temp += (num % 10)
                num = num // 10
            
            if temp < 10:
                return temp
            
            num = temp
            temp = 0