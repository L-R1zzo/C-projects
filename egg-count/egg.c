int egg_count(int decimal){
    int count = 0;
    while (decimal > 0){
        count += decimal & 1;
        decimal >>= 1;
    }
    return count;
}

int main(void){
    return 0;
}
