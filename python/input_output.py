#input function by default take input as string input
#so to convert to other data type we have to convert input explicitly 
#ex:- int() for integer float() for float

a = int(input("Enter a numbe : "))
print('you have enterred',a)
print(type(a))

#in print function sep parameter is printed after every character
#and end parameter is printed at the end of print function
#by default sep=' ' and end='\n'

print('g','f','h',sep="#",end="@")
print()

a = 5
b = 6

# formatting can be done in three ways

# (1) Using formatted string literals
print(f'hello {a} its me how are you doing')

# (2) Using format()
print('hello its me {0} hii its me {1}'.format(a,b))
print('hello i am {val_z} hii i am {val_y}'.format(val_z=a,val_y=b))
print('hello i am {val_z} hii i am {val_y}'.format(val_z=7,val_y=8))

# (3) Using % Operator
print("value of a is %d" %a)