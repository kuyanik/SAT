#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool check_match(vector<int> arr,vector<int> key){

	for(int i=0; i<arr.size(); i++){
		for(int j=0; j<key.size(); j++){
			if(arr[i] == key[j]){
				return 1;
			}
		}
	}
	return 0;
}

int find_last_negative(vector<int> key){
	int i = 0;
	int index = 0;
	int size = key.size();

	while(i < size){
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
void alter_key(vector<int>& key,int& full_loop){

	int last_index = key.size() - 1;

	if(is_all_positive(key) == 1){
		key[0] *= -1;
	}

	else if(is_all_negative(key) == 1){
		full_loop = 1;
	}

	else if( key[last_index] != abs( key[last_index] ) ){ // if last item is negative
		key[last_index] *= -1;
		int last_negative_index = find_last_negative(key); //finding the last negative item
		key[last_negative_index+1] *= -1;
		key[last_negative_index+2] *= -1;
	}
	else{
		int last_negative_index = find_last_negative(key); //finding the last negative item
		key[last_negative_index] *= -1;
		key[last_negative_index+1] *= -1;
	}
}
vector<int> create_key(int variable){
	vector<int> new_key;
	for(int i =1; i<=variable ;i++){
		new_key.push_back(i);
	}
	return new_key;
}

int main(){

	vector< vector<int> > arr;
	arr.resize(100);

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
	int full_loop = 0;
	int match = 1;
	vector<int> key = create_key(4);

	while(full_loop != 1){
		int j = 0;
		while(j < arr.size()){
			match = check_match(arr[j],key);
			++j;
			if(match == 0)
				break;
		}
		alter_key(key,full_loop);
		if(match == 1)
			break;
	}
	cout<<"writing the key: ";
	for(int i = 0;i < key.size();i++)
	cout<<key[i]<<" ";

	return 0;
}
