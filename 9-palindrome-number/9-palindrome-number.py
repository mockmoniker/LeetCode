class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: return False
        if x < 10: return True
        if x % 10 == 0 and x != 0: return False
        
        x_prime = 0
        
        while(x_prime < x):
            x_prime = x_prime * 10 + (x % 10)
            x = x // 10
            
            if x_prime == x or x_prime == x // 10:
                return True
        
        return False