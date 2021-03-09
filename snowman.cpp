#include "snowman.hpp"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//for all none 
string _none = "";

//Hats
string straw_hat = "_===_";
string mexican_hat = " ___ \n .....";
string fez = "  _ \n  /_\\";
string ushanka = " ___ \n(_*_)";

string hats[4] = {straw_hat, mexican_hat, fez, ushanka};

//Noses
string normal_nose = ",";
string dot_nose = ".";
string line_nose = "_";
string none_nose = " ";

string noses[4] = {normal_nose, dot_nose, line_nose, none_nose};

//Left eye
string dot_l_eye = "(.";
string bigger_dot_l_eye = "(o";
string biggest_dot_l_eye = "(O";
string closed_l_eye = "(-";

string left_eyes[4] = {dot_l_eye, bigger_dot_l_eye, biggest_dot_l_eye, closed_l_eye};

//Right eye
string dot_r_eye = ".)";
string bigger_dot_r_eye = "o)";
string biggest_dot_r_eye = "O)";
string closed_r_eye = "-)";

string right_eyes[4] = {dot_r_eye, bigger_dot_r_eye, biggest_dot_r_eye, closed_r_eye};

//left arm
string normal_l_arm = "<";
string upwards_l_arm = "\\";
string downwards_l_arm = "/";

string left_arms[4] = {normal_l_arm, upwards_l_arm, downwards_l_arm, _none};

//right arm
string normal_r_arm = ">";
string upwards_r_arm = "/";
string downwards_r_arm = "\\";

string right_arms[4] = {normal_r_arm, upwards_r_arm, downwards_r_arm, _none};

//Torso
string buttons_torso = "( : )";
string vest_torso = "(] [)";
string inwards_arms_torso = "(> <)";
string none_torso = "(   )";

string torsos[4] = {buttons_torso, vest_torso, inwards_arms_torso, none_torso};

//Base
string buttons_base = "( : )";
string feet_base = "(\" \")";
string flat_base = "(___)";
string none_base = "(   )";

string bases[4] = {buttons_base, feet_base, flat_base, none_base};


namespace ariel
{  

    string snowman(int num){
        int num_of_digits = count_digits(num);

        if(num_of_digits < 8){
             throw std::invalid_argument( "input has less then 8 digits" );
        }
        else if(num_of_digits > 8){
             throw std::invalid_argument( "input has more then 8 digits" );
        }
        else if(num < 0){
            throw std::invalid_argument( "input is negative value" );
        }
        else if(is_digit_valid(num)){
            throw std::invalid_argument( "input has digit that is greater then 4 or is 0 " );
        }

        //HAT - H
        string hat = "";
        switch (next_digit_in_num(num, 7)) //extract the first digit in num(from the left)
        {
        case 1: //first cell in array of hats
            hat = hat + hats[0];
            break;
        case 2:
            hat = hat + hats[1];
            break;
        case 3:
            hat = hat + hats[2];
            break;
        case 4:
            hat = hat + hats[3];
            break;    
        }

        //FACE
        string face = ""; // composed of from left eye, node, right eye
        //left eye - L
        switch (next_digit_in_num(num, 5)) //extract the third digit in num(from the left)
        {
        case 1: //first cell in array of left_eyes
            face = face + left_eyes[0];
            break;
        case 2:
            face = face + left_eyes[1];
            break;
        case 3:
            face = face + left_eyes[2];
            break;
        case 4:
            face = face + left_eyes[3];
            break;    
        }

        //nose - N
        switch (next_digit_in_num(num, 6)) //extract the second digit in num(from the left)
        {
        case 1: //first cell in array of noses
            face = face + noses[0];
            break;
        case 2:
            face = face + noses[1];
            break;
        case 3:
            face = face + noses[2];
            break;
        case 4:
            face = face + noses[3];
            break;    
        }

        //right eye - R
        switch (next_digit_in_num(num, 4)) //extract the fourth in num(from the left)
        {
        case 1: //first cell in array of right_eyes
            face = face + right_eyes[0];
            break;
        case 2:
            face = face + right_eyes[1];
            break;
        case 3:
            face = face + right_eyes[2];
            break;
        case 4:
            face = face + right_eyes[3];
            break;    
        }

        
        //TORSO - T
        string torso = "";
        switch (next_digit_in_num(num, 1)) //extract the second digit from right in num
        {
        case 1: //first cell in array of right_eyes
            torso = torso + torsos[0];
            break;
        case 2:
            torso = torso + torsos[1];
            break;
        case 3:
            torso = torso + torsos[2];
            break;
        case 4:
            torso = torso + torsos[3];
            break;    
        } 

        //BASE - B
        string base = "";
        switch (next_digit_in_num(num, 0)) //extract the first digit from right in num
        {
        case 1: //first cell in array of right_eyes
            base = base + bases[0];
            break;
        case 2:
            base = base + bases[1];
            break;
        case 3:
            base = base + bases[2];
            break;
        case 4:
            base = base + bases[3];
            break;    
        } 

        //left arm - X
        switch (next_digit_in_num(num, 3)) //extract the fifth digit from left in num
        {
        case 1: //first cell in array of left_arms
            torso = left_arms[0] + torso;
            face = " " + face;
            base = " " + base;
            hat = " " + hat;
            break;
        case 2:
            face = left_arms[1] + face;
            torso = " " + torso;
            base = " " + base;
            hat = " " + hat;
            break;
        case 3:
            torso = left_arms[2] + torso;
            face = " " + face;
            base = " " + base;
            hat = " " + hat;
            break;
        case 4:
            //base = base + bases[3];
            break;    
        }

        //right arm - Y
        switch (next_digit_in_num(num, 2)) //extract the third digit from right in num
        {
        case 1: //first cell in array of right_arms
            torso = torso + right_arms[0];
            break;
        case 2:
            face = face + right_arms[1];
            break;
        case 3:
            torso = torso + right_arms[2];
            break;
        case 4:
            //base = base + bases[3];
            break;    
        } 
        
        string ans_str = hat + "\n" + face + "\n" + torso + "\n" + base;
        return ans_str;

    }

    
    int is_digit_valid(int n){
        int current=0;

        while (n != 0) 
        {
            current = n%10;
            if(current > 4 || current == 0){
                return 1;
            }
            n = n / 10;
            
        }
        return 0;
    }

    int count_digits(int n)
    {
        int count = 0;
        while (n != 0) 
        {
            n = n / 10;
            ++count;
        }
        return count;
    }

    int next_digit_in_num(int num, int divide){
        if(divide == 0){ //in case we need the first digit from right
            return num%10;
        }
        divide = pow(10, divide); //if we want the first digit in num so we will enter 7, divide = 10000000
        int ans = num/divide; //we take our input num and divide it by "divide" , so that in unity digit (digit in the one`s column)
                            //is the next number we want to extract
        ans = ans%10; // mod 10 to extract the unity digit.
        return ans; 
    }
};

