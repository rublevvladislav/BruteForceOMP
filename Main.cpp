#include "BruteFunc.h"
#include <chrono>


int main(int argc, char* argv[]) {
	auto passwords = get_passwords_from_file("database.txt");
	auto start = std::chrono::high_resolution_clock::now();
	runDictBrute(passwords, md5("omnipote"));
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Time taken by function: "
		<< duration.count() << " microseconds" << std::endl;
}