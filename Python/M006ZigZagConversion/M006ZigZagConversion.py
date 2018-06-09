class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        if numRows <= 1:
            return s

        res = ''
        n = len(s)

        for i in range(numRows):
            for j in range(i, n, 2 * (numRows - 1)):
                res += s[j]

                if i > 0 and i < numRows - 1 and j + 2 * (numRows - 1 - i) < n:
                    res += s[j + 2 * (numRows - 1 - i)]

        return res

def stringToString(input):
    return input[1:-1]#.decode('string_escape')

import sys
def readlines():
    for line in sys.stdin:
        yield line.strip('\n')

def main():
        lines = readlines()
        while True:
            try:
                line = next(lines)
                s = stringToString(line);
                line = next(lines)
                numRows = int(line);

                ret = Solution().convert(s, numRows)

                out = (ret);
                print(out)
            except StopIteration:
                break

if __name__ == '__main__':
    main()
