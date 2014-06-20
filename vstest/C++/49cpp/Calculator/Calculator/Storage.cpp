#include "Storage.h"
#include <cmath>
#include "SymbolTable.h"
#include <cassert>
#include <iostream>
Storage::Storage(SymbolTable& tbl){
	AddConstants(tbl);
}
void Storage::Clear(){
	cells_.clear();
	inits_.clear();
}
bool Storage::IsInit(unsigned int id)const{
	return id < cells_.size() && inits_[id];
}
void Storage::AddConstants(SymbolTable& tbl){
	std::cout << "variable list:" << std::endl;
	unsigned int id = tbl.Add("e");
	AddValue(id,exp(1.0));
	std::cout << "e = " << exp(1.0) << std::endl;
	id = tbl.Add("pi");
	AddValue(id,2.0*acos(0.0));//·´ÓàÏÒ pi=2*acos(0.0)
	std::cout << "pi = " << 2.0*acos(0.0) << std::endl;
}
double Storage::GetValue(unsigned int id)const{
	assert(id<cells_.size());
	return cells_[id];
}
void Storage::SetValue(unsigned int id,double val){
	std::cout << "id= " << id << std::endl;
	std::cout << "cells_.size() " << cells_.size() << std::endl;
	assert(id>=0);

	if(id < cells_.size()){
		cells_[id]=val;
		inits_[id]=true;
	}
	else{
		AddValue(id,val);
	}

}
void Storage::AddValue(unsigned int id,double val){
	cells_.resize(id+1);
	inits_.resize(id+1);
	cells_[id]=val;
	inits_[id]=true;
}