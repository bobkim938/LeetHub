class Solution:
    def intToRoman(self, num: int) -> str:
        romanNum = ['D', 'L', 'V'] # 500, 50, 5
        tenMulti = ['M', 'C', 'X', 'I'] # 1000, 100, 10, 1
        roman = ""
        cnt, rmd = 0, 0
        while cnt < 4:
            if cnt == 0: #1000s
                tmp = int(num / 1000)
                rmd = int(num % 1000)
            elif cnt == 1: #100s
                tmp = int(rmd/100)
                rmd = int(rmd % 100)
            elif cnt == 2: #10s
                tmp = int(rmd / 10)
                rmd = int(rmd % 10)
            elif cnt == 3:
                tmp = rmd

            if tmp == 9 or tmp == 4:
                roman += tenMulti[cnt]
                if tmp >= 5:
                    roman += tenMulti[cnt - 1]
                else:
                    roman += romanNum[cnt - 1]
            elif tmp == 0:
                pass
            else:
                if tmp >= 5:
                    roman += romanNum[cnt - 1]
                    for i in range(tmp-5):
                        roman += tenMulti[cnt]
                else:
                    for i in range(tmp):
                        roman += tenMulti[cnt]
            cnt += 1

        return roman
