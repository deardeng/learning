struct test1{
    int a;
    char b;
};

class base{
    public:
        int get_test();
        void set_test(int i);
    private:
        int t1;
};

int base::get_test(){
    return 0;
}

void base::set_test(int i){
    t1=i;
}

int test(){
    base *b;
    struct test1 t;
    t.
