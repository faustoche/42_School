def count_in_list(lst: list, item: any) -> int:
	"""
	Count number of occurrences of one specific element in a list
	"""

	try:
		if not isinstance(lst, list):
			raise TypeError("First argument has to be a list")
		return lst.count(item)
	
	except Exception:
		## on intercepte toutes les exceptions
		return 0