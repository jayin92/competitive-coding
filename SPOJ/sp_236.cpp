#include <iostream>
#include <string>
#include <cstring>
struct Student {
    int id;
    double score;
    char name[10];
};
void admissionListSort(Student students[], int sizeOfStudents);

void admissionListSort(Student students[], int sizeOfStudents){
	int n = sizeOfStudents;
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(students[j].score > students[j+1].score){
				Student temp = students[j];
				students[j] = students[j+1];
				students[j+1] = temp;
				continue;
			}
			if(students[j].score == students[j+1].score){
				if(strcmp(students[j].name, students[j+1].name) > 0){
					Student temp = students[j];
					students[j] = students[j+1];
					students[j+1] = temp;
					continue;
				}
			}
		}
	}
}

int main() {
    int n;
    Student students[5000];
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> students[i].id
            >> students[i].score
            >> students[i].name;
    }
    admissionListSort(students, n);
    for (int i = 0; i < n; i++) {
        std::cout << students[i].id
            << " " << students[i].score
            << " " << students[i].name
            << std::endl;
    }
    return 0;
}
