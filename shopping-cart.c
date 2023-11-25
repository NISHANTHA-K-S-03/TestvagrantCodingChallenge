#include<stdio.h>
#include<math.h>

void main(){
    int unit_price[] = {1100, 900, 200, 100};
    float gst[] = {.18, .12, .28, .0};
    int quantity[] = {1, 4, 3, 2};
    int total_amount[4]; 
    int single_total[4];  
    int ind_gst_unit_amt[4];
    int ind_gst_amt[4];
    int i;
    int max = 0;
    int m = 0;

    //first quetion
    for(i=0;i<4;i++){
        ind_gst_unit_amt[i] = unit_price[i] * gst[i];
        ind_gst_amt[i] = ind_gst_unit_amt[i] * quantity[i];

        // to check product with max gst amount

        if(m<ind_gst_amt[i]){
            max = i;
            m = ind_gst_amt[i];
        }
    }
    printf("product of maximum gst is ");
    switch(max){
        case 0: printf("leather wallet\n");
                break; 
        case 1: printf("umbrella\n");
                break;
        case 2: printf("cigarette\n");
                break;
        case 3: printf("Honey\n");
                break;
    }

    // second question
    for(i=0;i<4;i++){
        // discount
        if(unit_price[i]<500){
        single_total[i] = (unit_price[i]+ind_gst_unit_amt[i]) * quantity[i];
        }
        else{
            unit_price[i] = unit_price[i] * 1.05;
            single_total[i] = (unit_price[i]+ind_gst_unit_amt[i]) * quantity[i];
        }
    }
    int add = 0;
    for(i=0;i<4;i++){
        // total amount
        add += single_total[i];
    }
    printf("total amount to be paid = %d ",add);
}
