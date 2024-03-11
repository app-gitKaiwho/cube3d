# libft
My own lib of usefull function

## Big function
### Printf
 Is able to print :
 - string (%s)
 - char (%c)
 - int (%i & %d)
 - unsigned (%u)
 - hexadecimal (%x for lowcase %X for uppercase)
 - pointer (%p)
 - double (%f) (usable but less accurate and - is not implemented)<br> 
 outside of being a less printf it does not uses buffer which can be usefull in some cases
 ### GNL
 Give one line after the next of a file
 ## Smaller function
 - ft_abs : give absolute value
 - ft_atoi : string to int
 - ft_bzero : fill a ptr with '\0'
 - ft_caloc : malloc but with a integrated ft_bzero
 - ft_whitespace : return 1 in case of whitespace
 - ft_whiespace : return 1 in case of alphanumeric
 - ft_alpha : return 1 in case of letters
 - ft_isascci : return 1 if char value contain by std ascii table
 - ft_isdigit : return 1 in case of numbers
 - ft_isprint : return 1 in case of printable char
 - ft_itoa : int to string
 - ft_memchr : if char c is contain in string return a point to the position of the first char c
 - ft_memcmp : return the difference between the first different occuring
 - ft_memecpy : copy src into dst but does not allocate
 - ft_memove : copy src into dst by n character but taking into account overlapping memory regions
 - ft_memset : ft_bezero but with your character of choice
 - ft_power : return nb to the power of power
 - ft_putchar_fd : write a char in a open file
 - ft_putendl_fd : putchar for a string + a '\n'
 - ft_putnbr_fd : putchar for numbers
 - ft_putstr_fd : putendl_fd without '\n'
 - ft_rev_int_tab : do a 180 to your int tab 1234 -> 4321
 - ft_split : separate a string by word(char separated by whitespace or start/end of the string) and return a array of string containing them
 - ft_strchr : ft_memchr for strings
 - ft_strdup : copying your string allocating space for it
 - ft_striteri : apply the function passed to every character of the string
 - ft_strjoin : glue to string making allocating space for it
 - ft_strlcat : a strjoin with a size limit that makes sure the string is null terminated
 - ft_strlcpy : memcpy but with a size and for string
 - ft_strlen : return the size of a string
 - ft_strmapi : striteri but return a new string without altering the original one
 - ft_strncmp : memcpm for string making sure to not segfault
 - ft_strrchr : memchr for string
 - ft_strtrim : remove unwanted character for the beginin and the end of a string
 - ft_substr : copy a sub string allocating space for it
 - ft_swap : intervert the value of to int
 - ft_tolower : GOES FROM THIS, to this
 - ft_toupper : goes from this, TO THIS
