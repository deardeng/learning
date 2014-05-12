#include<stdio.h>
#include"l15.11.part.h"
#include"l15.11.process.h"
#include"l15.11.io.h"
#include<string.h>

static void total(void){
    Part_number p;
    Part part;
    Value total_value;

    total_value=0;
    for(p=last_part_number();p>0;p--)
        if(read_part(p,&part))
            total_value+=part.total_value;
    printf("Total value of inventory = %.2f\n",total_value);
}

static void new_part(char const *description,Quantity quantity,Value price_each){
    Part part;
    Part_number part_number;

    strcpy(part.description,description);
    part.quantity=quantity;
    part.total_value=quantity*price_each;

    part_number=next_part_number();
    write_part(part_number,&part);
    printf("%s is part number %lu\n",description,part_number);
}

static void buy_sell(char request_type,Part_number part_number,Quantity quantity,Value price_each){
    Part part;

    if(!read_part(part_number,&part))
        fprintf(stderr,"No such part\n");
    else{
        if(request_type=='b'){
            part.quantity+=quantity;
            part.total_value=quantity*price_each;
        }
        else{
            Value unit_value;
            if(quantity>part.quantity){
                printf("Sorry,only %hu in stock\n",part.quantity);
                return ;
            }
            unit_value=part.total_value/part.quantity;
            part.total_value-=quantity*unit_value;
            part.quantity-=quantity;
            printf("Total profit:$%.2f\n",quantity*(price_each-unit_value));
        }
        write_part(part_number,&part);
    }
}

static void delete(Part_number part_number){
    Part part;
    if(!read_part(part_number,&part))
        fprintf(stderr,"No such part\n");
    else{
        part.description[0]='\0';
        write_part(part_number,&part);
    }
}

static void print(Part_number part_number){
    Part part;
    if(!read_part(part_number,&part))
        fprintf(stderr,"No such part\n");
    else{
        printf("Part number %lu\n",part_number);
        printf("Description: %s\n",part.description);
        printf("Quantity on hand: %hu\n",part.quantity);
        printf("Total value: %.2f\n",part.total_value);
    }
}

static void print_all(void){
    Part_number p;
    Part part;
    printf("Part number Description     Quantity " "Total value\n");
    printf("----------- --------------- ---------   -----------\n");
    for(p=1;p<=last_part_number();p++)
        if(read_part(p,&part))
            printf("%11lu %-*.*s %10hu %11.2f\n",p,MAX_DESCRIPTION,MAX_DESCRIPTION,part.description,part.quantity,part.total_value);
}

int process_request(void){
    char request[MAX_REQUEST_LINE_LENGTH];
    char request_type[10];
    char description[DESCRIPTION_FIELD_LEN];
    Part_number part_number;
    Quantity quantity;
    Value price_each;
    char left_over[2];

    fputs("\nNext request?",stdout);
    if(fgets(request,MAX_REQUEST_LINE_LENGTH,stdin)==NULL)
        return  FALSE;

    if(sscanf(request,"%10s %ls",request_type,left_over)==1&&(strcmp(request_type,"end")==0||strcmp(request_type,"total")==0)){
        if(request_type[0]=='e')
            return FALSE;
        else
            total();
    }
    else if(sscanf(request,"new %20[^,],%hu,%lf %ls",description,&quantity,&price_each,left_over)==3){
        new_part(description,quantity,price_each);
    }
    else if(sscanf(request,"%s,%d,%d,%d,%s",request_type,&part_number,&quantity,&price_each,left_over)==4&&(strcmp(request_type,"buy")==0||strcmp(request_type,"sell")==0)){
        buy_sell(request_type[0],part_number,quantity,price_each);
    }
    else if(sscanf(request,"%s %u %s",request_type,&part_number,left_over)==2&&(strcmp(request_type,"delete")==0||strcmp(request_type,"print")==0)){
        if(request_type[0]=='d')
            delete(part_number);
        else 
            print(part_number);
    }
    else if(sscanf(request,"print %s %s",request_type,left_over)==1&&strcmp(request_type,"all")==0){
        print_all();
    }
    else{
        if(sscanf(request,"%10s",request_type)==1)
            fprintf(stderr,"Invalid request:%s\n",request_type);
    }
    return TRUE;
}
