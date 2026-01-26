ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello" : "titi!"}

#################################################################

# Updating second word of the list
ft_list[1] = "World!"

#################################################################

# Tuples cannot be modified
# Changing it as a list, modified it, and then as a tuple again
ft_new_tuple = list(ft_tuple)
ft_new_tuple[1] = "France!"
ft_tuple = tuple(ft_new_tuple)

#################################################################

# Updating an element by removing the one we don't want
# Creating a new set with the word we want
# Updating the set with update function
ft_set.remove("tutu!")
ft_new_set = {"Paris!"}
ft_set.update(ft_new_set, ft_set)

#################################################################

#Updating "Hello" definition
ft_dict.update({"Hello" : "42Paris!"})

#################################################################

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)