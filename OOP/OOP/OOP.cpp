
#include <iostream>
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsStringNew.h"

int main()
{ 

    clsStringNew S1("  kk  YYY uuu  o    p   o");

    string word = "mohammad HATEM";
    
    cout << clsStringNew::CountLetter(word, 'M');



    
    return 0;
}