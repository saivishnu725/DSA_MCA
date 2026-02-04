#include <iostream>

using namespace std;

int step_count = 1;

// minimum steps = (2^n)-1
// towerHanoi(disk_num, source, dest, aux)
void towerHanoi(int disk, char fromT, char toT, char auxT) {

	// if out of disks, exit
	if (disk <= 0)	return;
	
	// send n - 1 disk from source to aux
	// towerHanoi(disk_num, source, dest, aux)
	towerHanoi(disk - 1, fromT, auxT, toT);
	// print that it went from `fromT` to `toT` of current function call
	cout << step_count << " - Disk " << disk << " moved from " << fromT << " to " << toT << endl;
	step_count++;
	// send this n - 1 disk from aux to dest
	// towerHanoi(disk_num, source, dest, aux)
	towerHanoi(disk - 1, auxT, toT, fromT);
}

int main() {
	
	int disk;
	cout << "Number of disks: ";
	cin >> disk;
	if (disk < 1) {
		cout << "Number of disks should be >= 1" << endl;
		return 1;
	}
	
	/*
		* towers
		* A: from / source
		* B: aux
		* C: to / destination
	*/
	// towerHanoi(disk_num, source, dest, aux)
	towerHanoi(disk, 'A', 'C', 'B');
	
	return 0;
}
