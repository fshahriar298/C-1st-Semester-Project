#include<stdio.h>
int menu( int bundle_offer,float offer_percentage,int coupon_code,float coupon_discount);
int main()
{
    printf("Name : Shahriar MD Fahim\nID: 1211205362\n\n");


    //owner inter face
    int bundle_offer=0;
    float offer_percentage=0;
    int user_owner_choice;
    int owner_choice;
    char close;
    int coupon_code=0;
    float coupon_discount=0;

    float daily_total_sell=0;


    int total_coustomer=0;
    float daily_sell[total_coustomer];

    printf("(Pass : 123)\n\nContinue as a owner enter password : \nAs a customer press 2 ==> 2 : ");
    scanf("%d",&user_owner_choice);

    while (user_owner_choice>0){

    if  (user_owner_choice==123){

        printf("\n\n*****************FAHIM FOODS*****************\n");
        printf("For making coupons press      ==> 1 : \n");
        printf("For making bundle offer press ==> 2 : \n");
        printf("For showing todays total sell ==> 3 : \n");
        printf("For todays total customer     ==> 4 : \n");
        printf("For exit from admin panel     ==> 5 : \n");
        scanf("%d",&owner_choice);

        switch (owner_choice)
        {
        case 1 :
            printf("Make coupon code : ");
            scanf("%d",&coupon_code);

            printf("Set coupon discount percentage :");
            scanf("%f",&coupon_discount);


            break;

        case 2 :
            printf("Provide offer minimum bundle amount    : ");
            scanf("%d",&bundle_offer);

            printf("Set bundle discount percentage :");
            scanf("%f",&offer_percentage);

            break;

        case 3 :

            for(int p=0;p<total_coustomer;p++){
                daily_total_sell=daily_total_sell+daily_sell[p];
            }
            printf("Today total sell ==> %.2f",daily_total_sell);

            break;

        case 4 :

            printf("Todays total customer ==> %d",total_coustomer);

            break;

        case 5 :
            printf("\n\nContinue as a owner enter password\nAs a customer press 2 ==> 2 : ");
            scanf("%d",&user_owner_choice);

            break;

        default : printf("Invalid choice");
            break;
        }

    }

    else if (user_owner_choice==2){

        daily_sell[total_coustomer]=menu(bundle_offer,offer_percentage,coupon_code,coupon_discount);
        total_coustomer++;

        printf("For login addmin panel press password : \n");
        printf("Continue as a customer press 2 ==> 2  : ");
        scanf("%d",&user_owner_choice);
    }
    else{
        printf("Invalid choice try again\n");

        printf("\n\nContinue as a owner enter password :\nAs a customer press 2 ==> 2 : ");
        scanf("%d",&user_owner_choice);
    }
    }



    getchar();
}
int menu(int bundle_offer,float offer_percentage,int coupon_code,float coupon_discount)
{
    int order_list_num;
    int quantity;

    char foods[11][20]={{"Nasi limak"}, {"Mi goren"}, {"Tomiyum"}, {"Ayam fries"}, {"Daging"}, {"Pizza"}, {"Shawrma"}, {"Burger"}, {"Rice"}, {"Roti"}, {"Salad"}};
    char drink[11][15]={{"Coca Cola"}, {"Pepsi"}, {"Sprite"}, {"7 Up"}, {"Teo ice"}, {"Milo ice"}, {"Limu ice"},{"Mirinda"},{"Hot water"},{"Water"},{"Milk tea"}};

    float foods_prices[11]={6.5,5.5,8.5,5,6,15,5.5,8,2,1.5,5};
    float drinks_price[11]={2,2,2,2,1.5,1.5,1.5,2,1,1,2.8};

    printf("\n***********************************************FAHIM FOODS***********************************************\n");
    printf("\n\nFoods list\t\t Price\t\t\t\tDrinks\t\t\t Price\n");
    printf("----------------------------------------------------------------------------------------------------------\n");


    if(0<bundle_offer&&offer_percentage>0.0){

    printf("\n\t\t If you purchase %d RM you will get %.2f percent discount\n\n\n",bundle_offer,offer_percentage);
    }



    for(int i=0;i<11;i++){


        printf("%d : %s \t\t RM %.2f\t\t\t%d : %s \t\t RM %.2f \n",i+1, foods[i], foods_prices[i],i+12,drink[i],drinks_price[i]);


    }

    char choice;
    int user_choice=0;

    int order_array[user_choice][2];

    do {

    printf("\nChoose your order list number : ");
    scanf("%d",&order_list_num);

    while(order_list_num<1||order_list_num>22){
        printf("Invalid choice\n");
        printf("Choose your order list number : ");
        scanf("%d",&order_list_num);
    }
        printf("Enter your quantity : ");
        scanf("%d",&quantity );

    order_array[user_choice][0]=order_list_num;
    order_array[user_choice][1]=quantity;

    user_choice++;



    if (order_list_num<=11){
        printf("Foods=> %s Qty : %d RM : %.2f ", foods[order_list_num-1],quantity,foods_prices[order_list_num-1]*quantity);
    }
    else{
        printf("Drink=> %s Qty : %d RM : %.2f ", drink[order_list_num-12],quantity,drinks_price[order_list_num-12]*quantity);
    }

    printf("\nDo you want to continue order ? Y or N : ");
    scanf(" %c",&choice);

    }
    while(choice=='Y'||choice=='y');

    float total_price=0;

    int x;

    for(x=0;x<user_choice;x++){


    printf("\n\n");

    order_list_num=order_array[x][0];
    quantity=order_array[x][1];


    if (order_list_num<=11){
        total_price=total_price+(foods_prices[order_list_num-1]*quantity);
        printf("Foods=> %s Qty : %d RM : %.2f ", foods[order_list_num-1],quantity,foods_prices[order_list_num-1]*quantity);
    }
    else{
        total_price=total_price+(drinks_price[order_list_num-12]*quantity);
        printf("Drink=> %s Qty : %d RM : %.2f ", drink[order_list_num-12],quantity,drinks_price[order_list_num-12]*quantity);
    }

    }
    printf("\n-----------------------------------");
    printf("\nTotal bill => %.2f\n\n",total_price);


    if(total_price>=bundle_offer&&offer_percentage>0.0){

    printf("\n\nDiscount amount : %.2f\n",(offer_percentage*total_price)/100);

    printf("\nAfter discount total price : %.2f\n\n\n\n",total_price-(offer_percentage*total_price)/100);
    total_price=total_price-(offer_percentage*total_price)/100;
    }



    int user_coupon_code;

    if(coupon_code!=0){

    printf("\n\nDo you have any coupon ? : ");
    scanf("%d",&user_coupon_code);
    }

    if(user_coupon_code==coupon_code){

    printf("\n\nDiscount amount : %.2f\n",(coupon_discount*total_price)/100);

    printf("\nAfter discount total price : %.2f\n\n\n\n",total_price-(coupon_discount*total_price)/100);
    }



    return total_price;

}

