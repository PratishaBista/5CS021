//create a user defined datatype

// #include <stdio.h>


// struct Person {
//     char name[50];
//     int age;
// };

// int main () {
//     struct Person p1;

//     printf("Enter the name: ");
//     scanf("%s", p1.name);

//     printf("Enter the age: ");
//     scanf("%d", &p1.age);

//     printf(p1.name, p1.age);

//     return 0;

// }

//use of typedef keyword in c
// #include <stdio.h>


// struct Person {
//     char name[50];
//     int age;
// };

// typedef struct Person Person;

// int main () {
//     Person p1;

//     printf("Enter the name: ");
//     scanf("%s", p1.name);

//     printf("Enter the age: ");
//     scanf("%d", &p1.age);

//     printf(p1.name, p1.age);

//     return 0;

// }


//Create a structure for students(roll,name,address,mark) and access the members
// #include <stdio.h>

// struct Student {
//     char name[50];
//     int roll;
//     char address[50];
//     float mark;

// };

// typedef Student Student;

// int main () {
//     Student s1;
//     printf("Enter the name: ");
//     scanf("%s", &s1.name);

//     printf("Enter the roll: ");
//     scanf("%d", &s1.roll);

//     printf("Enter the address: ");
//     scanf("%s", &s1.address);

//     printf("Enter the mark: ");
//     scnaf("%f", &s1.mark);
//     printf("Name: %s\n", s1.name);
//     printf("Roll: %d\n", s1.roll);
//     printf("Address: %s\n", s1.address);
//     printf("Mark: %f\n", s1.mark);
//     return 0;

// }

//Create a structure for students (roll no, name, address: {province, district, city, ward}, mark) and access the members


// #include <stdio.h>
// #include <string.h>

// struct Student {
//     int roll;
//     char name[50];
//     struct { 
//         char province[50];
//         char district[50];
//         char city[50];
//         char ward[50];
//     } address; 
//     float mark;
// };

// int main() {
//     struct Student s1;

//     strcpy(s1.name, "Ram");  
//     s1.roll = 1;
//     strcpy(s1.address.province, "Sindh");
//     strcpy(s1.address.district, "Lahore");
//     strcpy(s1.address.city, "Lahore");
//     strcpy(s1.address.ward, "Ward 1");
//     s1.mark = 90.0;

//     printf("Name: %s\n", s1.name);
//     printf("Roll: %d\n", s1.roll);
//     printf("Province: %s\n", s1.address.province);
//     printf("District: %s\n", s1.address.district);
//     printf("City: %s\n", s1.address.city);
//     printf("Ward: %s\n", s1.address.ward);
//     printf("Mark: %.2f\n", s1.mark);

//     return 0;
// }

// Create a structure named student that has a name, roll number
// and marks as members. Assume appropriate types and size of
// members. Use this structure to read and display records of 10
// students. Create two functions: One is to read information of
// students and other to display the information



// #include <stdio.h>

// struct Student {
//     char name[50];
//     int roll;
//     float marks;
// };

// void readInfo(struct Student s[]) {
//     int i;
//     printf("Enter the information of 10 students:\n");
//     for (i = 0; i < 10; i++) {
//         printf("Enter the name, roll, and marks of student %d: ", i + 1);
//         scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);  
//     }
// }

// void displayInfo(struct Student s[]) {
//     int i;
//     printf("\nThe information of 10 students are:\n");
//     for (i = 0; i < 10; i++) {
//         printf("Student %d:\n", i + 1);
//         printf("Name: %s\n", s[i].name);
//         printf("Roll: %d\n", s[i].roll);
//         printf("Marks: %.2f\n\n", s[i].marks);  
//     }
// }

// int main() {
//     struct Student s[10];  
//     readInfo(s);           
//     displayInfo(s);        
//     return 0;
// }

// Create a user-defined data type for storing 2D coordinate points.
// Take two points from the user and calculate the midpoint using
// the function.

