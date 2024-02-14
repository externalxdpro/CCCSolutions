def stat(n):
    minimum = 0
    maximum = 0
    total = 0
    for i in range(n):
        if i == 0:
            num = float(input("First value: "))
        else:
            num = float(input("Next value: "))
        if i == 0 or num < minimum:
            minimum = num
        if num > maximum:
            maximum = num
        total += num
    avg = total / n
    print(minimum, maximum, total, avg)

stat(5)