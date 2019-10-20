#include <iostream>
#include <string>
#include <cstring>
struct Student {
    int id;
    double score;
    char name[10];
};
void admissionListSort(Student students[], int sizeOfStudents);


#include <iomanip>
void admissionListSort(Student students[], int sizeOfStudents)
{ 
	
	for(int i=0; i<sizeOfStudents; i++)
	{
		int min=i;
		for(int j=i+1; j<sizeOfStudents; j++)
		{
			if(students[j].score< students[min].score) min=j;
		}
		Student iii=students[i];
		students[i]=students[min];
		students[min]=iii;
	}
	for(int i=0; i<sizeOfStudents; i++)
	{
		int min=i;
		for(int j=i+1; j<sizeOfStudents; j++)
		{
			if( students[i].score!= students[j].score) break;
			if(strcmp(students[j].name, students[i].name)<0) min=j;
		}
		Student iii=students[i];
		students[i]=students[min];
		students[min]=iii;		
	}
	 
	
	return;
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
