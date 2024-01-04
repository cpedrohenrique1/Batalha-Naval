#include "batalhanaval.h"

int main(){
    BatalhaNaval b;
    try{
        b.start();
    }catch(std::string& e){
        std::cout << e << '\n';
    }
    return 0;
}