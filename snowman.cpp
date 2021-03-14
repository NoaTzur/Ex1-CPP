#include "snowman.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <array>

using namespace std;

const int BASE = 0;
const int TORSO = 1;
const int RIGHT_ARM = 2;
const int LEFT_ARM = 3;
const int RIGHT_EYE = 4;
const int LEFT_EYE = 5;
const int NOSE = 6;
const int HAT = 7;
const int VALID_NUM_OF_DIGIT = 8;

const int EXTRACT_LAST_DIGIT = 10;



//for all none 
string _none;

//Hats
string straw_hat = "_===_";
string mexican_hat = " ___ \n .....";
string fez = "  _ \n  /_\\";
string ushanka = " ___ \n(_*_)";

array<string, 4> hats= {straw_hat, mexican_hat, fez, ushanka};

//Noses
string normal_nose = ",";
string dot_nose = ".";
string line_nose = "_";
string none_nose = " ";

array<string, 4> noses = {normal_nose, dot_nose, line_nose, none_nose};

//Left eye
string dot_l_eye = "(.";
string bigger_dot_l_eye = "(o";
string biggest_dot_l_eye = "(O";
string closed_l_eye = "(-";

array<string, 4> left_eyes = {dot_l_eye, bigger_dot_l_eye, biggest_dot_l_eye, closed_l_eye};

//Right eye
string dot_r_eye = ".)";
string bigger_dot_r_eye = "o)";
string biggest_dot_r_eye = "O)";
string closed_r_eye = "-)";

array<string, 4> right_eyes = {dot_r_eye, bigger_dot_r_eye, biggest_dot_r_eye, closed_r_eye};

//left arm
string normal_l_arm = "<";
string upwards_l_arm = "\\";
string downwards_l_arm = "/";

array<string, 4> left_arms = {normal_l_arm, upwards_l_arm, downwards_l_arm, _none};

//right arm
string normal_r_arm = ">";
string upwards_r_arm = "/";
string downwards_r_arm = "\\";

array<string, 4> right_arms = {normal_r_arm, upwards_r_arm, downwards_r_arm, _none};

//Torso
string buttons_torso = "( : )";
string vest_torso = "(] [)";
string inwards_arms_torso = "(> <)";
string none_torso = "(   )";

array<string, 4> torsos = {buttons_torso, vest_torso, inwards_arms_torso, none_torso};

//Base
string buttons_base = "( : )";
string feet_base = "(\" \")";
string flat_base = "(___)";
string none_base = "(   )";

array<string, 4> bases = {buttons_base, feet_base, flat_base, none_base};


namespace ariel
{  

