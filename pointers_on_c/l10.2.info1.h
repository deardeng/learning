struct INFO1{
    char cust_name[21];
    char cust_addr[31];
    char model[21];
    enum {PURE_CASE,CASH_LOAN,LEASE}type;
    union{
        struct{
            float msrp;
            float sales_price;
            float sales_tax;
            float licensing_fee;
        }pure_case;
        struct{
            float msrp;
            float sales_price;
            float sales_tax;
            float licensing_fee;
            float down_payment;
            int loan_duration;
            float interest_rate;
            float monthly_payment;
            char bank[21];
        }cash_loan;
        struct{
            float msrp;
            float sales_price;
            float down_payment;
            float security_deposit;
            float monthly_payment;
            float lease_term;
        }lease;
    }info;
};
