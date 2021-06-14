#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
/*
"A strong password is determined by the usage of all characters."
Conditions:
1.at least one upper case, lowercase, special character.
2.at least 8 length.
3.at least 2 numbers.
Password suggestor:
Input : keshav123
Output : Suggested Password
k(eshav12G3
keshav1@A23
kesh!Aav123
ke(shav12V3
keGshav1$23
kesXhav@123
keAshav12$3
kesKhav@123
kes$hav12N3
$kesRhav123

Input :rakesh@1995kumar
Output : Your Password is Strong
*/
int random_number(int low, int up){
    int x = rand() % (up - low +1) + low;
    return x;
}
int random_number1(int low, int up,int special){
    int x = rand() % (up - low +1) + low;
    if(x != special){
        return x;
    }
    else{
        x = random_number1(low, up,special);
    }
}
int random_number2(int low, int up,int special,int special2){
    int x = rand() % (up - low +1) + low;
    if(x != special && x != special2){
        return x;
    }
    else{
        x = random_number2(low, up,special,special2);
    }
}
int random_number3(int low, int up,int special,int special2,int special3){
    int x = rand() % (up - low +1) + low;
    if(x != special && x != special2 && x != special3){
        return x;
    }
    else{
        x = random_number3(low, up,special,special2,special3);
    }
}
int random_number4(int low, int up,int special,int special2,int special3,int special4){
    int x = rand() % (up - low +1) + low;
    if(x != special && x != special2 && x != special3 && x != special4 ){
        return x;
    }
    else{
        x = random_number4(low, up,special,special2,special3,special4);
    }
}

int main(){
    srand(time(NULL));
    char schar[]="#@_&";
    char uprchar[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lwrchar[]="abcdefghijklmnopqrstuvwxyz";
    char num[]="1234567890";
    int check=0;
    bool a=true;
    bool b=true;
    bool c=true;
    bool d=true;

    char input[100];
    int suggestions=0;
    start:
    printf("Enter your New Password : ");
    scanf("%s",input);
    printf("---------------------------------------------------------------------\n");
    // TO CHECK WHETHER INPUT IS STRONG---------------------------------------
    for(int i=0;i<strlen(input);i++){
        for(int j=0;j<4 && a;j++){
            if(input[i]==schar[j] ){
                a = false;
            }
        }
    }
    for(int i=0;i<strlen(input);i++){
        for(int j=0;j<strlen(num) && d;j++){
            if(input[i]==num[j]){
                check++;
                if(check == 2){
                    d = false;
                }
            }
        }
        for(int j=0;j<strlen(lwrchar) && b;j++){
            if(input[i]==lwrchar[j] ){
                b = false;
            }
        }
        for(int j=0;j<strlen(uprchar) && c;j++){
            if(input[i]==uprchar[j] ){
                c = false;
            }
        }
    }
    if(strlen(input) < 8){
        printf("Your Password must contain 8 characters\n");
        goto start;
    }
    else if(a != true && b != true && c != true && d != true){
        printf("Strong\n");
    }
    // TO SUGGEST A STRONG PASSWORD:---------------------------------------------   
    else{
        printf("Your Password strength is Weak\nSuggested Passwords are : \n");
    char new_password[100];
    int x,y,z,w,u;
    suggest:
    if(a == true){
        x = random_number(0,strlen(input)-1);
       new_password[x] = schar[random_number(0,strlen(schar)-1)];
    }
    if(b == true){
        y = random_number1(0,strlen(input)-1,x);
       new_password[y] = lwrchar[random_number(0,strlen(lwrchar)-1)];
    }
    if(c == true){
        z = random_number2(0,strlen(input)-1,x,y);
       new_password[z] = uprchar[random_number(0,strlen(uprchar)-1)];
    }
    if(d == true && check==1){
        w = random_number3(0,strlen(input)-1,x,y,z);
       new_password[w] = num[random_number(0,strlen(num)-1)];
    }
    else if(d == true && check != 1){
        u = random_number3(0,strlen(input)-1,x,y,z);
       new_password[u] = num[random_number(0,strlen(num)-1)];
        w = random_number4(0,strlen(input)-1,x,y,z,u);
       new_password[w] = num[random_number(0,strlen(num)-1)];
    }
    int j=0;
    for(int i=0;i<=strlen(input);){
        if(j==x || j==y || j==z || j== w || j==u){
            j++;
            continue;
        }
        new_password[j]=input[i];
        j++;
        i++;
    }   
    printf("\t\t\t\t%s\n",new_password);
    }
    suggestions++;
    if(suggestions < 5){
        goto suggest;
    }
    getchar();
    getchar();
    return 0;
}
//program_by: Tejas    