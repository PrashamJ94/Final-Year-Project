import math

def main():
    A, B, H, M = map(int, input().split())
    AA = A
    BB = B
    HH = H
    MM = M
    
    mkaku = MM * 6
    hkaku = HH * 30
    hkaku = hkaku + (M / 2)
    
    kaku = mkaku - hkaku
    dkaku = math.radians(abs(kaku))
    
    AA2 = AA * AA
    BB2 = BB * BB
    CC = AA2 + BB2
    DD = math.cos(dkaku) * 2 * AA * BB
    
    ans2 = CC - DD
    ans = math.sqrt(ans2)
    print(ans)

main()


