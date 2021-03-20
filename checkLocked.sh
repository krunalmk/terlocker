#!/bin/bash  

countLines=0
cd
cd terlocker
word=$(cat YesNo.txt)

    # If YesNo.txt file has "Yes" then execute terlocker
if [[ $word == "Yes" ]]
then
    clear_console
    terlocker
    exit
# If YesNo.txt file has neither "Yes" nor "No" then print error message
elif [[ $word != "No" ]]
then
    echo "Error in programming"
    exit
    
# If YesNo.txt file has "No" then don't execute terlocker
else
    exit
fi
