#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct sat{

	vector< vector<int> > arr;
	int loop;
	int  full_loop;
	sat(){
		arr.resize(100);
		loop = 0;
		full_loop = 0;
	}
}

bool check_match(vector<int> arr,vector<int> key){

	for(int i; i<arr.size()-1; i++){

		for(int j; j<key.size()-1; j++){
			if(arr[i] == key[j])
				return 1;
		}
	}
	return 0;
}

int find_last_negative(vector<int> key){
	int i = 0;
	int index = 0;
	int size = key.size();

	while(i <= size-1){
		if( key[i] != abs(key[i]) )
			index = i;
			++i;
	}
	return index;
}

bool is_all_negative(vector<int> key){
	for(int i =0;i<key.size();i++){
		if(abs(key[i]) == key[i])
			return 0;
	}
	return 1;
}
bool is_all_positive(vector <int> key){
	for(int i =0;i<key.size();i++){
		if(abs(key[i]) != key[i])
			return 0;
	}
	return 1;
}
sat alter_key(sat box,int loop,int full_loop ){

	int last_index = key.size() -1;
	bool loop = 0; //checking if we are at the end
	int last_negative_index = find_last_negative(key); //finding the last negative item

	if(is_all_positive(key) == 1){
		key[0] *= -1;
	}

	if(is_all_negative(key) == 1)
		return (key,0,1);

	if( key[last_index] != abs( key[last_index] ) ){ // if last item is negative
		key[size-1] *= -1;
		loop = 1;
		return (key,1,0);
	}
	if(loop == 1){ //if we just did a full loop
		key[last_negative_index+1] *= -1;
		return key;
	}
	else{
		key[last_negative_index] *= -1;
		key[last_negative_index+1] *= -1;
		return key;
	}
}
int main(){

	sat my_box();

	ifstream infile;
	infile.open("example.txt");
	if (!infile){
		cout<< "Unable to open the file";
		exit(1);
	}

	int i = 0;
	int x;

	while(infile >> x){
	cout<<x<<endl;
		if(x !=0 ){
			arr[i].push_back(x);
		}
		else if (x == 0){
			++i;
		}
	}

	infile.close();

	while(full_loop != 1){
		while(match == 1 && j<arr_ptr[j].size() ){
			match = check_match(arr_ptr[j],key);
			++j;
		}
		key = alter_key(key);
	}

	return 0;
}
