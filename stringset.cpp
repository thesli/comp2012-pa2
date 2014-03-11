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

void toString(StringSet strset){
	cout << "Capacity:" << strset.getCapacity() << endl;
	cout << "SIZE: " << strset.getSize() << endl;
	cout << "arr: " << endl;
	cout << "\t" ;
	for (int i = 0; i < strset.getSize(); ++i)
	{		
		printf("%i[%s],", i, strset.getItem(i).c_str());
	}
	cout << endl << "endarr" << endl;
}

StringSet::StringSet(){
	arr = NULL;
	size = 0;
	capacity = 0;
}
StringSet::~StringSet(){
	delete[] arr;
}
StringSet::StringSet(const std::string& oneItem){	
	size = 1;
	capacity = 2;
	arr = new string[capacity];
	arr[size-1] = oneItem;	
}
StringSet::StringSet(const StringSet& otherSet){	
	size = otherSet.getSize();
	capacity = otherSet.getCapacity();	
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
	return (size==0);
}
bool StringSet::exists(const std::string& item) const{
	for (int i = 0; i < size; i++)
	{		
		if(item.compare(arr[i])==0){			
			return true;
		}
	}
	return false;
}
int StringSet::searchItem(const std::string& item) const{
	if(!exists(item)){
		return -1;
	}
	for (int i = 0; i < size; ++i)
	{	
		if(arr[i].compare(item)==0){
			return i;
		}
	}
}

bool StringSet::insert(const std::string& newItem){	
	if(exists(newItem)){
		return false;
	}
	if(capacity==0){
		capacity=2;
	}	
	if((size+1)>capacity){
		capacity = (size+1) * 2;
	}
	string* tempArr = new string[capacity];	
	for (int i = 0; i < size; ++i)
	{
		tempArr[i] = arr[i];
	}
	tempArr[size] = newItem;
	size++;
	arr = tempArr;	
	return true;
}
bool StringSet::remove(const std::string& item){
	if(!exists(item)){
		return false;
	}
	int index = searchItem(item);
	if((size-1)<(capacity/2)){
		capacity /=2;
	}
	if(size==1){
		arr[index].clear();
		capacity = 0;
		size--;	
		return true;
	}
	if(index==(size-1)){
		arr[index].clear();
		size--;
		return true;
	}
	for (int i = index; i < size-1; ++i)
	{
		arr[i] = arr[i+1];
	}	
	size--;		
	return true;
}

bool islowerAlpPos(string A,string B){	
	// A is at lower Position alphabetical-wise compare to B	
	int longerLength = (A.length() >= B.length()) ? A.length() : B.length();
	for (int i = 0; i < longerLength; i++)
	{
		if(tolower(B[i])==tolower(A[i])){
			continue;
		}
		if(tolower(B[i])>tolower(A[i])){			
			return true;
		}
		if(tolower(B[i])<tolower(A[i])){
			return false;
		}
	}	
	return true;
}

void StringSet::sort(){
	for (int i = 0; i < size-1; ++i)
	{
		if(islowerAlpPos(arr[i],arr[i+1])){
			continue;
		}else{
			string temp;
			temp = arr[i+1];
			arr[i+1] = arr[i];
			arr[i] = temp;
			i = -1;	
		}
	}
}
StringSet& StringSet::operator=(const StringSet& inputSet){	
	size = inputSet.getSize();
	capacity = inputSet.getCapacity();
	arr = new string[inputSet.getSize()];
	for (int i = 0; i < inputSet.getSize(); ++i)
	{
		arr[i] = inputSet.getItem(i);
	}	
}
bool StringSet::operator==(const StringSet& other) const{
	if(!(other.getSize()==size&&other.getCapacity()==capacity)){
		return false;
	}	
	for (int i = 0; i < size; ++i)
	{
		bool isExist = false;
		for (int j = 0; j < size; ++j)
		{
			if(other.getItem(j)==arr[i]){
				isExist = true;
			}
		}
		if(!isExist){
			return false;
		}
	}
	return true;
}
bool StringSet::operator!=(const StringSet& other) const{
	return !(*this==other);
}
StringSet& StringSet::operator+=(const StringSet& other){			
	for (int i = 0; i < other.getSize(); ++i)
	{
		insert(other.getItem(i));
	}
	return *this;
}
StringSet& StringSet::operator^=(const StringSet& other){				
	StringSet newSet;	
	for (int i = 0; i < size; ++i)
	{
		if(other.exists(arr[i])){
			newSet.insert(arr[i]);			
		}
	}	
	*this = newSet;
	return *this;
}
StringSet& StringSet::operator-=(const StringSet& other){	
	StringSet newSet;
	newSet = *this;
	for (int i = 0; i < size; ++i)
	{
		if(other.exists(arr[i])){
			newSet.remove(arr[i]);
		}
	}	
	*this = newSet;
	return *this;
}
void StringSet::deallocateArray(){
	delete[] arr;	
	capacity = 0;
	size = 0;
}
StringSet operator+(const StringSet& first, const StringSet& second){		
	StringSet firstClone = first;		
	StringSet secondClone = second;	
	StringSet result = (secondClone+=firstClone);	
	return result;
}
StringSet operator^(const StringSet& first, const StringSet& second){	
	StringSet firstClone = first;		
	StringSet secondClone = second;	
	StringSet result = (secondClone^=firstClone);
	return result;
}
StringSet operator-(const StringSet& first, const StringSet& second){	
	StringSet firstClone = first;		
	StringSet secondClone = second;	
	StringSet result = (secondClone-=firstClone);		
	return result;
}
std::ostream& operator<< (std::ostream& out, const StringSet& inputSet){	
	out << "{" ;
	for (int i = 0; i < inputSet.getSize(); i++)
	{
		out << inputSet.getItem(i) << ",";
	}
	if(inputSet.getSize()!=0){
		out << "\b}";
	}else{
		out << "}";
	}
	return out;
}
StringSet readSetFromFile(const char fileName[]){
	ifstream ifs;
	ifs.open(fileName);
	StringSet strset;
	string str;
	getline(ifs,str);
	int k = 0;
	while(getline(ifs,str)){
		printf("%d%s\n",k,str.c_str());
		strset.insert(str.c_str());
		k++;
	}
	ifs.close();
	return strset;
}
void writeSetToFile(const char fileName[], const StringSet& s){

}