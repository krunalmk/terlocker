#!/bin/bash

# Open terminal where you saved the terlocker files
# Grant permissions to checkedLocked.sh
chmod a+x checkedLocked.sh

# Create executable for terlocker
g++ terlocker.cpp -o terlocker

# Putting checkLocked.sh, terlocker in /usr/local/bin/ so that it can be executed from anywhere
sudo cp "terlocker" '/usr/local/bin/'
sudo cp "checkLocked.sh" '/usr/local/bin/'

# Add following commands in .bashrc so that terlocker executes whenever terminal opens
echo "## For terlocker, made by Krunal" >> ~/.bashrc
echo "trap 'checkLocked.sh' DEBUG 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 EXIT" >> ~/.bashrc
echo "PROMPT_COMMAND= 'checkLocked.sh' \n" >> ~/.bashrc

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
