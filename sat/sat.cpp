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

vector<int> create_key(int variable){
	vector<int> new_key;
	for(int i =1; i<=variable ;i++){
		new_key.push_back(i);
	}
	return new_key;
}

int main(){

	vector< vector<int> > arr;

	ifstream infile;
	infile.open("example.txt");
	if (!infile){
		cout<< "Unable to open the file";
		exit(1);
	}

	int i = 0;
	int x;
	arr.push_back( vector<int>() );
	while(infile >> x){
		if(x !=0 ){
			arr[i].push_back(x);
		}
		else if (x == 0){
			++i;
			arr.push_back( vector<int>() );
		}
	}

	infile.close();

/*
cout<<arr.size()<<"-----\n";
for(int i = 0 ; i < arr.size() ; ++i){
	for(int k = 0; k < arr[k].size(); ++k){
		cout<< arr[i][k] <<endl;
	}
}
*/ cout<<arr[0][3]<<endl;
	return 0;
}
