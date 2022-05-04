#include <vector>
#include <iostream>
#include <list>
#include <array>
#include <algorithm>



template<typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++=*p;
	}

	return f2;
}
	


int main(){

	constexpr int size = 10;

	int a_int[size] = {0,1,2,3,4,5,6,7,8,9};
	/*
	for(int a : a_int){
		std::cout << a << ' ';
	}
	*/

	std::vector<int> v_int = {0,1,2,3,4,5,6,7,8,9};
	/*
	for(int a : v_int){
		std::cout << a << std::endl;
	}
	*/

	std::list<int> l_int = {0,1,2,3,4,5,6,7,8,9};
	/*
	for(int a : l_int){
		std::cout << a << std::endl;
	}
	*/

	std::array<int, size> a2_int;
	std::copy(a_int, a_int+size, a2_int.begin());
	/*
	for(int a : a2_int){
		std::cout << a << std::endl;
	}
	*/

	std::vector<int> v2_int(size);
	std::copy(a_int, a_int + size, v2_int.begin());
	/*
	for(int a : v2_int){
		std::cout << a << std::endl;
	}
	*/

	std::vector<int> l2_int(size);
	std::copy(a_int, a_int + size, l2_int.begin());
	/*
	for(int a : l2_int){
		std::cout << a << std::endl;
	}
	*/

	int i = 0;
	while(i < size){
		a2_int[i] = a2_int[i] + 2;
		std::cout << a2_int[i] << '\n';
		i = i+1;
	}

	i=0;
	while(i < size){
		v2_int[i] = v2_int[i] + 3;
		std::cout << v2_int[i] << '\n';
		i = i+1;
	}

	i=0;
	while(i < size){
		l2_int[i] = l2_int[i] + 5;
		std::cout << l2_int[i] << '\n';
		i = i+1;
	}

	copy2(a2_int.begin(), a2_int.end(), v2_int.begin());
	/*
	for(int a : v2_int){
		std::cout << a << std::endl;
	}
	*/

	copy2(l2_int.begin(), l2_int.end(), a2_int.begin());
	/*
	for(int a : a2_int){
		std::cout << a << std::endl;
	}
	*/

	auto vp = std::find(v2_int.begin(), v2_int.end(), 3);
	if (vp != v2_int.end())
		std::cout << "v2: 3 was found at " << std::distance(v2_int.begin(), vp) - 1 << std::endl;

	else
		std::cout << "v2: 3 was not found" << std::endl;

	auto vp1 = std::find(l2_int.begin(), l2_int.end(), 27);
	if (vp1 != l2_int.end())
		std::cout << "l3: 27 was found at " << std::distance(l2_int.begin(), vp1) - 1 << std::endl;

	else
		std::cout << "l3: 27 was not found" << std::endl;
}

