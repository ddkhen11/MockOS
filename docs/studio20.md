# Studio 20

# Responses:
Students:
1. Daniel Khen
2. Adam Shumway
3. Malcolm Newmark


Question Answers:
1. If we do not delete the pointer to the file when the 'PasswordProxy' object is destroyed, it will lead 
to a memory leak because the memory that was allocated for the real file won't be freed. Therefore, we delete 
the file to prevent any memory leaks in our program.
