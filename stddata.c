#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[13];
    long int rollNo;
    int marks[5];
    char status;
    char category;
    int noGrace;
    int noFail;
    struct student *next;
}*head,*ptr,*ptr1;
void insertbeg(int,int);
void insertend(int,int);
void insertmiddle(int,int);
void deletebeg();
void deleteend();
void deletemiddle();
int numberofdigits(int);
void listOfFailedStudents();
void checkingForFailed(struct student *,int,int);
void addgrace(struct student *,int,int,int);
void listOfTotalStudents();
void listOfGracedStudents();
void listOfPassStudents();
int conditionGraced(int,int);
int conditionFailed(int,int);

int conditionGraced(int n,int num){
    switch(n){
        case 1: if(ptr->category=='g'){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;

        case 2: if(ptr->status=='p' && ptr->category=='g'){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;

        case 3: if(ptr->status=='f' && ptr->category=='g'){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;

        case 4: if(ptr->category=='g' && ptr->noGrace==num){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;

    }
}
int conditionFailed(int n,int m){
    switch(n){
        case 1: if(ptr->status=='f'){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;

        case 2: if(ptr->noFail==m){
                    return 1;
                    }
                else{
                    return 0;
                }
                break;
    }
}

int numberofdigits(int n){
    int count=0;
    while(n!=0){
        count++;
        n=n/10;
    }
    return count;
}
void insertbeg(int passmarks, int grace){
 struct student *std=(struct student *)malloc(sizeof(struct student));
    printf("Enter the name-\n");
    scanf(" %[^\n]s",&std->name);
    printf("Enter the Roll No-\n");
    scanf(" %d",&std->rollNo);
    printf("Enter the marks for each subject one by one-\n");
    for(int i=0; i<5 ; i++){
        scanf(" %d",&std->marks[i]);
    }
    std->next=head;
    head=std;
    checkingForFailed(std,passmarks,grace);
}
void insertend(int passmarks, int grace){
struct student *std=(struct student *)malloc(sizeof(struct student));
    printf("Enter the name(max 12 spaces)-\n");
    scanf(" %[^\n]",&std->name);
    printf("Enter the Roll No-\n");
    scanf(" %d",&std->rollNo);
    printf("Enter the marks for each subject one by one-\n");
    for(int i=0; i<5 ; i++){
        scanf(" %d",&std->marks[i]);
    }
if(!head){
    std->next=head;
    head=std;
}
else{
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    std->next=NULL;
    ptr->next=std;
}
checkingForFailed(std,passmarks,grace);
}
void insertmiddle(int passmarks,int grace){
    int p,count=0;
    printf("Enter the postion where you want to insert data-\n");
    scanf(" %d",&p);
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    if(p>count){
        printf("This position doesn't exist.\n");
    }
    else{
        struct student *std=(struct student *)malloc(sizeof(struct student));
        printf("Enter the name(max 12 spaces)-\n");
        scanf(" %[^\n]s",&std->name);
        printf("Enter the Roll No-\n");
        scanf(" %d",&std->rollNo);
        printf("Enter the marks for each subject one by one-\n");
            for(int i=0; i<5 ; i++){
                scanf(" %d",&std->marks[i]);
            }
        ptr=head;
        for(int i=1; i<p-1; i++){
            ptr=ptr->next;
        }
        std->next=ptr->next;
        ptr->next=std;
        checkingForFailed(std,passmarks,grace);
    }
}
void deletebeg(){
    if(!head){
        printf("NO STUDENT DATA\n");
    }
    else{
        ptr=head;
        head=ptr->next;
        ptr->next=NULL;
        free(ptr);
    }
}
void deleteend(){
    if(!head){
        printf("NO STUDENT DATA\n");
    }
    else{
        ptr=head;
        if(ptr->next==NULL){
            head=NULL;
            free(ptr);
        }
        else{
            ptr1=ptr->next;
            while(ptr1->next!=NULL){
                ptr1=ptr1->next;
                ptr=ptr->next;
            }
            ptr->next=NULL;
            free(ptr1);
        }
    }
}
void deletemiddle(){

    if(!head){
        printf("NO STDUENT DATA\n");
    }
    else{
        int p,count=0;
        printf("Enter the position.\n");
        scanf(" %d",&p);
        ptr=head;
        while(ptr!=NULL){
            ptr=ptr->next;
            count++;
        }
        if(p>count){
            printf("This position doesn't exist,\n");
        }
        else{
            ptr=head;
            ptr1=ptr->next;
            for(int j=1; j<p-1 ; j++){
                ptr1=ptr1->next;
                ptr=ptr->next;
            }
            ptr->next=ptr1->next;
            free(ptr1);
        }

    }
}

void listOfTotalStudents(){
    if(!head){
        printf("NO DATA OF STUDENTS INSERTED\n");
    }
    else{
        ptr=head;
        ptr1=head;
        printf("NAME                ROLL NO         SUBJECT1        SUBJECT2        SUBJECT3        SUBJECT4        SUBJECT5\n");
        while(ptr!=NULL){
            int i1=0,s1=numberofdigits(ptr->marks[0]),s2=numberofdigits(ptr->marks[1]),s3=numberofdigits(ptr->marks[2]),s4=numberofdigits(ptr->marks[3]),r=numberofdigits(ptr->rollNo);
            for(; ptr->name[i1]!='\0'; i1++){
                printf("%c",ptr->name[i1]);
            }
            for(int j =1; j<=20-i1; j++){
                printf(" ");
            }
            printf("%d",ptr->rollNo);
            for(int j =1; j<=16-r; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[0]);

            for(int j =1; j<=16-s1; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[1]);

            for(int j =1; j<=16-s2; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[2]);

            for(int j =1; j<=16-s3; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[3]);

            for(int j =1; j<=16-s4; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[4]);

            ptr=ptr->next;
            printf("\n");
        }
       
    }
}
void listOfFailedStudents(){
    int n,m;
    printf("1)List of all students failed\n2)List of students who failed some subjects\n");
    scanf(" %d",&n);
    if(n==2){
    printf("Enter the number of subjects failed-\n");
        while(m>5 || m<0){
        scanf(" %d",&m);
        if(m>5 || m<0){
            printf("INVALID\n");
        }
        }
}
    if(!head){
        printf("NO DATA OF STUDENTS INSERTED\n");
    }
    else{
        ptr=head;
        ptr1=head;
        printf("NAME                ROLL NO         SUBJECT1        SUBJECT2        SUBJECT3        SUBJECT4        SUBJECT5\n");
        while(ptr!=NULL){
                if(conditionFailed(n,m)){
                        int i1=0,s1=numberofdigits(ptr->marks[0]),s2=numberofdigits(ptr->marks[1]),s3=numberofdigits(ptr->marks[2]),s4=numberofdigits(ptr->marks[3]),r=numberofdigits(ptr->rollNo);
                        for(; ptr->name[i1]!='\0'; i1++){
                            printf("%c",ptr->name[i1]);
                        }
                        for(int j =1; j<=20-i1; j++){
                            printf(" ");
                        }
                        printf("%d",ptr->rollNo);
                        for(int j =1; j<=16-r; j++){
                            printf(" ");
                        }

                        printf("%d",ptr->marks[0]);

                        for(int j =1; j<=16-s1; j++){
                            printf(" ");
                        }

                        printf("%d",ptr->marks[1]);

                        for(int j =1; j<=16-s2; j++){
                            printf(" ");
                        }

                        printf("%d",ptr->marks[2]);

                        for(int j =1; j<=16-s3; j++){
                            printf(" ");
                        }

                        printf("%d",ptr->marks[3]);

                        for(int j =1; j<=16-s4; j++){
                            printf(" ");
                        }

                        printf("%d",ptr->marks[4]);

                        printf("\n");
                }
                    ptr=ptr->next;
            }
    }
}
void listOfGracedStudents(){
    int n,num=0;
    printf("1)List of all graced students\n2)List of Graced students who passed\n3)List of graced students who didn't pass all subjects\n4)List of students graced in specific number of subjects\n");
    scanf(" %d",&n);
    if(n==4){
        printf("Enter the number of graced subjects\n");
                scanf(" %d",&num);
    }
    if(!head){
        printf("NO DATA OF STUDENTS INSERTED\n");
    }
    else{

        ptr=head;
        ptr1=head;
        printf("NAME                ROLL NO         SUBJECT1        SUBJECT2        SUBJECT3        SUBJECT4        SUBJECT5\n");
        while(ptr!=NULL){
            if(conditionGraced(n,num)){
                int i1=0,s1=numberofdigits(ptr->marks[0]),s2=numberofdigits(ptr->marks[1]),s3=numberofdigits(ptr->marks[2]),s4=numberofdigits(ptr->marks[3]),r=numberofdigits(ptr->rollNo);
            for(; ptr->name[i1]!='\0'; i1++){
                printf("%c",ptr->name[i1]);
            }
            for(int j =1; j<=20-i1; j++){
                printf(" ");
            }
            printf("%d",ptr->rollNo);
            for(int j =1; j<=16-r; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[0]);

            for(int j =1; j<=16-s1; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[1]);

            for(int j =1; j<=16-s2; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[2]);

            for(int j =1; j<=16-s3; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[3]);

            for(int j =1; j<=16-s4; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[4]);

            
            printf("\n");
            }
            ptr=ptr->next;
        }
    
    }
}
void listOfPassStudents(){
    if(!head){
        printf("NO DATA OF STUDENTS INSERTED\n");
    }
    else{
        ptr=head;
        ptr1=head;
        printf("NAME                ROLL NO         SUBJECT1        SUBJECT2        SUBJECT3        SUBJECT4        SUBJECT5\n");
        while(ptr!=NULL){
            if(ptr->status!='f'){
                int i1=0,s1=numberofdigits(ptr->marks[0]),s2=numberofdigits(ptr->marks[1]),s3=numberofdigits(ptr->marks[2]),s4=numberofdigits(ptr->marks[3]),r=numberofdigits(ptr->rollNo);
            for(; ptr->name[i1]!='\0'; i1++){
                printf("%c",ptr->name[i1]);
            }
            for(int j =1; j<=20-i1; j++){
                printf(" ");
            }
            printf("%d",ptr->rollNo);
            for(int j =1; j<=16-r; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[0]);

            for(int j =1; j<=16-s1; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[1]);

            for(int j =1; j<=16-s2; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[2]);

            for(int j =1; j<=16-s3; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[3]);

            for(int j =1; j<=16-s4; j++){
                printf(" ");
            }

            printf("%d",ptr->marks[4]);

            
            printf("\n");
            }
            ptr=ptr->next;
        }
    
    }
}

void checkingForFailed(struct student *std,int passmarks, int grace){
    int noOfFailedSubjects=0;
    for(int i=0 ; i<5 ; i++){
        if(std->marks[i]<passmarks){
            noOfFailedSubjects++;
        }
    }
    std->status='p';
    std->category='n';
    std->noFail=0;
    std->noGrace=0;
    if(noOfFailedSubjects!=0){
        addgrace(std,noOfFailedSubjects,passmarks,grace);
    }
}
void addgrace(struct student *std,int noOfFailedSubjects,int passmarks,int grace){
            int k=noOfFailedSubjects;
            for(int i=0; i<5 ; i++){
                if(std->marks[i]<passmarks && std->marks[i]>=passmarks-grace){
                    std->marks[i]=passmarks;
                    noOfFailedSubjects--;
                }  
            }
           if(noOfFailedSubjects!=0){
                std->status='f';
           }
           else{
                std->status='p';
           }
           if(k>noOfFailedSubjects){
                std->category='g';
           }
           else{
                std->category='n';
           }
           std->noFail=noOfFailedSubjects;
           std->noGrace=k-noOfFailedSubjects;

}

int main(){
    head=NULL;
    int n,i,grace,passmarks;
    char c='y';
    printf("This is a program to store the data of students.\n");
    printf("Enter the min marks required by a student to pass--\n");
    scanf(" %d",&passmarks);
    printf("Enter the number of max grace marks that can be given-\n");
    scanf(" %d",&grace);
while(c=='y' || c=='Y'){
    printf("Function you want to perform\n1)Insert Student Data\n2)Delete Student Data\n3)List Of Students\n4)List Of Graced Students\n5)List Of Failed Students\n6)List Of Pass Students\n");
    scanf(" %d",&n);
    switch(n){
            case 1:{ printf("1)Beginning\n2)Midlle\n3)End\n");
                    scanf(" %d",&i);
                        switch(i){
                            case 1: insertbeg(passmarks,grace);
                                    break;
                            case 2: insertmiddle(passmarks,grace);
                                    break;
                            case 3: insertend(passmarks,grace);
                        }
                    break;
            }
            case 2: { printf("1)Beginning\n2)Midlle\n3)End\n");
                    scanf(" %d",&i);
                        switch(i){
                            case 1: deletebeg();
                                    break;
                            case 2: deletemiddle();
                                    break;
                            case 3: deleteend();
                        }
                    break;
            }
                    break;
            case 3: listOfTotalStudents();
                    break;
            case 4: listOfGracedStudents();
                    break;
            case 5: listOfFailedStudents();
                    break;
            case 6: listOfPassStudents();
                    break;
            default: printf("INVALID\n");
                        break;
    }
    printf("Do you want to perform another function?\n");
    scanf(" %c",&c);
}
ptr=head;
while(head!=NULL){
    ptr=head;
    head=head->next;
    free(ptr);
}
}
//