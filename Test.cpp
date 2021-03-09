
/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Noa Tzur>
 * 
 * Date: 2021-02
 */
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>


using namespace std;


string erase_spaces(string origin){
    string new_ans = "";
    for (int i = 0; i < origin.length(); i++)
    {
        if(origin[i] != ' '){
            new_ans = new_ans + origin[i];
        }
    }
    return new_ans;
    
}

TEST_CASE("Good snowman code") {


    CHECK(erase_spaces(ariel::snowman(11114411)) == erase_spaces("_===_\n(.,.)\n( : )\n( : )"));

    CHECK(erase_spaces(ariel::snowman(11114411)) == erase_spaces("_===_\n(.,.)\n( : )\n( : )"));

    CHECK(erase_spaces(ariel::snowman(33232124)) == erase_spaces("   _ \n  /_\\\n\\(o_O)\n (] [)>\n (   )"));

    CHECK(erase_spaces(ariel::snowman(12222212)) == erase_spaces(" _===_\n\\(o.o)/\n ( : )\n (\" \")"));
    
    CHECK(erase_spaces(ariel::snowman(32443333)) == erase_spaces("   _\n  /_\\\n (-.-)\n/(> <)\\\n (___)"));

    CHECK(erase_spaces(ariel::snowman(44444432)) == erase_spaces(" ___\n(_*_)\n(- -)\n(> <)\n(\" \")"));

    CHECK(erase_spaces(ariel::snowman(44242123)) == erase_spaces("  ___\n (_*_)\n\\(o -)\n (] [)>\n (___)"));

    CHECK(erase_spaces(ariel::snowman(41341144)) == erase_spaces("  ___\n (_*_)\n (O,-)\n<(   )>\n (   )"));

    CHECK(erase_spaces(ariel::snowman(11111111)) == erase_spaces(" _===_\n (.,.)\n<( : )>\n ( : )"));

    CHECK(erase_spaces(ariel::snowman(22222222)) == erase_spaces("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));

    CHECK(erase_spaces(ariel::snowman(33333333)) == erase_spaces("   _\n  /_\\\n (O_O)\n/(> <)\\\n (___)"));

    CHECK(erase_spaces(ariel::snowman(44444444)) == erase_spaces(" ___\n(_*_)\n(- -)\n(   )\n(   )"));

    CHECK(erase_spaces(ariel::snowman(11112311)) == erase_spaces(" _===_ \n\\(.,.)\n ( : )\\\n ( : )"));

    CHECK(erase_spaces(ariel::snowman(44444443)) == erase_spaces(" ___\n(_*_)\n(- -)\n(   )\n(___)"));
    
    CHECK(erase_spaces(ariel::snowman(11114411)) == erase_spaces("_===_\n(.,.)\n( : )\n( : )"));
    
}


TEST_CASE("Invalid input - negative") {

    CHECK_THROWS(ariel::snowman(-222));
    CHECK_THROWS(ariel::snowman(-1));
    CHECK_THROWS(ariel::snowman(-23454321));
     
}

TEST_CASE("Invalid input - more then 8 digits") {

    CHECK_THROWS(ariel::snowman(343212443));
    CHECK_THROWS(ariel::snowman(143212422));
    CHECK_THROWS(ariel::snowman(333212411));
    CHECK_THROWS(ariel::snowman(211112441));
  
}

TEST_CASE("Invalid input - less then 8 digits") {

    CHECK_THROWS(ariel::snowman(222));
    CHECK_THROWS(ariel::snowman(23));
    CHECK_THROWS(ariel::snowman(1234567));
    CHECK_THROWS(ariel::snowman(234567)); 
    
}

TEST_CASE("Invalid input - digits not in range [1,4]") {

    CHECK_THROWS(ariel::snowman(44445532));
    CHECK_THROWS(ariel::snowman(55555555));
    CHECK_THROWS(ariel::snowman(34567123));
    CHECK_THROWS(ariel::snowman(88888888));
    
    
}

