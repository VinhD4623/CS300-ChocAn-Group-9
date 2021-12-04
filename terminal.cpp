#include "terminal.h"
#include "util.h"
#include <iostream>
#include "ChocAnDataCenter.h"

using namespace std;

Terminal::Terminal(){

    this->data_center = new ChocAnDataCenter();
}

Terminal::~Terminal(){
    
}