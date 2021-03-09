/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */
#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int main() {
	//cout<<"hE"<<endl;
	 cout << ariel::snowman(33232124) << endl; 
	//  cout << ariel::snowman(33232122) << endl; 
	//  cout << ariel::snowman(21111111) << endl; 
	//  cout << ariel::snowman(11114411) << endl;    
	//  cout << ariel::snowman(22222222) << endl; 
	//  cout << ariel::snowman(33333333) << endl; 
	//  cout << ariel::snowman(44444444) << endl; 
	//  cout << ariel::snowman(12341234) << endl;
	//cout <<ariel::snowman(11114411)<<endl; 
	// string a = string("_===_\n(.,.)\n( : )\n( : )");
	// cout <<a <<endl;
	/* Should print:
_===_
(.,.)
( : )
( : )

	*/
	//cout << ariel::snowman(33232124) << endl;   
	/* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	// try {
	// 	cout << ariel::snowman(5) << endl;   // Exception - not a valid code
	// } catch (exception& ex) {
	//  	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	// }


	
	return 0;
}


