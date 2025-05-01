
string = input()

max_count = 0
count = 0

for char in string:
    if char in ['A', 'C', 'G', 'T']:
        count += 1
    else:
        count = 0
    max_count = max(max_count, count)

print(max_count)

#
