import re

class Solution:
    def romanToInt(self, s: str) -> int:
        # running total 
        total = 0
        
        # dictionary of every numeral combo and their values
        values = {
            "CD" : 400,
            "CM" : 900,
            "XL" : 40,
            "XC" : 90,
            "IV" : 4,
            "IX" : 9,
            "I"  : 1,
            "V"  : 5,
            "X"  : 10,
            "L"  : 50,
            "C"  : 100,
            "D"  : 500,
            "M"  : 1000
        }
        
        # search for numerals in string and remove, adding to total as necesssary
        for numeral in values:
            while re.search(numeral, s):
                total += values[numeral]
                s = s.replace(numeral, "", 1)
                
        # send it back
        return total