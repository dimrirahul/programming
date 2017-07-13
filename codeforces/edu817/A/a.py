R = lambda : list(map(int, input().split()))
sx, sy, ex, ey = R()
a, b = R()
dx = abs(sx - ex)
dy = abs(sy - ey)
m = lambda x: x % 2
print ( "YES" if dx % a == 0 and dy % b == 0 and m(dx / a) == m(dy / b) else "NO")
