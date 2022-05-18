#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>



int main(){
try{
	std::string iname {"input_floats.txt"};
	std::ifstream ifs {iname};
	if (!ifs) throw std::runtime_error("Could not read from file: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
	}
	for(auto elem : vd){
		std::cout << elem << '\n';
	}
	std::cout << std::endl;
	
	std::vector<int> vi(vd.size());
	std::copy(vd.begin(), vd.end(), vi.begin()); 
	for(auto elem : vi){
		std::cout << elem << '\n';
	}
	std::cout << std::endl;
	
	for(int i=0; i<vd.size(); i++){
		std::cout << vd[i] << '\t' << vi[i] << std::endl;
	}
	std::cout << std::endl;
	
	double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
	std::cout << "vd's sum: " << vd_sum << std::endl;
	
	std::cout << std::endl;
	double vi_sum = std::accumulate(vi.begin(), vi.end(), 0);
	std::cout << "The difference between vd_sum and vi_sum: " << vd_sum-vi_sum << std::endl;
	
	std::cout << std::endl;
	reverse(vd.begin(), vd.end());
	for(auto elem : vd){
		std::cout << elem << '\n';
	}
	std::cout << std::endl;
	
	double vd_mean = vd_sum / vd.size();
	std::cout << "VD mean: " << vd_mean << std::endl;
	
	std::vector<double> vd2;
	for(double d : vd){
		if (d < vd_mean){
			vd2.push_back(d);
		}
	}
	
	for(auto elem : vd2){
		std::cout << elem << '\n';
	}
	std::cout << std::endl;
	
	std::sort(vd.begin(), vd.end());
	for(auto elem : vd){
		std::cout << elem << '\n';
	}
	std::cout << std::endl;
}
catch(std::exception& e){
	std::cerr << e.what() << '\n';
	return 1;
}
catch(...){
	std::cerr << "Unexpected error occured.\n";
	return 2;
}
}
