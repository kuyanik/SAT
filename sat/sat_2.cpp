#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool check_match(vector<int> arr,vector<int> key){
	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < key.size(); j++){
			if(arr[i] == key[j]){
			        return true;
			}
			else
				continue;
		}
	}
	return false;
}

vector<int> create_key(int variable_count){ // creates a key of variable count
	vector<int> new_key;
	for(int i =1; i<=variable_count ;i++){
		new_key.push_back(i);
	}
	return new_key;
}

vector<int> solver (vector<vector<int>> arr, int var_count) { // my solving algorithm

	vector<int> key = create_key(var_count);
	vector<int> empty;
	int i = 0;
	while(i < key.size()){// random key
		if(rand() % 2 == 1){
			key[i] = key[i] * -1;
		}
		++i;
	}
	while(i < arr.size()){
		if(check_match(arr[i], key) == false){
			return empty;
		}
		++i;
	}
	return key;
}
int main(){
	srand(time(0));
	vector<int> temp;
	ifstream infile;
	infile.open("example.dimacs");
	if (!infile){
		cout<< "Unable to open the file";
		exit(1);
	}

	int x;
	string skip;
	getline(infile,skip,'f');
	while(infile >> x){
			temp.push_back(x);
	}

	infile.close();

	vector<vector<int>> arr;
	int var_count = temp[0];
	int clause_count = temp[1];
	int i = 0;
	while(i < clause_count){
		arr.push_back(vector<int>());
		++i;
	}
	i = 2;
	int j = 0;
	while(i < temp.size()) { // transfering temp to individual arrays
		if(temp[i] == 0){
			++j;
			++i;
		}
		else if(j<arr.size()) {
			arr[j].push_back(temp[i]);
			++i;
		}
	}
	vector<int> key,empty;
	cout<<"\nTESTING THE SOLVER " <<endl;
		while(key == empty) {
			key = solver(arr,var_count);
		}

	i = 0;
	while(i<key.size()){
		cout<<key[i]<<" ";
		++i;

	}

	return 0;
}
