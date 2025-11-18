#include <stdio.h>
#include <string.h>
#define INITIAL_COUNT 5
#define MAX_ARRAY_SIZE 50

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;


void print_students(Student arr[], int count);
void delete_student(Student arr[], int *count_ptr);

int main() {

    Student students[MAX_ARRAY_SIZE];

    students[0] = (Student){101, "Nguyen Van A", 20, "0901111111"};
    students[1] = (Student){102, "Tran Thi B", 21, "0902222222"};
    students[2] = (Student){103, "Le Van C", 22, "0903333333"};
    students[3] = (Student){104, "Pham Thi D", 19, "0904444444"};
    students[4] = (Student){105, "Hoang Van E", 20, "0905555555"};

    int current_student_count = INITIAL_COUNT; 

    printf("--- Danh sach sinh vien ban dau (%d sinh vien) ---\n", current_student_count);
    print_students(students, current_student_count);

    delete_student(students, &current_student_count);

    printf("\n--- Danh sach sinh vien sau khi xoa (%d sinh vien) ---\n", current_student_count);
    print_students(students, current_student_count);

    return 0;
}

void print_students(Student arr[], int count) {
    int i;
    if (count == 0) {
        printf("Mang hien tai KHONG co sinh vien nao.\n");
        return;
    }
    printf("-----------------------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("ID: %d | Ten: %-20s | Tuoi: %d | SDT: %s\n", 
               arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
    printf("-----------------------------------------------------------------\n");
}

void delete_student(Student arr[], int *count_ptr) {
    int search_id;
    int found_index = -1; 
    int current_count = *count_ptr;
    int i;

    printf("\n\n--- CHUC NANG XOA SINH VIEN ---\n");
    if (current_count == 0) {
        printf("Danh sach hien tai dang trong. Khong the xoa.\n");
        return;
    }
    
    printf("Nhap ID (Ma sinh vien) can xoa: ");
    if (scanf("%d", &search_id) != 1) {

        while(getchar() != '\n');
        printf("Loi nhap lieu ID.\n");
        return;
    }

    for (i = 0; i < current_count; i++) {
        if (arr[i].id == search_id) {
            found_index = i;
            break; 
        }
    }


    if (found_index == -1) {

        printf("-> KHONG TIM THAY sinh vien co ID: %d trong danh sach.\n", search_id);
    } else {

        printf("-> Tim thay sinh vien ID %d (%s). Tien hanh xoa...\n", 
               arr[found_index].id, arr[found_index].name);
        for (i = found_index; i < current_count - 1; i++) {
            arr[i] = arr[i + 1]; 
        }
        (*count_ptr)--; 

        printf("-> XOA THANH CONG sinh vien ID %d. Danh sach da cap nhat.\n", search_id);
    }
}
