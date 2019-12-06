
# Project Get_next_line (GNL):

## This function, called "get_next_line()" reads from a file descriptor, one line at a time. Each call of the function returns subsequent lines read from the file descriptor, until EOF is reached. 

### Return Value:
	* return 1 for each line read
	* return 0 when EOF is reached
	* Return -1 when an error occurs

### Bonus:
	* Uses single static variable
	* Supports multiple file descriptors (including switching back and forth between fds). 
