def NULL_not_found(object: any) -> int:
	if (isinstance(object, bool)):
		print("Fake :", object, type(object))
		return 0
	elif (object is None):
		print("Nothing :", object, type(object))
		return 0
	elif (isinstance(object, float) and object != object):
		print("Cheese :", object, type(object))
		return 0
	elif (isinstance(object, int) and object == 0):
		print("Zero :", object, type(object))
		return 0
	elif (isinstance(object, str) and len(object) == 0):
		print("Empty: ", object, type(object))
		return 0
	else:
		print("Type not found")
		return 1