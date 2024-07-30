#include <iostream>
#include <vector>
// given a sorted array A find a  given number in O(log(n))

int find(const std::vector<int>& A, int num)
{
	// give the size of the vector decide the middle point
	int low = 0;
	int high = A.size() -1;
	int mid = low + (high -low)/2;
	// std::cout<<"mid = "<<mid<< " low = "<<low<<" high = "<<high<<std::endl;
	// std::cout<<"--------------------------------"<<std::endl;
	int last_mid = mid;
	for (int i = 0; i < A.size(); i++)
	{
		// if num > A[mid] then go right
		if (num > A[mid])
		{
			// update mid and low
			low = mid;
			mid = low + (high -low)/2;
		}
		// if num < A[mid] then go left
		if (num < A[mid])
		{
			// update mid and high
			high = mid;
			mid = low + (high -low)/2;
		}
		if (num == A[mid])
		{
			// std::cout<< "got it num ="<< num<<" = A[mid]" <<A[mid]<<std::endl;
			return mid;
		}

		if (last_mid == mid)
		{
			return -2;
		}
		last_mid=mid;
		// std::cout<<"mid = "<<mid<< " low = "<<low<<" high = "<<high<<std::endl;

	}
}

int main()
{
	std::vector<int> array {1,2,3,4,6,7,8,9,11,14,19,21,34};
	int value = find(array,21);
	std::cout<< "the input has index "<<value +1<<" in the input arary"<<std::endl;
	value = find(array,5);
	std::cout<< "the input has index "<<value +1<<" in the input arary"<<std::endl;
	return 0;
}