    string snowman(int num){
        int num_of_digits = count_digits(num);

        if(num_of_digits < VALID_NUM_OF_DIGIT){
             throw std::invalid_argument( "input has less then 8 digits" );
        }
        if(num_of_digits > VALID_NUM_OF_DIGIT){
             throw std::invalid_argument( "input has more then 8 digits" );
        }
        if(num < VALID_NUM_OF_DIGIT){
            throw std::invalid_argument( "input is negative value" );
        }
        if(is_digit_valid(num) !=0 ){
            throw std::invalid_argument( "input has digit that is greater then 4 or is 0 " );
        }

        //HAT - H
        string hat;
        switch (next_digit_in_num(num, HAT)) //extract the first digit in num(from the left)
        {
        case 1: //first cell in array of hats
            hat = hat + hats.at(0);
            break;
        case 2:
            hat = hat + hats.at(1);
            break;
        case 3:
            hat = hat + hats.at(2);
            break;
        case 4:
            hat = hat + hats.at(3);
            break;    
        }

        //FACE
        string face; // composed of left eye, nose, right eye
        //left eye - L
        switch (next_digit_in_num(num, LEFT_EYE)) //extract the third digit in num(from the left)
        {
        case 1: //first cell in array of left_eyes
            face = face + left_eyes.at(0);
            break;
        case 2:
            face = face + left_eyes.at(1);
            break;
        case 3:
            face = face + left_eyes.at(2);
            break;
        case 4:
            face = face + left_eyes.at(3);
            break;    
        }

        //nose - N
        switch (next_digit_in_num(num, NOSE)) //extract the second digit in num(from the left)
        {
        case 1: //first cell in array of noses
            face = face + noses.at(0);
            break;
        case 2:
            face = face + noses.at(1);
            break;
        case 3:
            face = face + noses.at(2);
            break;
        case 4:
            face = face + noses.at(3);
            break;    
        }

        //right eye - R
        switch (next_digit_in_num(num, RIGHT_EYE)) //extract the fourth in num(from the left)
        {
        case 1: //first cell in array of right_eyes
            face = face + right_eyes.at(0);
            break;
        case 2:
            face = face + right_eyes.at(1);
            break;
        case 3:
            face = face + right_eyes.at(2);
            break;
        case 4:
            face = face + right_eyes.at(3);
            break;    
        }

        
        //TORSO - T
        string torso;
        switch (next_digit_in_num(num, TORSO)) //extract the second digit from right in num
        {
        case 1: //first cell in array of right_eyes
            torso = torso + torsos.at(0);
            break;
        case 2:
            torso = torso + torsos.at(1);
            break;
        case 3:
            torso = torso + torsos.at(2);
            break;
        case 4:
            torso = torso + torsos.at(3);
            break;    
        } 

        //BASE - B
        string base;
        switch (next_digit_in_num(num, BASE)) //extract the first digit from right in num
        {
        case 1: //first cell in array of right_eyes
            base = base + bases.at(0);
            break;
        case 2:
            base = base + bases.at(1);
            break;
        case 3:
            base = base + bases.at(2);
            break;
        case 4:
            base = base + bases.at(3);
            break;    
        } 

        //left arm - X
        switch (next_digit_in_num(num, LEFT_ARM)) //extract the fifth digit from left in num
        {
        case 1: //first cell in array of left_arms
            torso = left_arms.at(0) + torso;
            face = " " + face;
            base = " " + base;
            hat = " " + hat;
            break;
        case 2:
            face = left_arms.at(1) + face;
            torso = " " + torso;
            base = " " + base;
            hat = " " + hat;
            break;
        case 3:
            torso = left_arms.at(2) + torso;
            face = " " + face;
            base = " " + base;
            hat = " " + hat;
            break;
        case 4:
            //base = base + bases[3];
            break;    
        }

        //right arm - Y
        switch (next_digit_in_num(num, RIGHT_ARM)) //extract the fourth digit from right in num
        {
        case 1: //first cell in array of right_arms
            torso = torso + right_arms.at(0);
            break;
        case 2:
            face = face + right_arms.at(1);
            break;
        case 3:
            torso = torso + right_arms.at(2);
            break;
        case 4:
            //base = base + bases[3]; - it is none
            break;    
        } 
        
        string ans_str = hat + "\n" + face + "\n" + torso + "\n" + base;
        return ans_str;

    }

    
    int is_digit_valid(int n){ // checks if all digitsin num is in range [1-4]
        int current=0;

        while (n != 0) 
        {
            current = n%EXTRACT_LAST_DIGIT;
            if(current > 4 || current == 0){
                return 1;
            }
            n = n / EXTRACT_LAST_DIGIT;
            
        }
        return 0;
    }

    int count_digits(int n) // counts the number of digits
    {
        int count = 0;
        while (n != 0) 
        {
            n = n / EXTRACT_LAST_DIGIT;
            ++count;
        }
        return count;
    }

    int next_digit_in_num(int num, int divide){ //return the wanted digit in num
        if(divide == 0){ //in case we need the first digit from right
            return num%EXTRACT_LAST_DIGIT;
        }
        divide = pow(EXTRACT_LAST_DIGIT, divide); //if we want the first digit in num so we will enter 7, divide = 10000000
        int ans = num/divide; //we take our input num and divide it by "divide" , so that in unity digit (digit in the one`s column)
                            //is the next number we want to extract
        ans = ans%EXTRACT_LAST_DIGIT; // mod 10 to extract the unity digit.
        return ans; 
    }
};

