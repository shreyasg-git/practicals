import random
selected_number = random.randint(1, 100)
# print(selected_number)
def hard_level():
    global selected_number
    level = 5
    while level >0:
        guess = int(input("Guess the number: "))
        if guess != selected_number:
            level-=1
            print(f"You have {level} attempts left")
            if level == 0:
                print("you lose")
            elif guess - selected_number<0:
                print("too Low")
            elif guess - selected_number>0:
                print("Too high")
        else:
            print(f"You WON.......... the number was: {selected_number}")
            break
    
def easy_level():
    global selected_number
    level = 10
    while level >0:
        guess = int(input("Guess the number: "))
        if guess != selected_number:
            level-=1
            print(f"You have {level} attempts left")
            if level == 0:
                print("you lose")
            elif guess - selected_number<0:
                print("too Low")
            elif guess - selected_number>0:
                print("Too high")
        else:
            print(f"You won the number was: {selected_number}")
            break

def bot_game():

    print("""
 ________  ___  ___  _______   ________   ________           _________  ___  ___  _______           ________   ___  ___  _____ ______   ________  _______   ________     
|\   ____\|\  \|\  \|\  ___ \ |\   ____\ |\   ____\         |\___   ___\\  \|\  \|\  ___ \         |\   ___  \|\  \|\  \|\   _ \  _   \|\   __  \|\  ___ \ |\   __  \    
\ \  \___|\ \  \\\  \ \   __/|\ \  \___|_\ \  \___|_        \|___ \  \_\ \  \\\  \ \   __/|        \ \  \\ \  \ \  \\\  \ \  \\\__\ \  \ \  \|\ /\ \   __/|\ \  \|\  \   
 \ \  \  __\ \  \\\  \ \  \_|/_\ \_____  \\ \_____  \            \ \  \ \ \   __  \ \  \_|/__       \ \  \\ \  \ \  \\\  \ \  \\|__| \  \ \   __  \ \  \_|/_\ \   _  _\  
  \ \  \|\  \ \  \\\  \ \  \_|\ \|____|\  \\|____|\  \            \ \  \ \ \  \ \  \ \  \_|\ \       \ \  \\ \  \ \  \\\  \ \  \    \ \  \ \  \|\  \ \  \_|\ \ \  \\  \| 
   \ \_______\ \_______\ \_______\____\_\  \ ____\_\  \            \ \__\ \ \__\ \__\ \_______\       \ \__\\ \__\ \_______\ \__\    \ \__\ \_______\ \_______\ \__\\ _\ 
    \|_______|\|_______|\|_______|\_________\\_________\            \|__|  \|__|\|__|\|_______|        \|__| \|__|\|_______|\|__|     \|__|\|_______|\|_______|\|__|\|__|
                                 \|_________\|_________|                                                                                                                 
                                                                                                                                                                         
                                                                                                                                                                         
""")

    print("I have number between 1-100 in my mind can you guess it?")
    level = input("Type level easy or hard: \n").lower()
    
       
    if level == "easy":
        easy_level()
    elif level == "hard":
        hard_level()
    else:
        print("Invalid input")

print("Hii Im SHERU your personal chatbot")
game = input("Want to play a game?......type yes/no: \n").lower()
if game=="yes":
    bot_game()
elif game=="no":
    print("I will see you back soon................")
    exit()
elif game!="yes" or "no":
    print("Wrong input")
    exit()