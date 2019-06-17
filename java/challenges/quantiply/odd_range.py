
def odd_range(left, right):
    # list comprehension to create range of odds
    return [value for value in range(left, right+1) if is_odd(value)]

def is_odd(value):
    return value%2 == 1

if __name__ == "__main__":
    pass
