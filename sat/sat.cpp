#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool check_match(vector<int> arr,vector<int> key){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < key.size(); j++){
			if( arr[i] == key[j] )
				return 1;
		}
	}
	return 0;
}

vector<int> create_key(int variable_count){ // creates a key of variable count
	vector<int> new_key;
	for(int i =1; i<=variable_count ;i++){
		new_key.push_back(i);
	}
	return new_key;
}

void solver (vector<vector<int>> arr, vector<int> key, vector<int> &remember, int count) { // my solving algorithm

	int j = 0;
	bool match = 1;
	while(j < arr.size()-1 && key != remember) {
		if(!check_match(arr[j],key)) {
			match = 0;
		}
		++j;
	}

	if(match == 1 && key != remember) {
		cout<<"Printing the key : ";
		int k = 0;
		while(k < key.size()) {
			cout<<key[k]<<" ";
			++k;
		}
		cout<<endl;
		remember = key;
	}
	if(count < key.size()) {
		vector<int> key_positive = key;
		vector<int> key_negative = key;
		key_negative[count] *= -1;
		++count;
		solver(arr, key_positive, remember, count);
		solver(arr, key_negative, remember, count);
	}

}
int main(){

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

/*	for(int i = 0; i < temp.size(); ++i){// temp array raw form print
		cout<<temp[i];
	}
*/	vector< vector<int> > arr;
	arr.push_back( vector<int>() );
	int j = 0;
	int i = 2;
	int variable_count = temp[0];
	int clause_count = temp[1];

	while(i < temp.size() ){ // transfering temp to individual arrays
		if(temp[i] == 0){
			++j;
			++i;
			arr.push_back( vector<int>() );
		}
		else{
			arr[j].push_back(temp[i]);
			++i;
		}
	}

/*	cout<<"\nPrint Test"<<endl; // Printing the clauses
	i=0;
	j=0;
	while(j < arr.size() ){
		while(i < arr[j].size() ){
			cout<<arr[j][i];
			++i;
		}
		++j;
		i=0;
		cout<<endl;
	}
*/	vector<int> key = create_key(variable_count);
	vector<int> remember;
	cout<<"\nTESTING THE SOLVER " <<endl;
	solver(arr,key,remember,0);

	return 0;
}
