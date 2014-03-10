/*
 * stringset.cpp
 *
 *      Author:  [Your Name] (   _________ @stu.ust.hk )
 *
 *      Implementation of the StringSet class
 *
 */

#include "stringset.h"
#include <string.h>
using namespace std;

StringSet::StringSet(){
	arr = NULL;
	size = 0;
	capacity = 0;
}
StringSet::~StringSet(){
	// delete arr;
}
StringSet::StringSet(const std::string& oneItem){	
	size = 1;
	capacity = 2;
	arr = new string[capacity];
	arr[size-1] = oneItem;
}
StringSet::StringSet(const StringSet& otherSet){
	size = otherSet.size;
	capacity = otherSet.capacity;
	arr = new string[capacity];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = otherSet.getItem(i);
	}
}
std::string StringSet::getItem(int index) const{	
	return arr[index];
}
int StringSet::getSize() const{	
	return size;
}
int StringSet::getCapacity() const{
	return capacity;
}
bool StringSet::isEmpty() const{
	return (sizeof(arr) == 0);
}
bool StringSet::exists(const std::string& item) const{
	for (int i = 0; i < size; ++i)
	{
		if(item.compare(arr[i])==0){
			return true;
		}
	}
	return false;
}
int StringSet::searchItem(const std::string& item) const{

}

bool StringSet::insert(const std::string& newItem){
	if(exists(newItem)){
		return false;
	}
	for (int i = 0; i < size; ++i)
	{
		cout << "arr" << i << arr[i] << endl;
	}
	string* temp = new string[capacity];
	for (int i = 0; i < size; ++i)
	{
		temp[i] = arr[i];
	}
	for (int i = 0; i < size; ++i)
	{
		cout << "temp" << i << temp[i] << endl;
	}
	delete[] arr;
	if((size)>capacity){
		cout << "capacity: " << capacity << endl;
		capacity *=2;
	}
	cout << "capacity" << capacity << endl;
	cout << "size" << size << endl;
	arr = new string[capacity+1];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = temp[i];
	}
	size++;
	arr[size] = newItem;
	for (int i = 0; i < size; ++i)
	{
		cout << "arr After:" << i << arr[i] << endl;
	}
	return true;
}
bool StringSet::remove(const std::string& item){

}
void StringSet::sort(){

}
StringSet& StringSet::operator=(const StringSet& inputSet){

}
bool StringSet::operator==(const StringSet& other) const{

}
bool StringSet::operator!=(const StringSet& other) const{

}
StringSet& StringSet::operator+=(const StringSet& other){

}
StringSet& StringSet::operator^=(const StringSet& other){

}
StringSet& StringSet::operator-=(const StringSet& other){

}
void StringSet::deallocateArray(){

}
StringSet operator+(const StringSet& first, const StringSet& second){

}
StringSet operator^(const StringSet& first, const StringSet& second){

}
StringSet operator-(const StringSet& first, const StringSet& second){

}
std::ostream& operator<< (std::ostream& out, const StringSet& inputSet){
	for (int i = 0; i < inputSet.getSize(); i++)
	{
		out << inputSet.getItem(i);
	}	
	return out;
}
StringSet readSetFromFile(const char fileName[]){

}
void writeSetToFile(const char fileName[], const StringSet& s){

}