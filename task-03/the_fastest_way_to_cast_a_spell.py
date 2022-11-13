n,m = map(int, input().split())
words = dict()
for i in range(m):
    fl,sl = input().split()
    words[fl]=sl
spell = input().split()
ans =""
for j in spell:
    if len(j)==len(words[j]) or len(j)<len(words[j]):
        ans += j + " "
    else:
        ans += words[j] + " "
print(ans)
