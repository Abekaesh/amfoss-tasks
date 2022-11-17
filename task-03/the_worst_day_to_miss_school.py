n = int(input())
si = [int(x) for x  in input().split()]
f = si.count(4)
t = si.count(3)
to = si.count(2)
o = si.count(1)

ans=f
if(t>o):
    ans+=o
    t-=o
    if(to%2==0):
        ans=ans+int(to/2)+t
    else:
        ans=ans+int(to/2)+1+t
elif(o>t):
    ans+=t
    o-=t
    if(to%2==0):
        if(o%4!=0):
            ans=ans+int(to/2)+1+int(o/4)
        else:
           ans=ans+int(to/2)+int(o/4)
    else:
        p=to%2
        if(o==2):
            ans=ans+int(to/2)+p
        elif(o>4):
            if(o==3):
                ans=ans+int(to/2)+p+1
            else:
                ans=ans+int(to/2)+p+int((o-2)/4)+(o-2)%4
        else:
            ans=ans+int(to/2)+p
print(ans)
