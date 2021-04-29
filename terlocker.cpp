#include<iostream>
#include<stdlib.h>
#include<termios.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include <cstdio>
#include <fstream>
#include <bits/stdc++.h> 
#include <unistd.h>

using namespace std;

#define MAX_NAME_LEN 60

// Function for making the input in command line invisible
void getch( char *arr) {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    cin.getline( arr, MAX_NAME_LEN);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// Function to display message whenever user tries to terminate the process using SIGINT or signal interrupt
void sig_handler(int signum){
  printf("Terminal is secured\n");
}

/* Most important requirement of terlocker is this function.
   * For any input received like commands, interrupts, etc. the terminal is not going to execute it.
   * It will respond only when user enters terlocker's password.
   * After entering the password the terminal will function normally.
*/
void lockTerminals_And_UnlockIfUserEntersPassword( char *password){
  char strFromYesNoTxt[5];
  char str[MAX_NAME_LEN];
  fstream YesNoFile("/home/democratickmk/terlocker/YesNo.txt", ios::out | ios::in | ios::trunc);
  YesNoFile << "Yes";
  YesNoFile.close();

  system("clear");
  system("xmodmap -e \'keycode 52 = 0x0000\'");
  
  for(int i=0;; i++){
    getch( str); // Getting inputs like cmd, texts from user
    // Checking each time if YesNo.txt has password set "Yes" or "No"
    fstream File("/home/democratickmk/terlocker/YesNo.txt", ios::out | ios::in);
    File >> strFromYesNoTxt;
    File.close();

    if( strcmp( strFromYesNoTxt, "No") == 0){
      system("clear");
      exit(1);
    }
    cout<<"Enter password to unlock terminal\n";

    // Check if entered password matches actual password. If matches then exit from terlocker
    if( strcmp( password, str) == 0){
        fstream YesNoFile("/home/democratickmk/terlocker/YesNo.txt", ios::out | ios::in | ios::trunc);
        YesNoFile << "No";
        YesNoFile.close();
        signal(SIGINT,SIG_DFL);
        system("xmodmap -e \'keycode 52 = 0x7a\'");
        system("clear");
        exit(1);
    }
  }
}

bool checkForcharZ( char* str){
    for( int i=0; i< strlen(str); i++)
        if( str[i] == 'z' || str[i] == 'Z')
            return true;
    return false;
}

int main( int args, char *argv[]){
  signal(SIGINT,sig_handler); // Register signal handler
  char str[MAX_NAME_LEN], yesOrNo;
  char * password = (char*)malloc(MAX_NAME_LEN*sizeof( char));
  
  // Storing password in a variable "password"
  fstream File("/home/democratickmk/terlocker/password.txt", ios::out | ios::in);
  File >> str;
  File.close();
  
  strcpy( password, str);
  
  SetPassword:
    if( args > 1){
        // Check if user wants to set new password
      if( strcmp( argv[1], "setpassword") == 0){
        char tpStr[MAX_NAME_LEN];
        cout<<"Enter current password: ";
        cin>> tpStr;
        
        // Compare if user entered current password correctly 
        if( strcmp( tpStr, str) == 0){
          cout<<"Enter password: ";
          cin>> str;
          cout<< "Do you wish to continue (Y/n)\n";
          cin>> yesOrNo;
          if( yesOrNo != 'Y' && yesOrNo != 'y'){
            return -1;
          }
          else{
            if( checkForcharZ( str)){
                cout<<"Password doesn\'t meet the standards"<<endl;
                exit(0);
            }
            
              // Set new password in password.txt
            fstream MyFile("/home/democratickmk/terlocker/password.txt", ios::out | ios::in | ios::trunc);
            MyFile << str;
            cout<<"Password set successfully\n";
            MyFile.close();
            return 1;
          }
        }
        else{ // If current password entered doesn't match with the password stored
          cout<<"Password doesn't match\n";
          return -1;
        }
      }
    }
  
  // If no password is typed again ask the user to repeat the same process for changing the password
  if( strlen( str)  == 0){
    goto SetPassword;
  }
  
  // Run terlocker
  lockTerminals_And_UnlockIfUserEntersPassword( password);
  return 0;
}
