0x11. C - printf
Write a function that produces output according to a format.
1. Education is when you read the fine print. Experience is what you get if you don't
mandatory
Handle the following conversion specifiers:

d
i
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
2. With a face like mine, I do better in print
Handle the following custom conversion specifiers:

b: the unsigned int argument is converted to binary
3. What one has not experienced, one will never understand in print

Handle the following conversion specifiers:

u
o
x
X
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
4. Nothing in fine print is ever good news
Use a local buffer of 1024 chars in order to call write as little as possible
My weakness is wearing too much leopard print
Handle the following custom conversion specifier:

S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
