import sys
from bisect import bisect_left, bisect_right

def main():
    N = int(input().strip())
    a = list(map(int, input().strip().split()))
    ind_a = [0] * 200000
    for i in range(N):
        ind_a[a[i] - 1] = i

    used_inds = set()
    ans = 0
    for i in range(N):
        cur_ind = ind_a[i]
        left_it = bisect_left(sorted(used_inds), cur_ind)
        right_it = bisect_right(sorted(used_inds), cur_ind)

        if left_it == 0:
            left_border = -1
        else:
            if left_it == len(used_inds) or sorted(used_inds)[left_it] > cur_ind:
                left_it -= 1
            left_border = sorted(used_inds)[left_it]

        if right_it == len(used_inds):
            right_border = N
        else:
            right_border = sorted(used_inds)[right_it]

        ans += (cur_ind - left_border) * (right_border - cur_ind) * (i + 1)

        used_inds.add(cur_ind)

    print(ans)

if __name__ == "__main__":
    main()


