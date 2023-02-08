#include<stdio.h>

int main()
{
    /*-----------------------------------------Structure Declaration-----------------------------------------*/
    // struct student
    // {
    //     int Roll_no;
    //     char Name[20];
    //     char Course[20];
    //     float fees;
    // }stud1, stud2;      //declaring variables along with structure declaration
    // struct student stud3, stud4;    //Declaring variable of 'struct student' type

    /*-----------------------------------------Typedef Declaration-----------------------------------------*/
    //Syntax: typedef Existing Datatype New Datatype
    // Eg: 
    // typedef int INTEGER;
    // INTEGER n = 5;
    // printf("%d",sizeof(n));

    typedef struct 
    {
        int Roll_no;
        char Name[20];
        char Course[20];
        float fees;
    }student;
    // student stud1;  //Note we have not written struct student stud1
    // printf("%d", sizeof(stud1));

    /*----------------------------------------Initializating Structures----------------------------------------*/
    // struct student
    // {
    //     int Roll_no;
    //     char Name[20];
    //     char Course[20];
    //     float fees;
    // }stud1 = {01, "Kush", "Btech", 45000};
    // struct student stud2 = {02, "Kush", "BCA", 40000}, stud3;

    /*------------------------------------Accessing Members of Structures------------------------------------*/
    // printf("Roll Number of Student: %d\n", stud1.Roll_no);
    // printf("Name of Student: %s\n", stud1.Name);
    // printf("Course of Student: %s\n", stud1.Course);
    // printf("Fees of Student: %f\n", stud1.fees);

    // printf("Enter Roll Number of Student 3: ");
    // scanf("%d", &stud3.Roll_no);
    // printf("Enter Fees of Student 3: ");
    // scanf("%f", &stud3.fees);

    // printf("Roll Number of Student 3: %d\n", stud3.Roll_no);
    // printf("Fees of Student 3: %f\n", stud3.fees);

    /*------------------------------------Copying and Comparing Structures------------------------------------*/
    // stud3 = stud1;      //copying structure
    // if (stud1.fees > stud2.fees)        //comapring individual member of structures
    // {
    //     printf("1 greater");
    // }
    
    /*-------------------------------------------Nested Structures-------------------------------------------*/
    //Structure 1 defination
    //Structure 2 defination
    // struct stuct_varname_3
    // {
            // member 1;
            // member 2
            // struct struct_var_1 mem 3
            // struct struct_var_2 mem 4
    // }

    /*-------------------------------------------Arrays of Structures-----------------------------------------*/
    // student stud[30];

    // stud[1].Roll_no = 1;
    // stud[1].fees = 45000;

    return 0;
}