import random

print("================================")
print("      🗡️ THE DARK FOREST 🗡️")
print("================================")

name = input("Enter your name: ")

print(f"\nWelcome, {name}!")
print("You wake up in a mysterious forest.")
print("You see a dark cave 🕳️ and an old castle 🏰.")

choice = input("\nWhere do you want to go? (cave/castle): ").lower()

# CAVE
if choice == "cave":
    print("\nYou enter the dark cave...")
    print("Suddenly, a monster 👹 appears!")

    fight = input("Do you want to fight or run? (fight/run): ").lower()

    if fight == "fight":
        player = random.randint(1, 10)
        monster = random.randint(1, 10)

        print(f"\nYour power: {player}")
        print(f"Monster power: {monster}")

        if player > monster:
            print("\n⚔️ You defeated the monster!")
            print("💰 You found 100 gold coins!")
            print("🏆 YOU WIN!")
        elif player < monster:
            print("\n💀 The monster defeated you!")
            print("GAME OVER!")
        else:
            print("\n😮 It's a draw! You escape safely.")

    elif fight == "run":
        print("\n🏃 You escaped from the cave!")
        print("But you got lost in the forest...")
        print("GAME OVER!")

    else:
        print("\n❌ Invalid choice!")

# CASTLE
elif choice == "castle":
    print("\nYou enter the mysterious castle...")
    print("There are two doors 🚪")
    print("1. A red door 🔴")
    print("2. A blue door 🔵")

    door = input("\nWhich door do you choose? (red/blue): ").lower()

    if door == "red":
        print("\n🔥 The room is full of fire!")
        print("You quickly escape!")
        print("GAME OVER!")

    elif door == "blue":
        print("\n✨ You found a treasure room!")
        print("💎 You found a legendary diamond!")
        print("🏆 YOU WIN!")

    else:
        print("\n❌ Invalid choice!")

else:
    print("\n❌ You got confused and wandered into the forest.")
    print("GAME OVER!")

print("\nThanks for playing! 🎮")
