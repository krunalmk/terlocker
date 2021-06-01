# Terlocker
Its is an application which secures the terminals of Linux based systems. Bash and cpp are used for programming purposes.

## Setting up Terlocker
1. Download the terlocker file.
2. Extract its contents.
3. Open terminal in the directory where you downloaded terlocker.
4. To make the executable of terlocker.cpp execute following code:
```
gcc terlocker.cpp -o terlocker
```
5. Make terlocker executable anywhere in the PC using following code:
```
CurrDir=$(pwd)
sudo cp "$CurrDir/terlocker" '/usr/local/bin/'
sudo cp "$CurrDir/checkLocked.sh" '/usr/local/bin/'
```
6. Execute following commands in terminal to execute Terlocker in all terminals, to execute it while opening terminal, sending signals, etc.:
```
echo "## For terlocker, made by Krunal" >> ~/.bashrc
echo "trap 'checkLocked.sh' DEBUG 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 EXIT" >> ~/.bashrc
echo "PROMPT_COMMAND= 'checkLocked.sh' \n" >> ~/.bashrc
```
7. For user authentication and password execute following:
```
#Going to home directory
cd

# Creating terlocker
mkdir terlocker

# Change directory
cd terlocker

# Creating password.txt and YesNo.txt in terlocker directory
touch password.txt
touch YesNo.txt

# Setting "root" in password.txt and "No" in YesNo.txt as default
echo "root" > password.txt
echo "No" > YesNo.txt
```

## How to use
1. Execute following command to enable terlocker:
```
terlocker
```
2. To disable terlocker just type the password ( default is "root")
3. To change password execute following:
```
terlocker setpassword
```

## Demo

[Terlocker demo video](https://drive.google.com/file/d/1WBzwL93sgc0awDiQ9Csa71WiDw5uvR3J/view?usp=sharing)
