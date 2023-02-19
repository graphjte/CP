def maximum_sum(a, b):
    # Sort the arrays a and b in non-descending order
    a.sort()
    b.sort()
    # Iterate through the elements of b
    for x in b:
        # Find the maximum element in a that is less than or equal to x
        i = len(a) - 1
        while i >= 0 and a[i] > x:
            i -= 1
        # If such an element was found, replace it with x and remove it from the array a
        if i >= 0:
            a[i] = x
            a.pop(i)
    # Return the sum of the elements in the array a
    return sum(a)

a = [1, 2, 3]
b = [4, 5]
print(maximum_sum(a,b))