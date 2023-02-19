n = int(input())

good = [1,2,3,3,4,10]
evil = [1,2,2,2,3,5,10] 

for indx in range(0,n):
	l1 = list(map(int, input().strip().split(" ")))
	l2 = list(map(int, input().strip().split(" ")))

	print(list(map(lambda a,b: a*b, l1,good)))
	# for i,val in enumerate((l1)):
	# 	l1[i] = val*good[i]
	# for i,val in enumerate((l2)):
	# 	l2[i] = val*evil[i]


	if (sum(l1)<sum(l2)):
		print(f"Battle {indx+1}: Evil eradicates all trace of Good")
	elif sum(l1)>sum(l2):
		print(f"Battle {indx+1}: Good triumphs over Evil")
	else:
		print(f"Battle {indx+1}: No victor on this battle field")
