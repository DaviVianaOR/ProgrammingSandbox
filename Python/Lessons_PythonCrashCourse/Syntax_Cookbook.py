
print("Hello, World!") # for good luck

message = "Hello, Python world!"
print(message) ## prints the message
print(message.title()) ## message, but words's first letters is uppercase
print(message.upper()) ## message, uppercase
print(message.lower()) ## message, lowercase - useful for data storing

first_name = "Aaron"
last_name = "Zygmunt"
full_name = f"{first_name} {last_name}" ##              | f: f-strings, f is for format, replaces the variable with it's value 
print(f"Good afernoon, {full_name.title()}.")

print("Python") ## normal print
print("\tPython") ##                                    | \t = printing with tabulation
print("Python\nR\nSQL") ##                              | \n = printing with newline

favorite_language = ' python ' ##           ' python '
print(f"{favorite_language}") ##            ' python '
print(f"{favorite_language.rstrip()}") ##   ' python'   | .rstrip() cuts the whitespace at the right
print(f"{favorite_language.lstrip()}") ##   'python '   | .lstrip() cuts the whitespace at the left
print(f"{favorite_language.strip()}") ##    'python'    | .strip() cuts the whitespace at the left

