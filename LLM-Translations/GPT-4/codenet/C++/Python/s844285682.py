
a = int(input())

hours = a // (60 * 60)
minutes = (a % (60 * 60)) // 60
seconds = (a % (60 * 60)) % 60

print(f"{hours}:{minutes}:{seconds}")

#
