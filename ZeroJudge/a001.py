while True:
	try:
		s = input()
		print("hello, " + s)
	except EOFError:
		break