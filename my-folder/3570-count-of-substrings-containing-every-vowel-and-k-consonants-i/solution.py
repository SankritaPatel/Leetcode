class Solution:
    def countOfSubstrings(self, s: str, k: int) -> int:
        vowels = set("aeiou")
        count = 0
        consonant_count = 0
        # Generate all substrings
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                substring = s[i:j]
                if vowels.issubset(set(substring)):

                    # Count consonants in the substring
                    consonants = sum(
                        1 for char in substring if char.isalpha() and char not in vowels
                    )
                    if consonants==k:
                        count+=1
        return count
