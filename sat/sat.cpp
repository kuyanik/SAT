#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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



vector<int> alter_key(vector<int> key){

	int size = key.size();
	bool full_loop = 0;

	if( key[size-1] != abs( key[size-1] ) ){
		key[size-1] *= -1;
		full_loop = 1;
	}
	int last_negative_index = find_last_negative(key);

	if(full_loop == 1){
		key[last_negative_index+1] *= -1;
	}

	else if(last_negative_index != 0){
		key[last_negative_index] *= -1;
		key[last_negative_index+1] *= -1;
	}
	else
		key[last_negative_index] *= -1;
	return key;
}

int main(){

	vector<int> arr_ptr;

	ifstream infile;
	infile.open("example.txt");
	if (!infile){
		cout<< "Unable to open the file";
		exit(1);
	}

	int i = 0;
	int x;
	bool flag =0;

	while(infile >> x){
cout<<x<<endl;
		while(x != 0){
			if(x != '-'){
				if(flag ==1){
					arr_ptr.push_back(-x);
					flag = 0;
				}
				else{
					arr_ptr.push_back(x);
				}
			}
			else{
				flag = 1;
			}
		}
		i++:
	}

	infile.close();

	vector<int> key = {1,2,3};
	vector<int> trigger_key = {-1,-2,-3};
	/*int j =0;
	bool match = 1;
	bool trigger = 0;
	while(trigger != 1){

		if(key == trigger_key)
			trigger = 1;

		while(match != 0 && j<arr_ptr[j].size() ){

			match = check_match(arr_ptr[j],key);
			++j;
		}
		key = alter_key(key);
	}
*/
	return 0;
}
