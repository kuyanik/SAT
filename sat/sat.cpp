#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool check_match(vector<int> arr,vector<int> key){
	bool equal = 0;
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < key.size(); j++){
			if( arr[i] == key[j] )
				equal = 1;
		}
		if(equal == 0)
			return 0;
		equal = 0;
	}
	return 1;
}

vector<int> create_key(int variable_count){ // creates a key of variable count
	vector<int> new_key;
	for(int i =1; i<=variable_count ;i++){
		new_key.push_back(i);
	}
	return new_key;
}

int power(int x, int y){
	if(y==0)
		return 1;

	return x * power(x,y-1);
}

bool all_negative(vector<int> arr){

	int i = 0;
	while(i < arr.size()){
		if( arr[i] == abs(arr[i]) )
			return 0;
		++i;
	}
	return 1;
}

bool solver ( vector< vector<int> > arr , vector<int> key , int count){

	int j = 0;
	bool flag = 0;
	while(j < arr.size() ){
		if( !check_match(arr[j],key) ){
			flag = 1;
			++j;
		}
		else{
			++j;
		}
	}

	if(flag != 1){
		cout<<"Printing the key :";
		int k = 0;
		while( k < key.size() ){
			cout<<key[k];
			++k;
		}
		return 1;
	}

	else if( !all_negative(key) ){
		return 0;
	}

	if( count <= key.size() ){
		vector<int> key_positive = key;
		vector<int> key_negative = key;
		key_negative[count] *= -1;
		return solver(arr,key_positive,++count);
		return solver(arr,key_negative,++count);
	}

}
int main(){

	vector<int> temp;
	ifstream infile;
	infile.open("example.txt");
	if (!infile){
		cout<< "Unable to open the file";
		exit(1);
	}

	int x;
	while(infile >> x){
		temp.push_back(x);
	}

	infile.close();

	for(int i = 0; i < temp.size(); ++i){// temp array filling
		cout<<temp[i];
	}
	vector< vector<int> > arr;
	arr.push_back( vector<int>() );
	int j = 0;
	int i = 0;
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

	cout<<"Test"<<endl; // Print testing
	i=0;
	j=0;
	while(j < arr.size() ){
		while(i < arr[j].size() ){
			cout<<arr[j][i];
			++i;
		}
		++j;
		i=0;
	}
	cout<<"\nTESTING THE SOLVER " <<endl;
	vector<int> key = create_key(4);
	cout<< "Solver outcome : "<<solver(arr,key,0)<<endl;
	return 0;
}
